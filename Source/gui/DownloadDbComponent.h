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

class HybridReverb2Editor;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DownloadDbComponent  : public Component,
                             public Button::Listener
{
public:
    //==============================================================================
    DownloadDbComponent (HybridReverb2Editor *editor);
    ~DownloadDbComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    HybridReverb2Editor *editor = nullptr;
    double progressValue = 0;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupComponent;
    std::unique_ptr<TextButton> btnLoadFile;
    std::unique_ptr<Label> label;
    std::unique_ptr<HyperlinkButton> hyperlinkButton;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Label> label5;
    std::unique_ptr<HyperlinkButton> hyperlinkButton2;
    std::unique_ptr<Label> label6;
    std::unique_ptr<HyperlinkButton> hyperlinkButton3;
    std::unique_ptr<Label> label7;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DownloadDbComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
