/***************************************************************************
 *   Copyright (C) 2009 by Christian Borss                                 *
 *   christian.borss@rub.de                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "HybridReverb2Processor.h"
#include "MasterAndCommander.h"
#include "SystemConfig.h"


//==============================================================================
/**
    This function must be implemented to create a new instance of your
    plugin object.
*/
AudioProcessor* JUCE_CALLTYPE createPluginFilter(const String &userDir)
{
    std::shared_ptr<SystemConfig> systemConfig(new SystemConfig(userDir));
    systemConfig->setupLanguage();
    return new HybridReverb2Processor(systemConfig);
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return createPluginFilter(String());
}


//==============================================================================
HybridReverb2Processor::HybridReverb2Processor(const std::shared_ptr<SystemConfig> &systemConfig)
    : AudioProcessor(BusesProperties()
                     .withInput("Input", AudioChannelSet::stereo(), true)
                     .withOutput("Output", AudioChannelSet::stereo(), true)),
      systemConfig(systemConfig)
{
    master.reset(new MasterAndCommander(this, systemConfig));
    paramPreferences = master->getPreferences();
    paramPartitionWisdom = master->getPartitionWisdom();
    partitioner.reset(new Partitioner(paramPartitionWisdom));

    setLatencySamples(paramPreferences.sflen);
}

HybridReverb2Processor::~HybridReverb2Processor()
{
}

//==============================================================================
const String HybridReverb2Processor::getName() const
{
#ifdef NO_OMP
    return "HybridReverb2";
#else
    return "HybridReverb2 - OpenMP";
#endif
}

int HybridReverb2Processor::getNumParameters()
{
    return 1;
}

float HybridReverb2Processor::getParameter (int index)
{
    float ret = 0.0;
    switch (index) {
    case 0:
        ret = (currentPreset - 1.0) / 255.0;
        break;
    }
    return ret;
}

void HybridReverb2Processor::setParameter (int index, float newValue)
{
    switch (index) {
    case 0:
        int newPreset = roundf(newValue * 255.0 + 1.0);
        if (currentPreset != newPreset)
        {
            // if this is changing the preset number, broadcast a change message which
            // our editor will pick up.
            currentPreset = newPreset;
            sendChangeMessage ();
        }
        break;
    }
}

const String HybridReverb2Processor::getParameterName (int index)
{
    if (index == 0)
        return TRANS("preset nr.");

    return String();
}

const String HybridReverb2Processor::getParameterText (int index)
{
    if (index == 0)
        return String (currentPreset);

    return String();
}

const String HybridReverb2Processor::getInputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String HybridReverb2Processor::getOutputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

bool HybridReverb2Processor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool HybridReverb2Processor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool HybridReverb2Processor::acceptsMidi() const
{
    return false;
}

bool HybridReverb2Processor::producesMidi() const
{
    return false;
}

int HybridReverb2Processor::getNumPrograms()
{
    return 1;
}

int HybridReverb2Processor::getCurrentProgram()
{
    return 0;
}

void HybridReverb2Processor::setCurrentProgram (int index)
{
}

const String HybridReverb2Processor::getProgramName (int index)
{
    return String();
}

void HybridReverb2Processor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void HybridReverb2Processor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // do your pre-playback setup stuff here..
}

void HybridReverb2Processor::releaseResources()
{
    // when playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void HybridReverb2Processor::processBlock (AudioSampleBuffer& buffer,
                                   MidiBuffer& midiMessages)
{
    if (!convolver)
    {
        buffer.clear();
        return;
    }

    if (newConvolver)
    {
        newConvolver = false;
        for (int i = 0, n = getTotalNumInputChannels(); i < n; ++i)
            buffer.applyGainRamp(i, 0, buffer.getNumSamples(), 0.0, 1.0);
    }

    if (convolver)
    {
        convolver->process(buffer);
    }

    // in case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getTotalNumInputChannels(), n = getTotalNumOutputChannels(); i < n; ++i)
    {
        buffer.clear(i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
AudioProcessorEditor* HybridReverb2Processor::createEditor()
{
    HybridReverb2Editor* editor = new HybridReverb2Editor(this, this, systemConfig);
    return editor;
}

void HybridReverb2Processor::onReadyEditor()
{
    master->loadInitialPreset();
    master->onGuiReady();
}

//==============================================================================
void HybridReverb2Processor::getStateInformation (MemoryBlock& destData)
{
    // create a root element..
    XmlElement xmlState ("HybridReverb2Settings");

    // add some attributes to it..
    xmlState.setAttribute ("pluginVersion", 2);
    xmlState.setAttribute ("presetNum", currentPreset);
    xmlState.setAttribute ("uiWidth", lastUIWidth);
    xmlState.setAttribute ("uiHeight", lastUIHeight);

    // use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xmlState, destData);

    master->print(String("saving preset: ") +
                  String(currentPreset) +
                  String(" [HybridReverb2Processor::getStateInformation()]\n"));
}

void HybridReverb2Processor::setStateInformation (const void* data, int sizeInBytes)
{
    // use this helper function to get the XML from this binary blob..
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState)
    {
        // check that it's the right type of xml..
        if (xmlState->hasTagName ("HybridReverb2Settings"))
        {
            // ok, now pull out our parameters..
            currentPreset = xmlState->getIntAttribute ("presetNum", currentPreset);

            lastUIWidth = xmlState->getIntAttribute ("uiWidth", lastUIWidth);
            lastUIHeight = xmlState->getIntAttribute ("uiHeight", lastUIHeight);

            master->print(String("restoring preset: ") +
                          String(currentPreset) +
                          String(" [HybridReverb2Processor::setStateInformation()]\n"));

            sendChangeMessage ();
        }
    }
}


//==============================================================================
void HybridReverb2Processor::setNewFilterSet(SampleData *impulses)
{
    int hlen, type, sflen, mflen, lflen;
    std::unique_ptr<HybridConvolver> brandnewConvolver;

    master->print("*** updating filter ***\n");
    paramPreferences = master->getPreferences();
    hlen = impulses->getDataLen();
    sflen = paramPreferences.sflen;
    partitioner->analyze(hlen, sflen, paramPreferences.strategy);
    mflen = partitioner->getM();
    lflen = partitioner->getL();
    type  = partitioner->getType();

    switch (type) {
    case PARTITION_TYPE_TRIPPLE:
        brandnewConvolver.reset(new HybridConvolverTripple(sflen, mflen, lflen, impulses));
        break;
    case PARTITION_TYPE_DUAL:
        brandnewConvolver.reset(new HybridConvolverDual(sflen, mflen, impulses));
        break;
    default:
        brandnewConvolver.reset(new HybridConvolverSingle(sflen, impulses));
    }

    // critical section
    suspendProcessing(true);
    newConvolver = convolver != nullptr;
    convolver = std::move(brandnewConvolver);
    suspendProcessing(false);
}
