//          Copyright Jean Pierre Cimalando 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../HybridReverb2Processor.h"
#include "../gui/Editor.h"
#include <memory>
#include <jack/jack.h>
#include <jack/midiport.h>
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

    const String getApplicationName() override
        { return JucePlugin_Name; }
    const String getApplicationVersion() override
        { return JucePlugin_VersionString; }

private:
    static int process(jack_nframes_t nframes, void *user_data);

    std::unique_ptr<HybridReverb2Processor> processor_;
    std::unique_ptr<Application_Window> window_;

    struct jack_client_deleter {
        void operator()(jack_client_t *c) const { jack_client_close(c); }
    };
    std::unique_ptr<jack_client_t, jack_client_deleter> client_;
    jack_port_t *inport_[JackNumInputs] = {};
    jack_port_t *outport_[JackNumOutputs] = {};
};

void Application_Jack::initialise(const String &args)
{
    jack_client_t *client = jack_client_open(JucePlugin_Name, JackNoStartServer, nullptr);
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

void Application_Jack::shutdown()
{
    client_.reset();
    window_.reset();
    processor_.reset();
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

JUCE_CREATE_APPLICATION_DEFINE(Application_Jack);
JUCE_MAIN_FUNCTION_DEFINITION;
