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


#ifndef __AUDIOPLUGIN_H__
#define __AUDIOPLUGIN_H__


#include "../JuceLibraryCode/JuceHeader.h"
#include "gui/Editor.h"
#include "SampleData.h"
#include "HybridConvolver.h"
#include "HybridConvolverTripple.h"
#include "HybridConvolverDual.h"
#include "HybridConvolverSingle.h"
#include "Partitioner.h"
#include "ParamPreferences.h"
#include "ParamPartitionWisdom.h"


// forward declarations
class MasterAndCommander;
class SystemConfig;


//==============================================================================
/**
    A simple plugin filter that just applies a gain change to the audio
    passing through it.

*/
class HybridReverb2Processor  : public AudioProcessor,
                                public HybridReverb2Editor::ReadyListener,
                                public ChangeBroadcaster
{
public:
    //==============================================================================
    explicit HybridReverb2Processor(const std::shared_ptr<SystemConfig> &systemConfig);
    ~HybridReverb2Processor();

    //==============================================================================
    MasterAndCommander *getMaster() { return master.get(); }

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer& buffer,
                       MidiBuffer& midiMessages) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }
    void onReadyEditor() override;

    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;

    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (const int channelIndex) const override;
    const String getOutputChannelName (const int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    double getTailLengthSeconds() const override
        { return 0; }

    bool acceptsMidi() const override;
    bool producesMidi() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==============================================================================
    void setNewFilterSet(SampleData *impulses);

    //==============================================================================
    // These properties are public so that our editor component can access them
    //  - a bit of a hacky way to do it, but it's only a demo!

    // this is kept up to date with the midi messages that arrive, and the UI component
    // registers with it so it can represent the incoming messages
//    MidiKeyboardState keyboardState;

    // this keeps a copy of the last set of time info that was acquired during an audio
    // callback - the UI component will read this and display it.
//    AudioPlayHead::CurrentPositionInfo lastPosInfo;

    // these are used to persist the UI's size - the values are stored along with the
    // filter's other parameters, and the UI component will update them when it gets
    // resized.
    int lastUIWidth = 828, lastUIHeight = 548;

private:
    // this is our current preset - the UI and the host can access this by getting/setting
    // parameter 0.
    int currentPreset = 1;
    std::shared_ptr<SystemConfig> systemConfig;
    std::unique_ptr<MasterAndCommander> master;
    std::unique_ptr<Partitioner> partitioner;
    std::unique_ptr<HybridConvolver> convolver;
    bool newConvolver = false;
    ParamPreferences paramPreferences;
    ParamPartitionWisdom paramPartitionWisdom;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HybridReverb2Processor)
};


#endif
