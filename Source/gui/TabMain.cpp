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

//[Headers] You can add your own extra header files here...
#include "../MasterAndCommander.h"
#include "../PresetManager.h"
#include "IRPlot.h"
#include <iostream>
//[/Headers]

#include "TabMain.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabMain::TabMain (MasterAndCommander *m)
    : master (m)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponentNotes.reset (new GroupComponent ("new group",
                                                   TRANS("Notes")));
    addAndMakeVisible (groupComponentNotes.get());

    groupComponentNotes->setBounds (336, 8, 480, 224);

    groupComponentMainControl.reset (new GroupComponent ("new group",
                                                         TRANS("Main Controls")));
    addAndMakeVisible (groupComponentMainControl.get());

    groupComponentMainControl->setBounds (8, 240, 320, 268);

    labelPresetNum.reset (new Label ("new label",
                                     TRANS("1")));
    addAndMakeVisible (labelPresetNum.get());
    labelPresetNum->setFont (Font (Font::getDefaultMonospacedFontName(), 32.00f, Font::plain));
    labelPresetNum->setJustificationType (Justification::centred);
    labelPresetNum->setEditable (false, false, false);
    labelPresetNum->setColour (Label::backgroundColourId, Colours::white);
    labelPresetNum->setColour (Label::textColourId, Colours::black);
    labelPresetNum->setColour (Label::outlineColourId, Colour (0xffa6a6a6));
    labelPresetNum->setColour (TextEditor::textColourId, Colours::black);
    labelPresetNum->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelPresetNum->setBounds (16, 16, 64, 48);

    groupComponentPresetSelector.reset (new GroupComponent ("new group",
                                                            TRANS("Preset Selector")));
    addAndMakeVisible (groupComponentPresetSelector.get());

    groupComponentPresetSelector->setBounds (8, 72, 320, 160);

    labelPresetText.reset (new Label ("new label",
                                      TRANS("123456789012345678901234")));
    addAndMakeVisible (labelPresetText.get());
    labelPresetText->setFont (Font (Font::getDefaultMonospacedFontName(), 20.00f, Font::plain));
    labelPresetText->setJustificationType (Justification::centred);
    labelPresetText->setEditable (false, false, false);
    labelPresetText->setColour (Label::backgroundColourId, Colours::white);
    labelPresetText->setColour (Label::outlineColourId, Colour (0xffa6a6a6));
    labelPresetText->setColour (TextEditor::textColourId, Colours::black);
    labelPresetText->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelPresetText->setBounds (112, 16, 208, 48);

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("---"));
    comboBox->addItem (TRANS("channels: front"), 1);
    comboBox->addListener (this);

    comboBox->setBounds (24, 96, 288, 24);

    comboBox2.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox2.get());
    comboBox2->setEditableText (false);
    comboBox2->setJustificationType (Justification::centredLeft);
    comboBox2->setTextWhenNothingSelected (String());
    comboBox2->setTextWhenNoChoicesAvailable (TRANS("---"));
    comboBox2->addItem (TRANS("room: large concert hall"), 1);
    comboBox2->addListener (this);

    comboBox2->setBounds (24, 128, 288, 24);

    comboBox3.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox3.get());
    comboBox3->setEditableText (false);
    comboBox3->setJustificationType (Justification::centredLeft);
    comboBox3->setTextWhenNothingSelected (String());
    comboBox3->setTextWhenNoChoicesAvailable (TRANS("---"));
    comboBox3->addItem (TRANS("purpose: music"), 1);
    comboBox3->addListener (this);

    comboBox3->setBounds (24, 160, 288, 24);

    comboBox4.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox4.get());
    comboBox4->setEditableText (false);
    comboBox4->setJustificationType (Justification::centredLeft);
    comboBox4->setTextWhenNothingSelected (String());
    comboBox4->setTextWhenNoChoicesAvailable (TRANS("---"));
    comboBox4->addItem (TRANS("distance: 1m"), 1);
    comboBox4->addListener (this);

    comboBox4->setBounds (24, 192, 288, 24);

    textEditorNotes.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditorNotes.get());
    textEditorNotes->setMultiLine (true);
    textEditorNotes->setReturnKeyStartsNewLine (true);
    textEditorNotes->setReadOnly (true);
    textEditorNotes->setScrollbarsShown (true);
    textEditorNotes->setCaretVisible (false);
    textEditorNotes->setPopupMenuEnabled (true);
    textEditorNotes->setText (String());

    textEditorNotes->setBounds (352, 32, 448, 184);

    groupComponentIRPlot.reset (new GroupComponent ("new group",
                                                    TRANS("Impulse Response")));
    addAndMakeVisible (groupComponentIRPlot.get());

    groupComponentIRPlot->setBounds (336, 240, 480, 268);

    sliderInitialGap.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderInitialGap.get());
    sliderInitialGap->setRange (0, 100, 0.1);
    sliderInitialGap->setSliderStyle (Slider::Rotary);
    sliderInitialGap->setTextBoxStyle (Slider::TextBoxAbove, false, 72, 20);
    sliderInitialGap->setColour (Slider::rotarySliderFillColourId, Colour (0xff100040));
    sliderInitialGap->addListener (this);

    sliderInitialGap->setBounds (32, 264, 64, 88);

    labelInitialGap.reset (new Label ("new label",
                                      TRANS("Initial Gap")));
    addAndMakeVisible (labelInitialGap.get());
    labelInitialGap->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelInitialGap->setJustificationType (Justification::centred);
    labelInitialGap->setEditable (false, false, false);
    labelInitialGap->setColour (TextEditor::textColourId, Colours::black);
    labelInitialGap->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelInitialGap->setBounds (24, 344, 80, 24);

    sliderLength.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderLength.get());
    sliderLength->setRange (0, 1, 0.001);
    sliderLength->setSliderStyle (Slider::Rotary);
    sliderLength->setTextBoxStyle (Slider::TextBoxAbove, false, 72, 20);
    sliderLength->setColour (Slider::rotarySliderFillColourId, Colour (0xff100040));
    sliderLength->addListener (this);

    sliderLength->setBounds (136, 264, 64, 88);

    labelLength.reset (new Label ("new label",
                                  TRANS("Length")));
    addAndMakeVisible (labelLength.get());
    labelLength->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelLength->setJustificationType (Justification::centred);
    labelLength->setEditable (false, false, false);
    labelLength->setColour (TextEditor::textColourId, Colours::black);
    labelLength->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelLength->setBounds (128, 344, 80, 24);

    sliderPreDelay.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderPreDelay.get());
    sliderPreDelay->setRange (-100, 100, 0.1);
    sliderPreDelay->setSliderStyle (Slider::Rotary);
    sliderPreDelay->setTextBoxStyle (Slider::TextBoxAbove, false, 72, 20);
    sliderPreDelay->setColour (Slider::rotarySliderFillColourId, Colour (0xff100040));
    sliderPreDelay->addListener (this);

    sliderPreDelay->setBounds (240, 264, 64, 88);

    labelPreDelay.reset (new Label ("new label",
                                    TRANS("Pre-Delay")));
    addAndMakeVisible (labelPreDelay.get());
    labelPreDelay->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelPreDelay->setJustificationType (Justification::centred);
    labelPreDelay->setEditable (false, false, false);
    labelPreDelay->setColour (TextEditor::textColourId, Colours::black);
    labelPreDelay->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelPreDelay->setBounds (232, 344, 80, 24);

    sliderDryGain.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderDryGain.get());
    sliderDryGain->setRange (-120, 0, 0.1);
    sliderDryGain->setSliderStyle (Slider::Rotary);
    sliderDryGain->setTextBoxStyle (Slider::TextBoxAbove, false, 72, 20);
    sliderDryGain->addListener (this);

    sliderDryGain->setBounds (32, 392, 64, 88);

    labelDryGain.reset (new Label ("new label",
                                   TRANS("Dry Gain")));
    addAndMakeVisible (labelDryGain.get());
    labelDryGain->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelDryGain->setJustificationType (Justification::centred);
    labelDryGain->setEditable (false, false, false);
    labelDryGain->setColour (TextEditor::textColourId, Colours::black);
    labelDryGain->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelDryGain->setBounds (32, 472, 72, 24);

    sliderWetGain.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderWetGain.get());
    sliderWetGain->setRange (-40, 40, 0.1);
    sliderWetGain->setSliderStyle (Slider::Rotary);
    sliderWetGain->setTextBoxStyle (Slider::TextBoxAbove, false, 72, 20);
    sliderWetGain->addListener (this);

    sliderWetGain->setBounds (136, 392, 64, 88);

    sliderMasterGain.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderMasterGain.get());
    sliderMasterGain->setRange (-40, 40, 0.1);
    sliderMasterGain->setSliderStyle (Slider::Rotary);
    sliderMasterGain->setTextBoxStyle (Slider::TextBoxAbove, false, 72, 20);
    sliderMasterGain->addListener (this);

    sliderMasterGain->setBounds (240, 392, 64, 88);

    labelWetGain.reset (new Label ("new label",
                                   TRANS("Wet Gain")));
    addAndMakeVisible (labelWetGain.get());
    labelWetGain->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelWetGain->setJustificationType (Justification::centred);
    labelWetGain->setEditable (false, false, false);
    labelWetGain->setColour (TextEditor::textColourId, Colours::black);
    labelWetGain->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelWetGain->setBounds (128, 472, 80, 24);

    labelMasterGain.reset (new Label ("new label",
                                      TRANS("Master Gain")));
    addAndMakeVisible (labelMasterGain.get());
    labelMasterGain->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelMasterGain->setJustificationType (Justification::centred);
    labelMasterGain->setEditable (false, false, false);
    labelMasterGain->setColour (TextEditor::textColourId, Colours::black);
    labelMasterGain->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelMasterGain->setBounds (232, 472, 80, 24);

    sliderPresetIncDec.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderPresetIncDec.get());
    sliderPresetIncDec->setRange (0, 257, 1);
    sliderPresetIncDec->setSliderStyle (Slider::IncDecButtons);
    sliderPresetIncDec->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sliderPresetIncDec->addListener (this);

    sliderPresetIncDec->setBounds (88, 16, 18, 48);

    irPlot.reset (new IRPlot (master));
    addAndMakeVisible (irPlot.get());
    irPlot->setName ("new component");

    irPlot->setBounds (352, 264, 448, 228);

    slider0ms.reset (new Slider ("new slider"));
    addAndMakeVisible (slider0ms.get());
    slider0ms->setRange (-80, 20, 0.1);
    slider0ms->setSliderStyle (Slider::LinearVertical);
    slider0ms->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 12);
    slider0ms->setColour (Slider::thumbColourId, Colour (0xffb00000));
    slider0ms->setColour (Slider::trackColourId, Colour (0x60a08080));
    slider0ms->setColour (Slider::rotarySliderFillColourId, Colour (0x7f800000));
    slider0ms->setColour (Slider::textBoxTextColourId, Colours::maroon);
    slider0ms->setColour (Slider::textBoxHighlightColourId, Colour (0x40ff0000));
    slider0ms->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    slider0ms->addListener (this);

    slider0ms->setBounds (389, 276, 56, 178);

    slider20ms.reset (new Slider ("new slider"));
    addAndMakeVisible (slider20ms.get());
    slider20ms->setRange (-80, 20, 0.1);
    slider20ms->setSliderStyle (Slider::LinearVertical);
    slider20ms->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 12);
    slider20ms->setColour (Slider::thumbColourId, Colour (0xffb00000));
    slider20ms->setColour (Slider::trackColourId, Colour (0x60a08080));
    slider20ms->setColour (Slider::rotarySliderFillColourId, Colour (0x7f800000));
    slider20ms->setColour (Slider::textBoxTextColourId, Colours::maroon);
    slider20ms->setColour (Slider::textBoxHighlightColourId, Colour (0x40ff0000));
    slider20ms->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    slider20ms->addListener (this);

    slider20ms->setBounds (489, 276, 56, 178);

    slider120ms.reset (new Slider ("new slider"));
    addAndMakeVisible (slider120ms.get());
    slider120ms->setRange (-80, 20, 0.1);
    slider120ms->setSliderStyle (Slider::LinearVertical);
    slider120ms->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 12);
    slider120ms->setColour (Slider::thumbColourId, Colour (0xffb00000));
    slider120ms->setColour (Slider::trackColourId, Colour (0x60a08080));
    slider120ms->setColour (Slider::rotarySliderFillColourId, Colour (0x7f800000));
    slider120ms->setColour (Slider::textBoxTextColourId, Colours::maroon);
    slider120ms->setColour (Slider::textBoxHighlightColourId, Colour (0x40ff0000));
    slider120ms->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    slider120ms->addListener (this);

    slider120ms->setBounds (614, 276, 56, 178);

    sliderENDms.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderENDms.get());
    sliderENDms->setRange (-80, 20, 0.1);
    sliderENDms->setSliderStyle (Slider::LinearVertical);
    sliderENDms->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 12);
    sliderENDms->setColour (Slider::thumbColourId, Colour (0xffb00000));
    sliderENDms->setColour (Slider::trackColourId, Colour (0x60a08080));
    sliderENDms->setColour (Slider::rotarySliderFillColourId, Colour (0x7f800000));
    sliderENDms->setColour (Slider::textBoxTextColourId, Colours::maroon);
    sliderENDms->setColour (Slider::textBoxHighlightColourId, Colour (0x40ff0000));
    sliderENDms->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    sliderENDms->addListener (this);

    sliderENDms->setBounds (739, 276, 56, 178);


    //[UserPreSize]
    sliderInitialGap->setTextValueSuffix (T(" ms"));
    sliderInitialGap->setDoubleClickReturnValue (true, 0.0);

    sliderLength->setTextValueSuffix (T(" s"));
    sliderLength->setDoubleClickReturnValue (true, 1.0);

    sliderPreDelay->setTextValueSuffix (T(" ms"));
    sliderPreDelay->setDoubleClickReturnValue (true, 0.0);

    sliderDryGain->setTextValueSuffix (T(" dB"));
    sliderDryGain->setDoubleClickReturnValue (true, 0.0);

    sliderWetGain->setTextValueSuffix (T(" dB"));
    sliderWetGain->setDoubleClickReturnValue (true, 0.0);

    sliderMasterGain->setTextValueSuffix (T(" dB"));
    sliderMasterGain->setDoubleClickReturnValue (true, 0.0);

    slider0ms->setTextValueSuffix (T(" dB"));
    slider0ms->setDoubleClickReturnValue (true, 0.0);

    slider20ms->setTextValueSuffix (T(" dB"));
    slider20ms->setDoubleClickReturnValue (true, 0.0);

    slider120ms->setTextValueSuffix (T(" dB"));
    slider120ms->setDoubleClickReturnValue (true, 0.0);

    sliderENDms->setTextValueSuffix (T(" dB"));
    sliderENDms->setDoubleClickReturnValue (true, 0.0);

    sliderPresetIncDec->setValue(1, dontSendNotification);
    //[/UserPreSize]

    setSize (828, 548);


    //[Constructor] You can add your own custom stuff here..
//    master->print("TabMain::TabMain : Waiting for your commands, Sir!");
    master->registerTabMain(this);
    //[/Constructor]
}

TabMain::~TabMain()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponentNotes = nullptr;
    groupComponentMainControl = nullptr;
    labelPresetNum = nullptr;
    groupComponentPresetSelector = nullptr;
    labelPresetText = nullptr;
    comboBox = nullptr;
    comboBox2 = nullptr;
    comboBox3 = nullptr;
    comboBox4 = nullptr;
    textEditorNotes = nullptr;
    groupComponentIRPlot = nullptr;
    sliderInitialGap = nullptr;
    labelInitialGap = nullptr;
    sliderLength = nullptr;
    labelLength = nullptr;
    sliderPreDelay = nullptr;
    labelPreDelay = nullptr;
    sliderDryGain = nullptr;
    labelDryGain = nullptr;
    sliderWetGain = nullptr;
    sliderMasterGain = nullptr;
    labelWetGain = nullptr;
    labelMasterGain = nullptr;
    sliderPresetIncDec = nullptr;
    irPlot = nullptr;
    slider0ms = nullptr;
    slider20ms = nullptr;
    slider120ms = nullptr;
    sliderENDms = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabMain::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffffe000));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabMain::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TabMain::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox.get())
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        int index = comboBoxThatHasChanged->getSelectedItemIndex();
        int old_preset = sliderPresetIncDec->getValue();
        int new_preset = presetManager->getSimilarPreset(old_preset, 0, index);
        if (new_preset != old_preset)
        {
            sliderPresetIncDec->setValue(new_preset, sendNotification);
            labelPresetNum->setText(String(new_preset), dontSendNotification);
        }
        //[/UserComboBoxCode_comboBox]
    }
    else if (comboBoxThatHasChanged == comboBox2.get())
    {
        //[UserComboBoxCode_comboBox2] -- add your combo box handling code here..
        int index = comboBoxThatHasChanged->getSelectedItemIndex();
        int old_preset = sliderPresetIncDec->getValue();
        int new_preset = presetManager->getSimilarPreset(old_preset, 1, index);
        if (new_preset != old_preset)
        {
            sliderPresetIncDec->setValue(new_preset, sendNotification);
            labelPresetNum->setText(String(new_preset), dontSendNotification);
        }
        //[/UserComboBoxCode_comboBox2]
    }
    else if (comboBoxThatHasChanged == comboBox3.get())
    {
        //[UserComboBoxCode_comboBox3] -- add your combo box handling code here..
        int index = comboBoxThatHasChanged->getSelectedItemIndex();
        int old_preset = sliderPresetIncDec->getValue();
        int new_preset = presetManager->getSimilarPreset(old_preset, 2, index);
        if (new_preset != old_preset)
        {
            sliderPresetIncDec->setValue(new_preset, sendNotification);
            labelPresetNum->setText(String(new_preset), dontSendNotification);
        }
        //[/UserComboBoxCode_comboBox3]
    }
    else if (comboBoxThatHasChanged == comboBox4.get())
    {
        //[UserComboBoxCode_comboBox4] -- add your combo box handling code here..
        int index = comboBoxThatHasChanged->getSelectedItemIndex();
        int old_preset = sliderPresetIncDec->getValue();
        int new_preset = presetManager->getSimilarPreset(old_preset, 3, index);
        if (new_preset != old_preset)
        {
            sliderPresetIncDec->setValue(new_preset, sendNotification);
            labelPresetNum->setText(String(new_preset), dontSendNotification);
        }
        //[/UserComboBoxCode_comboBox4]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void TabMain::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderInitialGap.get())
    {
        //[UserSliderCode_sliderInitialGap] -- add your slider handling code here..
        //[/UserSliderCode_sliderInitialGap]
    }
    else if (sliderThatWasMoved == sliderLength.get())
    {
        //[UserSliderCode_sliderLength] -- add your slider handling code here..
        //[/UserSliderCode_sliderLength]
    }
    else if (sliderThatWasMoved == sliderPreDelay.get())
    {
        //[UserSliderCode_sliderPreDelay] -- add your slider handling code here..
        //[/UserSliderCode_sliderPreDelay]
    }
    else if (sliderThatWasMoved == sliderDryGain.get())
    {
        //[UserSliderCode_sliderDryGain] -- add your slider handling code here..
        //[/UserSliderCode_sliderDryGain]
    }
    else if (sliderThatWasMoved == sliderWetGain.get())
    {
        //[UserSliderCode_sliderWetGain] -- add your slider handling code here..
        //[/UserSliderCode_sliderWetGain]
    }
    else if (sliderThatWasMoved == sliderMasterGain.get())
    {
        //[UserSliderCode_sliderMasterGain] -- add your slider handling code here..
        //[/UserSliderCode_sliderMasterGain]
    }
    else if (sliderThatWasMoved == sliderPresetIncDec.get())
    {
        //[UserSliderCode_sliderPresetIncDec] -- add your slider handling code here..
        int value = (int)sliderThatWasMoved->getValue();
        if (value == 0)
        {
            value = presetManager->getNumPresets();
            sliderPresetIncDec->setValue(value, dontSendNotification);
            labelPresetNum->setText(String(value), dontSendNotification);
        }
        if (value > presetManager->getNumPresets())
        {
            value = 1;
            sliderPresetIncDec->setValue(value, dontSendNotification);
            labelPresetNum->setText(String(value), dontSendNotification);
        }
        String str(value);
        labelPresetNum->setText (str, dontSendNotification);
        master->onValueChangedPresetNum(value);
        //[/UserSliderCode_sliderPresetIncDec]
    }
    else if (sliderThatWasMoved == slider0ms.get())
    {
        //[UserSliderCode_slider0ms] -- add your slider handling code here..
        paramEnvelope.db0ms = (float)sliderThatWasMoved->getValue();
        irPlot->setEnvelope(&paramEnvelope);
        //[/UserSliderCode_slider0ms]
    }
    else if (sliderThatWasMoved == slider20ms.get())
    {
        //[UserSliderCode_slider20ms] -- add your slider handling code here..
        paramEnvelope.db20ms = (float)sliderThatWasMoved->getValue();
        irPlot->setEnvelope(&paramEnvelope);
        //[/UserSliderCode_slider20ms]
    }
    else if (sliderThatWasMoved == slider120ms.get())
    {
        //[UserSliderCode_slider120ms] -- add your slider handling code here..
        paramEnvelope.db120ms = (float)sliderThatWasMoved->getValue();
        irPlot->setEnvelope(&paramEnvelope);
        //[/UserSliderCode_slider120ms]
    }
    else if (sliderThatWasMoved == sliderENDms.get())
    {
        //[UserSliderCode_sliderENDms] -- add your slider handling code here..
        paramEnvelope.dbENDms = (float)sliderThatWasMoved->getValue();
        irPlot->setEnvelope(&paramEnvelope);
        //[/UserSliderCode_sliderENDms]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TabMain::setPresetManager(PresetManager *man)
{
    presetManager = man;
}


void TabMain::setGainDelayRange (ParamGainDelay *min,
                                 ParamGainDelay *value,
                                 ParamGainDelay *max)
{
    paramGainDelay.initialGap = value->initialGap;
    paramGainDelay.length     = value->length;
    paramGainDelay.preDelay   = value->preDelay;
    paramGainDelay.dryGain    = value->dryGain;
    paramGainDelay.wetGain    = value->wetGain;
    paramGainDelay.masterGain = value->masterGain;

    sliderInitialGap->setRange (min->initialGap, max->initialGap, 0.1);
    sliderInitialGap->setDoubleClickReturnValue (true, value->initialGap);
    sliderInitialGap->setValue (value->initialGap);

    sliderLength->setRange (min->length, max->length, 0.001);
    sliderLength->setDoubleClickReturnValue (true, value->length);
    sliderLength->setValue (value->length);

    sliderPreDelay->setRange (min->preDelay, max->preDelay, 0.1);
    sliderPreDelay->setDoubleClickReturnValue (true, value->preDelay);
    sliderPreDelay->setValue (value->preDelay);

    sliderDryGain->setRange (min->dryGain, max->dryGain, 0.1);
    sliderDryGain->setDoubleClickReturnValue (true, value->dryGain);
    sliderDryGain->setValue (value->dryGain);

    sliderWetGain->setRange (min->wetGain, max->wetGain, 0.1);
    sliderWetGain->setDoubleClickReturnValue (true, value->wetGain);
    sliderWetGain->setValue (value->wetGain);

    sliderMasterGain->setRange (min->masterGain, max->masterGain, 0.1);
    sliderMasterGain->setDoubleClickReturnValue (true, value->masterGain);
    sliderMasterGain->setValue (value->masterGain);
}


void TabMain::setEnvelope (ParamEnvelope *param)
{
    paramEnvelope.db0ms   = param->db0ms;
    paramEnvelope.db20ms  = param->db20ms;
    paramEnvelope.db120ms = param->db120ms;
    paramEnvelope.dbENDms = param->dbENDms;

    slider0ms->setDoubleClickReturnValue (true, param->db0ms);
    slider0ms->setValue (param->db0ms);

    slider20ms->setDoubleClickReturnValue (true, param->db20ms);
    slider20ms->setValue (param->db20ms);

    slider120ms->setDoubleClickReturnValue (true, param->db120ms);
    slider120ms->setValue (param->db120ms);

    sliderENDms->setDoubleClickReturnValue (true, param->dbENDms);
    sliderENDms->setValue (param->dbENDms);

    irPlot->setEnvelope(param);
}


void TabMain::setNum(int num)
{
    sliderPresetIncDec->setValue(num, sendNotification);
    labelPresetNum->setText(String(num), dontSendNotification);
}


void TabMain::setID(const String &id)
{
    labelPresetText->setText(id, dontSendNotification);
}


void TabMain::setNotes(const String &notes)
{
    textEditorNotes->setText(notes, false);
}


void TabMain::addNotes(const String &notes)
{
    textEditorNotes->setText(textEditorNotes->getText() + notes, false);
}


void TabMain::setComboText(int num, const std::vector<String> & items)
{
    ComboBox *combo = 0;

    switch (num) {
    case 0:
        combo = comboBox.get();
        break;
    case 1:
        combo = comboBox2.get();
        break;
    case 2:
        combo = comboBox3.get();
        break;
    case 3:
        combo = comboBox4.get();
        break;
    default:
        return;
    }

    combo->clear();
    int size = items.size();
    for (int i = 0; i < size; i++)
    {
        combo->addItem(items[i], i + 1);
        combo->setSelectedItemIndex(0, sendNotification);
    }
}


void TabMain::setComboIndex(int num, int index)
{
    ComboBox *combo = 0;

    switch (num) {
    case 0:
        combo = comboBox.get();
        break;
    case 1:
        combo = comboBox2.get();
        break;
    case 2:
        combo = comboBox3.get();
        break;
    case 3:
        combo = comboBox4.get();
        break;
    default:
        return;
    }

    combo->setSelectedItemIndex(index, dontSendNotification);
}



void TabMain::sliderDragEnded (Slider* sliderThatWasMoved)
{
    if (sliderThatWasMoved == sliderInitialGap.get())
    {
        paramGainDelay.initialGap = (float)sliderThatWasMoved->getValue();
        master->onValueChangedGainDelay(&paramGainDelay);
    }
    else if (sliderThatWasMoved == sliderLength.get())
    {
        paramGainDelay.length = (float)sliderThatWasMoved->getValue();
        master->onValueChangedGainDelay(&paramGainDelay);
    }
    else if (sliderThatWasMoved == sliderPreDelay.get())
    {
        paramGainDelay.preDelay = (float)sliderThatWasMoved->getValue();
        master->onValueChangedGainDelay(&paramGainDelay);
    }
    else if (sliderThatWasMoved == sliderDryGain.get())
    {
        paramGainDelay.dryGain = (float)sliderThatWasMoved->getValue();
        master->onValueChangedGainDelay(&paramGainDelay);
    }
    else if (sliderThatWasMoved == sliderWetGain.get())
    {
        paramGainDelay.wetGain = (float)sliderThatWasMoved->getValue();
        master->onValueChangedGainDelay(&paramGainDelay);
    }
    else if (sliderThatWasMoved == sliderMasterGain.get())
    {
        paramGainDelay.masterGain = (float)sliderThatWasMoved->getValue();
        master->onValueChangedGainDelay(&paramGainDelay);
    }
    else if (sliderThatWasMoved == slider0ms.get())
    {
        paramEnvelope.db0ms = (float)sliderThatWasMoved->getValue();
        master->onValueChangedEnvelope(&paramEnvelope);
    }
    else if (sliderThatWasMoved == slider20ms.get())
    {
        paramEnvelope.db20ms = (float)sliderThatWasMoved->getValue();
        master->onValueChangedEnvelope(&paramEnvelope);
    }
    else if (sliderThatWasMoved == slider120ms.get())
    {
        paramEnvelope.db120ms = (float)sliderThatWasMoved->getValue();
        master->onValueChangedEnvelope(&paramEnvelope);
    }
    else if (sliderThatWasMoved == sliderENDms.get())
    {
        paramEnvelope.dbENDms = (float)sliderThatWasMoved->getValue();
        master->onValueChangedEnvelope(&paramEnvelope);
    }
    else if (sliderThatWasMoved == sliderPresetIncDec.get())
    {
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TabMain" componentName=""
                 parentClasses="public Component" constructorParams="MasterAndCommander *m"
                 variableInitialisers="master (m)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="828"
                 initialHeight="548">
  <BACKGROUND backgroundColour="ffffe000"/>
  <GROUPCOMPONENT name="new group" id="2aedd7f3e63566ae" memberName="groupComponentNotes"
                  virtualName="" explicitFocusOrder="0" pos="336 8 480 224" title="Notes"/>
  <GROUPCOMPONENT name="new group" id="ba8ec165006103c9" memberName="groupComponentMainControl"
                  virtualName="" explicitFocusOrder="0" pos="8 240 320 268" title="Main Controls"/>
  <LABEL name="new label" id="cb80d2c00f6f4fde" memberName="labelPresetNum"
         virtualName="" explicitFocusOrder="0" pos="16 16 64 48" bkgCol="ffffffff"
         textCol="ff000000" outlineCol="ffa6a6a6" edTextCol="ff000000"
         edBkgCol="0" labelText="1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="32.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="new group" id="4ae17a7023ba5a57" memberName="groupComponentPresetSelector"
                  virtualName="" explicitFocusOrder="0" pos="8 72 320 160" title="Preset Selector"/>
  <LABEL name="new label" id="339d5634c5d72249" memberName="labelPresetText"
         virtualName="" explicitFocusOrder="0" pos="112 16 208 48" bkgCol="ffffffff"
         outlineCol="ffa6a6a6" edTextCol="ff000000" edBkgCol="0" labelText="123456789012345678901234"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="20.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="new combo box" id="87beef21daa23739" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="24 96 288 24" editable="0"
            layout="33" items="channels: front" textWhenNonSelected="" textWhenNoItems="---"/>
  <COMBOBOX name="new combo box" id="bd5157c19f9c7890" memberName="comboBox2"
            virtualName="" explicitFocusOrder="0" pos="24 128 288 24" editable="0"
            layout="33" items="room: large concert hall" textWhenNonSelected=""
            textWhenNoItems="---"/>
  <COMBOBOX name="new combo box" id="e73e4e224a5962ef" memberName="comboBox3"
            virtualName="" explicitFocusOrder="0" pos="24 160 288 24" editable="0"
            layout="33" items="purpose: music" textWhenNonSelected="" textWhenNoItems="---"/>
  <COMBOBOX name="new combo box" id="10a8db346ad11563" memberName="comboBox4"
            virtualName="" explicitFocusOrder="0" pos="24 192 288 24" editable="0"
            layout="33" items="distance: 1m" textWhenNonSelected="" textWhenNoItems="---"/>
  <TEXTEDITOR name="new text editor" id="b55e466f47a1e1e2" memberName="textEditorNotes"
              virtualName="" explicitFocusOrder="0" pos="352 32 448 184" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <GROUPCOMPONENT name="new group" id="a7877980277a1ec9" memberName="groupComponentIRPlot"
                  virtualName="" explicitFocusOrder="0" pos="336 240 480 268" title="Impulse Response"/>
  <SLIDER name="new slider" id="3a29d000adba987a" memberName="sliderInitialGap"
          virtualName="" explicitFocusOrder="0" pos="32 264 64 88" rotarysliderfill="ff100040"
          min="0.00000000000000000000" max="100.00000000000000000000" int="0.10000000000000000555"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="72" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="new label" id="5798d3217c731b41" memberName="labelInitialGap"
         virtualName="" explicitFocusOrder="0" pos="24 344 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Initial Gap" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="28765c3773e71052" memberName="sliderLength"
          virtualName="" explicitFocusOrder="0" pos="136 264 64 88" rotarysliderfill="ff100040"
          min="0.00000000000000000000" max="1.00000000000000000000" int="0.00100000000000000002"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="72" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="new label" id="f3c2b7440b347a61" memberName="labelLength"
         virtualName="" explicitFocusOrder="0" pos="128 344 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Length" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="7301188eec83b236" memberName="sliderPreDelay"
          virtualName="" explicitFocusOrder="0" pos="240 264 64 88" rotarysliderfill="ff100040"
          min="-100.00000000000000000000" max="100.00000000000000000000"
          int="0.10000000000000000555" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="72" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="new label" id="c38c84e89303b7bb" memberName="labelPreDelay"
         virtualName="" explicitFocusOrder="0" pos="232 344 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pre-Delay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="5cb4bd672fe901b9" memberName="sliderDryGain"
          virtualName="" explicitFocusOrder="0" pos="32 392 64 88" min="-120.00000000000000000000"
          max="0.00000000000000000000" int="0.10000000000000000555" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="72"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="62ee2c982a920e38" memberName="labelDryGain"
         virtualName="" explicitFocusOrder="0" pos="32 472 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="8b8df4d967726bae" memberName="sliderWetGain"
          virtualName="" explicitFocusOrder="0" pos="136 392 64 88" min="-40.00000000000000000000"
          max="40.00000000000000000000" int="0.10000000000000000555" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="72"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="new slider" id="1a1bd25399e125e9" memberName="sliderMasterGain"
          virtualName="" explicitFocusOrder="0" pos="240 392 64 88" min="-40.00000000000000000000"
          max="40.00000000000000000000" int="0.10000000000000000555" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="72"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="578ba82700669d32" memberName="labelWetGain"
         virtualName="" explicitFocusOrder="0" pos="128 472 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Wet Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="49662ce77eee2baf" memberName="labelMasterGain"
         virtualName="" explicitFocusOrder="0" pos="232 472 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Master Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="32c4e582e5416a7f" memberName="sliderPresetIncDec"
          virtualName="" explicitFocusOrder="0" pos="88 16 18 48" min="0.00000000000000000000"
          max="257.00000000000000000000" int="1.00000000000000000000" style="IncDecButtons"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <GENERICCOMPONENT name="new component" id="fd905be5f952e922" memberName="irPlot"
                    virtualName="" explicitFocusOrder="0" pos="352 264 448 228" class="IRPlot"
                    params="master"/>
  <SLIDER name="new slider" id="41658652959a9450" memberName="slider0ms"
          virtualName="" explicitFocusOrder="0" pos="389 276 56 178" thumbcol="ffb00000"
          trackcol="60a08080" rotarysliderfill="7f800000" textboxtext="ff800000"
          textboxhighlight="40ff0000" textboxoutline="0" min="-80.00000000000000000000"
          max="20.00000000000000000000" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="12" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="new slider" id="f87d8ddeeff666ea" memberName="slider20ms"
          virtualName="" explicitFocusOrder="0" pos="489 276 56 178" thumbcol="ffb00000"
          trackcol="60a08080" rotarysliderfill="7f800000" textboxtext="ff800000"
          textboxhighlight="40ff0000" textboxoutline="0" min="-80.00000000000000000000"
          max="20.00000000000000000000" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="12" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="new slider" id="df0287b13f868f7a" memberName="slider120ms"
          virtualName="" explicitFocusOrder="0" pos="614 276 56 178" thumbcol="ffb00000"
          trackcol="60a08080" rotarysliderfill="7f800000" textboxtext="ff800000"
          textboxhighlight="40ff0000" textboxoutline="0" min="-80.00000000000000000000"
          max="20.00000000000000000000" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="12" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="new slider" id="110b3dfc023c5cc5" memberName="sliderENDms"
          virtualName="" explicitFocusOrder="0" pos="739 276 56 178" thumbcol="ffb00000"
          trackcol="60a08080" rotarysliderfill="7f800000" textboxtext="ff800000"
          textboxhighlight="40ff0000" textboxoutline="0" min="-80.00000000000000000000"
          max="20.00000000000000000000" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="12" skewFactor="1.00000000000000000000" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
