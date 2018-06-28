//          Copyright Jean Pierre Cimalando 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "Jack.h"

enum {
    JackNumInputs = 2,
    JackNumOutputs = 2,
};

class Application_Window : public DocumentWindow
{
public:
    explicit Application_Window(const String &name)
        : DocumentWindow(
            name,
            LookAndFeel::getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId),
            DocumentWindow::minimiseButton|DocumentWindow::closeButton)
        {}

    void closeButtonPressed() override
        { JUCEApplicationBase::quit(); }
};

class Application_Jack : public JUCEApplication
{
public:
    void initialise(const String &args) override;
    void shutdown() override;
    void open(const String &client_name, const String &pref_file);
    void save();
    bool is_open() const { return is_open_; }
    void on_idle();

    const String getApplicationName() override
        { return JucePlugin_Name; }
    const String getApplicationVersion() override
        { return JucePlugin_VersionString; }

private:
    static int process(jack_nframes_t nframes, void *user_data);

    std::unique_ptr<HybridReverb2Processor> processor_;
    std::unique_ptr<Application_Window> window_;
    bool is_open_ = false;

    struct jack_client_deleter {
        void operator()(jack_client_t *c) const { jack_client_close(c); }
    };
    std::unique_ptr<jack_client_t, jack_client_deleter> client_;
    jack_port_t *inport_[JackNumInputs] = {};
    jack_port_t *outport_[JackNumOutputs] = {};

    class Idle_Timer : public Timer
    {
    public:
        explicit Idle_Timer(Application_Jack *app) : app_(app) {}
        void timerCallback() override { app_->on_idle(); }
    private:
        Application_Jack *app_ = nullptr;
    };

    std::unique_ptr<Idle_Timer> idle_timer_;

    static void handle_interrupts();
    static sig_atomic_t interrupted_by_signal ;

#if defined(WITH_NSM_SESSION_SUPPORT)
    static int session_open(const char *path, const char *display_name, const char *client_id, char **out_msg, void *userdata);
    static int session_save(char **out_msg, void *userdata);
    static void session_show_optional_gui(void *userdata);
    static void session_hide_optional_gui(void *userdata);
    void session_notify_gui_visibility();

    nsm_client_u nsmclient_;
    File session_dir_;
    bool session_gui_shown_ = false;
#endif
};

void Application_Jack::initialise(const String &args)
{
    handle_interrupts();

    Application_Window *window = new Application_Window(getApplicationName());
    window_.reset(window);

#if defined(WITH_NSM_SESSION_SUPPORT)
    if (const char *url = getenv("NSM_URL")) {
        nsm_client_t *nsmclient = nsm_new();
        if (!nsmclient)
            throw std::runtime_error("nsm_new");
        nsmclient_.reset(nsmclient);

        if (nsm_init(nsmclient, url) != 0)
            throw std::runtime_error("nsm_init");

        nsm_set_open_callback(nsmclient, &session_open, this);
        nsm_set_save_callback(nsmclient, &session_save, this);
        nsm_set_show_optional_gui_callback(nsmclient, &session_show_optional_gui, this);
        nsm_set_hide_optional_gui_callback(nsmclient, &session_hide_optional_gui, this);

        const char *capabilities = ":switch:optional-gui:";
        nsm_send_announce(
            nsmclient, JucePlugin_Name, capabilities, juce_argv[0]);

        session_notify_gui_visibility();
    }
    else
#endif
    {
        open(JucePlugin_Name, String());
        window_->setVisible(true);
    }

    Idle_Timer *idle_timer = new Idle_Timer(this);
    idle_timer_.reset(idle_timer);
    idle_timer->startTimer(50);
}

void Application_Jack::shutdown()
{
    idle_timer_.reset();
    client_.reset();
    window_.reset();
    processor_.reset();
}

void Application_Jack::on_idle()
{
    if (interrupted_by_signal) {
        setApplicationReturnValue(1);
        quit();
        return;
    }

#if defined(WITH_NSM_SESSION_SUPPORT)
    nsm_client_t *nsmclient = nsmclient_.get();
    if (nsmclient)
        nsm_check_nowait(nsmclient);
#endif
}

void Application_Jack::open(const String &client_name, const String &pref_file)
{
    if (is_open_)
        return;
    is_open_ = true;

    jack_client_t *client = jack_client_open(client_name.toRawUTF8(), JackNoStartServer, nullptr);
    if (!client)
        throw std::runtime_error("error creating Jack client");
    client_.reset(client);

    for (unsigned i = 0; i < JackNumInputs; ++i) {
        char name[64];
        sprintf(name, "audio_in_%u", i + 1);
        jack_port_t *port = jack_port_register(client, name, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
        if (!port)
            throw std::runtime_error("error creating Jack input ports");
        inport_[i] = port;
    }

    for (unsigned i = 0; i < JackNumOutputs; ++i) {
        char name[64];
        sprintf(name, "audio_out_%u", i + 1);
        jack_port_t *port = jack_port_register(client, name, JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
        if (!port)
            throw std::runtime_error("error creating Jack output ports");
        outport_[i] = port;
    }

    jack_nframes_t buffer_size = jack_get_buffer_size(client);
    unsigned sample_rate = jack_get_sample_rate(client);

    HybridReverb2Processor *processor = static_cast<HybridReverb2Processor *>(
        createPluginFilter(pref_file));
    processor_.reset(processor);
    processor->prepareToPlay(sample_rate, buffer_size);
    processor->setPlayConfigDetails(JackNumInputs, JackNumOutputs, sample_rate, buffer_size);

    jack_set_process_callback(client, &process, this);

    if (jack_activate(client) != 0)
        throw std::runtime_error("error activating Jack client");

    String effective_name = jack_get_client_name(client);

    Application_Window *window = window_.get();
    window->setName(getApplicationName() + " [jack:" + effective_name + "]");

    HybridReverb2Editor *editor = static_cast<HybridReverb2Editor *>(
        processor->createEditor());
    window->setContentOwned(editor, true);
}

void Application_Jack::save()
{
    HybridReverb2Processor &processor = *processor_;

    processor.getSystemConfig().writePreferencesFile();
}

int Application_Jack::process(jack_nframes_t nframes, void *user_data)
{
    Application_Jack *self = reinterpret_cast<Application_Jack *>(user_data);
    HybridReverb2Processor &processor = *self->processor_;

    static_assert(JackNumOutputs >= JackNumInputs, "cannot have more inputs than outputs");
    float *channels[JackNumOutputs];

    for (unsigned i = 0; i < JackNumOutputs; ++i) {
        channels[i] = (float *)jack_port_get_buffer(self->outport_[i], nframes);
    }
    for (unsigned i = 0; i < JackNumInputs; ++i) {
        const float *buf = (float *)jack_port_get_buffer(self->inport_[i], nframes);
        memcpy(channels[i], buf, nframes * sizeof(*buf));
    }

    AudioSampleBuffer sample_buffer(channels, JackNumOutputs, nframes);
    MidiBuffer midi_messages;

    const ScopedLock lock(processor.getCallbackLock());
    if (processor.isSuspended())
        sample_buffer.clear();
    else
        processor.processBlock(sample_buffer, midi_messages);

    return 0;
}

void Application_Jack::handle_interrupts()
{
    sigset_t sigs;
    int nsignal = 0;

    sigemptyset(&sigs);
    for (int signo : {SIGINT, SIGTERM}) {
        sigaddset(&sigs, signo);
        nsignal = signo + 1;
    }

    for (int sig = 1; sig < nsignal; ++sig) {
        if (!sigismember(&sigs, sig))
            continue;
        struct sigaction sa = {};
        sa.sa_handler = +[](int) { interrupted_by_signal = 1; };
        sa.sa_mask = sigs;
        if (sigaction(sig, &sa, nullptr) == -1)
            throw std::system_error(errno, std::generic_category(), "sigaction");
    }

    std::thread handler_thread(+[]() { for (;;) pause(); });
    handler_thread.detach();

    if (pthread_sigmask(SIG_BLOCK, &sigs, nullptr) == -1)
        throw std::system_error(errno, std::generic_category(), "pthread_sigmask");
}

#if defined(WITH_NSM_SESSION_SUPPORT)
int Application_Jack::session_open(const char *path, const char *display_name, const char *client_id, char **out_msg, void *userdata)
{
    Application_Jack *self = reinterpret_cast<Application_Jack *>(userdata);

    File session_dir(path);
    self->session_dir_ = session_dir;
    session_dir.createDirectory();

    self->open(client_id, session_dir.getFullPathName());

    bool session_gui_shown = session_dir.getChildFile("gui_shown").existsAsFile();
    self->window_->setVisible(session_gui_shown);
    if (self->session_gui_shown_ != session_gui_shown) {
        self->session_gui_shown_ = session_gui_shown;
        self->session_notify_gui_visibility();
    }

    HybridReverb2Processor &processor = *self->processor_;
    File state_file = session_dir.getChildFile("state.dat");
    MemoryBlock state;
    if (state_file.loadFileAsData(state))
        processor.setStateInformation(state.getData(), state.getSize());

    return 0;
}

int Application_Jack::session_save(char **out_msg, void *userdata)
{
    Application_Jack *self = reinterpret_cast<Application_Jack *>(userdata);

    self->save();

    HybridReverb2Processor &processor = *self->processor_;
    const File &session_dir = self->session_dir_;
    File state_file = session_dir.getChildFile("state.dat");
    MemoryBlock state;
    processor.getStateInformation(state);
    state_file.replaceWithData(state.getData(), state.getSize());

    File gui_shown_file = session_dir.getChildFile("gui_shown");
    if (self->session_gui_shown_)
        gui_shown_file.create();
    else
        gui_shown_file.deleteFile();

    return 0;
}

void Application_Jack::session_show_optional_gui(void *userdata)
{
    Application_Jack *self = reinterpret_cast<Application_Jack *>(userdata);
    Application_Window &window = *self->window_;

    self->session_gui_shown_ = true;
    if (self->is_open_)
        window.setVisible(true);

    self->session_notify_gui_visibility();
}

void Application_Jack::session_hide_optional_gui(void *userdata)
{
    Application_Jack *self = reinterpret_cast<Application_Jack *>(userdata);
    Application_Window &window = *self->window_;

    self->session_gui_shown_ = false;
    if (self->is_open_)
        window.setVisible(false);

    self->session_notify_gui_visibility();
}

void Application_Jack::session_notify_gui_visibility()
{
    Application_Window &window = *window_;
    nsm_client_t *nsmclient = nsmclient_.get();

    if (session_gui_shown_)
        nsm_send_gui_is_shown(nsmclient);
    else
        nsm_send_gui_is_hidden(nsmclient);
}
#endif

sig_atomic_t Application_Jack::interrupted_by_signal = 0;

JUCE_CREATE_APPLICATION_DEFINE(Application_Jack);
JUCE_MAIN_FUNCTION_DEFINITION;
