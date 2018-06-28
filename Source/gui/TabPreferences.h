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
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../model/Parameter.h"

// forward declarations
class MasterAndCommander;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabPreferences  : public Component,
                        public TextEditor::Listener,
                        public Button::Listener,
                        public ComboBox::Listener
{
public:
    //==============================================================================
    TabPreferences (MasterAndCommander *m);
    ~TabPreferences();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setPreferences(const ParamPreferences & param);
    String getFileChooserResult(String dir);
    void textEditorTextChanged (TextEditor &editor) override;
    void textEditorReturnKeyPressed (TextEditor &editor) override;
    void textEditorEscapeKeyPressed (TextEditor &editor) override;
    void textEditorFocusLost (TextEditor &editor) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* directivity2_png;
    static const int directivity2_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MasterAndCommander* master;
    ParamPreferences paramPreferences;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupComponentHelp;
    std::unique_ptr<Label> labelPreset;
    std::unique_ptr<TextEditor> textEditorPreset;
    std::unique_ptr<GroupComponent> groupComponentStrategy;
    std::unique_ptr<ToggleButton> toggleButtonUniform;
    std::unique_ptr<ToggleButton> toggleButtonLowest;
    std::unique_ptr<Label> labelLatency;
    std::unique_ptr<ComboBox> comboBoxLatency;
    std::unique_ptr<TextEditor> textEditorHelp;
    std::unique_ptr<TextButton> textButton;
    std::unique_ptr<Label> label;
    Image cachedImage_directivity2_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabPreferences)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
