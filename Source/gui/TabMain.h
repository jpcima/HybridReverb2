/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../Param.h"
#include "../TextList.h"
#include <vector>

// forward declarations
class MasterAndCommander;
class PresetManager;

class IRPlot;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabMain  : public Component,
                 public ComboBox::Listener,
                 public Slider::Listener
{
public:
    //==============================================================================
    TabMain (MasterAndCommander *m);
    ~TabMain();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setPresetManager (PresetManager *man);
    void setGainDelayRange (ParamGainDelay *min,
                            ParamGainDelay *value,
                            ParamGainDelay *max);
    void setEnvelope (ParamEnvelope *param);
    void setNum(int num);
    void setID(const String &id);
    void setNotes(const String &notes);
    void addNotes(const String &notes);
    void setComboText(int num, const std::vector<String> & items);
    void setComboIndex(int num, int index);
    void sliderDragEnded (Slider* sliderThatWasMoved) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MasterAndCommander* master = nullptr;
    PresetManager* presetManager = nullptr;
    ParamGainDelay paramGainDelay;
    ParamEnvelope paramEnvelope;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupComponentNotes;
    std::unique_ptr<GroupComponent> groupComponentMainControl;
    std::unique_ptr<Label> labelPresetNum;
    std::unique_ptr<GroupComponent> groupComponentPresetSelector;
    std::unique_ptr<Label> labelPresetText;
    std::unique_ptr<ComboBox> comboBox;
    std::unique_ptr<ComboBox> comboBox2;
    std::unique_ptr<ComboBox> comboBox3;
    std::unique_ptr<ComboBox> comboBox4;
    std::unique_ptr<TextEditor> textEditorNotes;
    std::unique_ptr<GroupComponent> groupComponentIRPlot;
    std::unique_ptr<Slider> sliderInitialGap;
    std::unique_ptr<Label> labelInitialGap;
    std::unique_ptr<Slider> sliderLength;
    std::unique_ptr<Label> labelLength;
    std::unique_ptr<Slider> sliderPreDelay;
    std::unique_ptr<Label> labelPreDelay;
    std::unique_ptr<Slider> sliderDryGain;
    std::unique_ptr<Label> labelDryGain;
    std::unique_ptr<Slider> sliderWetGain;
    std::unique_ptr<Slider> sliderMasterGain;
    std::unique_ptr<Label> labelWetGain;
    std::unique_ptr<Label> labelMasterGain;
    std::unique_ptr<Slider> sliderPresetIncDec;
    std::unique_ptr<IRPlot> irPlot;
    std::unique_ptr<Slider> slider0ms;
    std::unique_ptr<Slider> slider20ms;
    std::unique_ptr<Slider> slider120ms;
    std::unique_ptr<Slider> sliderENDms;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabMain)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
