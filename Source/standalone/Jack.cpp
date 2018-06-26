//          Copyright Jean Pierre Cimalando 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../HybridReverb2Processor.h"
#include "../gui/Editor.h"
#include <jack/jack.h>
#include <jack/midiport.h>
#include <memory>
#include <thread>
#include <system_error>
#include <signal.h>
#include <unistd.h>
extern AudioProcessor* JUCE_CALLTYPE createPluginFilter();

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
            DocumentWindow::minimiseButton|DocumentWindow::closeButton) {}

    void closeButtonPressed() override
        { JUCEApplicationBase::quit(); }
};

class Application_Jack : public JUCEApplication
{
public:
    void initialise(const String &args) override;
    void shutdown() override;
    void open(const String &client_name);
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
};

void Application_Jack::initialise(const String &args)
{
    handle_interrupts();
    open(JucePlugin_Name);

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
}

void Application_Jack::open(const String &client_name)
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
        createPluginFilter());
    processor_.reset(processor);
    processor->prepareToPlay(sample_rate, buffer_size);
    processor->setPlayConfigDetails(JackNumInputs, JackNumOutputs, sample_rate, buffer_size);

    jack_set_process_callback(client, &process, this);

    if (jack_activate(client) != 0)
        throw std::runtime_error("error activating Jack client");

    Application_Window *window = new Application_Window(
        getApplicationName() + " [jack:" + (const char *)jack_get_client_name(client) + "]");
    window_.reset(window);

    HybridReverb2Editor *editor = static_cast<HybridReverb2Editor *>(
        processor->createEditor());
    window->setContentOwned(editor, true);
    window->setVisible(true);
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

sig_atomic_t Application_Jack::interrupted_by_signal = 0;

JUCE_CREATE_APPLICATION_DEFINE(Application_Jack);
JUCE_MAIN_FUNCTION_DEFINITION;
