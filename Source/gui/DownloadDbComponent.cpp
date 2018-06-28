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
#include "Editor.h"
#include "../utility/I18nTools.h"
//[/Headers]

#include "DownloadDbComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DownloadDbComponent::DownloadDbComponent (HybridReverb2Editor *editor)
{
    //[Constructor_pre] You can add your own custom stuff here..
    this->editor = editor;
    //[/Constructor_pre]

    groupComponent.reset (new GroupComponent ("new group",
                                              TRANS("Setup Preset Database")));
    addAndMakeVisible (groupComponent.get());

    groupComponent->setBounds (0, 0, 600, 376);

    btnLoadFile.reset (new TextButton ("new button"));
    addAndMakeVisible (btnLoadFile.get());
    btnLoadFile->setButtonText (TRANS("Load database file..."));
    btnLoadFile->addListener (this);

    btnLoadFile->setBounds (296, 104, 272, 24);

    label.reset (new Label ("new label",
                            TRANS("This software must install some impulse responses to continue.")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (32, 40, 536, 24);

    hyperlinkButton.reset (new HyperlinkButton (TRANS("HybridReverb2_large_database.zip"),
                                                URL ("http://www2.ika.ruhr-uni-bochum.de/HybridReverb2/HybridReverb2_large_database.zip")));
    addAndMakeVisible (hyperlinkButton.get());
    hyperlinkButton->setTooltip (TRANS("http://www2.ika.ruhr-uni-bochum.de/HybridReverb2/HybridReverb2_large_database.zip"));
    hyperlinkButton->setButtonText (TRANS("HybridReverb2_large_database.zip"));

    hyperlinkButton->setBounds (296, 72, 272, 24);

    propertyLabel.reset (new Label ("new label",
                                    CharPointer_UTF8 ("These room impulse responses for HybridReverb2 are property of the Institute of Communication Acoustics, Ruhr Universit\xc3\xa4t Bochum, Germany.")));
    addAndMakeVisible (propertyLabel.get());
    propertyLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    propertyLabel->setJustificationType (Justification::centredLeft);
    propertyLabel->setEditable (false, false, false);
    propertyLabel->setColour (TextEditor::textColourId, Colours::black);
    propertyLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    propertyLabel->setBounds (32, 176, 536, 32);

    label3.reset (new Label ("new label",
                             TRANS("Copyright Notice")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (32, 144, 536, 24);

    label4.reset (new Label ("new label",
                             TRANS("Click link to download:")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (56, 72, 232, 24);

    label5.reset (new Label ("new label",
                             TRANS("Install the file:")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (56, 104, 232, 24);

    hyperlinkButton2.reset (new HyperlinkButton (TRANS("http://www.ruhr-uni-bochum.de/ika/"),
                                                 URL ("http://www.ruhr-uni-bochum.de/ika/")));
    addAndMakeVisible (hyperlinkButton2.get());
    hyperlinkButton2->setTooltip (TRANS("http://www.ruhr-uni-bochum.de/ika/"));
    hyperlinkButton2->setButtonText (TRANS("http://www.ruhr-uni-bochum.de/ika/"));

    hyperlinkButton2->setBounds (40, 216, 272, 24);

    label6.reset (new Label ("new label",
                             TRANS("They are free for non-commercial use.\n"
                             "For commercial use, please contact:")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (32, 248, 536, 32);

    hyperlinkButton3.reset (new HyperlinkButton (TRANS("rainer.martin@ruhr-uni-bochum.de"),
                                                 URL ("mailto:rainer.martin@ruhr-uni-bochum.de")));
    addAndMakeVisible (hyperlinkButton3.get());
    hyperlinkButton3->setTooltip (TRANS("mailto:rainer.martin@ruhr-uni-bochum.de"));
    hyperlinkButton3->setButtonText (TRANS("rainer.martin@ruhr-uni-bochum.de"));

    hyperlinkButton3->setBounds (40, 288, 272, 24);

    label7.reset (new Label ("new label",
                             TRANS("They were generated with the \"tinyAVE\" software.")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (32, 320, 536, 24);


    //[UserPreSize]
    propertyLabel->setText(
        TRANS_UTF8(
            "These room impulse responses for HybridReverb2 are property of the "
            "Institute of Communication Acoustics, Ruhr Universität Bochum, Germany."),
        dontSendNotification);
    //[/UserPreSize]

    setSize (600, 378);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DownloadDbComponent::~DownloadDbComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    btnLoadFile = nullptr;
    label = nullptr;
    hyperlinkButton = nullptr;
    propertyLabel = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    hyperlinkButton2 = nullptr;
    label6 = nullptr;
    hyperlinkButton3 = nullptr;
    label7 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DownloadDbComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffffe000));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DownloadDbComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DownloadDbComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == btnLoadFile.get())
    {
        //[UserButtonCode_btnLoadFile] -- add your button handler code here..
        editor->chooseDbFileAndLoad();
        //[/UserButtonCode_btnLoadFile]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DownloadDbComponent" componentName=""
                 parentClasses="public Component" constructorParams="HybridReverb2Editor *editor"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="378">
  <BACKGROUND backgroundColour="ffffe000"/>
  <GROUPCOMPONENT name="new group" id="45a8c1e1ce67cc73" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 0 600 376" title="Setup Preset Database"/>
  <TEXTBUTTON name="new button" id="dee618dad1c2490" memberName="btnLoadFile"
              virtualName="" explicitFocusOrder="0" pos="296 104 272 24" buttonText="Load database file..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="dfed1153e8981211" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="32 40 536 24" edTextCol="ff000000"
         edBkgCol="0" labelText="This software must install some impulse responses to continue."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <HYPERLINKBUTTON name="new hyperlink" id="ab2dc46b149cd192" memberName="hyperlinkButton"
                   virtualName="" explicitFocusOrder="0" pos="296 72 272 24" tooltip="http://www2.ika.ruhr-uni-bochum.de/HybridReverb2/HybridReverb2_large_database.zip"
                   buttonText="HybridReverb2_large_database.zip" connectedEdges="0"
                   needsCallback="0" radioGroupId="0" url="http://www2.ika.ruhr-uni-bochum.de/HybridReverb2/HybridReverb2_large_database.zip"/>
  <LABEL name="new label" id="ed5965b814f8c4c0" memberName="propertyLabel"
         virtualName="" explicitFocusOrder="0" pos="32 176 536 32" edTextCol="ff000000"
         edBkgCol="0" labelText="These room impulse responses for HybridReverb2 are property of the Institute of Communication Acoustics, Ruhr Universit&#228;t Bochum, Germany."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2683eec4ab09418b" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="32 144 536 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Copyright Notice" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="new label" id="f40fe395ed330642" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="56 72 232 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Click link to download:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="391914e76a33d4d9" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="56 104 232 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Install the file:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <HYPERLINKBUTTON name="new hyperlink" id="c2d7cbb2a3435d72" memberName="hyperlinkButton2"
                   virtualName="" explicitFocusOrder="0" pos="40 216 272 24" tooltip="http://www.ruhr-uni-bochum.de/ika/"
                   buttonText="http://www.ruhr-uni-bochum.de/ika/" connectedEdges="0"
                   needsCallback="0" radioGroupId="0" url="http://www.ruhr-uni-bochum.de/ika/"/>
  <LABEL name="new label" id="f784da25f47214f" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="32 248 536 32" edTextCol="ff000000"
         edBkgCol="0" labelText="They are free for non-commercial use.&#10;For commercial use, please contact:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <HYPERLINKBUTTON name="new hyperlink" id="cb7948d2fe4c0b41" memberName="hyperlinkButton3"
                   virtualName="" explicitFocusOrder="0" pos="40 288 272 24" tooltip="mailto:rainer.martin@ruhr-uni-bochum.de"
                   buttonText="rainer.martin@ruhr-uni-bochum.de" connectedEdges="0"
                   needsCallback="0" radioGroupId="0" url="mailto:rainer.martin@ruhr-uni-bochum.de"/>
  <LABEL name="new label" id="70aa8eb69a72c639" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="32 320 536 24" edTextCol="ff000000"
         edBkgCol="0" labelText="They were generated with the &quot;tinyAVE&quot; software."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
