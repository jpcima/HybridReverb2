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
//[/Headers]

#include "TabPreferences.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabPreferences::TabPreferences (MasterAndCommander *m)
    : master (m)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponentHelp.reset (new GroupComponent ("new group",
                                                  TRANS("Help")));
    addAndMakeVisible (groupComponentHelp.get());

    groupComponentHelp->setBounds (416, 8, 400, 500);

    labelPreset.reset (new Label ("new label",
                                  TRANS("Preset File:")));
    addAndMakeVisible (labelPreset.get());
    labelPreset->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelPreset->setJustificationType (Justification::centredLeft);
    labelPreset->setEditable (false, false, false);
    labelPreset->setColour (TextEditor::textColourId, Colours::black);
    labelPreset->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelPreset->setBounds (16, 32, 152, 24);

    textEditorPreset.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditorPreset.get());
    textEditorPreset->setTooltip (TRANS("XML formatted preset file"));
    textEditorPreset->setMultiLine (false);
    textEditorPreset->setReturnKeyStartsNewLine (false);
    textEditorPreset->setReadOnly (false);
    textEditorPreset->setScrollbarsShown (false);
    textEditorPreset->setCaretVisible (true);
    textEditorPreset->setPopupMenuEnabled (true);
    textEditorPreset->setText (String());

    textEditorPreset->setBounds (168, 32, 200, 24);

    groupComponentStrategy.reset (new GroupComponent ("new group",
                                                      TRANS("Segmentation Strategy")));
    addAndMakeVisible (groupComponentStrategy.get());

    groupComponentStrategy->setBounds (8, 112, 394, 88);

    toggleButtonUniform.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButtonUniform.get());
    toggleButtonUniform->setTooltip (TRANS("slightly higher, but constant processing load"));
    toggleButtonUniform->setButtonText (TRANS("Uniform Processing Load"));
    toggleButtonUniform->setRadioGroupId (7007);
    toggleButtonUniform->addListener (this);
    toggleButtonUniform->setToggleState (true, dontSendNotification);

    toggleButtonUniform->setBounds (24, 136, 360, 24);

    toggleButtonLowest.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButtonLowest.get());
    toggleButtonLowest->setTooltip (TRANS("lowest overall processing load with load peaks"));
    toggleButtonLowest->setButtonText (TRANS("Lowest Mean Processing Load"));
    toggleButtonLowest->setRadioGroupId (7007);
    toggleButtonLowest->addListener (this);

    toggleButtonLowest->setBounds (24, 160, 360, 24);

    labelLatency.reset (new Label ("new label",
                                   TRANS("Latency:")));
    addAndMakeVisible (labelLatency.get());
    labelLatency->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelLatency->setJustificationType (Justification::centredLeft);
    labelLatency->setEditable (false, false, false);
    labelLatency->setColour (TextEditor::textColourId, Colours::black);
    labelLatency->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelLatency->setBounds (16, 72, 80, 24);

    comboBoxLatency.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBoxLatency.get());
    comboBoxLatency->setTooltip (TRANS("latency selection"));
    comboBoxLatency->setEditableText (false);
    comboBoxLatency->setJustificationType (Justification::centredLeft);
    comboBoxLatency->setTextWhenNothingSelected (String());
    comboBoxLatency->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxLatency->addItem (TRANS("64 samples (latency: 1.3ms at 48kHz)"), 1);
    comboBoxLatency->addItem (TRANS("128 samples (latency: 2.7ms at 48kHz)"), 2);
    comboBoxLatency->addItem (TRANS("256 samples (latency: 5.3ms at 48kHz)"), 3);
    comboBoxLatency->addItem (TRANS("512 samples (latency: 10.7ms at 48kHz)"), 4);
    comboBoxLatency->addItem (TRANS("1024 samples (latency: 21.3ms at 48kHz)"), 5);
    comboBoxLatency->addItem (TRANS("2048 samples (latency: 42.7ms at 48kHz)"), 6);
    comboBoxLatency->addItem (TRANS("4096 samples (latency: 85.3ms at 48kHz)"), 7);
    comboBoxLatency->addListener (this);

    comboBoxLatency->setBounds (96, 72, 304, 24);

    textEditorHelp.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditorHelp.get());
    textEditorHelp->setMultiLine (true);
    textEditorHelp->setReturnKeyStartsNewLine (true);
    textEditorHelp->setReadOnly (true);
    textEditorHelp->setScrollbarsShown (true);
    textEditorHelp->setCaretVisible (false);
    textEditorHelp->setPopupMenuEnabled (true);
    textEditorHelp->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));
    textEditorHelp->setText (TRANS("Preset File:\n"
    "\n"
    "This XML file defines the preset set.\n"
    "(default: HybridReverb2_presets.xml)\n"
    "\n"
    "\n"
    "Latency:\n"
    "\n"
    "HybridReverb2 convolves the input signal with room impulse responses which are partitioned into segments of different size. This option specifies the size of the initial segments which introduce a certain processing latency. A small segment size results in a lower latency at the cost of a higher computational complexity. An effect plugin for musical instruments requires signal processing with low latency. If the latency is not relevant for your application, you can choose a larger segment size for better performance.\n"
    "\n"
    "\n"
    "Segmentation Strategy:\n"
    "\n"
    "\"Uniform Processing Load\": This strategy tries to avoid processing load peaks at the cost of a slightly higher mean processing load. This is the recommended choice for signal processing with low latency.\n"
    "\"Lowest Mean Processing Load\": This strategy results in the best overall performance. This is the recommended choice for offline rendering."));

    textEditorHelp->setBounds (440, 40, 352, 440);

    textButton.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton.get());
    textButton->setTooltip (TRANS("Choose a file"));
    textButton->setButtonText (TRANS("..."));
    textButton->addListener (this);

    textButton->setBounds (372, 32, 30, 24);

    label.reset (new Label ("new label",
                            TRANS("FIG1: Generation of a sound field as simulated in a virtual environment at a given listener position by a virtual coincidence microphone array with the outlined directivity pattern")));
    addAndMakeVisible (label.get());
    label->setFont (Font (Font::getDefaultSerifFontName(), 15.00f, Font::plain).withTypefaceStyle ("Italic"));
    label->setJustificationType (Justification::topLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colour (0x89000000));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (16, 456, 394, 48);

    cachedImage_directivity2_png_1 = ImageCache::getFromMemory (directivity2_png, directivity2_pngSize);

    //[UserPreSize]
    textEditorPreset->addListener (this);
    comboBoxLatency->setSelectedItemIndex (0, dontSendNotification);
    //[/UserPreSize]

    setSize (828, 548);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TabPreferences::~TabPreferences()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponentHelp = nullptr;
    labelPreset = nullptr;
    textEditorPreset = nullptr;
    groupComponentStrategy = nullptr;
    toggleButtonUniform = nullptr;
    toggleButtonLowest = nullptr;
    labelLatency = nullptr;
    comboBoxLatency = nullptr;
    textEditorHelp = nullptr;
    textButton = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabPreferences::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffffe000));

    {
        int x = 24, y = 232, width = 362, height = 216;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black.withAlpha (0.200f));
        g.drawImageWithin (cachedImage_directivity2_png_1,
                           x, y, width, height,
                           RectanglePlacement::centred,
                           false);
    }

    {
        int x = 432, y = 32, width = 368, height = 456;
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabPreferences::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TabPreferences::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButtonUniform.get())
    {
        //[UserButtonCode_toggleButtonUniform] -- add your button handler code here..
        paramPreferences.strategy = STRATEGY_UNIFORM;
        fprintf(stderr, "TabPreferences: strategy = %d\n", STRATEGY_UNIFORM);
        master->onValueChangedPreferences(paramPreferences);
        //[/UserButtonCode_toggleButtonUniform]
    }
    else if (buttonThatWasClicked == toggleButtonLowest.get())
    {
        //[UserButtonCode_toggleButtonLowest] -- add your button handler code here..
        paramPreferences.strategy = STRATEGY_LOWEST;
        fprintf(stderr, "TabPreferences: strategy = %d\n", STRATEGY_LOWEST);
        master->onValueChangedPreferences(paramPreferences);
        //[/UserButtonCode_toggleButtonLowest]
    }
    else if (buttonThatWasClicked == textButton.get())
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        String filename = getFileChooserResult(master->getUserdir());
        if (filename != String())
        {
            paramPreferences.presetFile = filename;
            textEditorPreset->setText(filename, false);
            fprintf(stderr, "TabPreferences: preset file = %s\n", filename.toRawUTF8());
            AlertWindow::showMessageBox(AlertWindow::InfoIcon,
                                        TRANS("Info"),
                                        TRANS("HybridReverb2 needs to be restarted to make your changes effective."));
            master->onValueChangedPreferences(paramPreferences);
        }
        //[/UserButtonCode_textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TabPreferences::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBoxLatency.get())
    {
        //[UserComboBoxCode_comboBoxLatency] -- add your combo box handling code here..
        int index = comboBoxThatHasChanged->getSelectedItemIndex();
        paramPreferences.sflen = 64 << index;
        fprintf(stderr, "TabPreferences: SFLEN = %d\n", paramPreferences.sflen);
        AlertWindow::showMessageBox(AlertWindow::InfoIcon,
                                    TRANS("Info"),
                                    TRANS("HybridReverb2 needs to be restarted to make your changes effective."));

        master->onValueChangedPreferences(paramPreferences);
        //[/UserComboBoxCode_comboBoxLatency]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TabPreferences::setPreferences(const ParamPreferences & param)
{
    paramPreferences = param;
    textEditorPreset->setText(paramPreferences.presetFile, false);
    int sflenIndex = (int)log2(paramPreferences.sflen) - 6;
    comboBoxLatency->setSelectedItemIndex(sflenIndex, dontSendNotification);
    bool isUniform = (paramPreferences.strategy == STRATEGY_UNIFORM);
    toggleButtonUniform->setToggleState(isUniform, dontSendNotification);
    toggleButtonLowest->setToggleState(!isUniform, dontSendNotification);
}


String TabPreferences::getFileChooserResult(String dir)
{
    FileChooser fc(TRANS("Choose a preset file to open..."),
                   dir,
                   "*.xml",
                   true);

    if (fc.browseForFileToOpen())
    {
        File chosenFile = fc.getResult();
        return chosenFile.getFullPathName();
    }

    return String();
}


void TabPreferences::textEditorTextChanged (TextEditor &editor)
{
}


void TabPreferences::textEditorReturnKeyPressed (TextEditor &editor)
{
    paramPreferences.presetFile = editor.getText();
    fprintf(stderr, "TabPreferences: preset file = %s\n", paramPreferences.presetFile.toRawUTF8());
    AlertWindow::showMessageBox(AlertWindow::InfoIcon,
                                TRANS("Info"),
                                TRANS("HybridReverb2 needs to be restarted to make your changes effective."));
    master->onValueChangedPreferences(paramPreferences);
}


void TabPreferences::textEditorEscapeKeyPressed (TextEditor &editor)
{
}

void TabPreferences::textEditorFocusLost (TextEditor &editor)
{
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TabPreferences" componentName=""
                 parentClasses="public Component, public TextEditor::Listener"
                 constructorParams="MasterAndCommander *m" variableInitialisers="master (m)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="828" initialHeight="548">
  <BACKGROUND backgroundColour="ffffe000">
    <IMAGE pos="24 232 362 216" resource="directivity2_png" opacity="0.20000000000000001110"
           mode="1"/>
    <RECT pos="432 32 368 456" fill="solid: ffffffff" hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="735a0a2a7a30ed50" memberName="groupComponentHelp"
                  virtualName="" explicitFocusOrder="0" pos="416 8 400 500" title="Help"/>
  <LABEL name="new label" id="9f5eff377a1b3c8f" memberName="labelPreset"
         virtualName="" explicitFocusOrder="0" pos="16 32 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Preset File:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="e8e07b2e8a259e33" memberName="textEditorPreset"
              virtualName="" explicitFocusOrder="0" pos="168 32 200 24" tooltip="XML formatted preset file"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="0" caret="1" popupmenu="1"/>
  <GROUPCOMPONENT name="new group" id="cc8396c955dc75e8" memberName="groupComponentStrategy"
                  virtualName="" explicitFocusOrder="0" pos="8 112 394 88" title="Segmentation Strategy"/>
  <TOGGLEBUTTON name="new toggle button" id="3fe5a25a51b54518" memberName="toggleButtonUniform"
                virtualName="" explicitFocusOrder="0" pos="24 136 360 24" tooltip="slightly higher, but constant processing load"
                buttonText="Uniform Processing Load" connectedEdges="0" needsCallback="1"
                radioGroupId="7007" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="6c86fff6787f71e" memberName="toggleButtonLowest"
                virtualName="" explicitFocusOrder="0" pos="24 160 360 24" tooltip="lowest overall processing load with load peaks"
                buttonText="Lowest Mean Processing Load" connectedEdges="0" needsCallback="1"
                radioGroupId="7007" state="0"/>
  <LABEL name="new label" id="6825c569ae03a38a" memberName="labelLatency"
         virtualName="" explicitFocusOrder="0" pos="16 72 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Latency:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="2c65de4dc3e7086" memberName="comboBoxLatency"
            virtualName="" explicitFocusOrder="0" pos="96 72 304 24" tooltip="latency selection"
            editable="0" layout="33" items="64 samples (latency: 1.3ms at 48kHz)&#10;128 samples (latency: 2.7ms at 48kHz)&#10;256 samples (latency: 5.3ms at 48kHz)&#10;512 samples (latency: 10.7ms at 48kHz)&#10;1024 samples (latency: 21.3ms at 48kHz)&#10;2048 samples (latency: 42.7ms at 48kHz)&#10;4096 samples (latency: 85.3ms at 48kHz)"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="new text editor" id="bd5b83d29aa4002" memberName="textEditorHelp"
              virtualName="" explicitFocusOrder="0" pos="440 40 352 440" bkgcol="ffffff"
              initialText="Preset File:&#10;&#10;This XML file defines the preset set.&#10;(default: HybridReverb2_presets.xml)&#10;&#10;&#10;Latency:&#10;&#10;HybridReverb2 convolves the input signal with room impulse responses which are partitioned into segments of different size. This option specifies the size of the initial segments which introduce a certain processing latency. A small segment size results in a lower latency at the cost of a higher computational complexity. An effect plugin for musical instruments requires signal processing with low latency. If the latency is not relevant for your application, you can choose a larger segment size for better performance.&#10;&#10;&#10;Segmentation Strategy:&#10;&#10;&quot;Uniform Processing Load&quot;: This strategy tries to avoid processing load peaks at the cost of a slightly higher mean processing load. This is the recommended choice for signal processing with low latency.&#10;&quot;Lowest Mean Processing Load&quot;: This strategy results in the best overall performance. This is the recommended choice for offline rendering."
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="f637ba2e28c2e2ba" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="372 32 30 24" tooltip="Choose a file"
              buttonText="..." connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="407c242ecc8500cb" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 456 394 48" textCol="89000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FIG1: Generation of a sound field as simulated in a virtual environment at a given listener position by a virtual coincidence microphone array with the outlined directivity pattern"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default serif font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="1" justification="9"
         typefaceStyle="Italic"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: directivity2_png, 35442, "../resources/directivity2.png"
static const unsigned char resource_TabPreferences_directivity2_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,2,88,0,0,1,144,8,6,0,0,0,114,53,30,152,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,14,196,0,0,14,196,1,149,43,14,27,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,17,
116,69,88,116,84,105,116,108,101,0,83,86,71,32,100,114,97,119,105,110,103,6,76,211,167,0,0,32,0,73,68,65,84,120,156,236,157,117,184,28,229,217,135,239,221,184,145,16,34,16,32,66,66,8,86,36,184,91,129,
82,160,56,20,247,98,69,90,164,64,75,209,18,172,64,113,138,21,90,138,148,66,139,59,20,8,193,157,64,72,144,16,32,6,36,196,72,114,206,206,247,199,111,222,111,246,236,89,183,153,217,125,238,235,218,107,207,
217,29,121,118,118,118,222,223,60,239,35,96,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,
97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,
97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,97,24,134,
97,24,134,97,24,134,97,24,134,97,52,44,29,129,68,5,235,119,170,112,255,149,172,31,230,190,237,184,149,135,29,183,242,232,0,36,43,220,127,217,228,251,194,142,1,142,168,151,33,134,97,52,44,59,1,83,194,54,
34,131,35,128,83,128,69,192,226,18,215,77,0,67,253,245,202,249,92,221,128,97,192,23,192,188,50,214,95,26,232,9,124,10,164,74,92,183,35,48,28,152,9,124,91,198,190,251,0,203,0,147,208,177,43,133,106,29,
183,201,192,220,50,214,95,6,232,65,124,143,91,11,240,101,25,251,238,10,172,64,249,199,173,210,243,109,5,224,123,96,70,25,251,238,13,12,162,252,227,54,4,104,165,252,227,6,240,99,142,247,123,1,243,129,221,
129,79,178,45,208,49,207,198,7,1,107,2,239,80,250,5,200,48,12,99,25,96,89,160,75,216,134,100,97,40,176,34,186,104,127,12,44,44,114,189,4,26,104,123,251,255,123,72,40,21,75,15,96,4,186,179,30,142,46,204,
115,74,88,127,89,52,224,129,6,174,9,20,63,232,117,242,247,221,21,88,222,95,175,148,65,175,47,26,176,18,254,118,74,57,110,73,42,59,110,221,253,245,221,128,93,234,113,91,14,24,232,255,61,204,95,191,148,
227,54,28,9,188,229,145,237,211,75,216,119,250,113,27,142,190,179,74,206,183,207,75,216,119,119,244,93,185,227,54,17,248,161,132,245,51,207,183,79,144,96,41,6,183,207,238,254,35,5,76,43,97,223,75,162,
223,105,57,231,91,194,223,119,159,180,215,62,71,199,175,24,220,113,107,5,222,207,178,222,146,254,246,19,232,188,40,153,243,253,141,46,87,206,202,134,97,52,61,127,64,215,144,225,97,27,146,5,103,219,34,
116,225,93,161,136,117,186,2,143,248,235,253,25,184,219,255,251,38,138,155,134,88,31,221,201,127,15,28,136,6,155,185,192,150,69,218,124,137,191,191,199,129,179,252,191,95,4,150,40,98,221,101,209,0,213,
2,28,11,188,137,6,188,99,139,220,247,126,254,186,19,128,195,209,93,253,100,52,8,21,162,27,240,152,111,239,165,192,61,148,118,220,214,1,190,3,102,1,7,1,223,32,207,223,54,69,172,155,0,46,243,247,247,40,
240,71,255,239,23,40,238,184,45,3,124,136,62,251,175,129,215,208,113,59,177,136,117,33,56,110,31,35,175,105,41,199,173,11,240,144,111,239,149,192,157,254,223,183,82,220,113,91,27,121,220,102,163,227,246,
21,176,0,216,190,72,219,199,248,251,123,18,56,211,255,251,101,218,138,150,92,12,4,222,67,2,229,68,96,156,191,254,201,69,238,123,31,228,216,249,4,56,204,183,123,10,48,178,136,117,59,3,15,248,251,187,6,
248,155,255,247,63,200,239,84,114,172,69,112,220,54,206,242,254,158,232,186,241,173,191,221,159,20,177,205,118,152,192,50,12,163,18,226,32,176,14,69,23,239,201,200,163,149,139,238,192,19,254,58,23,251,
175,117,32,184,120,223,73,254,139,247,70,232,130,253,61,176,158,255,218,74,104,208,155,15,252,52,207,186,9,224,114,2,145,224,166,46,126,235,191,246,58,242,146,228,98,121,52,80,181,0,251,251,175,245,65,
131,94,49,98,225,151,104,176,251,8,9,53,208,32,189,0,137,157,85,242,172,219,29,13,208,30,112,145,255,90,7,224,118,138,59,110,163,209,64,246,61,18,168,160,65,118,10,18,43,59,229,89,55,1,92,225,239,231,
17,130,227,118,50,197,29,183,165,129,15,208,113,59,208,127,173,55,18,25,30,18,29,249,72,63,110,131,252,215,138,61,110,93,128,7,9,68,41,232,184,221,230,191,246,79,138,59,110,179,128,13,252,215,134,2,159,
33,47,208,206,5,108,191,192,223,207,99,4,30,154,163,209,249,242,6,176,84,158,117,211,197,213,33,254,107,61,129,231,252,109,254,190,192,190,157,184,250,152,224,124,219,22,253,78,166,2,171,229,89,55,93,
92,93,135,206,129,4,18,90,30,112,47,249,99,186,156,184,154,5,108,152,229,253,189,125,219,38,0,231,96,2,203,48,140,144,136,131,192,26,14,108,135,46,222,223,0,171,102,89,182,59,240,148,191,252,152,140,247,
210,7,189,187,200,62,232,109,140,166,101,190,67,222,152,116,210,197,66,182,65,47,129,188,23,30,240,48,129,72,112,156,68,48,232,101,19,11,131,209,180,80,11,176,111,198,123,197,136,133,67,209,64,57,158,
64,36,56,210,7,189,92,199,237,105,202,63,110,217,68,169,99,69,20,87,147,75,44,36,128,191,248,219,127,136,246,211,212,233,199,45,155,88,200,38,74,29,61,128,103,253,109,159,149,101,93,40,254,184,101,19,
11,233,162,244,226,140,247,146,200,131,229,33,15,106,169,199,109,8,138,165,90,8,236,146,101,221,92,162,212,241,43,255,115,189,5,244,203,178,126,186,40,61,40,227,189,30,192,51,228,63,110,251,250,235,166,
139,82,199,102,104,90,120,26,176,122,150,117,187,0,255,165,173,40,117,36,128,171,252,247,30,36,123,216,66,186,40,93,63,203,251,153,55,26,191,193,4,150,97,24,33,17,23,129,5,176,57,186,120,103,14,122,61,
200,45,18,28,9,224,90,127,153,123,104,123,135,188,41,18,87,211,201,125,33,30,74,246,65,175,152,65,1,224,40,36,22,222,164,173,88,72,31,76,119,205,177,110,62,177,112,4,26,76,63,36,136,195,201,36,125,208,
203,60,110,110,48,253,99,142,117,243,29,183,77,200,45,74,29,67,9,62,223,47,50,182,91,140,199,226,87,232,184,101,138,5,39,74,23,211,94,148,58,210,63,95,230,121,113,24,193,113,91,38,199,250,185,196,66,62,
49,239,168,244,184,13,38,8,26,79,63,47,10,137,82,71,174,243,34,159,40,117,228,19,221,135,83,248,184,185,207,55,29,88,35,99,187,153,30,230,76,242,221,172,140,70,199,44,155,40,133,236,130,217,4,150,97,24,
161,17,39,129,5,18,67,110,208,251,9,197,121,42,28,9,224,106,127,217,127,161,65,175,208,29,119,58,67,208,160,183,16,216,141,210,166,53,0,142,164,173,103,33,221,195,243,139,60,235,65,118,177,80,200,83,145,
78,250,113,91,29,121,198,198,250,219,251,67,129,117,211,143,155,19,145,229,30,183,93,145,135,231,22,2,15,79,161,227,230,196,194,219,64,127,138,19,165,142,108,98,40,125,123,133,142,91,166,88,40,70,148,
58,210,143,155,59,63,74,57,110,153,158,205,244,243,205,157,191,249,200,20,28,249,60,165,153,100,59,110,238,252,117,223,67,62,54,70,30,186,239,128,117,115,108,47,23,153,211,237,221,8,60,126,110,123,153,
228,18,126,38,176,12,195,8,141,184,9,44,8,6,169,25,40,160,217,3,78,45,114,155,233,158,133,231,208,52,208,215,192,202,69,174,239,6,247,69,4,3,70,161,24,165,116,156,39,235,93,130,128,230,159,21,185,110,
250,224,254,152,191,157,66,49,74,233,56,15,224,116,52,237,86,74,64,115,250,224,254,60,10,96,47,20,163,148,206,80,130,227,230,188,35,127,71,211,144,197,224,68,209,251,40,22,239,71,96,199,34,215,77,159,
206,115,199,45,211,147,152,15,39,178,102,2,175,250,219,57,189,200,117,19,40,206,168,220,243,45,221,83,231,206,183,92,211,181,217,56,8,9,170,15,81,162,72,49,162,212,145,46,138,220,113,43,20,219,149,206,
134,104,42,239,59,130,0,250,66,55,65,233,184,132,145,23,9,126,239,107,100,89,46,243,198,37,29,19,88,134,97,132,70,28,4,214,113,89,222,115,119,200,41,20,171,83,10,233,211,44,197,102,61,165,227,166,89,60,
20,8,94,172,72,112,184,187,237,66,129,243,217,72,23,11,227,40,46,91,44,29,39,22,82,192,9,37,174,155,30,251,243,21,74,0,40,5,55,237,229,161,216,174,82,143,219,193,232,184,149,146,101,231,72,207,146,124,
29,165,240,151,130,19,11,165,136,82,71,250,52,242,151,148,126,190,45,135,2,182,75,21,165,14,151,37,89,40,225,32,27,221,80,70,172,135,196,101,169,199,109,61,52,165,87,138,40,77,231,66,127,221,92,30,191,
93,208,185,60,157,236,55,26,38,176,12,195,8,141,40,11,44,151,37,213,130,50,131,50,217,0,121,132,202,33,129,62,123,49,169,248,217,88,22,56,143,242,43,80,31,4,108,85,230,186,221,80,182,95,49,37,12,178,177,
17,154,94,44,151,51,201,159,205,153,143,229,168,236,184,237,71,233,162,212,209,5,197,254,148,42,74,29,235,161,226,222,229,224,206,183,114,127,103,131,208,120,95,170,184,114,236,77,241,158,210,76,186,162,
227,214,187,208,130,57,24,13,28,95,230,186,32,239,116,182,4,13,104,91,38,227,207,180,47,204,110,2,203,48,140,208,136,178,192,114,182,185,160,220,3,194,53,199,48,140,8,210,25,184,31,93,43,174,167,173,200,
42,40,176,66,235,209,99,24,134,17,1,246,71,105,215,183,210,62,173,220,48,140,230,102,17,242,208,221,143,60,179,215,83,130,110,50,129,101,24,70,51,51,19,77,167,141,71,217,103,7,135,106,141,97,24,81,195,
137,172,127,163,160,247,162,69,86,177,217,2,134,97,24,141,202,116,96,107,148,213,116,11,138,67,186,46,84,139,12,195,136,18,139,129,189,80,231,134,35,144,192,26,95,104,37,19,88,134,97,24,109,69,214,53,
4,37,23,12,195,48,64,89,166,7,161,184,171,195,80,230,99,94,76,96,25,134,97,136,25,4,34,235,106,116,65,189,33,84,139,12,195,136,18,173,40,140,32,73,80,80,53,231,116,161,197,96,25,134,97,4,204,68,53,117,
18,168,78,78,161,106,220,134,97,52,23,173,168,94,217,66,255,255,209,185,22,52,129,101,24,134,17,176,14,240,15,84,248,113,123,36,184,12,195,48,28,3,81,223,195,206,254,255,175,229,90,208,4,150,97,24,134,
216,24,181,90,1,216,150,34,98,44,12,195,104,42,150,70,215,136,149,81,175,203,188,152,192,50,12,195,80,155,151,71,145,219,127,11,242,220,149,26,134,209,148,44,141,250,117,142,2,14,161,136,107,132,9,44,
195,48,154,157,205,144,184,90,128,130,220,223,13,215,28,195,48,34,198,242,192,11,168,215,227,65,192,29,197,172,100,2,203,48,140,102,102,61,224,97,96,30,18,87,239,133,107,142,97,24,17,99,48,240,44,48,4,
213,194,250,71,177,43,154,192,50,12,163,153,185,5,152,139,170,185,191,31,178,45,134,97,68,139,33,192,115,200,131,181,23,170,230,94,52,86,7,203,48,140,102,100,164,255,60,11,77,17,126,18,162,45,134,97,68,
143,17,40,230,106,0,176,59,240,80,169,27,48,15,150,97,24,205,72,15,255,121,30,48,39,76,67,12,195,136,36,189,129,158,40,241,165,172,114,45,38,176,12,195,104,70,222,242,159,135,2,207,3,203,134,103,138,97,
24,17,228,13,20,58,176,8,117,119,216,162,212,13,152,192,50,12,163,153,57,9,88,1,5,177,46,23,178,45,134,97,68,139,183,129,109,128,249,104,138,112,203,82,86,54,129,101,24,70,51,243,8,234,41,54,20,165,97,
15,11,213,26,195,48,162,198,59,192,230,192,15,72,100,109,93,236,138,38,176,12,195,104,118,238,5,126,137,166,9,159,69,30,45,195,48,12,199,120,52,93,56,11,248,47,242,106,21,196,4,150,97,24,6,220,7,236,138,
170,53,63,11,12,15,215,28,195,48,34,198,71,4,34,235,33,96,149,66,43,152,192,50,12,195,16,15,3,187,161,180,236,103,81,154,182,97,24,134,227,99,20,135,53,19,85,116,207,139,9,44,195,48,140,128,71,128,3,80,
97,193,103,129,126,225,154,99,24,70,196,152,128,68,86,171,255,255,154,185,22,52,129,101,24,134,17,208,3,56,218,255,251,54,202,172,127,99,24,70,67,115,36,208,197,255,123,124,174,133,76,96,25,134,97,136,
30,40,128,117,43,224,34,224,15,225,154,99,24,70,196,72,0,151,3,39,163,152,44,80,33,210,172,152,192,50,12,195,144,184,122,8,137,171,63,2,191,11,215,28,195,48,34,70,2,184,2,56,17,133,18,220,90,104,5,19,
88,134,97,52,59,189,129,39,81,165,230,63,0,231,134,106,141,97,24,81,35,1,252,5,56,30,221,136,237,6,180,20,90,201,4,150,97,24,205,76,47,224,49,96,67,224,76,224,252,112,205,49,12,35,98,36,128,171,129,227,
128,127,33,113,149,115,90,48,157,142,53,52,202,48,12,35,234,220,6,252,4,181,204,185,34,92,83,12,195,136,24,73,224,38,224,16,224,30,96,63,138,240,92,57,76,96,25,134,209,140,116,247,159,127,130,220,254,
87,135,104,139,97,24,209,163,3,138,179,58,0,248,59,112,48,65,105,134,162,176,41,66,195,48,154,145,205,253,231,151,48,113,101,24,70,123,118,67,226,106,58,112,12,37,138,43,48,129,101,24,70,115,242,132,255,
188,9,112,45,138,179,48,12,195,112,220,139,178,137,7,160,46,15,189,74,221,128,9,44,195,48,154,17,119,55,250,36,42,44,122,29,38,178,12,195,104,203,69,72,100,109,10,60,74,137,34,203,4,150,97,24,205,204,
175,129,251,129,95,1,55,96,215,68,195,48,218,114,17,112,42,176,49,202,56,94,162,216,21,237,98,98,24,70,51,211,2,236,9,220,9,28,129,137,44,195,48,218,115,9,170,222,190,17,240,12,208,183,152,149,44,139,
208,48,140,102,167,21,56,16,72,1,135,35,129,117,132,255,191,97,24,6,192,101,232,154,112,25,10,45,184,191,208,10,38,176,12,195,48,36,178,14,6,60,224,80,160,27,18,93,69,215,188,49,12,163,225,185,28,88,128,
18,99,6,22,90,216,4,150,97,24,134,104,69,5,5,19,192,254,72,92,29,66,25,233,217,134,97,52,44,215,163,26,89,87,249,255,247,201,181,160,197,26,24,134,97,4,180,2,47,251,127,175,65,9,1,173,134,97,52,13,111,
2,139,253,191,115,122,178,76,96,25,134,97,4,28,137,238,76,223,6,182,6,190,15,215,28,195,48,34,134,203,38,116,158,237,143,115,45,104,2,203,48,12,67,28,133,220,255,239,0,219,0,51,195,53,199,48,140,136,177,
9,170,135,181,16,184,166,208,194,22,131,101,24,134,1,191,65,217,65,111,0,219,2,223,133,107,142,81,1,189,128,174,254,115,79,160,83,198,251,173,192,15,200,59,57,27,203,22,53,138,99,83,224,17,96,62,186,1,
251,105,161,21,76,96,25,134,209,236,156,140,234,220,188,142,196,149,77,11,70,139,174,192,242,105,143,33,64,127,96,41,84,143,168,47,208,207,127,238,93,198,246,167,1,159,164,61,38,248,143,143,129,69,21,
218,110,52,6,155,3,15,1,243,144,184,122,31,19,88,134,97,24,121,57,18,85,105,126,9,216,1,121,54,140,250,179,4,176,18,176,50,48,202,255,123,48,18,84,185,130,136,231,34,79,227,183,192,167,192,171,200,35,
53,15,248,209,255,123,62,154,206,73,167,147,191,191,222,72,148,45,7,140,0,214,167,173,183,171,197,223,238,123,192,43,40,249,225,117,127,219,70,243,176,29,170,121,245,3,138,203,252,160,216,21,77,96,25,
134,209,204,156,10,188,136,196,213,156,144,109,105,6,186,1,107,1,107,3,171,32,33,53,10,24,148,177,220,15,192,231,192,107,192,100,96,10,240,37,240,133,255,252,53,213,247,46,117,2,134,250,54,57,187,86,69,
94,205,221,253,101,22,163,1,246,77,255,241,14,240,46,38,204,27,149,237,145,184,154,133,196,213,135,165,172,108,2,203,48,140,102,100,51,255,249,109,116,17,157,23,162,45,141,74,7,36,162,214,5,214,243,31,
171,211,118,220,153,140,4,203,125,192,120,52,45,247,17,18,80,245,102,49,193,52,225,67,105,175,119,64,66,107,99,244,25,214,70,69,104,15,77,91,230,51,244,57,62,38,152,98,252,16,152,94,115,171,141,90,177,
13,240,0,186,241,218,4,152,84,234,6,76,96,25,134,209,140,124,130,46,160,35,80,189,171,177,225,154,211,16,244,69,3,209,166,4,66,164,167,255,94,10,9,167,191,35,175,212,171,72,80,197,65,216,182,34,47,213,
187,192,117,254,107,221,144,88,92,195,127,252,4,216,0,216,49,99,221,233,104,138,241,93,20,183,243,62,18,95,179,106,110,181,81,41,111,163,115,116,13,228,197,188,46,255,226,237,49,129,101,24,70,51,242,141,
255,188,24,120,2,216,9,120,54,60,115,98,73,127,36,166,54,247,31,171,19,148,254,249,18,29,215,87,253,199,235,52,214,20,236,2,130,207,150,78,95,130,233,197,81,72,120,173,142,166,151,210,153,142,4,167,243,
120,57,17,246,13,70,84,152,9,108,9,60,142,74,50,116,6,174,44,101,3,38,176,12,195,104,102,246,1,110,67,83,66,59,1,207,132,106,77,180,25,0,108,129,166,87,183,64,211,127,9,212,191,113,60,112,3,240,63,255,
17,198,20,95,20,248,14,5,195,191,156,241,122,95,36,182,92,0,255,40,96,36,154,118,236,144,182,220,12,36,180,92,108,215,107,72,136,89,41,137,112,152,133,130,220,31,3,174,0,186,3,23,22,187,178,9,44,195,48,
154,153,73,192,86,192,211,192,131,192,47,128,167,66,181,40,58,36,80,64,250,207,209,212,215,58,200,67,149,66,241,70,87,19,8,42,139,53,202,207,119,192,115,254,35,157,46,72,104,173,142,4,216,26,180,247,120,
253,128,60,128,175,16,120,205,154,85,192,134,65,186,200,250,19,250,13,92,80,204,138,38,176,12,195,104,118,62,66,34,235,25,224,191,72,100,61,25,170,69,225,209,3,197,166,253,220,127,184,236,190,201,200,
67,245,4,240,2,42,141,96,84,206,66,52,61,248,30,112,103,218,235,75,1,107,18,36,7,172,135,206,81,199,68,52,165,253,156,255,108,83,139,181,101,54,250,93,60,12,156,143,68,86,69,241,131,231,35,215,239,114,
21,155,102,24,70,51,242,7,116,13,25,30,182,33,89,200,102,219,72,84,14,224,71,52,93,216,44,44,1,28,134,90,128,44,64,199,165,5,213,6,59,29,121,86,140,240,89,14,216,13,21,197,125,13,125,71,30,193,20,237,
53,72,4,152,227,164,118,244,64,55,98,30,242,104,121,148,249,251,48,129,101,24,70,37,196,77,96,1,172,136,2,180,127,68,181,177,26,149,36,170,68,253,119,84,140,211,67,21,236,239,2,246,71,149,209,141,104,
211,7,216,25,184,28,101,188,181,162,239,113,6,240,87,52,173,149,217,38,200,168,156,158,200,115,232,196,173,9,44,195,48,234,78,28,5,22,72,120,120,40,246,165,209,132,198,74,40,142,228,75,244,25,23,163,105,
209,221,81,60,144,17,95,150,1,142,69,83,134,206,187,53,5,248,45,234,203,104,84,143,254,232,38,204,3,142,40,103,3,38,176,12,195,168,132,56,10,172,17,40,222,232,71,218,215,52,138,43,93,81,81,204,177,4,119,
221,239,0,39,145,187,13,141,17,111,6,2,199,160,169,67,231,157,188,0,121,189,140,202,232,129,68,172,121,176,12,195,8,141,184,9,172,70,139,193,90,30,121,171,102,160,207,58,29,165,154,175,21,166,81,70,93,
73,2,187,162,178,17,30,106,63,180,97,152,6,197,28,139,193,50,12,35,18,196,73,96,173,4,124,133,226,145,126,26,150,81,85,98,83,224,94,52,253,231,161,180,254,253,81,161,68,163,121,217,3,121,178,22,163,228,
133,68,184,230,196,142,244,216,171,63,0,191,193,4,150,97,24,33,17,23,129,53,10,213,21,154,135,178,176,226,72,103,224,32,224,45,244,185,22,162,180,255,13,194,52,202,136,28,67,80,118,168,7,252,27,139,205,
42,150,222,4,94,192,51,253,215,76,96,213,129,37,129,219,105,219,248,211,104,92,18,168,1,104,89,129,141,77,70,28,4,214,182,168,134,208,60,218,214,25,138,11,75,0,39,19,4,173,79,5,206,65,1,207,134,145,141,
78,192,95,208,249,242,1,141,151,200,81,109,250,0,227,80,129,221,19,211,94,55,129,85,7,186,160,198,177,211,144,202,53,26,155,125,209,239,226,252,176,13,137,1,113,16,88,223,1,115,81,207,177,56,49,8,24,131,
170,76,123,168,167,221,17,40,160,221,48,138,225,112,116,238,220,19,182,33,17,166,15,154,98,79,1,199,103,188,103,2,171,78,236,134,142,213,37,5,150,91,182,14,182,24,229,211,133,252,119,115,221,80,144,232,
20,52,31,111,228,39,202,2,235,90,100,219,28,96,163,144,109,41,133,101,128,235,8,82,196,199,162,32,230,100,190,149,12,35,7,127,69,231,209,30,97,27,18,65,250,161,41,247,20,112,116,150,247,77,96,213,145,
199,81,220,195,74,89,222,235,9,156,141,170,36,255,188,142,54,25,165,113,26,10,2,61,141,236,53,129,206,69,191,137,253,234,105,84,140,137,178,192,122,2,217,246,54,202,12,138,58,189,209,53,121,46,178,251,
65,96,147,80,45,50,26,129,37,80,118,233,123,88,208,123,38,91,163,27,153,25,168,124,75,38,38,176,234,200,42,40,59,227,161,180,215,58,162,194,111,46,77,250,105,212,200,211,136,38,91,3,239,163,239,234,35,
218,214,65,90,30,197,233,140,197,46,68,197,18,101,129,229,108,243,80,111,189,168,6,251,118,70,245,170,220,53,228,69,96,227,80,45,50,26,141,179,8,226,17,141,182,108,143,28,35,223,160,49,62,29,19,88,117,
230,26,116,204,126,134,178,145,222,37,136,143,216,51,68,187,140,226,73,2,7,162,152,58,15,120,10,253,128,238,69,173,40,214,11,207,180,216,17,7,129,53,198,127,126,9,221,205,71,137,141,80,16,178,11,70,222,
57,92,115,140,6,101,85,116,142,253,46,108,67,34,202,182,168,124,203,84,116,172,28,38,176,234,76,95,52,197,52,135,32,128,54,215,116,147,17,109,250,160,193,247,71,130,30,95,119,230,93,195,200,36,14,2,107,
56,106,37,226,1,175,163,223,112,216,44,129,110,214,90,81,16,251,209,64,135,80,45,50,26,153,62,232,252,255,75,216,134,68,152,205,208,184,62,13,88,205,127,205,4,86,29,89,10,184,146,96,48,30,139,250,21,25,
241,102,20,18,205,30,26,236,76,48,23,79,92,4,22,104,26,46,5,188,65,184,34,107,51,130,146,11,247,99,137,49,70,237,89,6,157,111,23,133,109,72,196,217,20,245,39,157,134,66,125,10,10,44,203,60,169,156,206,
192,9,192,36,148,198,249,44,42,219,176,42,118,215,217,8,108,137,238,240,110,68,61,234,198,160,169,95,155,242,109,44,46,71,189,219,214,66,211,194,75,213,121,255,9,52,69,243,52,202,86,221,3,101,7,126,85,
103,59,140,230,99,176,255,108,231,90,126,94,0,118,64,191,207,231,81,92,110,217,152,7,171,48,59,1,159,162,227,244,6,176,133,255,250,86,254,107,55,132,99,150,81,37,150,68,193,197,19,145,215,170,35,112,36,
202,186,241,128,39,177,164,133,124,196,201,131,229,56,18,121,161,223,162,126,5,24,187,1,255,37,240,124,15,206,191,184,97,84,21,231,137,137,83,185,146,48,217,8,152,141,226,178,108,138,176,70,92,137,142,
207,87,192,193,180,247,6,62,128,46,212,235,212,215,44,163,138,184,239,120,199,140,215,251,250,239,45,242,31,214,142,36,59,113,20,88,32,79,150,43,225,176,100,141,237,232,129,188,86,46,6,166,83,141,247,
103,24,153,188,136,194,31,236,220,43,158,13,81,89,38,143,50,103,51,76,96,229,103,45,212,146,34,87,13,157,21,80,122,231,139,88,90,127,28,89,25,137,167,39,11,44,115,5,54,213,158,139,56,10,172,14,168,245,
149,7,220,65,109,167,249,187,162,144,2,15,213,88,51,140,122,179,62,58,255,46,15,219,144,152,113,44,138,217,244,80,220,100,201,152,192,170,156,11,209,49,220,43,108,67,140,146,121,12,213,53,91,173,208,130,
70,78,226,38,176,210,197,213,63,168,173,184,74,162,22,37,30,186,81,51,140,48,184,23,93,231,134,134,108,71,156,56,10,137,171,41,216,20,97,168,244,2,190,70,173,45,140,248,176,52,10,104,183,187,186,202,136,
147,192,234,0,252,221,127,237,38,106,239,149,60,1,139,211,52,194,101,69,160,5,43,63,83,10,46,94,237,117,224,247,152,192,10,157,129,97,27,96,148,69,119,162,91,221,59,46,196,69,96,117,2,238,243,255,191,
145,218,139,171,238,168,50,244,199,40,113,194,48,194,192,197,9,175,17,182,33,49,225,100,116,141,120,13,197,102,22,44,211,96,63,238,218,51,45,108,3,140,178,152,31,182,1,70,93,232,4,220,141,74,34,220,136,
138,122,166,106,188,207,163,144,151,244,20,228,65,48,140,122,179,7,240,11,52,187,242,78,200,182,196,129,83,81,157,176,151,80,169,134,31,42,221,160,121,176,12,195,168,132,56,120,176,158,244,159,175,163,
62,201,40,61,80,203,141,143,136,95,157,188,78,200,219,177,141,255,88,49,92,115,140,50,25,142,138,39,79,70,53,254,140,252,156,70,246,158,165,230,193,50,12,195,200,130,187,246,109,3,252,25,181,203,169,7,
191,67,97,3,39,162,233,153,40,211,5,29,159,45,80,21,235,181,80,97,229,116,62,5,30,7,110,3,94,173,163,109,70,121,116,70,201,21,221,81,207,220,89,225,154,19,121,206,6,254,72,80,100,116,110,181,54,108,30,
44,195,48,42,33,202,30,172,151,9,238,74,235,197,32,52,245,60,150,104,151,110,89,14,93,255,93,195,115,15,21,219,189,3,221,181,239,137,50,163,207,71,241,40,173,104,90,245,6,84,122,194,136,46,151,162,239,
243,55,97,27,18,3,246,68,199,106,26,217,227,113,173,23,161,97,24,161,17,101,129,245,39,100,91,10,248,117,157,246,121,141,191,207,77,235,180,191,82,25,10,220,138,210,246,93,48,239,97,20,238,135,184,60,
74,247,119,217,85,249,190,239,21,145,7,229,200,10,109,53,2,238,71,45,188,10,37,229,28,138,190,163,199,136,182,192,143,10,29,144,103,214,67,25,198,153,83,250,38,176,12,195,8,141,40,11,44,103,219,219,254,
243,233,53,222,223,250,72,184,60,90,227,253,148,195,210,192,85,168,50,117,10,137,165,114,186,19,28,239,111,99,26,237,7,157,62,192,101,4,213,175,103,82,255,126,143,141,200,94,4,94,198,47,129,253,200,46,
158,182,64,133,147,223,199,226,174,74,33,1,92,139,142,239,61,180,173,118,111,2,203,48,140,208,136,131,192,90,147,96,186,240,204,26,237,171,39,48,30,101,30,13,171,209,62,202,161,35,138,5,155,141,62,255,
35,192,218,21,110,115,115,244,57,167,163,207,218,1,248,21,65,255,206,39,144,199,208,106,128,85,78,15,20,168,254,21,112,16,240,5,58,174,47,35,65,239,24,134,122,170,78,3,134,212,217,198,70,32,65,224,125,
190,151,64,100,153,192,50,12,35,52,226,32,176,134,35,1,244,156,255,255,239,171,188,159,78,104,74,198,67,83,52,81,97,19,148,158,239,1,239,34,97,84,45,54,67,222,186,247,9,60,132,19,104,219,179,205,213,96,
90,175,138,251,109,54,220,52,247,126,254,255,221,80,198,219,15,200,19,121,15,18,204,31,32,207,97,89,45,93,12,64,34,235,42,116,188,31,66,9,32,38,176,12,195,8,141,184,8,44,144,55,224,25,255,181,179,170,
180,143,36,65,117,248,49,85,218,102,165,244,68,245,190,82,200,115,117,34,213,207,38,31,12,60,143,62,247,28,148,137,213,37,203,50,115,81,156,151,245,242,44,157,17,192,143,40,73,35,115,74,112,16,242,14,
182,18,36,32,88,204,91,229,36,128,43,209,121,253,48,170,141,101,2,203,48,140,80,136,147,192,2,165,174,63,77,117,4,81,23,130,192,239,91,137,70,80,241,6,192,39,4,241,36,203,84,121,251,61,144,152,90,128,
6,246,219,201,223,201,226,44,223,150,195,171,108,71,51,240,48,42,82,155,175,10,251,104,96,18,58,198,83,144,200,50,49,91,25,9,212,66,205,67,211,254,38,176,12,195,8,133,184,9,44,104,235,201,58,183,204,109,
247,68,181,161,60,224,22,194,175,55,216,17,77,29,45,66,94,171,106,123,51,146,192,129,168,253,143,135,142,95,49,237,87,186,160,118,65,223,2,253,170,108,83,35,179,11,58,206,87,22,185,252,78,192,103,254,
58,175,2,27,215,200,174,102,226,50,130,228,130,117,203,217,128,9,44,195,48,42,33,142,2,11,212,70,196,101,101,149,58,240,15,6,222,242,215,63,187,2,251,170,197,242,192,56,100,207,115,84,63,200,121,125,130,
36,129,201,72,104,149,194,118,254,186,215,86,217,174,70,165,27,42,238,58,141,210,178,1,179,197,103,89,192,123,249,184,41,90,143,210,207,121,192,4,150,97,24,149,17,71,129,181,3,154,226,154,140,46,162,165,
176,5,202,150,91,132,50,231,194,102,93,224,107,20,112,126,42,213,159,30,114,49,40,179,209,224,157,25,103,85,44,255,69,211,93,163,171,100,87,35,115,54,58,230,135,148,185,254,114,168,96,108,10,197,192,217,
49,47,157,145,104,202,181,5,155,34,52,12,35,36,226,38,176,126,142,238,74,191,160,116,155,143,68,194,106,6,176,85,53,12,172,144,221,129,121,200,99,177,67,141,246,49,18,101,167,61,79,101,49,102,43,160,10,
247,47,99,49,66,249,24,70,117,142,211,114,72,92,189,73,252,250,97,134,205,74,168,44,198,143,192,77,152,192,50,12,35,36,226,36,176,246,64,2,233,115,74,171,85,181,12,240,31,130,202,231,203,87,207,196,178,
57,1,5,153,79,2,86,174,241,190,46,68,159,125,223,10,182,145,0,238,243,183,243,20,170,147,101,141,164,69,39,84,94,225,2,84,234,194,3,14,174,112,155,119,33,15,214,70,21,110,167,217,24,133,196,213,60,212,
163,211,202,52,24,134,17,26,113,17,88,123,33,113,245,25,106,23,83,44,7,3,223,33,49,115,21,225,247,225,235,0,220,140,62,215,243,212,167,82,122,15,20,171,246,21,133,91,181,100,99,67,130,24,177,175,81,243,
225,244,254,135,87,3,59,250,251,105,22,134,3,199,160,90,97,63,16,28,143,73,200,131,213,138,190,231,165,203,216,246,86,254,182,110,171,134,161,77,196,202,232,252,156,71,224,161,54,129,101,24,70,104,196,
65,96,29,143,98,148,62,166,112,207,61,199,50,104,240,115,131,222,150,181,48,176,68,186,162,158,116,30,240,15,160,115,29,247,189,183,191,223,139,75,88,103,89,84,198,33,133,6,173,179,81,32,118,7,20,23,116,
26,240,34,18,19,30,250,142,94,244,95,31,77,52,202,94,84,139,30,200,35,50,6,21,5,117,130,106,30,240,36,193,103,6,141,199,238,184,205,69,199,173,88,97,223,17,21,149,157,77,245,75,116,52,50,107,162,169,255,
185,180,253,173,155,192,50,12,35,52,226,32,176,90,128,143,80,113,198,66,36,145,103,97,182,191,222,101,72,20,132,77,79,212,130,198,67,30,159,48,226,152,158,70,94,192,66,83,146,61,128,115,144,120,104,69,
158,148,124,199,126,32,202,210,186,19,13,114,78,124,76,70,159,117,137,74,140,14,153,61,144,167,113,17,250,76,173,104,154,249,2,84,89,191,83,238,85,217,196,95,214,67,89,133,123,20,177,63,39,8,78,40,223,
228,166,99,45,212,55,115,14,74,98,73,199,4,150,97,24,161,17,101,129,245,111,100,219,39,228,47,134,233,24,133,170,102,123,168,5,76,57,205,144,107,65,47,84,219,200,3,254,24,162,29,171,32,161,240,84,142,
247,19,192,1,40,251,202,67,222,168,117,74,216,126,119,84,152,116,177,191,254,191,136,230,121,85,10,157,128,99,9,132,227,171,104,64,47,150,36,154,166,254,138,96,90,56,87,47,201,101,208,141,193,187,132,
95,151,45,46,172,131,66,0,102,145,253,247,110,2,203,48,140,208,136,178,192,186,3,217,54,21,101,195,229,194,21,233,92,128,4,196,24,202,47,71,80,109,210,251,28,70,193,43,225,138,47,102,122,83,214,5,94,34,
168,45,118,32,197,79,241,37,80,15,67,87,40,243,53,26,175,167,94,79,130,10,248,229,212,168,234,238,175,63,223,95,255,118,218,79,1,186,150,77,91,84,100,105,115,49,28,121,74,127,68,197,90,51,49,129,213,132,
244,70,149,122,215,39,254,243,236,157,80,10,247,230,192,106,216,157,87,220,136,178,192,114,182,45,64,34,107,213,44,203,172,79,208,16,249,229,28,203,132,201,181,200,182,63,133,109,136,79,47,228,77,249,
18,77,5,230,138,179,42,150,13,128,177,4,194,172,209,91,189,44,79,219,227,53,134,210,166,64,115,197,103,109,236,191,246,247,42,218,218,44,12,65,113,150,11,129,93,51,222,51,129,213,224,44,3,252,12,56,3,
245,61,155,136,126,72,94,218,227,47,161,89,87,60,93,81,160,236,5,232,34,240,34,186,160,186,0,87,247,152,143,220,232,55,0,71,145,219,29,110,68,131,56,8,172,95,162,248,138,105,72,196,131,166,12,111,65,231,
223,28,228,29,138,218,192,126,38,65,64,123,148,2,190,247,71,118,189,64,16,103,117,43,197,197,184,57,70,18,4,236,207,6,78,39,26,177,110,245,34,93,88,126,13,28,70,105,231,223,198,180,141,207,154,128,178,
17,75,249,14,140,128,193,104,108,93,4,236,150,246,186,9,172,6,164,11,170,226,235,238,172,221,99,14,18,38,87,161,31,228,175,144,96,249,89,56,102,22,197,154,200,222,239,8,62,199,2,212,68,243,49,36,164,206,
64,23,237,83,80,160,235,135,4,21,116,159,169,191,201,70,9,196,65,96,13,7,54,37,16,89,231,160,160,86,15,120,144,104,182,19,249,9,65,86,93,84,166,43,29,9,224,13,2,145,85,74,156,213,82,192,21,104,32,91,12,
92,79,113,241,113,141,72,2,149,15,249,20,29,203,183,81,166,97,177,36,129,131,8,226,179,206,170,182,129,77,198,242,40,94,179,5,216,207,127,205,4,86,131,177,50,154,206,240,80,99,213,75,145,231,103,36,209,
187,195,206,69,111,228,125,122,29,125,142,20,10,206,60,144,226,235,186,244,64,245,115,172,80,94,180,137,139,192,2,56,142,192,99,250,25,234,145,23,69,146,40,158,105,33,181,47,34,90,46,147,145,200,42,214,
179,214,25,13,86,238,70,235,81,162,55,29,27,22,93,128,147,129,239,209,177,121,8,37,20,20,203,48,127,189,63,87,223,180,166,99,105,130,27,252,253,49,129,213,112,116,64,245,221,69,184,212,0,0,32,0,73,68,
65,84,119,14,34,122,119,174,133,232,141,90,11,204,35,16,136,23,145,63,192,216,136,55,113,16,88,155,163,160,98,231,5,94,128,6,250,82,60,47,245,228,8,100,235,57,97,27,146,131,159,80,154,125,59,33,207,128,
135,6,175,29,107,100,87,220,233,139,98,178,126,68,55,2,183,83,188,119,111,2,240,94,141,236,106,54,150,70,181,202,90,208,140,138,9,44,163,36,134,34,55,125,53,171,82,175,70,208,230,225,33,96,23,242,215,
120,49,26,131,40,11,172,63,33,219,22,162,1,235,38,96,0,242,138,206,70,30,131,245,66,179,46,59,189,144,7,123,18,225,87,141,207,197,239,208,113,45,84,198,98,29,228,185,246,80,153,130,19,176,190,120,197,
48,146,224,134,192,5,178,23,138,79,187,6,205,20,196,61,233,41,42,12,68,130,213,121,188,77,96,25,69,115,54,65,58,244,224,42,108,111,53,228,25,152,139,2,138,141,230,33,138,2,171,51,202,70,155,75,80,143,
41,179,246,208,14,254,123,223,2,253,234,106,93,126,206,67,118,237,21,182,33,121,120,30,9,166,92,98,105,57,20,91,217,138,146,86,74,205,148,51,196,134,20,159,97,185,139,191,220,1,245,49,173,41,24,132,188,
137,30,112,104,57,27,48,129,213,188,28,137,238,236,103,2,219,86,184,173,4,112,37,101,170,252,42,211,151,104,101,92,53,58,81,18,88,174,158,210,36,100,211,116,178,219,214,15,120,11,221,241,31,93,79,3,11,
208,3,21,60,124,133,232,158,195,189,81,128,250,29,89,222,235,65,219,90,77,247,80,90,223,71,163,61,197,214,8,91,2,125,47,183,215,207,180,134,166,3,65,93,49,15,37,107,149,140,9,172,230,102,19,148,34,220,
130,46,140,113,9,162,207,69,71,116,1,122,130,250,52,193,53,162,35,176,182,34,72,91,255,18,101,225,158,69,123,219,250,163,236,220,20,106,137,19,37,14,71,246,238,87,104,193,16,217,11,217,184,111,218,107,
73,148,192,242,13,65,61,49,75,78,169,46,221,81,49,220,217,4,217,175,35,50,150,25,139,190,131,168,138,243,184,208,129,160,72,241,43,216,20,161,81,1,131,8,42,48,255,139,248,5,214,167,211,5,53,163,77,161,
12,167,62,225,154,211,20,132,45,176,70,3,143,19,212,83,58,3,13,70,208,222,182,1,168,141,72,43,18,96,81,99,44,242,40,71,53,246,10,84,239,170,133,224,6,102,27,130,114,50,19,144,183,197,6,248,218,209,15,
205,22,180,32,143,213,13,232,166,1,148,116,224,17,212,122,51,74,167,3,170,59,231,1,127,5,126,139,9,172,200,19,245,248,131,206,168,30,141,7,92,30,178,45,213,224,48,36,178,198,161,160,97,163,118,132,37,
176,134,18,196,249,44,244,255,206,204,184,74,183,109,32,234,47,216,130,50,116,163,198,112,116,206,94,27,182,33,121,72,32,143,247,75,168,124,196,131,232,248,126,135,188,43,113,190,57,139,27,217,142,255,
214,254,255,39,133,104,87,156,233,76,208,191,244,6,228,153,181,50,13,17,103,57,20,19,18,213,148,107,71,2,101,255,165,80,0,112,220,57,1,157,219,47,161,62,96,70,109,168,183,192,234,79,219,84,246,123,80,
171,165,108,56,219,54,32,72,187,142,106,16,240,185,200,214,141,195,54,36,15,163,9,42,143,183,32,97,251,103,20,247,104,132,195,207,208,141,131,171,237,230,1,143,132,106,81,60,233,76,208,89,224,58,2,47,
172,9,172,8,51,128,160,104,217,222,33,219,82,12,253,81,85,224,233,52,70,186,175,251,113,60,69,115,181,225,168,39,245,18,88,75,2,23,18,212,88,123,128,194,133,42,157,109,159,19,20,14,140,34,29,129,41,232,
90,17,229,233,53,119,60,61,224,62,218,199,0,25,225,208,17,117,245,112,5,170,231,98,222,196,82,232,12,252,135,160,88,107,250,111,208,4,86,68,233,77,48,37,177,79,200,182,148,194,54,200,51,240,4,241,15,122,
135,32,46,225,97,26,227,243,68,141,90,11,172,94,254,62,92,149,235,231,41,62,128,250,50,127,157,197,192,30,53,177,174,58,236,137,236,60,62,108,67,10,240,50,234,19,186,105,216,134,24,89,233,133,106,191,
205,7,182,12,217,150,184,208,13,181,108,243,80,252,110,38,38,176,34,202,77,84,80,63,35,100,198,160,96,219,149,194,54,164,74,92,142,190,139,19,195,54,164,1,169,149,192,234,142,122,83,206,240,183,255,6,
165,79,93,191,64,144,213,22,229,2,151,227,80,128,126,239,176,13,201,67,103,84,227,46,202,30,54,67,12,198,68,112,177,236,140,194,98,166,147,189,30,158,9,172,8,178,29,250,210,238,14,219,144,50,233,68,99,
76,17,58,58,162,190,136,243,128,21,67,182,165,209,168,182,192,114,69,66,93,3,219,15,41,63,51,205,149,105,240,80,172,86,199,42,217,88,77,182,37,247,221,179,97,24,181,231,48,52,107,243,33,237,123,229,154,
192,138,24,75,0,95,160,59,239,1,33,219,82,13,182,165,49,122,135,173,133,210,154,255,135,77,21,86,147,106,9,172,142,168,150,146,43,18,250,25,18,90,149,120,158,156,109,174,96,224,189,68,171,125,83,55,212,
163,239,59,138,239,57,103,24,70,245,57,20,137,172,241,180,117,46,152,192,138,24,55,162,99,186,103,216,134,84,129,158,40,112,242,43,84,165,57,238,156,131,178,207,214,13,219,144,6,162,82,129,213,9,93,220,
92,51,224,207,209,29,101,53,188,77,206,182,17,192,85,4,5,26,163,18,0,124,49,241,13,35,48,140,70,227,151,40,94,243,35,84,31,18,76,96,69,138,173,208,212,224,3,97,27,82,37,78,162,125,213,230,56,211,25,53,
82,53,170,71,185,2,171,27,112,28,242,246,186,234,235,199,161,239,168,22,182,185,118,78,46,225,33,236,98,158,191,64,215,138,39,177,184,38,195,136,10,123,35,145,245,49,176,44,38,176,34,67,18,221,133,55,
202,212,96,39,52,248,77,34,154,177,43,70,52,40,85,96,245,68,53,202,92,140,213,103,254,255,181,16,60,153,182,37,8,18,30,30,169,209,62,139,97,36,234,57,56,153,198,184,86,24,70,35,177,23,18,89,19,8,178,208,
77,96,133,204,118,232,88,158,22,182,33,85,226,48,244,121,126,21,182,33,70,164,41,86,96,45,129,126,27,223,250,203,191,143,98,174,106,41,222,115,217,118,129,255,250,163,212,191,62,90,127,20,231,177,0,155,
170,54,140,168,178,7,138,217,117,215,43,19,88,33,115,4,74,245,108,132,59,210,36,202,168,152,138,21,232,52,242,83,72,96,13,67,83,115,115,252,229,94,7,118,165,62,137,6,249,108,187,200,127,239,49,234,119,
142,175,4,76,68,193,180,7,214,105,159,134,97,148,199,238,168,142,165,135,28,40,89,177,140,169,250,240,87,20,24,55,61,108,67,170,192,238,168,215,213,159,209,157,182,97,148,202,6,40,107,239,19,84,64,243,
53,96,123,96,29,212,146,34,21,158,105,128,218,188,128,98,190,234,113,141,220,8,213,229,90,14,216,15,184,189,14,251,52,12,163,124,22,33,113,5,101,122,218,205,131,101,100,227,53,20,35,18,229,194,135,70,
52,72,247,18,37,129,157,80,224,182,135,60,53,15,34,177,21,182,109,233,184,190,127,207,81,159,62,149,7,160,236,213,105,132,119,44,12,195,40,158,159,163,223,236,119,216,20,161,81,69,92,225,195,243,195,54,
196,136,5,78,196,252,1,77,127,121,72,156,95,12,44,31,162,93,144,93,96,185,107,222,227,212,126,106,176,3,112,9,65,193,212,97,53,222,159,97,24,149,227,226,175,62,39,136,215,52,129,101,84,133,103,209,180,
96,102,69,219,116,186,215,201,22,35,218,44,129,132,138,171,150,254,57,106,71,212,43,68,155,210,201,20,88,127,34,8,110,175,117,6,97,95,130,99,243,40,106,86,109,24,70,180,217,19,137,171,207,208,13,145,149,
105,48,170,198,8,116,62,92,147,103,153,127,0,79,215,199,28,35,162,244,3,206,38,200,176,241,128,51,137,86,149,116,104,91,104,244,10,234,87,3,107,37,148,41,232,161,0,255,40,247,65,52,12,67,164,215,192,114,
154,200,4,150,81,53,14,68,231,67,190,166,186,15,160,158,126,86,27,171,249,24,9,92,135,190,127,15,120,5,184,147,218,52,123,174,6,78,96,253,205,127,126,136,218,87,113,223,27,248,1,29,163,189,107,188,47,
195,48,170,195,62,180,175,226,14,38,176,140,42,50,12,85,211,238,155,103,153,211,209,57,179,102,93,44,50,162,192,22,192,127,81,208,122,10,149,54,216,202,127,175,218,205,158,171,73,122,179,231,90,247,33,
236,135,154,187,187,226,169,246,251,48,140,120,144,222,135,112,80,198,123,38,176,140,186,178,37,141,85,128,180,19,176,98,216,70,68,144,158,168,217,242,155,232,251,254,17,184,25,88,45,99,185,40,11,172,
255,33,219,198,81,91,143,235,207,9,42,211,223,131,197,91,25,70,92,216,9,137,171,105,100,175,97,105,2,203,168,43,61,144,43,245,150,176,13,169,18,55,32,175,76,84,2,179,195,102,117,224,90,96,54,186,54,76,
69,101,13,6,230,88,62,202,2,235,207,200,182,69,168,247,95,181,233,131,206,31,15,248,26,93,172,13,195,136,15,221,129,167,208,111,248,130,44,239,155,192,50,234,206,59,40,237,188,17,56,1,253,6,154,185,109,
73,111,84,252,242,5,116,44,82,40,145,97,47,10,55,95,142,178,192,114,182,125,129,68,214,110,85,220,246,30,192,55,254,246,111,193,106,198,25,70,92,233,130,234,245,121,168,172,74,58,38,176,140,186,115,35,
26,132,27,97,42,196,213,253,58,32,108,67,234,204,170,192,201,192,51,4,21,139,191,67,94,159,149,74,216,78,28,4,214,38,168,162,124,11,18,146,149,176,42,193,29,239,20,242,39,132,24,134,17,15,58,163,56,83,
15,184,44,237,117,19,88,70,221,113,141,160,183,13,219,144,42,224,98,202,14,10,219,144,26,211,5,216,6,184,26,152,76,16,252,61,29,181,109,217,155,242,10,111,198,65,96,13,71,117,221,62,68,34,107,255,50,182,
213,7,24,131,90,236,44,66,229,23,150,168,142,153,134,97,68,128,206,40,75,222,67,217,210,9,138,16,88,150,78,95,59,174,2,214,0,54,11,219,144,58,51,206,127,94,31,120,34,76,67,170,128,171,137,244,99,168,86,
84,159,4,176,30,176,51,242,224,172,131,226,13,60,212,10,233,38,148,13,248,58,225,247,5,172,7,83,81,230,227,211,192,109,168,173,79,49,253,0,147,72,144,93,140,226,208,158,66,211,202,141,50,69,110,24,134,
88,132,194,34,238,6,142,66,215,208,79,10,173,100,2,171,118,12,166,125,86,85,51,48,30,5,65,175,31,182,33,85,192,213,69,90,152,119,169,120,144,4,54,68,241,65,187,19,180,170,153,130,98,12,158,70,162,234,
203,80,172,11,31,39,178,158,66,113,83,73,36,182,114,177,5,112,41,48,26,93,104,15,67,133,74,13,195,104,76,156,200,186,11,101,202,143,203,191,184,9,172,90,242,35,181,175,10,29,69,82,40,125,127,237,176,13,
169,2,113,247,96,37,144,168,218,27,137,170,101,253,215,223,64,110,238,251,128,9,225,152,22,73,166,161,169,210,167,81,217,137,36,237,51,98,183,70,53,180,54,3,230,0,191,3,46,71,23,95,195,48,26,155,197,168,
240,232,157,232,102,21,116,157,40,25,139,193,170,140,191,161,26,26,205,200,157,52,198,128,115,48,250,13,108,17,174,25,37,179,38,138,9,250,156,32,243,111,28,10,92,31,90,71,59,226,18,131,149,201,246,254,
123,223,163,34,161,0,219,1,47,250,175,207,65,211,130,217,106,227,24,134,209,248,44,141,110,188,61,228,189,206,138,121,176,106,199,143,72,217,118,161,49,166,152,74,225,21,84,140,178,51,241,22,90,113,242,
96,141,70,119,84,123,160,254,122,160,146,25,215,35,151,246,231,225,152,21,59,214,6,254,142,166,185,119,0,54,0,126,143,166,188,231,0,23,162,108,202,153,97,25,104,24,70,168,244,71,205,218,93,153,154,215,
114,45,104,2,171,118,184,65,185,7,205,39,176,174,244,31,113,167,187,255,28,85,129,181,22,176,47,154,254,27,230,191,246,33,42,254,121,23,138,135,51,138,103,52,74,204,232,128,166,8,111,67,61,22,103,3,231,
161,166,208,223,133,101,156,97,24,161,51,0,197,105,174,6,252,27,93,123,115,98,2,171,118,124,224,63,143,6,158,12,211,144,10,233,132,230,157,155,145,117,144,7,46,74,113,74,75,35,81,117,48,170,172,14,240,
46,240,71,224,95,88,6,91,185,108,132,238,74,59,161,169,253,223,32,175,223,169,192,95,129,89,161,89,102,24,70,20,24,136,226,51,71,1,135,0,75,81,64,96,229,195,98,176,42,99,37,116,252,206,15,219,144,10,185,
5,137,140,14,97,27,18,2,95,1,47,133,109,4,154,102,222,3,101,251,45,70,231,213,100,212,190,161,148,194,159,245,38,14,49,88,163,252,191,91,8,226,213,158,64,37,44,202,10,94,53,12,163,225,88,26,57,77,90,128,
3,253,215,172,14,86,136,124,140,122,144,109,30,182,33,21,210,7,77,145,117,1,78,65,211,38,95,228,88,118,83,84,205,250,175,196,63,192,191,11,154,102,11,203,123,213,9,101,180,237,5,236,130,190,135,249,190,
77,127,67,85,214,155,161,70,85,173,232,239,63,191,138,122,77,122,192,63,209,244,234,71,97,25,101,24,70,228,88,30,93,111,135,161,153,131,191,87,99,163,230,193,170,156,187,81,252,85,247,66,11,70,152,231,
128,25,168,62,82,33,143,220,191,253,101,222,69,233,236,70,105,116,4,126,138,10,125,126,139,142,101,11,154,98,62,132,248,53,157,142,154,7,107,73,148,241,227,250,42,122,232,70,96,54,42,188,106,24,134,145,
206,96,96,34,186,14,239,155,241,158,181,202,9,153,99,208,49,220,50,108,67,202,100,29,96,46,65,111,181,35,201,63,109,210,9,85,178,254,222,95,231,73,96,149,26,219,24,119,18,192,198,192,181,168,53,141,19,
85,207,162,138,193,253,115,175,26,121,162,32,176,122,162,11,227,127,209,205,142,135,196,235,135,254,223,211,128,149,67,179,206,48,140,168,50,12,248,12,93,55,118,205,242,190,77,17,134,204,243,254,243,230,
104,192,140,11,131,80,208,244,225,72,0,76,70,89,19,115,10,172,183,24,101,15,222,225,175,127,12,240,54,42,106,121,22,242,20,24,98,37,212,92,120,63,96,5,244,67,125,9,77,81,221,7,124,19,158,105,161,50,0,
221,212,13,4,250,162,158,126,63,160,120,184,57,104,154,244,35,116,188,178,177,44,186,224,109,230,63,214,69,194,127,30,58,174,119,161,96,246,187,145,176,250,30,43,185,96,24,70,123,6,32,175,247,124,106,
208,225,194,60,88,149,147,64,94,137,40,4,74,23,67,55,224,12,228,181,74,161,172,180,25,168,133,74,57,140,66,94,44,15,165,183,159,64,115,6,203,59,6,2,199,163,58,97,110,138,234,67,116,204,135,132,104,87,
173,200,230,193,234,129,122,116,238,10,252,22,184,6,120,20,149,148,152,79,112,92,242,61,190,70,125,18,159,66,229,20,238,71,181,104,102,103,44,247,57,138,87,219,135,246,211,244,206,182,86,127,223,203,84,
233,51,27,134,209,56,172,141,60,222,179,80,77,188,116,108,138,48,2,92,141,142,227,58,97,27,146,135,78,192,37,192,2,210,6,168,68,34,177,56,145,72,204,67,222,131,82,218,254,172,4,92,153,76,38,93,220,86,
250,227,123,224,216,42,218,30,117,150,4,14,69,153,105,46,83,237,107,84,172,178,17,218,9,229,98,105,36,110,60,20,20,250,20,242,132,102,19,76,95,161,42,233,119,162,10,244,199,32,1,182,25,42,115,178,37,242,
244,29,137,138,126,62,139,4,214,231,72,32,125,139,138,170,254,11,101,86,238,71,97,193,234,4,214,137,200,243,250,17,242,220,26,134,97,164,179,22,242,114,207,66,173,199,28,38,176,34,192,48,116,1,191,59,
108,67,114,176,23,126,156,85,50,153,244,214,93,119,93,239,156,115,206,241,206,59,239,60,239,192,3,15,244,6,12,24,144,242,223,251,12,101,9,230,35,9,156,147,72,36,22,1,222,122,235,173,151,58,241,196,19,
189,49,99,198,120,167,156,114,138,55,98,196,136,244,65,245,51,26,55,62,203,197,253,252,135,32,238,103,22,202,192,220,142,198,242,226,37,144,135,106,15,36,110,30,65,2,50,253,187,78,161,204,211,39,145,199,
234,4,96,71,244,253,135,213,175,51,221,187,182,15,250,141,126,76,208,175,209,48,12,195,177,38,154,205,153,75,208,58,205,4,86,68,184,27,121,47,70,20,90,176,142,12,34,200,250,243,182,218,106,43,111,218,
180,105,94,38,139,23,47,246,110,189,245,86,111,169,165,150,106,77,38,147,11,129,157,114,108,47,137,60,16,222,230,155,111,158,122,239,189,247,218,109,203,243,60,239,245,215,95,247,86,88,97,133,244,129,
247,106,160,119,29,62,111,173,233,138,188,46,119,161,120,31,207,127,190,203,127,189,17,26,127,247,6,54,65,30,166,235,129,177,40,62,42,93,76,77,71,222,186,139,128,123,252,215,86,11,195,216,2,100,78,95,
238,133,68,214,4,236,154,103,24,70,123,86,70,177,177,115,129,173,48,129,21,25,214,65,199,242,234,2,203,173,143,210,241,79,64,83,33,23,3,55,32,129,246,40,202,132,186,25,248,19,112,18,176,63,165,199,238,
116,3,78,67,1,195,94,199,142,29,83,15,63,252,112,86,49,148,206,196,137,19,189,33,67,134,180,38,147,201,185,100,23,138,167,1,222,97,135,29,230,181,180,180,20,220,222,209,71,31,157,62,40,207,164,182,241,
89,199,3,199,161,2,113,59,162,224,233,106,208,11,216,27,125,63,78,104,44,68,158,171,125,145,39,43,142,36,80,224,253,110,40,232,254,63,200,227,152,254,157,181,2,159,160,105,185,63,160,227,154,121,173,136,
66,22,97,46,178,217,182,39,42,170,251,25,65,235,33,195,48,12,199,202,200,67,63,15,37,111,153,192,138,8,207,160,47,165,95,158,101,110,34,123,140,202,108,148,197,240,13,65,28,143,123,236,87,130,13,59,1,
159,18,120,26,188,71,31,125,180,160,24,114,188,241,198,27,94,167,78,157,82,137,68,226,169,140,237,46,155,72,36,22,110,184,225,134,169,197,139,23,23,189,189,61,246,216,195,75,36,18,41,130,26,91,31,2,219,
103,177,123,16,202,104,188,155,242,60,65,206,163,228,30,45,168,192,228,5,40,190,167,75,9,219,234,135,106,41,61,68,208,77,125,1,170,178,126,8,138,185,138,19,75,160,27,128,67,129,191,160,204,215,89,180,
61,94,223,161,184,167,191,0,71,160,154,81,61,138,216,118,220,4,22,168,245,197,34,20,223,181,66,157,109,50,162,65,7,84,80,242,5,116,99,155,203,107,111,52,39,163,80,220,168,11,255,48,129,21,1,126,134,142,
231,139,192,27,192,1,89,150,89,9,245,68,91,13,121,166,114,13,214,253,81,252,202,102,40,51,173,16,163,129,255,17,4,20,31,159,76,38,23,236,176,195,14,69,139,33,199,177,199,30,235,6,221,85,211,182,127,33,
224,141,29,59,182,164,109,77,158,60,217,75,38,147,41,20,12,125,2,193,192,254,16,26,232,206,243,143,85,138,96,202,109,116,17,159,55,147,97,40,115,109,83,228,113,186,145,64,104,186,237,62,138,92,190,3,178,
172,63,24,121,193,158,37,16,184,63,160,233,191,189,136,71,1,208,97,232,28,60,9,77,239,61,67,251,88,41,15,152,132,202,25,156,133,218,197,84,146,221,24,71,129,5,138,201,114,113,130,249,110,136,140,198,228,
74,130,155,208,217,200,91,107,133,147,141,116,70,17,220,96,103,27,203,11,98,2,171,122,108,135,60,3,110,16,251,20,221,33,213,154,158,40,176,186,21,165,192,159,135,60,15,187,0,222,93,119,221,85,178,192,
122,245,213,87,221,103,56,217,237,36,145,72,188,185,226,138,43,182,150,188,49,207,243,182,217,102,27,47,153,76,126,235,111,106,4,242,44,101,14,248,87,33,207,86,181,227,152,70,160,98,158,247,33,47,141,
151,118,156,86,5,206,68,217,106,206,150,25,104,138,118,199,26,216,82,45,122,32,15,211,17,104,74,250,127,180,247,72,165,144,120,120,28,121,165,142,65,98,189,218,177,112,113,20,88,221,80,89,18,15,77,209,
27,205,197,134,232,122,249,8,242,108,15,66,66,235,107,226,59,229,111,84,159,11,8,174,167,101,117,129,48,129,85,25,73,228,133,113,3,244,28,148,174,190,8,213,236,233,92,39,27,94,65,211,87,46,166,164,27,
242,188,120,19,39,78,44,89,16,45,90,180,200,121,157,110,118,59,73,36,18,139,247,219,111,191,114,244,149,119,218,105,167,185,147,244,10,130,10,240,19,80,218,252,3,117,56,70,160,98,148,111,163,210,9,147,
9,218,212,120,104,170,232,10,148,57,18,149,236,191,174,72,0,238,130,250,67,222,136,188,107,83,104,239,145,250,20,213,137,58,27,197,24,173,129,206,129,122,16,55,129,213,29,5,232,155,184,106,94,94,68,65,
204,131,211,94,251,37,58,39,126,23,138,69,70,212,56,15,157,15,174,224,177,77,17,214,145,142,192,65,4,173,56,190,5,206,1,150,242,223,63,149,250,254,88,51,7,211,99,253,253,123,83,167,78,45,75,20,117,237,
218,181,21,53,198,5,125,94,239,168,163,142,42,107,91,231,158,123,110,186,24,24,7,252,2,5,89,103,179,189,154,36,81,234,237,25,180,141,209,74,1,111,161,31,81,24,117,170,58,160,82,1,27,33,215,243,175,80,
70,222,127,128,247,80,66,64,166,136,106,65,66,234,113,228,181,58,6,101,251,133,157,157,25,39,129,213,29,213,234,242,80,45,46,163,249,248,41,250,254,47,202,120,61,9,188,143,98,96,19,153,43,25,77,197,159,
208,57,242,40,126,98,23,214,42,167,110,44,139,2,177,55,6,166,34,49,117,61,109,91,204,92,138,190,148,235,235,100,211,130,140,255,111,67,23,146,95,76,157,58,149,129,3,139,9,225,10,152,53,107,22,63,254,248,
99,18,77,151,1,180,36,147,201,239,167,76,153,82,86,112,247,212,169,83,221,159,251,208,190,86,88,166,237,149,50,20,125,246,109,80,154,109,122,124,205,56,148,177,249,56,217,219,212,92,135,188,143,39,163,
116,254,74,232,143,178,81,86,70,158,168,81,168,146,120,63,255,145,237,119,249,45,154,46,125,17,37,5,124,142,154,144,78,64,226,106,97,133,54,53,51,61,144,151,119,75,52,184,154,167,162,57,57,5,93,115,46,
205,120,61,133,74,142,156,3,172,142,154,217,27,205,69,2,184,28,197,10,63,138,50,172,143,41,180,146,9,172,234,177,49,154,138,89,18,221,29,95,138,130,224,50,73,161,170,233,97,49,15,184,12,248,197,115,207,
61,199,26,107,172,81,210,202,207,60,243,140,251,243,117,247,71,42,149,122,227,197,23,95,220,106,225,194,133,201,46,93,74,73,200,131,103,159,125,214,75,36,18,31,123,158,87,205,66,172,61,80,201,139,149,
81,220,196,48,52,197,183,146,255,254,2,36,84,102,160,114,10,119,160,18,14,185,232,2,172,136,2,93,215,241,215,249,34,207,242,29,145,152,27,233,175,183,130,111,195,48,255,245,204,88,142,201,40,249,224,51,
223,166,47,253,199,36,36,206,191,66,130,221,168,62,221,80,82,197,22,168,127,230,185,161,90,99,132,197,234,232,198,235,70,244,251,93,7,232,67,208,41,224,5,127,185,221,49,129,213,108,36,80,226,195,175,129,
135,209,57,80,241,13,173,77,17,150,198,96,224,3,228,33,137,58,157,146,201,228,151,195,135,15,111,45,165,172,130,231,121,222,230,155,111,158,74,38,147,11,104,155,225,120,40,224,221,124,243,205,37,109,235,
169,167,158,114,83,92,103,87,240,89,122,32,113,123,28,186,56,142,67,158,166,204,154,77,111,35,239,196,54,40,134,105,4,202,4,252,132,226,178,0,19,232,238,101,17,202,44,58,8,121,159,118,68,25,134,151,35,
47,200,199,89,246,239,50,146,94,65,241,111,23,162,99,182,30,42,147,208,168,196,97,138,240,77,255,249,204,112,205,49,66,164,39,65,98,131,75,118,201,246,248,14,221,152,109,75,116,226,49,141,218,146,32,104,
119,247,47,212,86,206,97,133,70,235,76,156,230,231,143,5,188,211,79,63,189,104,65,116,227,141,55,186,11,77,102,0,112,183,100,50,249,233,82,75,45,213,58,121,242,228,162,182,245,195,15,63,120,163,70,141,
106,77,38,147,243,208,148,89,177,44,137,218,178,220,136,226,220,210,235,130,181,32,129,115,59,18,48,107,35,239,81,166,199,104,40,193,180,90,174,30,145,9,116,238,111,142,234,91,157,7,252,3,221,189,102,
214,34,75,207,50,124,9,184,21,197,118,237,129,130,202,139,169,25,213,136,68,89,96,165,103,1,253,38,100,91,140,112,232,137,206,81,215,36,188,5,149,47,185,8,56,26,121,170,15,66,55,80,87,35,175,189,251,237,
127,132,126,223,113,186,230,27,165,145,4,254,138,190,239,187,105,63,227,103,2,203,200,73,50,145,72,60,153,72,36,188,243,207,63,223,75,165,82,121,5,209,109,183,221,230,117,236,216,49,149,76,38,63,32,187,
96,216,34,145,72,180,172,184,226,138,222,199,31,127,156,119,91,51,102,204,240,54,217,100,19,87,219,234,208,60,54,118,66,129,232,7,161,12,191,151,9,46,112,173,168,70,214,13,40,16,124,93,138,11,138,31,130,
166,222,22,162,22,54,125,80,106,246,225,104,90,247,97,96,60,65,141,147,244,199,2,228,165,124,28,121,190,92,150,222,102,52,182,39,170,92,162,44,176,94,70,182,189,80,104,65,163,33,217,31,77,187,123,40,150,
241,18,10,119,120,24,133,110,182,46,72,91,247,85,52,189,104,52,30,123,18,204,62,100,43,209,97,2,203,200,75,239,68,34,241,60,224,109,180,209,70,169,7,31,124,208,75,159,50,92,188,120,177,247,204,51,207,
120,59,238,184,163,7,120,201,100,242,19,96,249,60,219,123,37,145,72,120,221,186,117,107,61,239,188,243,188,175,190,250,170,141,176,154,57,115,166,119,197,21,87,120,253,250,245,107,69,177,104,153,193,196,
203,160,147,250,74,36,158,92,165,92,247,248,12,85,187,223,155,32,43,179,16,125,145,248,218,25,121,149,190,35,152,50,252,138,246,34,106,42,154,6,184,29,77,93,30,136,50,242,6,101,217,246,175,253,207,49,
14,171,145,147,141,40,11,172,115,9,190,243,48,99,34,141,250,210,17,77,231,123,168,62,156,203,32,126,174,136,117,207,34,56,103,190,69,55,98,115,81,156,228,174,53,176,213,8,31,119,157,120,142,246,215,120,
19,88,70,65,186,0,103,37,18,137,5,128,215,185,115,231,212,170,171,174,154,90,101,149,85,82,221,186,117,75,1,94,34,145,88,76,97,111,83,7,36,94,102,36,18,137,255,23,70,67,134,12,105,29,61,122,180,55,98,
196,136,148,95,63,203,75,38,147,159,162,59,193,109,208,84,229,223,8,60,66,174,84,194,7,40,227,241,36,148,241,87,232,238,178,23,10,84,62,205,223,222,75,104,202,46,87,60,197,100,228,137,186,28,21,229,220,
164,136,125,100,227,56,127,123,79,19,221,226,163,97,17,101,129,229,108,123,218,127,190,44,92,115,140,58,208,25,101,128,121,72,28,181,162,155,169,35,41,46,14,115,16,154,22,252,19,138,217,122,16,13,174,
159,162,107,214,73,213,55,217,136,0,103,163,115,230,121,218,138,44,19,88,70,209,244,69,113,7,255,64,30,153,113,40,53,249,68,20,16,62,23,121,125,114,121,106,86,65,83,104,30,240,36,186,163,115,65,231,147,
80,89,129,87,209,128,246,25,109,197,206,66,127,185,203,80,29,172,204,246,36,157,80,9,140,209,180,13,42,127,192,223,102,166,39,106,33,138,145,120,16,77,251,29,131,178,242,126,68,113,21,157,168,46,174,240,
220,125,88,240,107,58,113,16,88,163,208,121,228,161,82,28,22,83,211,184,220,66,16,67,58,144,182,197,68,43,161,31,48,22,9,54,243,100,53,38,174,230,213,11,4,98,220,4,86,204,9,187,80,100,58,174,64,233,203,
40,240,59,153,101,153,229,104,223,88,57,243,177,8,137,162,243,144,216,89,15,77,59,174,129,154,170,58,241,116,63,18,116,211,242,108,107,38,10,58,127,24,181,211,57,12,9,189,108,34,103,3,228,49,171,21,46,
211,228,224,26,238,35,110,196,65,96,13,71,158,141,251,9,234,211,153,200,106,60,78,65,223,239,223,106,180,253,126,232,70,114,46,138,27,53,26,15,87,36,252,69,20,115,91,80,96,89,29,172,232,178,44,240,14,
242,40,157,74,248,133,36,175,65,65,228,23,162,249,232,175,144,55,234,21,148,205,55,9,101,237,117,70,194,231,110,36,182,186,163,194,157,139,81,35,229,158,40,214,106,27,36,70,6,146,221,163,244,45,242,122,
141,243,215,159,138,196,214,87,168,6,213,103,168,204,66,177,140,43,97,217,114,56,30,253,240,92,45,180,14,20,14,124,239,129,142,87,31,116,12,138,153,166,232,140,226,207,220,163,83,218,235,253,253,135,19,
152,125,208,49,207,183,221,185,168,255,226,92,148,77,149,202,178,76,43,58,214,153,207,45,40,142,37,253,241,125,218,223,113,201,158,92,132,154,118,223,133,18,38,146,168,71,101,182,99,97,196,143,225,200,
97,48,22,77,7,214,130,153,232,6,113,28,242,220,175,143,6,95,163,113,184,152,160,142,229,163,232,198,62,47,38,176,162,205,155,104,224,222,10,101,210,189,25,174,57,92,138,188,106,167,33,209,243,75,218,23,
232,76,161,65,127,95,2,1,145,201,76,36,152,62,64,34,205,21,210,156,140,132,211,231,104,0,79,34,129,144,89,225,220,9,137,174,200,205,63,136,246,231,114,47,223,142,62,190,13,197,12,246,189,252,237,36,252,
245,240,183,81,76,0,123,87,234,215,227,47,27,139,81,204,217,12,36,124,64,199,243,53,242,11,209,37,144,8,238,78,219,218,102,233,116,69,199,223,29,139,98,143,137,227,125,36,184,102,251,143,239,81,102,206,
12,212,68,119,6,65,67,93,247,119,107,9,219,175,6,139,145,200,186,29,197,228,37,209,96,108,34,43,94,140,64,177,80,207,1,247,250,175,141,65,191,235,99,169,237,141,234,135,168,196,195,249,168,51,133,107,
39,214,29,221,196,24,241,199,117,98,185,148,34,166,152,77,96,21,166,43,82,174,151,145,191,122,119,181,249,10,216,14,93,236,47,67,158,162,203,80,38,203,162,58,218,145,201,195,192,239,145,183,102,83,52,
181,183,42,10,252,236,135,234,200,204,242,151,157,143,60,91,95,160,193,126,10,138,133,90,72,32,146,250,35,129,52,0,77,227,237,138,166,12,135,248,207,149,54,197,158,133,6,207,57,133,22,68,30,55,87,36,212,
197,137,57,111,77,33,22,162,207,219,226,239,203,101,41,229,99,1,138,11,251,193,183,113,118,17,251,89,140,188,123,238,17,230,185,224,188,111,217,30,75,2,59,160,18,22,143,35,175,90,111,255,177,10,154,102,
206,149,20,224,106,138,77,247,31,223,164,253,239,254,254,26,5,23,23,115,204,138,165,21,221,200,116,64,211,205,9,244,251,51,145,21,31,174,67,222,241,163,209,121,248,22,170,188,125,43,10,57,168,53,151,35,
239,231,159,144,192,187,18,9,245,19,128,107,235,176,127,163,246,92,134,174,9,46,49,38,231,76,133,9,172,194,252,22,165,227,191,135,138,142,213,19,15,185,155,159,66,25,117,167,1,219,163,187,164,127,81,121,
79,188,114,24,135,178,41,142,68,23,145,87,80,13,169,129,232,194,114,3,26,120,135,33,215,252,112,52,117,184,39,42,240,217,143,182,211,88,153,44,70,226,114,50,202,4,156,140,6,212,153,180,255,188,139,144,
104,155,66,123,161,49,47,203,107,70,117,89,68,32,130,178,209,25,9,172,223,34,161,157,201,18,104,186,120,0,58,127,150,70,231,198,210,105,127,15,67,194,187,123,142,125,204,68,66,107,18,58,15,166,33,129,
219,1,93,4,159,67,197,103,139,165,5,121,85,247,70,211,60,125,80,118,172,17,125,186,162,155,190,199,209,121,117,21,186,33,244,80,204,103,61,152,143,166,144,174,68,9,66,174,95,221,31,145,248,179,105,195,
198,224,5,52,30,117,70,225,60,89,49,129,149,159,165,81,252,211,219,40,3,37,44,62,69,37,8,78,68,222,163,59,145,139,242,90,36,192,102,228,92,179,54,92,136,210,148,79,64,3,220,225,40,237,121,123,116,188,
134,210,62,8,126,58,242,10,125,134,236,157,139,6,192,30,104,106,110,30,186,56,101,186,210,59,33,15,87,182,58,84,213,226,123,52,40,207,245,31,217,226,141,220,115,174,56,37,163,116,126,240,31,197,8,160,
30,232,247,56,16,9,175,229,8,4,252,112,96,23,114,79,209,78,69,131,238,117,232,134,32,31,135,163,64,247,241,200,19,98,226,42,62,172,137,202,206,60,138,174,79,239,160,184,168,255,161,176,131,122,113,39,
42,140,124,34,242,80,223,131,66,41,86,32,251,141,134,17,47,70,163,235,137,11,99,24,159,107,65,19,88,249,185,4,221,101,159,72,253,99,66,50,73,161,31,237,245,192,1,200,171,118,62,18,92,47,33,81,179,17,217,
189,9,9,212,63,107,15,96,173,100,50,185,148,231,121,115,61,207,123,31,93,140,238,69,211,85,133,72,162,41,193,149,209,244,215,25,4,25,87,43,35,17,244,30,242,184,77,202,120,12,68,94,129,45,208,69,239,255,
219,227,36,18,218,132,231,197,230,230,206,137,176,244,135,139,49,114,129,222,223,103,252,237,166,0,91,253,215,221,84,98,165,44,141,226,78,134,161,152,128,33,4,241,99,41,52,149,246,5,26,96,190,68,83,108,
97,196,56,85,202,60,130,115,41,23,75,34,111,216,82,4,211,143,155,249,143,253,208,244,223,235,200,179,145,205,131,122,4,250,125,189,139,122,138,206,172,134,225,70,221,112,217,170,227,145,104,191,7,93,43,
223,175,179,29,46,187,121,45,84,24,249,25,36,176,86,196,4,86,220,217,8,141,153,41,52,91,115,98,190,133,77,96,229,102,29,116,81,190,7,77,137,69,133,249,232,139,189,1,21,199,60,30,197,24,36,81,208,249,149,
25,203,143,78,36,18,55,121,158,183,102,50,153,244,70,142,28,201,114,203,45,151,152,57,115,166,55,126,252,248,85,23,46,92,184,79,50,153,188,36,149,74,253,6,101,44,102,210,5,5,108,238,225,239,207,13,222,
139,144,184,242,208,9,119,25,186,144,100,227,114,223,206,36,242,38,124,155,76,38,123,167,82,169,206,221,187,119,247,70,141,26,69,215,174,93,19,83,166,76,73,77,158,60,57,9,144,72,36,158,241,60,239,68,52,
237,211,29,77,19,109,134,178,188,186,160,152,167,49,89,62,111,169,36,9,98,131,122,18,120,212,50,3,186,93,150,95,31,36,186,211,31,253,9,98,143,74,77,241,119,113,88,179,209,49,157,131,4,155,243,166,101,
138,176,165,8,166,211,150,163,125,28,83,138,32,46,41,87,48,122,43,18,89,83,208,64,240,22,242,210,190,227,239,51,174,56,49,155,142,59,39,151,71,83,216,71,160,84,125,247,57,93,96,255,175,144,135,235,109,
36,174,190,173,169,165,70,45,112,93,38,190,244,159,95,65,2,235,129,16,108,121,9,121,212,174,66,101,107,59,52,0,0,32,0,73,68,65,84,181,214,32,123,105,27,35,62,108,140,198,186,22,228,176,216,172,146,141,
53,123,29,172,107,209,96,21,197,26,62,153,172,132,60,19,175,103,188,190,119,34,145,88,216,171,87,175,214,115,207,61,215,155,49,99,70,155,214,53,243,231,207,247,110,187,237,54,111,200,144,33,173,232,187,
190,156,64,32,12,2,206,33,232,185,181,0,245,236,186,12,221,29,186,0,240,244,186,84,211,145,72,59,156,96,96,95,25,29,199,167,208,9,122,47,224,173,190,250,234,169,251,239,191,223,91,184,112,97,27,155,38,
78,156,232,29,127,252,241,174,239,225,2,148,57,153,217,50,231,5,36,50,162,72,31,228,77,92,11,216,18,216,13,5,76,31,137,166,79,207,64,194,240,207,72,36,255,29,137,248,39,145,144,127,29,29,231,169,72,4,
100,214,254,250,14,221,161,63,15,220,129,226,224,14,241,247,229,106,58,101,218,227,106,140,29,139,90,63,220,12,60,132,238,236,23,167,109,187,21,125,183,119,249,182,110,67,238,204,194,98,136,98,29,172,
46,168,35,65,250,121,61,22,157,163,111,80,124,11,38,35,122,100,158,111,238,255,97,33,216,114,162,191,239,213,81,155,46,15,221,8,27,241,100,83,116,227,59,157,160,238,149,21,26,45,147,14,40,88,246,229,176,
13,41,1,151,62,234,26,143,110,158,72,36,22,173,180,210,74,173,19,39,78,204,219,124,121,206,156,57,222,206,59,239,236,6,217,9,200,197,237,154,49,167,63,62,71,21,223,39,162,246,1,75,161,66,161,143,167,45,
223,138,6,109,39,176,134,35,197,255,1,242,28,120,199,28,115,140,215,210,210,146,215,166,151,94,122,201,235,219,183,175,151,76,38,91,129,127,163,154,89,55,100,124,70,163,114,186,34,111,237,17,232,166,98,
44,237,139,197,126,138,132,241,239,80,99,236,98,61,223,81,20,88,14,215,87,110,34,65,123,166,235,73,155,186,54,98,199,233,232,187,92,217,255,255,98,255,255,48,68,243,193,254,190,55,70,191,47,15,121,241,
141,248,177,25,154,73,152,70,219,177,199,4,86,153,108,131,62,123,156,122,75,173,134,108,190,8,232,156,76,38,63,233,219,183,111,235,23,95,124,145,87,200,56,22,46,92,232,109,176,193,6,94,34,145,112,131,
205,84,224,9,228,213,58,22,149,98,112,222,173,108,174,238,21,208,116,221,124,130,106,183,59,249,235,236,138,166,193,188,125,246,217,167,40,123,60,207,243,198,142,29,235,117,232,208,33,133,188,45,29,80,
60,81,166,151,206,168,62,29,208,249,116,32,112,5,242,24,186,210,19,174,252,196,253,232,188,88,41,207,118,162,44,176,156,109,30,154,22,124,202,255,251,7,148,241,101,205,187,227,199,126,232,59,252,153,255,
255,24,255,255,48,68,243,1,254,190,183,68,215,70,15,157,115,70,188,216,22,141,105,83,209,24,152,142,9,172,50,185,17,137,140,229,11,45,24,49,222,70,37,14,14,4,188,235,174,187,174,104,49,227,121,158,247,
222,123,239,121,137,68,34,69,80,32,175,28,6,161,228,128,31,8,6,175,13,18,137,196,184,238,221,187,183,206,156,57,179,36,155,142,59,238,56,55,8,186,166,202,39,84,114,128,140,178,73,34,209,117,34,18,188,
233,130,235,11,52,237,184,59,109,133,73,148,5,214,227,4,231,167,171,116,191,37,42,67,226,161,187,213,67,194,49,205,40,147,45,104,219,174,234,12,255,255,145,33,216,226,166,8,215,192,4,86,92,217,10,133,
16,204,32,251,57,100,2,171,12,58,162,3,250,82,216,134,148,129,251,194,199,245,232,209,163,117,222,188,121,37,137,25,207,243,188,77,54,217,196,75,38,147,223,84,193,150,37,129,51,9,50,232,188,99,142,57,
166,100,123,198,143,31,239,6,241,15,253,237,68,53,246,42,31,39,162,10,225,141,68,39,228,58,63,23,77,165,183,16,196,52,61,140,98,206,220,20,77,20,5,150,155,110,158,141,166,185,29,9,20,55,55,193,127,255,
97,242,212,185,49,34,197,230,232,59,115,194,248,3,255,255,159,135,96,139,139,225,29,0,172,235,219,241,235,16,236,48,202,103,0,202,138,111,69,113,197,153,152,192,42,131,237,136,239,124,249,0,96,113,34,
145,152,183,245,214,91,151,44,102,60,207,243,206,56,227,12,39,104,170,245,189,15,65,193,212,222,61,247,220,83,150,77,253,250,245,107,69,3,248,127,170,100,83,189,185,14,93,108,135,134,108,71,45,89,18,77,
209,220,141,68,139,155,106,246,144,71,51,12,47,66,62,156,119,205,149,211,216,48,227,253,110,104,138,201,245,91,172,85,15,59,163,122,56,33,243,27,52,77,232,174,101,231,135,96,139,139,237,187,16,213,104,
243,144,112,55,226,197,146,168,221,88,10,205,162,164,83,80,96,89,218,104,123,182,245,159,239,15,213,138,242,152,14,60,225,121,94,247,126,253,250,149,181,129,1,3,6,184,63,123,87,201,166,47,80,0,62,3,7,
150,231,124,234,214,173,91,18,197,5,221,81,37,155,234,205,253,200,51,178,77,216,134,212,144,239,81,6,233,222,72,232,111,143,46,76,0,39,163,236,196,183,80,160,124,24,89,93,185,56,0,121,70,159,68,83,76,
142,5,200,214,45,145,71,251,6,224,191,168,19,129,17,77,222,69,177,158,59,0,87,163,105,236,41,212,223,131,181,44,154,22,156,138,110,212,71,251,175,127,85,103,59,140,202,249,30,105,130,215,129,191,80,162,
227,197,4,86,123,238,67,202,244,203,66,11,70,148,59,0,62,254,184,148,238,32,1,179,102,253,127,251,188,121,85,178,7,252,90,78,179,103,151,215,54,110,198,140,25,32,79,194,131,213,51,169,174,124,232,63,175,
16,170,21,245,99,33,138,113,122,200,255,127,55,36,178,251,162,59,250,79,129,87,81,11,157,176,227,28,93,197,246,249,200,222,45,51,222,127,1,197,209,92,5,236,136,236,46,107,74,192,168,57,11,81,249,146,173,
209,111,237,48,20,79,186,38,106,215,85,47,14,66,55,84,151,162,26,126,191,245,95,143,235,152,210,236,56,145,245,26,74,250,169,74,28,112,179,78,17,198,157,174,192,226,78,157,58,165,82,169,84,201,211,113,
59,238,184,163,151,76,38,231,81,93,241,61,10,240,126,255,251,223,151,108,207,27,111,188,225,220,252,239,86,209,158,122,147,68,119,214,119,134,109,72,157,201,12,114,79,160,74,200,87,160,187,121,55,141,
248,34,114,191,47,29,162,109,43,163,44,213,121,104,128,206,198,207,209,116,225,92,84,120,215,136,30,195,81,57,24,55,8,174,128,132,215,35,117,218,127,47,52,147,240,62,250,221,187,242,57,205,246,219,111,
68,122,19,36,193,156,142,197,96,53,45,175,0,222,205,55,223,92,146,152,153,50,101,138,215,169,83,167,20,53,184,24,36,147,201,137,67,134,12,105,93,180,104,81,73,54,253,244,167,63,117,2,235,183,133,246,17,
113,38,16,175,186,106,213,32,95,22,97,18,5,201,95,139,6,36,15,121,41,159,66,89,96,181,46,147,144,205,182,81,72,248,205,35,247,116,238,106,168,221,73,10,149,115,136,3,165,118,23,104,52,174,64,223,117,61,
166,232,221,184,153,94,84,116,64,142,101,27,153,70,157,29,235,141,174,227,30,18,237,38,176,154,144,159,1,94,255,254,253,83,165,100,18,238,185,231,158,206,163,144,25,240,91,13,142,1,188,49,99,198,20,109,
207,228,201,147,189,14,29,58,120,232,14,52,91,239,184,56,241,4,138,201,104,38,138,45,211,208,17,185,224,111,65,238,120,87,143,234,38,84,168,177,158,182,57,79,214,124,212,50,39,27,75,1,79,19,143,212,251,
222,40,6,174,153,89,10,157,87,147,168,109,12,221,6,168,221,213,255,104,110,81,219,27,56,37,108,35,106,200,18,168,202,128,187,249,55,129,213,100,36,240,189,2,59,239,188,179,55,127,254,252,188,66,38,149,
74,165,103,15,222,80,35,155,58,38,18,137,87,59,116,232,144,186,247,222,123,11,138,171,111,190,249,198,27,49,98,132,203,66,251,107,141,108,170,39,55,32,241,218,61,108,67,234,72,57,117,176,186,0,123,1,143,
17,180,98,154,132,10,232,174,75,245,6,174,124,182,253,148,64,228,229,26,144,187,1,207,249,203,229,109,248,26,50,127,68,29,24,26,213,163,80,44,187,162,243,233,127,180,111,39,85,13,134,162,128,250,239,137,
86,18,71,24,252,10,245,242,236,85,104,193,24,211,31,191,120,54,234,130,81,50,38,176,226,205,57,248,10,123,245,213,87,79,61,243,204,51,89,133,204,135,31,126,232,237,184,227,142,30,224,37,18,137,167,168,
205,197,199,177,108,50,153,252,52,145,72,164,78,56,225,132,118,189,17,61,207,243,90,90,90,188,127,254,243,159,222,50,203,44,211,138,4,73,138,198,184,96,253,14,125,31,171,132,109,72,29,169,180,208,232,
242,168,150,218,59,180,45,106,122,41,48,184,70,182,13,3,62,67,94,211,93,11,108,99,9,212,191,176,21,149,119,137,26,189,208,64,231,42,138,55,59,238,55,248,95,170,59,248,15,67,137,27,11,9,178,208,155,25,
231,221,57,53,108,67,106,68,119,52,35,97,30,172,38,102,4,18,39,207,38,147,201,57,128,55,108,216,176,212,193,7,31,236,157,118,218,105,222,177,199,30,235,173,187,238,186,41,191,114,123,43,106,62,92,75,113,
229,24,128,63,119,221,185,115,231,212,22,91,108,225,157,116,210,73,222,169,167,158,234,237,179,207,62,94,255,254,253,91,1,87,236,116,46,240,108,29,108,170,7,71,162,223,211,38,97,27,82,71,170,89,201,125,
36,170,204,253,134,191,205,133,168,111,226,239,40,175,215,92,54,219,134,18,12,148,187,20,185,157,129,168,140,195,36,228,213,138,18,78,80,120,192,173,33,219,18,21,92,208,249,123,84,231,188,220,14,125,255,
165,156,51,141,140,27,119,60,20,18,17,181,223,68,165,116,39,104,171,229,194,4,76,96,53,41,47,161,59,216,229,129,75,18,137,68,171,47,168,60,36,98,62,67,13,110,71,133,96,219,79,129,127,38,147,201,105,206,
158,68,34,177,32,145,72,140,67,25,64,174,151,215,161,33,216,86,11,78,69,159,39,179,159,85,35,83,171,86,57,235,162,114,36,159,251,219,255,22,56,154,210,166,193,50,109,91,17,165,209,47,4,118,46,209,158,
67,253,109,253,190,196,245,106,73,119,212,238,103,60,154,202,156,131,245,87,116,28,140,166,119,230,162,113,174,156,154,127,203,162,152,65,215,183,117,179,106,25,23,115,206,69,191,133,235,105,188,234,245,
61,8,68,213,24,44,139,176,233,57,10,125,135,187,162,106,226,30,74,65,95,146,104,221,89,244,66,54,237,142,6,130,245,80,77,162,249,84,175,224,105,216,92,136,142,255,160,176,13,169,35,181,238,69,152,64,69,
37,63,244,247,243,10,170,121,84,12,233,182,141,68,241,51,63,162,6,229,229,216,49,9,21,82,141,10,39,161,207,119,0,170,203,228,1,251,135,106,81,180,88,135,96,42,107,38,106,235,180,49,249,147,105,58,162,
98,180,183,18,196,223,220,77,115,102,9,102,195,253,14,38,160,86,90,159,162,155,150,122,204,140,212,154,30,104,54,197,3,206,242,95,51,129,213,228,244,70,34,229,113,148,221,242,112,184,230,20,100,89,100,
239,88,100,239,223,195,53,167,170,92,139,126,79,22,228,94,125,58,163,233,195,249,168,42,251,37,232,130,152,15,103,219,182,4,165,25,114,101,13,22,195,77,104,170,125,137,10,182,81,45,186,32,193,56,9,137,
130,30,232,198,229,241,48,141,138,40,191,64,194,216,77,165,78,7,30,69,30,152,49,254,227,22,52,184,186,6,231,173,168,232,241,70,33,216,27,101,92,47,72,231,201,117,55,248,101,5,129,71,136,222,104,76,202,
244,82,155,192,50,184,7,213,23,106,165,248,187,251,48,249,51,193,197,46,138,129,195,149,16,37,175,97,61,168,151,192,114,172,128,68,132,135,238,162,243,93,248,156,109,211,200,95,92,180,88,220,197,54,10,
191,177,99,144,45,233,13,106,111,71,215,128,176,43,231,71,149,225,232,59,124,18,157,19,94,218,35,133,146,43,30,64,225,11,67,66,178,49,234,220,76,219,164,164,76,161,31,71,210,139,139,158,145,241,158,9,
44,131,157,208,247,120,118,200,118,20,75,127,244,35,157,79,252,107,95,53,59,245,22,88,142,3,145,183,97,158,255,119,54,174,65,182,205,163,58,241,51,123,251,219,251,89,21,182,85,9,157,80,22,228,100,218,
78,205,108,131,236,59,45,12,163,98,72,87,212,218,105,73,116,76,141,252,116,67,93,14,50,147,146,220,84,117,28,167,167,251,162,30,132,41,178,183,199,49,129,85,38,141,84,36,174,19,186,35,123,44,108,67,138,
100,40,58,161,127,164,49,230,238,155,153,176,4,22,168,28,198,120,130,128,219,174,25,239,187,76,160,55,169,142,103,113,15,127,123,59,86,97,91,149,112,152,111,199,177,25,175,39,145,232,250,160,238,22,25,
205,192,190,232,188,59,36,227,117,151,108,241,33,241,171,197,182,45,74,122,153,142,198,165,76,76,96,149,193,95,209,69,183,145,88,149,120,221,133,157,73,253,90,91,24,181,35,76,129,5,74,158,184,219,183,
225,117,218,214,83,115,182,121,168,65,112,165,25,118,107,147,125,26,161,158,116,64,83,163,223,144,93,52,186,68,139,117,234,105,148,209,20,60,134,188,193,217,234,139,157,142,206,187,56,246,239,220,1,88,
128,110,78,70,100,188,103,2,171,12,254,130,62,183,197,42,132,199,96,228,197,250,75,216,134,24,21,17,182,192,114,28,137,238,68,103,3,187,249,175,57,219,46,246,159,95,160,178,226,147,73,84,46,34,140,126,
147,75,162,120,171,23,208,103,201,213,166,100,101,255,125,251,93,25,213,100,16,138,243,205,149,148,180,4,250,237,205,64,125,33,215,175,147,93,213,98,123,36,178,190,68,229,92,28,38,176,202,192,197,44,53,
74,253,165,184,242,54,170,115,100,196,151,168,8,44,80,127,205,47,145,112,63,15,165,90,59,219,78,243,255,126,145,202,68,150,75,208,168,71,118,89,87,228,17,184,159,160,100,128,235,227,120,105,158,245,94,
65,3,157,77,191,27,213,226,20,130,140,220,108,12,68,217,189,238,252,244,80,224,251,5,192,234,245,48,176,10,108,135,226,130,191,33,232,198,97,2,171,12,122,161,18,1,255,12,219,144,38,199,21,170,107,166,
178,6,141,70,148,4,22,40,129,194,197,94,189,79,91,219,220,32,241,18,229,151,90,24,140,174,29,47,83,155,41,249,36,234,4,112,37,170,221,228,161,59,235,7,129,61,145,104,122,11,21,190,204,181,255,227,252,
245,126,81,3,251,140,230,228,93,84,234,36,87,82,146,11,116,223,30,253,70,78,64,55,51,78,108,125,128,146,176,70,214,218,208,10,217,28,21,167,157,138,194,110,76,96,149,201,255,208,93,94,220,130,242,26,9,
55,117,99,69,252,226,75,212,4,22,104,16,112,97,0,30,109,91,23,253,150,32,94,171,111,153,219,119,241,38,23,85,96,99,38,171,162,122,76,95,19,212,97,122,17,77,125,102,138,193,227,253,101,114,85,163,239,139,
60,94,247,85,209,62,163,121,113,177,135,99,242,44,243,38,10,116,207,44,213,176,10,18,86,31,211,94,108,69,181,255,236,102,40,67,121,26,170,183,103,2,171,12,126,143,62,251,218,97,27,210,196,68,113,112,54,
74,35,202,223,225,127,8,234,96,141,78,123,253,36,52,141,248,6,229,245,56,76,162,90,92,173,148,222,114,39,27,59,19,12,62,175,160,187,255,165,243,44,191,20,18,80,15,228,89,230,223,40,38,173,156,207,103,
24,233,92,65,254,22,96,171,250,239,95,94,96,59,235,249,203,124,69,80,62,165,80,177,224,176,216,20,248,129,160,240,172,9,172,18,89,11,125,246,107,195,54,164,137,113,110,229,53,194,54,196,40,155,40,11,44,
103,219,28,228,246,79,175,226,126,2,129,39,171,79,25,219,30,136,226,7,231,80,249,77,90,87,84,95,232,133,18,214,185,23,77,85,14,204,241,254,46,100,47,229,96,24,165,224,74,0,189,158,103,25,151,185,90,236,
239,96,25,116,115,114,87,101,166,213,156,205,208,77,138,135,90,188,101,197,166,192,178,243,22,186,11,61,12,171,218,27,22,143,163,226,116,83,194,54,196,104,104,246,66,2,230,191,40,70,36,73,16,120,59,9,
137,175,82,153,134,210,187,91,80,79,205,74,50,146,221,116,222,198,100,175,197,147,141,91,209,224,183,95,142,247,31,65,49,92,7,84,96,151,97,108,143,66,56,110,207,241,126,18,157,131,227,41,190,244,209,190,
254,122,183,85,106,92,141,25,73,16,231,248,109,57,27,104,102,15,22,168,86,76,10,184,49,108,67,140,88,210,145,120,213,30,171,5,113,240,96,13,71,194,229,51,116,71,234,130,224,239,166,242,246,30,219,161,
236,169,9,192,74,21,108,103,43,223,166,223,21,185,124,7,84,183,231,253,60,203,92,229,111,115,84,5,118,25,205,205,189,232,252,206,229,41,45,245,188,5,120,135,252,1,243,81,224,8,228,101,115,211,153,54,69,
88,38,15,33,87,251,10,97,27,98,196,142,163,129,137,68,63,51,166,150,196,69,96,129,126,227,46,166,226,5,170,215,59,109,79,148,222,253,29,26,112,202,161,156,42,236,110,106,102,221,28,239,175,231,191,127,
65,153,54,25,205,205,146,200,187,250,159,60,203,220,74,105,253,47,139,9,152,15,155,35,209,103,122,139,224,26,98,2,171,76,214,70,94,172,91,194,54,164,76,18,40,158,36,142,125,160,226,76,79,84,47,101,18,
205,93,111,40,46,2,171,3,154,230,112,49,89,11,129,93,171,184,175,245,209,249,176,8,248,53,229,181,226,26,67,105,205,164,71,162,107,87,190,56,210,247,208,20,124,148,189,5,70,52,57,154,252,241,71,174,55,
225,51,37,108,243,74,127,155,171,85,102,90,205,56,10,253,166,222,68,9,34,86,166,161,10,220,143,226,48,202,77,219,14,155,207,9,167,186,116,51,243,71,244,219,217,39,108,67,66,38,14,2,107,36,112,135,255,
247,205,200,147,245,41,18,89,91,87,113,127,131,81,241,92,15,13,58,165,30,147,213,252,117,47,41,97,157,23,209,32,151,171,215,162,43,41,81,174,103,205,104,94,198,162,216,163,46,57,222,255,37,217,123,19,
230,162,51,42,141,52,137,104,102,15,166,103,23,59,45,96,2,171,10,12,69,173,0,226,202,223,80,176,237,50,97,27,210,36,108,134,60,21,175,208,88,77,195,203,33,14,2,203,149,107,248,43,65,210,207,48,84,76,112,
22,213,189,155,238,130,166,228,22,163,155,182,211,200,61,64,165,179,2,74,250,152,65,105,241,41,174,241,243,47,115,188,191,44,186,54,220,86,228,246,12,3,212,46,38,5,92,147,103,153,71,80,17,220,222,69,110,
115,87,130,114,36,95,162,115,55,42,222,255,92,245,241,76,96,25,108,143,190,199,19,195,54,164,9,24,140,50,200,102,98,113,123,16,109,129,117,54,193,5,253,6,218,103,84,175,131,68,208,23,84,255,6,107,109,
224,53,127,223,19,208,116,75,182,64,225,190,232,226,62,27,137,178,231,41,173,9,122,79,52,229,249,68,158,101,158,68,159,179,210,102,215,70,243,112,30,58,15,55,200,241,254,0,116,190,150,210,13,229,1,228,
53,62,18,197,27,122,168,66,124,216,89,252,249,58,60,152,192,50,232,136,238,198,95,11,219,144,6,167,27,58,198,139,128,45,67,182,37,42,68,89,96,141,37,232,63,152,203,211,184,19,242,240,188,73,101,61,10,
179,145,68,13,154,167,250,118,180,160,233,135,171,80,79,67,231,1,240,128,143,144,224,115,77,117,111,43,97,63,127,67,65,185,131,115,188,127,128,191,143,3,75,253,0,70,83,146,64,83,232,19,254,175,189,243,
14,155,163,170,219,255,231,73,39,33,36,1,164,68,74,64,154,20,165,137,16,1,41,130,20,21,126,72,47,130,10,82,244,69,68,1,59,188,8,250,138,5,59,69,5,81,80,64,69,17,4,145,42,77,138,128,128,180,208,81,106,
32,36,129,64,250,254,254,184,231,56,103,247,153,153,157,221,167,236,238,179,247,231,186,246,218,125,118,207,153,61,207,236,204,153,123,190,231,91,200,63,111,142,65,199,212,46,37,183,185,28,154,55,47,74,
254,30,133,124,135,231,161,243,99,171,102,7,219,71,62,140,254,143,151,200,46,159,101,129,101,128,212,121,176,47,161,226,38,159,30,148,24,175,2,28,213,226,177,180,19,237,44,176,130,211,248,34,36,116,242,
56,42,105,247,103,6,38,111,224,8,148,206,225,76,36,164,130,85,237,37,224,119,232,34,21,127,239,213,40,139,116,153,26,157,195,129,227,147,237,253,146,108,63,210,113,200,202,117,77,115,195,55,93,198,54,
232,120,250,82,206,231,239,64,121,175,230,83,126,121,61,8,178,93,107,222,223,22,45,139,207,35,127,153,123,32,25,65,58,175,255,140,222,231,191,5,150,1,116,247,91,65,147,184,233,127,130,179,176,115,166,
85,211,206,2,43,140,237,62,228,79,242,169,130,182,223,73,218,158,56,8,227,26,71,177,181,236,16,138,253,170,64,229,73,190,137,34,4,43,232,255,11,17,146,223,65,190,87,49,191,160,177,112,122,211,189,156,
131,142,149,218,165,187,109,145,213,117,49,233,241,86,65,150,226,195,41,174,136,112,15,170,179,153,149,26,101,53,116,227,177,16,37,5,30,108,134,35,43,112,5,248,53,213,99,180,192,50,255,229,50,180,46,222,
205,121,153,6,130,79,163,9,231,38,218,199,41,179,93,232,4,129,181,17,112,7,186,40,28,157,211,118,4,112,3,250,157,203,250,63,13,20,227,81,157,182,203,107,222,159,132,252,87,110,166,186,112,238,9,200,191,
107,75,52,7,84,144,69,224,151,164,73,70,67,66,200,47,12,240,216,77,103,51,22,89,79,67,234,133,97,104,25,253,239,244,62,174,66,129,242,176,4,62,23,184,56,105,31,139,148,13,146,207,79,43,248,222,21,208,
178,228,11,148,179,220,246,55,195,209,77,72,5,89,180,194,248,45,176,204,127,217,0,93,32,46,170,215,208,148,38,156,96,183,3,203,182,120,44,237,72,39,8,172,183,161,187,235,219,144,200,202,11,6,89,17,77,
240,47,210,219,2,52,216,252,6,221,44,173,130,46,88,23,163,37,153,10,178,4,124,31,9,199,44,54,70,23,193,69,201,227,50,228,172,252,36,240,200,128,142,218,116,58,7,162,99,236,19,200,103,239,161,228,239,89,
232,152,203,10,6,25,142,110,74,46,38,173,221,247,108,210,254,29,168,192,115,133,180,60,85,189,239,62,182,175,255,68,147,244,160,156,114,113,149,7,11,44,83,197,47,209,69,100,211,86,15,36,131,111,162,147,
174,147,172,64,83,144,201,188,29,243,182,180,3,157,34,176,64,225,228,225,78,60,207,191,100,123,180,84,113,35,253,151,233,189,25,118,69,227,12,162,106,14,112,62,242,229,42,155,194,97,125,148,255,107,65,
180,141,10,202,240,110,76,22,87,161,99,100,118,242,252,52,186,33,41,27,129,186,92,210,62,228,131,11,199,112,153,0,172,225,192,163,104,217,187,85,215,136,30,148,154,162,130,202,4,133,8,67,11,172,65,160,
19,178,33,79,65,145,73,247,211,94,162,32,92,184,174,110,245,64,76,191,210,73,2,11,116,161,184,33,121,255,43,57,253,190,154,124,126,228,64,14,174,14,35,145,53,237,6,148,200,49,43,194,169,44,83,128,31,161,
114,62,149,228,181,49,181,132,156,105,21,84,47,240,32,250,86,107,117,35,116,67,61,157,98,255,199,152,195,169,239,127,56,208,244,144,214,241,124,16,11,172,65,97,20,82,247,167,210,218,59,219,50,28,134,126,
215,70,10,112,14,36,43,163,136,169,118,88,122,49,253,75,167,9,44,144,143,211,77,228,91,178,70,161,108,211,207,209,218,155,148,190,136,170,44,150,67,243,87,183,151,119,50,217,28,143,124,175,118,166,127,
19,40,143,2,198,148,108,187,26,131,23,108,82,68,44,178,42,192,38,205,108,196,2,171,60,75,33,235,75,5,45,51,180,227,5,37,102,15,218,195,226,54,10,249,190,44,192,185,163,134,34,157,40,176,32,205,42,253,
28,217,190,117,251,39,159,127,113,192,70,215,58,150,162,255,197,155,233,124,218,161,18,200,120,116,222,253,176,213,3,65,98,111,46,26,207,193,205,108,192,2,171,49,134,161,136,157,121,104,141,250,144,150,
142,166,253,25,134,252,151,42,232,238,200,12,61,58,81,96,189,31,45,151,61,15,172,155,211,119,24,242,35,153,137,138,190,26,99,6,158,209,200,135,248,231,45,30,199,170,40,170,49,44,153,122,137,112,16,217,
132,52,186,226,98,58,183,72,244,64,50,10,69,66,85,128,11,112,205,190,161,74,167,9,172,157,144,143,226,191,81,189,181,34,130,163,249,151,7,100,116,198,152,90,214,165,56,8,101,48,152,130,34,110,231,145,
26,8,44,176,6,153,177,40,169,103,5,69,61,236,209,218,225,180,21,99,81,66,186,10,170,1,215,14,75,149,102,96,232,36,129,181,11,18,87,207,0,107,148,232,223,3,60,134,238,100,125,131,96,204,192,179,59,58,103,
247,108,209,247,175,133,174,231,115,81,122,148,186,105,26,6,162,244,131,209,18,195,17,192,110,104,242,253,61,18,21,101,38,238,161,204,10,200,87,109,103,148,132,238,8,148,139,167,157,120,55,46,41,212,109,
236,10,92,130,130,45,182,69,194,169,30,21,148,225,121,53,96,235,129,27,154,49,38,33,164,23,122,160,5,223,189,54,112,61,242,201,220,19,229,143,235,19,182,96,245,15,75,161,100,106,11,208,29,242,73,148,143,
154,24,74,124,0,69,10,46,2,62,215,226,177,100,177,52,178,168,45,2,174,108,241,88,134,10,157,96,193,250,36,202,197,243,20,18,75,141,176,10,58,94,126,218,175,35,51,198,100,113,63,178,24,15,54,235,160,228,
168,115,168,174,228,224,68,163,109,196,59,129,91,144,200,234,70,75,214,201,200,188,186,125,171,7,82,195,72,148,186,98,58,58,222,127,143,107,178,245,23,157,32,176,22,32,159,138,70,197,85,224,105,148,143,
202,24,51,112,188,13,157,175,223,27,228,239,125,59,138,38,158,67,239,107,151,5,86,155,209,131,132,86,39,209,95,37,96,70,208,94,14,255,35,129,67,209,29,81,5,101,9,222,169,165,35,26,122,180,179,192,186,
24,141,237,9,250,54,199,221,131,10,70,27,99,6,142,144,53,125,155,65,252,206,119,34,183,129,215,200,118,3,176,15,86,155,17,178,224,118,10,91,35,167,223,211,80,49,217,190,176,16,152,209,231,17,245,157,81,
40,35,240,163,104,105,103,24,202,202,189,30,240,151,22,142,203,12,46,11,147,231,145,244,45,57,240,76,250,126,110,24,99,138,217,27,85,47,184,105,16,191,115,62,154,39,134,163,20,17,13,99,129,101,138,152,
137,18,129,30,135,50,60,159,128,10,227,118,34,43,163,236,245,143,161,8,207,197,168,104,233,90,201,223,243,91,55,52,211,2,30,74,158,223,130,106,11,54,179,108,223,131,252,51,158,238,175,65,25,99,122,49,
5,165,63,186,132,193,13,138,122,8,89,204,102,0,151,3,31,234,207,141,123,137,208,4,118,70,203,32,161,40,236,217,52,185,238,220,34,214,64,39,102,5,152,6,124,140,190,213,209,50,229,104,231,37,194,48,182,
143,34,191,200,162,196,162,121,132,188,60,39,247,239,208,140,49,17,199,160,243,108,187,22,125,255,20,210,220,87,187,69,239,219,7,107,8,48,1,248,9,82,207,173,44,97,49,12,229,254,248,11,178,254,84,128,191,
1,31,105,241,184,202,114,34,176,37,206,89,52,152,116,130,192,122,27,105,246,246,23,208,82,113,89,66,225,231,247,246,251,232,140,49,129,191,2,175,210,218,155,226,85,209,42,206,60,84,74,11,44,176,134,4,
187,145,90,95,22,0,183,162,59,230,173,25,252,162,172,171,161,101,182,7,145,200,154,157,140,235,77,100,190,117,66,85,19,211,41,2,11,36,146,94,67,34,107,253,18,253,151,64,14,176,247,99,209,110,204,64,242,
60,112,77,171,7,129,210,178,60,134,220,73,246,192,2,107,200,176,60,42,48,123,14,242,247,8,85,188,231,161,40,166,243,208,143,189,61,253,19,245,55,12,45,171,237,134,4,213,175,80,237,181,96,185,122,26,248,
22,18,92,123,2,191,67,22,128,63,245,195,119,23,141,105,109,96,47,26,95,202,49,173,161,147,4,22,192,86,72,100,189,8,108,80,167,255,151,147,254,31,25,144,209,25,99,64,5,158,23,3,103,180,122,32,9,43,163,
0,169,133,192,249,88,96,13,73,214,2,142,2,126,137,132,207,124,82,209,85,1,62,219,196,54,143,67,126,86,207,146,86,9,15,143,185,201,247,124,31,152,74,246,29,251,120,180,86,221,40,219,162,172,238,241,227,
76,36,218,174,207,25,211,87,155,248,30,51,248,116,154,192,2,45,35,207,70,214,169,188,137,115,7,52,193,222,138,125,249,140,25,72,54,69,231,233,167,91,61,144,136,21,80,54,249,176,178,148,43,176,250,18,158,
108,90,199,180,228,241,147,228,239,81,200,170,243,142,228,241,207,38,182,57,12,57,176,63,3,188,156,108,255,97,224,95,164,149,195,139,120,45,121,52,202,84,20,157,88,203,12,224,149,228,241,76,242,252,8,
18,92,119,54,241,61,198,148,225,102,100,45,190,12,184,22,37,26,124,57,250,252,237,168,80,249,116,100,189,93,48,216,3,52,166,139,24,151,60,207,110,233,40,170,121,1,249,109,62,134,210,55,108,74,19,185,240,
108,193,50,131,193,24,148,71,40,126,56,125,200,208,160,19,45,88,147,144,128,95,76,239,187,230,149,208,242,248,28,96,243,129,30,160,49,134,41,232,60,253,70,139,199,17,51,12,185,235,132,21,149,141,242,26,
218,130,101,90,205,220,228,97,76,171,153,4,92,133,114,238,28,3,252,32,250,108,50,114,180,157,12,236,142,242,195,25,99,6,150,89,201,243,216,150,142,34,101,56,240,115,224,96,228,255,188,17,5,185,185,108,
41,48,198,24,137,171,191,34,115,255,209,244,22,87,55,32,107,215,71,128,63,15,246,224,140,233,82,118,72,158,31,105,233,40,196,112,224,92,36,174,126,3,252,186,47,27,243,18,161,49,166,47,116,202,18,225,91,
144,15,197,98,20,60,18,211,3,92,141,124,16,247,30,204,1,26,211,229,172,141,82,52,60,71,235,235,216,14,71,209,244,21,100,193,26,134,107,17,26,99,76,33,203,32,103,246,245,129,79,146,6,142,4,142,0,222,7,
124,23,21,136,54,198,12,60,219,160,40,221,9,200,98,212,202,58,182,195,81,196,254,129,192,207,128,195,208,205,88,159,176,5,203,24,211,23,58,193,130,53,13,89,167,14,206,105,55,13,69,209,142,25,164,113,25,
211,237,28,142,82,15,189,0,188,187,197,99,25,9,252,30,205,21,103,83,109,148,178,5,203,24,99,50,24,159,60,175,142,196,213,121,25,109,214,6,214,68,19,172,3,49,140,25,88,70,2,63,70,121,16,31,66,145,186,183,
183,112,60,163,80,62,198,61,128,31,33,225,215,144,229,202,2,203,24,211,141,76,77,158,239,64,14,171,89,108,150,60,95,55,240,195,49,166,171,121,47,112,55,242,129,188,4,120,15,240,84,43,7,4,236,138,106,0,
191,68,90,119,180,33,44,176,140,49,221,200,213,201,243,22,168,228,69,86,202,154,225,201,243,155,131,50,34,99,186,143,21,144,243,248,245,168,12,205,209,40,129,239,235,173,28,84,194,31,128,35,81,16,204,
181,200,95,179,33,156,7,203,24,211,141,4,83,255,37,192,126,40,90,240,32,170,43,22,132,252,54,19,6,113,92,198,116,3,111,65,98,234,104,180,92,127,62,112,60,242,187,106,39,206,36,173,133,120,13,74,27,241,
114,97,143,146,216,201,221,24,211,23,58,193,201,125,77,210,172,204,23,81,125,211,57,25,21,49,191,97,176,7,103,204,16,101,85,148,99,110,14,58,231,238,0,182,110,233,136,202,113,40,186,225,122,16,89,221,
160,132,147,123,17,22,88,198,152,190,208,9,2,235,109,200,122,245,227,228,239,223,82,93,192,249,187,201,251,239,27,236,1,26,51,132,216,28,165,58,152,143,206,167,171,129,237,91,58,162,198,249,24,18,89,15,
1,43,98,129,101,140,105,33,157,34,176,64,34,235,135,201,123,151,161,34,174,0,203,3,51,129,103,145,143,136,49,166,28,203,2,159,1,254,133,206,171,69,232,6,102,211,86,14,170,143,236,135,10,188,63,12,156,
132,5,150,49,166,69,116,146,192,2,137,172,239,39,239,255,153,52,247,213,142,232,206,251,62,96,169,65,28,163,49,157,198,36,96,95,36,164,230,161,115,233,105,36,70,86,109,221,176,250,149,125,144,200,122,
9,11,44,99,76,139,232,52,129,5,18,89,167,39,159,93,78,106,201,58,52,121,239,175,192,184,65,26,163,49,157,192,218,192,231,80,36,224,2,116,158,204,69,149,15,222,207,208,204,86,176,47,178,200,85,72,235,37,
246,194,81,132,198,24,147,82,33,141,18,154,128,146,13,206,67,37,50,166,0,95,2,238,68,19,236,125,45,24,159,49,237,192,122,192,94,40,165,194,122,201,123,47,161,104,192,203,209,141,200,107,173,25,218,160,
48,19,69,23,14,3,150,104,102,3,182,96,25,99,250,66,39,90,176,78,72,222,191,137,52,219,123,204,71,81,142,158,55,80,157,66,99,186,129,119,0,159,64,133,142,31,65,231,72,40,53,245,117,84,210,102,40,90,170,
178,216,9,229,198,155,73,157,37,66,91,176,140,49,70,156,4,156,8,220,136,178,56,103,37,59,60,23,184,13,165,116,56,3,69,66,29,73,63,229,198,49,102,16,24,134,28,208,151,6,38,34,75,109,150,111,225,120,224,
157,40,155,249,148,228,189,133,200,114,123,42,242,179,186,119,128,199,218,110,236,130,74,103,77,71,214,186,47,20,53,182,192,50,198,24,56,25,89,181,254,6,124,128,226,76,210,15,161,59,246,239,34,43,214,
78,40,205,195,119,208,196,107,204,96,179,36,74,222,185,2,176,92,242,188,124,242,122,197,228,179,101,163,71,79,3,219,254,39,58,55,110,64,229,108,222,232,175,65,119,24,187,34,113,245,34,176,29,176,91,189,
14,22,88,198,152,110,231,20,228,91,245,87,96,119,202,149,198,121,19,89,174,126,139,44,95,39,0,159,66,86,173,111,163,73,216,152,70,25,139,74,178,44,131,196,81,16,68,147,144,197,105,82,205,235,240,60,170,
96,155,175,162,227,241,101,180,188,55,29,249,75,189,138,150,185,102,37,207,181,204,69,233,8,108,157,133,15,163,154,165,207,33,113,245,68,153,78,22,88,198,152,110,230,115,200,10,245,23,224,255,161,139,
74,35,92,151,60,182,69,5,97,63,135,10,214,158,133,82,62,60,221,111,35,53,157,194,50,72,244,76,72,30,75,162,229,182,37,209,146,220,82,201,235,101,169,22,82,203,32,129,85,196,60,36,140,102,36,143,199,162,
191,167,3,207,35,241,244,34,42,59,51,61,233,99,154,103,47,224,2,148,11,111,59,224,201,178,29,45,176,140,49,221,72,88,34,57,2,184,18,216,131,198,197,85,204,245,201,99,107,36,180,62,3,124,26,21,137,61,7,
248,99,31,183,111,6,151,73,72,8,197,143,241,84,251,44,45,75,181,56,10,214,166,225,25,219,203,98,14,178,14,77,7,30,0,94,73,254,126,37,122,255,1,107,234,227,0,0,32,0,73,68,65,84,101,82,49,245,106,210,199,
12,30,123,35,113,245,36,18,87,255,105,164,179,5,150,49,166,27,217,46,121,190,19,45,11,206,239,167,237,222,136,202,234,108,6,28,134,146,18,238,128,46,142,23,32,177,117,79,63,125,151,41,102,34,138,130,95,
14,9,166,137,164,75,108,225,117,176,50,45,21,189,110,164,184,119,176,28,189,2,60,78,42,140,94,77,30,175,33,127,190,215,146,199,171,201,223,179,177,224,110,119,118,1,126,141,126,227,109,208,242,96,67,88,
96,25,99,186,145,123,129,247,162,16,235,237,208,18,97,127,114,71,242,56,6,229,10,250,56,240,73,228,167,117,15,138,70,188,2,93,148,77,227,12,71,197,184,167,36,143,213,80,166,240,149,80,73,163,85,168,159,
16,118,14,242,63,154,133,4,207,243,201,235,87,163,247,106,31,51,163,215,47,163,168,58,51,52,185,9,248,59,176,37,74,207,114,106,163,27,176,192,50,198,116,35,193,113,119,58,112,41,90,10,184,116,0,190,103,
14,112,94,242,88,19,77,212,7,3,63,72,30,207,160,165,197,235,146,231,127,15,192,24,58,145,209,192,219,129,117,146,231,21,73,35,228,38,39,175,71,214,244,89,136,252,142,158,1,238,71,203,57,207,32,159,164,
153,164,86,165,240,186,191,172,150,102,104,242,26,202,68,127,25,10,132,25,15,124,190,145,13,88,96,25,99,186,153,3,128,95,160,178,30,251,32,95,169,129,226,81,224,139,40,228,125,27,100,57,219,54,25,195,
193,73,155,199,80,170,136,91,128,219,81,74,136,202,0,142,169,213,12,3,214,2,54,72,30,235,37,207,171,83,237,203,84,65,66,233,37,180,79,174,5,158,66,190,49,79,37,143,103,81,249,18,99,250,139,55,128,15,162,
155,175,19,144,239,230,9,101,59,91,96,25,99,186,153,103,145,216,185,14,137,172,125,129,75,6,248,59,23,33,129,112,109,242,247,146,200,57,126,219,228,113,8,90,82,4,89,91,110,139,30,119,209,185,97,243,195,
145,53,106,227,232,177,33,213,25,243,103,33,135,239,27,128,7,147,215,15,163,229,59,47,199,153,86,240,6,74,182,122,41,112,60,186,41,56,174,76,71,11,44,99,76,183,243,12,18,54,65,100,29,140,28,210,7,139,
215,145,63,214,21,201,223,75,2,239,2,166,2,155,39,143,157,162,246,51,80,62,163,135,81,169,146,105,201,235,39,41,151,195,107,48,88,30,249,69,5,65,181,9,202,10,30,167,33,120,18,229,30,187,27,37,179,124,
0,167,181,48,237,201,155,200,146,245,91,148,138,101,24,186,57,43,196,2,203,24,99,228,251,180,21,178,42,157,135,38,208,95,181,104,44,175,147,166,125,8,172,133,132,214,250,192,218,200,55,233,64,122,251,
33,189,138,162,157,254,131,252,145,254,141,114,34,205,160,58,220,63,188,110,102,249,113,20,242,137,90,25,57,149,175,132,28,204,167,32,81,181,26,213,66,170,130,156,249,47,67,98,234,110,100,137,123,181,
137,239,54,166,85,204,67,1,43,23,3,199,2,183,214,235,96,129,101,140,49,226,5,148,82,225,58,20,229,87,65,245,198,218,129,96,169,138,25,137,124,149,214,65,2,44,8,158,21,144,47,211,118,244,22,96,181,204,
69,119,231,179,145,211,247,236,140,54,35,145,85,109,2,138,204,27,147,179,173,23,144,47,212,165,164,254,81,143,162,168,201,89,117,198,97,76,39,48,31,5,196,92,76,90,42,39,183,236,144,5,150,49,198,164,60,
135,18,132,254,5,248,81,242,220,174,62,79,11,208,82,225,35,57,159,247,144,70,222,45,93,243,88,6,9,166,177,40,98,111,34,18,82,227,51,182,51,23,57,151,207,70,254,40,179,145,85,236,105,82,107,217,147,56,
175,147,233,14,230,3,135,163,101,251,209,104,57,63,179,232,181,5,150,49,198,164,108,136,172,86,115,80,2,210,118,21,87,101,168,32,231,240,231,91,61,16,99,134,16,147,208,114,119,168,255,120,71,94,195,97,
131,50,28,99,140,105,127,54,2,174,65,150,156,29,80,36,155,49,198,4,38,161,192,140,77,41,145,210,197,2,203,24,99,20,233,118,13,178,234,239,132,50,56,27,99,76,96,57,148,163,110,19,84,145,225,230,122,29,
44,176,140,49,221,206,38,192,213,104,62,124,63,202,55,101,140,49,129,229,80,132,241,122,40,71,221,79,202,116,178,192,50,198,116,51,27,163,168,193,97,192,142,40,123,186,49,198,4,150,71,115,196,219,129,
143,161,8,227,82,88,96,25,99,186,153,115,81,102,245,29,128,59,91,60,22,99,76,123,177,2,18,87,235,32,113,117,94,35,157,29,69,104,140,233,70,166,36,207,243,80,22,247,251,90,55,20,99,76,27,178,18,18,87,171,
161,164,190,23,54,186,1,91,176,140,49,221,200,242,201,243,139,40,143,147,49,198,196,172,138,42,22,204,70,5,198,27,198,2,203,24,211,141,4,95,171,181,145,243,234,178,45,28,139,49,166,253,184,5,5,189,140,
64,101,171,222,213,232,6,44,176,140,49,221,204,151,129,119,0,55,34,127,11,99,140,9,220,138,74,78,85,80,254,171,205,26,233,108,129,101,140,233,102,46,6,14,67,150,172,235,209,146,128,49,198,4,238,66,65,
48,139,145,200,218,188,108,71,11,44,99,76,183,115,14,114,98,93,3,137,172,201,173,29,142,49,166,205,184,27,120,31,176,16,213,39,221,162,76,39,11,44,99,140,129,223,0,7,1,111,67,34,235,173,173,29,142,49,
166,205,184,7,137,172,5,40,49,241,26,245,58,88,96,25,99,140,184,16,56,0,88,29,137,172,149,90,59,28,99,76,155,241,79,96,107,224,53,148,209,189,16,11,44,99,140,73,185,24,248,40,176,38,42,246,188,76,75,71,
99,140,105,55,30,66,62,89,149,228,239,13,242,26,90,96,25,99,76,202,104,96,159,228,245,229,192,140,22,142,197,24,211,158,236,129,230,10,128,199,243,26,89,96,25,99,140,24,5,252,22,248,0,240,93,224,24,210,
187,84,99,140,1,56,9,248,95,224,137,228,239,55,242,26,186,84,142,41,203,36,224,255,50,222,191,149,6,235,51,25,211,134,140,6,126,135,196,213,183,129,227,90,56,150,113,72,224,213,114,7,240,243,65,30,139,
233,205,198,192,225,25,239,95,128,242,169,153,161,203,201,192,87,128,191,1,87,1,95,47,106,220,110,2,235,83,200,129,172,136,189,235,124,190,25,240,185,156,207,110,4,126,148,188,62,22,56,24,184,2,248,34,
190,83,173,199,56,224,19,25,239,143,164,111,2,107,79,234,255,166,49,11,128,89,192,51,40,211,238,45,40,63,137,49,205,50,22,184,20,69,8,157,6,156,208,64,223,45,129,163,27,104,255,42,240,18,10,251,190,22,
149,225,168,101,52,217,231,218,56,134,158,192,218,27,248,60,114,30,62,18,213,134,108,119,86,35,251,247,185,135,190,9,172,207,35,241,86,150,55,209,92,248,40,242,23,188,191,15,223,109,234,115,10,240,37,
148,11,107,119,116,188,246,105,99,21,6,55,146,230,188,228,59,139,30,245,216,163,160,111,16,2,107,161,139,114,120,127,187,126,251,15,122,51,17,89,127,38,13,224,119,12,54,31,36,221,119,231,244,113,91,95,
165,254,111,94,244,152,134,46,140,166,253,248,10,250,141,222,214,234,129,100,16,198,182,62,112,77,242,58,203,66,91,143,253,105,254,216,157,13,156,74,234,203,145,197,251,163,246,231,55,49,190,118,102,12,
18,9,225,255,59,162,181,195,105,138,147,233,191,241,95,78,243,199,82,5,137,172,181,251,56,6,147,205,215,209,62,190,18,29,183,32,35,77,5,85,130,104,152,86,8,172,192,100,100,169,8,7,206,183,154,220,206,
3,72,72,213,30,116,43,1,243,163,237,55,92,99,168,1,94,142,190,103,168,248,188,245,167,192,138,9,150,196,10,186,187,175,101,9,116,108,124,24,213,146,11,109,23,1,123,245,227,56,76,255,208,9,2,235,239,201,
243,137,253,176,205,189,73,143,201,167,51,62,159,0,188,19,249,111,188,30,181,189,5,88,50,103,155,67,89,96,141,160,122,126,60,160,181,195,105,138,254,20,88,49,127,140,182,251,141,140,207,199,163,116,34,
135,163,99,45,180,157,65,65,84,155,105,152,30,224,123,104,223,94,65,42,174,160,132,192,106,215,11,254,115,72,41,6,62,130,28,80,27,97,11,96,93,224,102,224,145,154,207,254,131,46,210,231,3,135,0,119,54,
53,74,51,216,188,137,142,141,223,163,165,153,27,146,247,135,1,63,197,5,123,77,121,130,213,104,115,100,246,255,223,65,248,206,89,192,189,72,204,109,139,142,103,128,169,192,15,7,225,251,219,141,133,192,
174,192,175,144,207,219,111,90,59,156,142,226,53,228,100,125,22,50,16,60,155,188,63,9,221,244,246,180,104,92,67,137,30,116,94,126,26,185,16,236,14,204,109,100,3,237,42,176,160,218,215,96,57,100,53,105,
132,67,147,231,159,229,124,126,25,202,220,108,7,237,206,100,1,42,212,27,152,0,236,219,162,177,152,206,99,251,228,249,102,234,56,170,14,16,119,2,63,137,254,62,24,249,246,116,27,183,163,27,232,111,99,95,
202,102,121,9,248,78,244,247,166,201,195,244,141,189,128,79,162,253,123,32,90,245,106,136,118,22,88,87,0,47,68,127,31,154,215,48,131,241,200,92,63,11,69,6,153,161,201,237,84,59,197,150,46,194,105,186,
158,107,146,231,45,233,159,229,193,102,248,83,244,186,7,45,7,26,211,12,55,213,252,237,185,176,239,252,22,248,62,50,240,92,72,177,175,100,38,237,22,69,24,179,0,248,37,112,124,242,247,142,192,42,40,122,
172,30,251,32,159,134,51,40,200,81,209,15,188,21,120,59,202,246,252,26,138,230,120,156,246,190,19,27,143,150,78,87,6,134,163,113,63,66,65,178,180,54,102,33,48,19,88,62,249,187,145,37,194,113,192,38,232,
228,169,0,211,129,127,208,252,241,178,6,202,254,189,20,242,175,121,2,101,252,237,43,43,34,191,157,49,192,83,192,125,100,31,95,19,128,13,209,190,152,129,124,139,230,244,195,247,15,85,194,221,232,45,40,
175,205,88,26,139,30,236,15,158,170,249,123,149,6,250,14,67,199,239,42,232,120,120,152,254,57,222,154,97,9,116,140,134,57,229,245,100,44,79,48,112,209,217,227,169,62,127,103,160,125,240,108,81,167,26,
222,2,172,151,60,15,3,94,65,145,120,47,246,235,72,7,135,151,107,254,110,100,46,92,14,249,17,45,131,150,192,158,7,238,66,190,173,141,50,44,217,214,202,232,156,154,9,252,139,198,126,151,60,214,68,215,174,
133,232,154,245,88,78,187,201,200,15,109,2,240,111,100,45,94,216,196,247,85,80,46,188,57,200,63,248,82,224,255,145,46,237,247,137,86,58,185,7,106,163,253,202,222,105,222,150,180,175,13,121,221,12,157,
136,181,143,172,180,14,127,203,104,247,96,242,217,74,200,9,113,81,52,182,216,33,255,132,168,79,60,254,172,239,14,147,250,103,115,62,207,58,81,238,204,104,247,253,130,253,241,22,228,128,121,53,213,193,
3,241,227,113,100,14,45,179,118,223,42,39,247,90,122,208,193,31,250,92,84,162,207,122,200,170,57,151,222,251,224,77,84,42,101,157,146,227,29,1,28,134,78,246,172,125,250,20,58,65,243,238,124,226,227,36,
126,108,140,4,213,25,84,7,99,84,208,49,184,107,180,141,225,200,209,118,118,77,187,57,40,236,187,149,116,130,147,251,122,40,236,186,47,193,52,129,122,78,238,181,172,70,245,111,118,114,70,155,44,39,247,
93,81,244,108,237,241,118,23,18,58,181,28,68,246,113,22,30,181,75,235,123,231,180,123,190,166,221,178,200,7,40,118,216,143,31,255,1,126,128,82,239,196,171,37,203,228,108,255,204,140,177,215,178,33,178,
252,205,203,249,206,103,146,237,228,89,112,214,64,243,204,63,114,250,87,144,101,124,215,156,254,181,180,202,201,189,150,13,168,254,31,62,91,162,207,14,200,242,149,117,29,155,1,156,78,121,161,182,20,242,
99,124,49,99,91,225,216,252,48,249,215,151,139,201,62,38,64,130,233,207,25,219,188,22,25,56,2,19,145,203,79,237,53,238,57,36,140,250,194,215,72,35,53,67,64,74,199,70,17,198,220,72,245,5,171,222,178,230,
250,73,219,187,51,62,91,23,137,140,171,209,221,78,216,238,87,50,218,158,153,180,187,38,106,247,44,186,88,60,139,132,211,67,72,236,204,138,218,124,27,249,20,132,239,137,47,144,215,68,239,135,199,71,146,
239,59,32,122,47,22,13,203,101,140,237,220,164,221,63,163,118,63,45,216,39,95,137,218,77,3,142,66,147,222,150,200,201,255,15,209,231,127,160,190,101,179,93,4,214,186,84,159,72,245,38,149,131,72,39,230,
39,129,255,65,14,198,83,145,35,227,51,201,103,115,169,239,207,181,20,250,13,98,113,247,33,116,87,189,51,218,47,65,92,223,70,246,239,24,31,39,211,163,109,77,69,199,202,98,20,9,123,27,186,19,12,159,47,2,
118,65,147,213,249,201,123,79,36,237,158,171,217,39,173,76,152,217,9,2,235,109,72,0,255,41,249,251,59,69,157,234,208,168,192,138,197,83,5,249,97,21,181,57,63,249,142,5,232,120,184,13,89,52,23,70,109,102,
32,203,122,204,206,244,158,243,94,38,61,246,118,168,105,191,125,244,89,72,163,112,29,114,219,8,76,70,55,101,225,127,61,14,165,187,217,12,93,72,127,69,245,133,59,190,16,78,136,182,127,119,212,230,151,89,
59,41,226,19,164,23,207,105,40,15,209,84,224,189,168,240,238,13,84,239,207,44,191,221,63,69,159,223,136,230,221,169,201,255,124,36,105,116,242,98,178,175,11,181,180,139,192,250,40,213,255,251,150,5,109,
135,161,235,84,104,123,27,242,49,218,12,237,203,175,161,149,141,32,78,234,229,230,90,19,173,222,84,208,252,122,58,218,159,239,66,199,107,60,79,158,71,118,192,218,215,201,190,102,174,128,142,179,121,72,
164,221,69,245,205,241,115,192,20,52,31,255,131,234,57,51,190,46,47,68,129,37,125,225,164,100,91,127,67,34,107,72,8,172,131,169,62,112,234,249,41,156,158,180,59,170,78,187,79,71,219,44,58,145,70,82,253,
99,94,159,60,226,139,198,4,82,33,248,237,154,254,205,164,105,136,45,34,89,23,230,192,238,81,187,50,2,235,78,180,52,150,197,167,162,109,125,181,206,248,218,69,96,253,34,106,63,131,226,194,188,31,34,21,
60,255,68,191,89,45,75,163,147,51,136,152,188,99,109,56,213,194,251,127,114,218,237,31,125,231,63,40,94,195,143,115,224,92,148,140,49,182,164,141,70,162,63,180,185,39,217,254,75,84,231,113,235,73,198,
19,218,189,134,150,83,90,65,167,8,44,208,164,31,46,106,103,208,92,20,86,163,2,235,156,168,253,92,178,207,245,88,96,93,141,230,147,227,168,190,72,173,130,142,135,208,238,71,100,179,46,233,241,248,42,249,
115,65,32,172,32,220,154,241,89,16,246,51,209,114,80,22,241,57,247,246,156,54,59,71,227,46,18,88,251,69,237,110,205,25,123,15,178,152,133,118,89,86,139,32,176,206,37,251,55,30,158,124,22,182,177,83,193,
152,160,61,4,214,40,170,111,182,239,160,248,248,61,37,106,123,1,250,159,107,89,159,244,166,110,6,18,49,89,44,67,245,141,105,86,162,240,30,210,235,114,133,252,192,179,64,124,179,121,17,112,9,213,150,180,
183,32,145,19,218,156,133,82,41,220,67,117,74,166,49,201,119,197,251,165,175,156,144,108,235,38,224,11,12,1,129,53,150,106,37,250,219,130,182,163,209,4,244,6,50,23,22,209,140,192,170,160,187,192,37,50,
218,237,68,251,11,172,29,235,124,239,29,164,147,230,152,130,118,173,22,88,171,2,103,71,109,103,82,156,44,118,2,242,175,168,160,9,127,195,130,182,239,142,182,251,34,217,249,137,142,137,218,92,147,241,121,
204,133,81,219,175,21,180,139,5,214,28,178,47,90,163,169,54,193,207,38,95,4,94,23,181,251,112,157,49,14,20,157,36,176,64,23,170,96,205,61,147,198,69,86,35,2,235,195,84,91,120,78,201,105,87,107,229,170,
157,95,2,91,69,109,254,83,240,189,215,71,237,14,171,51,198,112,81,60,168,230,253,97,164,86,246,171,235,108,227,102,250,46,176,150,39,181,168,204,71,22,147,60,198,144,158,35,121,2,107,1,197,75,95,227,163,
239,171,151,153,189,213,2,107,19,170,111,246,166,81,28,141,186,25,233,113,55,157,226,155,175,248,70,237,186,156,54,23,68,109,78,45,216,214,8,82,43,87,5,149,164,202,35,22,88,15,146,109,241,90,59,106,243,
6,186,6,100,105,149,37,168,190,6,55,226,231,152,199,241,201,182,130,143,97,71,11,44,168,190,115,159,135,20,108,22,251,80,255,78,40,208,172,192,250,72,78,187,49,232,96,175,221,95,237,32,176,86,67,217,206,
235,45,253,125,51,218,222,54,5,237,6,67,96,205,70,86,159,248,113,31,213,75,96,79,162,37,157,201,117,182,27,78,136,10,114,106,174,71,236,159,113,76,205,103,35,209,5,172,172,120,217,58,106,59,147,252,9,
45,22,88,231,22,108,239,247,81,187,162,210,24,95,138,218,101,249,246,12,6,157,38,176,64,147,249,37,201,103,141,90,178,98,129,245,60,154,15,226,199,102,104,142,186,144,106,113,245,107,178,173,8,80,45,176,
22,146,6,116,212,18,156,203,67,219,165,115,218,237,21,181,185,167,224,127,25,139,44,23,211,233,109,121,157,16,109,227,1,138,247,209,254,200,194,176,98,206,231,101,4,214,169,81,155,63,23,124,87,224,23,
228,11,172,13,209,146,96,61,130,16,93,128,150,159,242,24,12,129,245,60,189,231,194,7,73,111,26,23,33,11,214,241,212,183,74,198,243,199,233,117,218,142,67,226,37,180,175,221,111,171,147,46,79,47,38,223,
146,25,56,46,218,214,223,11,218,197,2,171,168,28,77,60,15,23,149,144,186,52,106,87,36,236,26,225,243,209,54,183,200,107,212,206,105,26,98,226,157,55,138,124,145,19,82,57,12,100,189,174,171,114,222,159,
139,214,135,139,238,30,91,197,147,232,46,167,94,36,197,204,232,245,234,3,55,156,82,140,32,45,49,52,9,9,205,117,72,39,234,105,104,66,249,44,18,93,69,196,19,109,153,165,199,216,42,181,71,205,103,155,81,
237,227,146,119,103,23,184,133,52,234,100,2,105,254,165,34,110,47,248,44,118,52,46,50,121,199,237,156,128,181,60,243,73,211,39,108,75,190,80,169,199,10,244,190,40,222,142,196,213,62,104,238,125,4,249,
64,238,79,185,136,173,199,201,143,112,91,132,150,139,3,121,191,249,31,73,143,141,13,201,191,56,236,71,154,180,178,182,62,224,44,82,7,228,117,145,85,45,203,170,15,18,143,135,211,219,65,190,17,226,115,176,
222,249,70,50,158,195,201,22,144,255,36,123,201,179,150,89,201,243,8,250,199,234,209,23,198,80,61,23,78,70,115,97,56,54,111,70,254,105,167,81,28,57,60,26,249,110,6,234,205,133,115,144,47,83,160,118,46,
220,141,244,198,224,81,20,177,87,68,60,175,110,78,253,27,99,40,63,199,21,205,153,113,186,167,254,154,11,255,66,122,94,76,201,107,212,206,105,26,98,238,68,214,139,96,138,251,56,189,157,81,87,67,203,68,
211,24,184,138,230,175,211,153,33,188,129,73,72,193,111,136,44,109,227,145,69,38,48,37,122,157,229,163,52,152,252,157,222,98,100,52,250,237,191,135,252,67,46,70,203,110,69,62,99,163,145,245,32,80,155,
213,63,139,135,163,215,155,161,243,36,136,211,248,130,244,34,242,101,41,98,17,10,39,14,229,43,166,162,139,92,17,69,130,113,70,244,186,168,93,28,182,93,180,220,107,170,217,15,89,131,31,65,243,201,43,77,
110,103,38,217,181,13,23,162,59,244,187,144,21,162,210,192,54,235,133,186,191,66,186,60,148,39,120,22,160,255,47,156,51,71,145,109,77,56,10,89,37,206,202,217,206,153,200,226,12,114,246,221,31,101,98,255,
13,169,5,184,63,88,154,106,191,154,50,231,239,191,146,71,17,171,34,177,17,210,19,76,164,218,18,23,71,99,182,122,46,60,19,249,251,196,44,131,18,45,31,131,172,228,183,32,235,100,209,220,178,17,213,115,193,
195,121,13,107,218,4,231,240,90,11,86,252,119,153,223,165,182,205,84,234,231,169,44,59,23,22,9,248,254,158,11,55,162,122,105,252,129,188,134,157,34,176,64,86,169,144,138,224,237,192,123,168,94,238,249,
40,186,43,12,142,163,3,193,107,3,180,221,129,102,36,10,161,61,150,242,201,210,218,177,212,194,60,148,253,122,30,169,163,228,87,80,244,80,222,157,237,50,84,139,200,25,57,237,98,226,139,234,104,52,201,7,
235,64,188,68,83,102,91,181,219,91,161,68,251,151,10,62,139,115,96,149,109,103,202,241,49,36,62,166,33,113,213,23,171,203,108,180,228,222,159,212,187,185,43,155,247,236,167,72,28,141,64,23,229,99,145,
232,11,108,142,34,199,174,64,126,38,89,156,140,206,173,195,147,191,87,0,62,147,60,158,67,203,50,231,32,177,213,23,150,167,122,46,42,123,206,229,177,44,42,127,178,15,229,231,184,118,156,11,95,65,251,122,
28,242,165,27,129,34,244,214,33,255,184,173,157,123,234,221,28,134,239,201,235,223,232,92,248,6,178,230,7,241,159,183,108,28,83,118,142,43,58,55,98,235,112,95,127,203,141,81,90,151,17,232,230,227,232,
162,198,157,178,68,8,114,166,139,77,213,113,102,247,225,72,96,45,96,96,75,223,12,148,112,27,72,122,80,36,198,23,144,88,120,2,165,32,88,21,9,143,158,232,241,197,156,109,180,27,231,80,45,174,191,75,254,
137,83,235,147,80,187,220,145,69,109,155,37,115,94,151,217,22,84,215,175,202,43,234,27,83,86,28,89,68,245,31,31,39,181,92,109,75,223,196,213,64,209,76,226,199,44,254,67,186,12,26,172,194,49,33,2,251,140,
130,109,204,67,62,71,91,160,136,194,56,249,226,100,228,59,115,39,90,142,91,187,87,239,242,212,158,191,13,151,43,137,88,10,173,110,236,139,230,139,155,80,224,207,100,170,231,193,30,234,91,153,219,133,227,
73,45,52,33,23,85,30,125,157,11,107,231,174,193,152,11,203,30,243,131,49,23,110,130,44,87,195,145,111,100,221,72,225,78,18,88,175,160,8,159,192,94,164,206,135,239,71,75,94,127,166,122,189,117,168,147,
231,24,27,179,59,169,15,210,44,20,109,116,17,10,173,109,38,187,109,59,80,161,58,231,213,59,145,63,64,22,179,106,254,30,91,98,251,181,109,102,230,188,206,91,134,169,37,158,216,102,230,182,50,173,226,48,
20,149,122,63,90,110,233,134,57,36,22,79,135,147,206,37,203,162,185,245,41,224,202,18,219,185,13,69,25,46,135,150,9,67,148,94,96,11,100,197,218,172,201,113,214,158,191,101,207,185,44,190,64,26,205,120,
55,202,255,117,53,237,41,166,203,50,147,234,232,228,67,208,205,115,22,205,236,203,120,46,172,157,187,154,153,11,227,237,149,177,160,181,11,83,209,42,201,48,164,55,138,124,190,254,75,39,9,44,168,142,88,
27,135,252,37,32,189,3,171,151,95,163,83,136,45,101,69,97,180,101,124,3,226,40,183,223,83,223,33,188,83,184,157,234,11,192,87,201,182,98,189,66,245,210,73,94,20,86,76,108,10,159,69,245,68,18,151,106,42,
179,173,218,237,149,201,143,100,6,143,253,144,169,255,62,20,105,91,91,114,100,168,114,45,169,79,204,20,82,231,231,143,35,63,149,179,104,204,98,246,58,242,191,218,13,5,129,156,66,106,173,88,18,57,96,55,
195,115,84,223,8,22,69,85,215,99,207,232,245,89,148,183,186,180,59,103,147,206,235,35,201,95,137,168,45,51,215,232,92,88,59,119,61,147,211,46,143,165,169,118,81,41,83,246,174,29,120,15,186,214,44,66,162,
188,116,62,173,78,19,88,215,82,93,191,235,80,116,144,124,16,57,128,254,165,5,99,26,8,226,122,120,69,201,51,203,152,222,227,8,152,167,234,180,237,180,227,33,54,135,111,132,18,27,214,178,136,234,229,196,
245,75,108,55,110,115,51,213,230,231,184,168,234,68,234,135,38,143,163,58,47,77,109,81,86,211,90,78,70,209,102,221,36,174,32,205,245,21,56,10,157,255,135,35,225,81,148,126,101,24,10,152,201,179,6,79,71,
190,145,7,70,239,109,74,115,243,203,28,20,16,16,88,175,68,159,53,208,239,89,91,46,167,145,185,176,204,234,64,187,48,151,106,127,191,67,200,142,124,252,23,213,190,82,141,206,133,181,193,99,241,223,101,
126,151,184,77,237,188,220,174,108,137,196,213,60,148,186,168,33,159,194,78,187,160,46,166,58,71,208,166,40,154,112,100,242,126,127,249,40,244,39,241,93,82,237,73,187,30,90,215,173,13,5,143,29,246,138,
46,224,101,234,101,197,190,17,245,114,154,229,153,150,219,149,219,169,22,213,121,86,172,95,69,175,119,201,105,19,232,65,185,121,178,250,130,38,169,184,12,211,46,20,179,35,105,48,201,83,12,92,132,171,105,
140,112,241,125,16,69,171,54,27,45,216,201,156,71,122,51,183,35,170,230,176,26,138,236,42,114,46,94,5,93,168,127,82,103,251,127,36,181,98,141,165,58,216,164,17,226,115,176,94,102,117,144,47,221,213,244,
206,161,20,223,184,214,155,11,91,157,154,161,81,98,43,214,40,122,71,29,130,174,159,23,68,127,215,187,126,172,64,26,129,189,8,165,220,136,249,35,178,92,130,252,216,138,18,56,215,126,223,165,244,94,178,
108,55,182,66,215,151,5,40,232,229,190,70,55,208,105,2,11,122,11,169,3,208,129,211,159,9,47,251,147,56,180,186,54,97,221,245,100,251,39,196,23,240,60,223,162,3,41,103,193,138,205,153,219,144,127,103,182,
20,242,215,234,52,98,43,214,198,100,39,146,187,136,180,80,247,90,20,255,159,31,38,205,1,118,31,217,97,196,39,69,175,63,67,254,133,163,135,234,66,226,95,163,115,253,222,134,26,193,239,102,50,5,121,108,
134,56,175,162,101,61,208,181,32,164,190,41,114,110,143,217,150,98,209,52,145,116,73,232,17,154,95,146,59,151,212,226,180,5,90,178,201,99,3,210,114,45,103,215,124,118,103,244,250,125,5,219,216,144,38,
179,115,183,144,185,84,47,195,126,140,108,145,248,109,210,104,248,189,40,206,250,126,44,169,70,56,15,229,97,139,153,129,82,230,4,142,47,216,214,68,210,192,180,5,228,87,46,104,39,30,71,1,33,19,168,47,30,
51,233,68,129,245,111,122,151,103,184,14,37,211,108,71,30,139,94,199,39,237,59,81,70,250,133,84,159,248,144,150,87,1,9,169,47,146,90,185,150,70,14,222,103,83,63,19,47,73,187,96,197,90,11,45,11,212,150,
30,152,136,74,16,117,98,66,202,219,168,78,254,154,101,197,90,128,194,178,195,196,114,54,213,121,110,2,27,145,46,155,204,70,209,70,89,86,209,203,80,205,51,144,200,253,25,189,211,95,12,71,23,172,144,43,
230,34,218,247,38,160,27,9,254,36,195,208,141,78,179,78,216,157,78,44,166,70,160,155,138,178,75,55,171,160,11,118,86,186,159,97,104,153,48,156,139,101,230,170,60,222,64,231,111,176,134,253,154,236,114,
57,43,162,121,108,88,210,166,246,255,248,126,244,122,95,100,177,171,157,43,214,68,249,245,58,145,179,73,111,28,70,161,108,227,181,60,131,132,206,98,52,103,253,142,108,95,172,125,145,192,2,229,194,170,
173,104,17,56,25,185,81,128,252,25,63,147,209,102,41,52,255,5,119,151,207,83,92,69,160,93,120,14,21,191,126,8,9,204,67,250,115,227,237,84,42,167,150,61,169,46,95,179,111,201,126,155,33,213,61,131,180,
150,86,168,101,20,222,15,85,200,127,22,189,23,218,45,138,222,155,65,185,172,220,219,145,22,60,125,20,149,11,248,2,18,138,21,242,11,179,198,197,49,195,35,84,182,95,140,44,35,113,169,156,185,209,184,106,
247,199,30,81,223,10,82,229,23,162,117,251,95,38,125,238,69,119,35,89,251,100,73,116,167,31,254,126,45,106,55,47,122,255,128,18,251,163,150,227,162,254,113,89,134,5,84,239,235,34,231,214,45,168,222,79,
175,38,125,106,29,250,55,162,186,48,233,249,168,100,210,167,73,211,128,84,208,221,114,150,0,139,233,65,21,224,67,201,147,71,209,57,115,56,178,112,221,23,141,231,44,178,239,244,247,136,254,191,184,130,
252,236,228,189,203,146,118,99,163,118,241,239,56,39,121,47,174,30,112,27,197,191,209,86,117,254,175,254,164,19,74,229,236,134,150,7,103,162,58,148,141,178,39,233,190,141,75,213,212,206,21,69,117,40,179,
120,132,226,223,49,248,198,108,23,189,183,32,106,27,178,173,215,171,21,8,58,102,26,41,247,50,153,234,227,112,26,186,225,56,22,229,5,58,13,221,88,134,207,107,211,168,44,67,253,185,228,224,140,239,157,138,
34,60,195,177,127,110,242,125,199,161,155,151,80,179,246,47,228,251,135,253,47,213,115,197,3,201,118,254,15,69,169,207,67,162,227,207,244,62,31,67,66,214,15,82,124,62,206,160,186,80,123,89,46,36,123,62,
120,51,122,255,222,58,219,136,235,164,46,140,250,93,86,211,110,47,210,227,245,101,244,251,125,18,237,203,171,162,109,220,68,126,105,186,192,146,84,151,246,185,21,93,227,142,4,190,69,90,210,102,30,18,181,
89,156,18,141,53,92,47,43,209,123,39,37,237,182,34,123,31,133,227,253,210,104,76,245,126,163,50,17,229,160,107,207,125,201,184,142,138,222,63,54,217,102,174,181,179,147,18,141,198,252,9,157,0,163,209,
78,254,67,113,243,255,242,58,213,14,147,89,4,43,199,147,37,218,206,46,241,157,215,33,43,212,137,200,130,20,204,184,175,160,11,116,94,222,146,99,209,69,251,24,210,187,181,49,201,152,78,65,7,244,84,178,
139,13,215,250,147,92,2,188,11,101,254,221,5,69,249,236,147,124,54,13,221,133,126,23,9,182,44,103,197,69,104,63,215,219,31,205,248,177,60,95,98,187,80,188,180,246,119,224,199,244,94,50,173,93,146,184,
7,77,124,159,66,255,255,254,164,162,112,113,242,249,69,72,244,190,73,49,21,100,89,188,8,137,221,157,80,253,191,192,76,52,81,159,78,126,105,142,25,20,255,239,33,202,107,113,157,118,113,110,153,7,40,78,
136,219,169,201,114,7,138,127,161,229,162,171,209,133,101,103,138,235,164,213,82,239,55,12,52,90,66,235,94,228,72,158,71,240,39,154,93,231,251,203,100,235,62,3,137,203,217,232,166,163,30,207,33,107,209,
94,104,127,109,142,10,3,199,204,64,150,160,31,209,59,176,99,33,245,247,89,86,192,193,173,104,46,60,6,9,219,67,72,173,10,11,145,187,197,153,232,166,49,47,103,225,137,201,118,142,67,23,235,117,147,199,226,
164,255,161,104,31,156,68,111,75,127,176,122,206,44,49,254,122,243,71,22,143,81,28,212,4,245,147,205,158,133,110,252,107,51,150,215,102,81,255,45,250,93,142,67,55,25,241,239,55,31,5,148,157,131,68,95,
189,28,83,175,163,107,199,174,72,84,109,75,117,197,139,103,147,113,157,70,126,226,218,255,80,188,79,131,171,205,107,117,218,77,75,158,23,213,105,7,229,115,103,189,132,246,233,53,232,120,238,65,215,155,
62,209,206,22,172,78,101,89,228,223,179,18,141,101,148,93,58,233,87,175,144,103,25,134,35,129,181,58,173,47,1,209,106,150,64,203,28,43,211,183,252,58,129,240,251,46,71,123,102,127,30,108,58,193,130,21,
198,182,33,138,126,123,157,226,66,231,67,145,131,41,182,166,151,97,73,116,236,175,206,224,185,26,140,69,129,57,83,104,174,4,202,232,164,255,170,244,207,220,218,201,44,137,252,177,38,211,124,48,66,96,56,
114,144,95,29,185,159,12,21,38,33,159,230,197,72,144,214,181,96,21,97,129,101,140,233,11,157,36,176,64,203,194,47,33,145,181,93,43,6,213,34,110,69,251,162,76,216,190,49,221,204,68,20,189,190,152,116,89,
52,87,96,117,162,147,187,49,198,12,4,247,34,167,214,217,200,103,165,140,143,101,167,243,14,180,156,243,55,234,23,72,54,166,219,153,137,82,154,220,65,126,132,255,127,177,192,50,198,152,148,135,144,95,207,
88,228,187,216,137,145,181,89,108,140,124,140,106,211,19,132,52,34,63,28,220,225,24,211,177,204,66,73,173,131,143,111,110,4,178,5,150,49,198,164,172,140,28,88,23,162,26,133,67,37,187,251,120,148,52,242,
211,164,41,69,246,66,65,30,247,82,62,80,200,152,110,103,12,138,60,13,231,81,109,154,165,255,210,169,81,132,198,24,211,223,172,130,162,126,167,0,31,161,115,243,33,21,241,1,82,63,179,201,40,42,235,99,148,
143,168,50,166,155,25,141,34,48,119,1,110,64,1,49,121,17,171,22,88,198,24,131,34,201,174,67,65,61,123,49,244,44,58,15,163,192,165,141,81,94,163,55,209,18,232,143,232,29,194,111,140,233,205,88,228,216,
190,3,202,239,245,2,117,34,142,45,176,140,49,221,206,20,36,174,66,126,184,63,182,116,52,3,195,139,40,114,210,24,211,56,99,81,254,205,237,81,130,238,207,147,102,186,207,197,62,88,198,152,110,102,10,74,
184,248,86,100,185,26,138,226,202,24,211,60,227,72,163,138,131,184,42,133,45,88,198,152,110,230,2,148,219,102,79,122,151,19,49,198,116,55,227,128,203,209,82,224,137,168,246,98,105,44,176,140,49,221,72,
168,175,54,1,213,150,43,83,179,207,24,211,61,44,5,92,137,74,210,125,1,213,171,108,8,47,17,26,99,186,145,13,146,231,127,1,55,182,114,32,198,152,182,228,61,40,199,213,116,202,213,232,236,133,5,150,49,166,
27,185,46,121,222,20,184,148,254,169,69,105,140,25,58,92,9,236,135,92,8,110,70,181,26,27,194,2,203,24,211,205,252,24,120,63,154,76,187,189,224,175,49,166,154,223,1,123,160,226,213,55,160,2,214,165,177,
192,50,198,116,51,167,35,199,213,247,2,87,0,75,182,118,56,198,152,54,227,114,36,178,150,3,174,167,129,226,245,22,88,198,152,110,231,68,20,122,189,53,18,89,227,91,59,28,99,76,155,113,5,213,34,107,205,50,
157,44,176,140,49,38,205,111,179,21,90,46,92,170,181,195,49,198,180,25,87,2,187,163,2,240,55,2,203,215,235,96,129,101,140,49,226,155,192,241,40,122,200,34,203,24,83,203,85,192,206,200,149,224,200,122,
141,45,176,140,49,38,229,91,72,100,77,5,254,138,69,150,49,166,154,191,1,187,1,99,146,191,115,29,223,45,176,140,49,38,165,135,116,194,124,14,152,219,194,177,24,99,218,147,149,129,225,201,235,217,121,141,
44,176,140,49,70,244,0,63,2,142,64,225,217,251,0,243,91,58,34,99,76,187,241,49,224,28,224,229,228,239,151,243,26,90,96,25,99,140,196,213,143,129,163,128,139,81,130,193,5,45,29,145,49,166,221,56,20,248,
41,240,8,240,147,122,141,45,176,140,49,221,206,112,224,92,228,180,122,17,112,0,176,176,165,35,50,198,180,27,135,1,103,1,247,163,148,46,175,213,235,96,129,101,140,233,102,134,35,115,255,193,192,133,192,
129,88,92,25,99,170,57,28,137,171,251,128,247,81,176,44,24,51,98,32,71,100,140,49,109,206,105,40,34,232,28,116,135,186,184,181,253,179,26,121,0,0,9,162,73,68,65,84,195,49,198,180,25,71,160,229,192,123,
128,29,129,87,202,118,180,5,203,24,211,141,132,185,111,55,224,231,88,92,25,99,122,115,44,112,6,112,55,176,3,13,136,43,176,5,203,24,211,157,236,152,60,223,138,196,85,165,133,99,49,198,180,31,123,0,223,
1,166,163,101,193,153,141,110,192,22,44,99,76,55,114,75,242,252,110,224,35,173,28,136,49,166,45,185,12,184,4,120,11,240,13,20,105,220,16,22,88,198,152,110,36,68,0,61,134,34,8,143,106,225,88,140,49,237,
199,2,96,111,224,2,228,135,245,83,26,212,76,94,34,52,198,116,51,7,1,63,67,9,70,67,46,44,99,140,1,88,132,34,140,23,3,31,7,150,64,22,239,69,101,58,91,96,25,99,186,153,25,192,54,168,136,235,15,209,29,234,
15,91,57,32,99,76,91,177,8,248,40,18,89,7,163,57,226,160,50,29,45,176,140,49,221,206,171,200,233,253,42,224,251,104,2,253,126,75,71,100,140,105,39,22,161,18,57,21,224,16,52,71,220,89,175,147,5,150,49,
198,40,66,40,136,172,239,1,227,128,175,183,116,68,198,152,118,98,49,18,89,111,32,159,205,117,234,117,176,147,187,49,198,136,89,192,251,129,219,128,83,129,227,10,218,30,10,236,218,228,247,44,137,150,33,
39,54,217,127,75,224,179,77,246,237,65,194,177,238,197,33,135,85,80,232,122,179,55,231,159,0,118,105,178,239,88,180,223,150,105,178,255,214,192,103,154,236,219,3,156,2,172,215,100,255,85,233,219,126,251,
40,240,161,38,251,46,1,252,0,69,195,53,195,84,138,207,133,122,156,4,188,163,201,190,43,3,223,5,70,54,217,255,32,148,110,161,25,194,126,91,54,122,175,2,252,15,112,54,205,255,79,128,14,166,10,176,82,95,
54,98,140,233,90,190,130,230,144,183,181,122,32,25,20,141,237,67,201,103,47,82,61,185,6,142,68,119,179,243,104,252,162,55,30,184,41,217,254,63,128,165,27,236,255,94,20,1,89,1,190,212,96,223,97,40,18,170,
2,60,15,172,219,96,255,41,192,19,73,255,139,105,252,162,247,73,180,223,230,2,31,108,176,239,56,224,250,228,187,239,33,251,119,41,98,91,224,245,164,255,23,27,236,219,131,50,121,135,99,98,131,6,251,79,1,
158,76,250,95,68,227,34,235,48,180,68,53,15,216,189,193,190,99,129,107,146,239,190,31,88,174,193,254,91,1,179,147,254,39,53,216,183,7,45,181,87,80,46,169,13,27,236,191,42,240,120,210,255,247,52,126,188,
125,20,237,183,249,192,94,13,246,29,11,92,155,124,247,189,244,22,167,61,164,199,99,83,66,203,2,203,24,211,23,58,81,96,5,1,243,34,176,126,70,191,79,33,145,112,55,186,104,54,114,209,91,10,229,223,170,0,
127,140,182,83,214,34,19,68,194,139,209,118,190,90,178,239,48,84,14,168,130,150,65,195,118,202,138,133,213,129,167,208,255,251,231,100,59,191,163,252,69,239,104,244,255,222,21,109,167,236,126,91,18,184,
145,116,191,45,34,251,162,151,199,246,192,28,36,42,111,77,182,243,149,146,125,135,161,26,116,21,224,106,36,54,26,17,11,171,3,79,211,252,126,59,2,237,183,127,34,113,59,159,242,22,153,88,148,94,138,246,
219,191,128,229,75,246,127,47,58,78,94,2,110,78,182,243,181,146,125,123,80,100,110,5,9,149,89,168,126,223,198,37,251,175,70,122,126,93,78,250,219,143,42,217,255,80,244,255,222,15,76,67,41,23,246,45,217,
119,28,112,29,213,251,237,126,122,239,183,99,177,192,50,198,180,136,78,19,88,59,34,255,138,23,200,94,10,10,23,187,187,144,40,90,5,229,209,90,8,236,95,231,251,38,0,127,167,218,130,18,46,2,15,2,43,212,233,
31,132,223,11,72,248,197,150,137,255,171,211,119,56,240,139,164,237,133,200,130,178,37,18,11,51,128,77,235,244,159,66,122,177,219,141,106,203,196,229,192,232,58,253,63,147,180,189,11,89,236,26,217,111,
177,72,8,162,232,99,104,191,61,4,172,88,167,127,237,111,218,200,126,139,45,87,193,98,55,21,137,133,87,129,119,213,233,63,133,116,191,125,40,217,222,15,40,191,223,14,71,199,91,176,216,173,12,60,74,249,
253,22,68,194,137,201,123,251,34,161,241,48,48,185,78,255,173,73,111,52,54,64,203,101,127,77,182,247,173,58,125,99,113,117,25,250,63,55,65,101,102,94,5,54,171,211,127,85,36,38,131,8,239,1,78,79,182,119,
5,48,166,78,255,96,241,251,39,18,225,43,0,15,160,253,118,112,157,190,99,233,189,223,246,35,123,191,89,96,25,99,90,70,39,9,172,157,128,55,201,95,58,11,147,105,237,178,94,124,209,59,32,231,187,38,32,191,
174,10,240,133,154,207,202,136,133,60,225,55,22,89,85,42,192,55,115,250,14,7,206,75,218,252,154,234,229,169,32,22,102,144,47,22,214,4,254,77,239,229,208,30,20,12,80,65,150,153,188,139,222,103,169,191,
223,14,204,233,59,129,212,226,84,187,28,186,95,210,183,104,191,229,253,166,101,247,219,185,84,139,210,64,44,22,222,157,211,63,222,111,241,114,104,188,223,138,196,66,173,152,15,172,68,99,251,237,203,53,
159,237,131,196,194,35,228,139,172,96,185,10,98,62,48,26,248,83,178,221,111,231,244,13,185,228,42,192,111,169,182,212,109,140,246,219,76,202,237,183,218,229,247,83,147,237,94,137,4,95,22,159,64,231,83,
237,50,242,242,200,10,181,8,69,1,102,17,139,210,90,11,103,16,167,143,0,111,77,222,179,192,50,198,180,140,78,17,88,59,163,11,241,51,192,26,25,109,63,151,180,189,19,152,148,241,121,124,135,92,155,31,103,
34,112,59,186,88,126,58,103,44,65,44,100,89,22,234,9,191,209,164,75,40,167,213,124,54,28,248,85,242,217,207,201,14,106,218,4,9,172,44,203,194,218,192,127,144,207,212,7,114,198,254,13,242,197,194,113,201,
103,183,160,229,209,90,138,246,91,145,40,13,20,89,100,234,253,166,163,145,117,37,203,34,19,139,210,223,144,237,51,21,139,133,205,107,62,91,139,250,251,237,235,164,98,161,118,191,229,137,249,64,189,227,
45,236,183,60,95,179,189,233,45,22,2,239,71,98,62,239,120,27,133,150,205,42,200,186,23,151,143,137,151,161,243,124,205,54,66,75,133,245,246,91,158,143,94,208,37,87,209,91,100,5,81,154,183,236,190,28,112,
95,210,166,182,114,67,108,41,173,21,165,129,176,223,166,33,93,100,129,101,140,105,25,157,32,176,14,69,19,250,211,100,143,243,248,164,221,205,100,139,132,192,242,164,23,189,80,219,112,34,112,7,154,208,
143,174,51,158,172,59,228,122,34,33,16,139,133,96,89,24,142,74,124,84,80,166,250,162,136,241,96,145,137,47,122,235,0,207,34,223,165,29,234,140,61,182,44,4,177,112,2,233,126,27,95,208,119,121,228,23,20,
47,223,196,162,244,152,58,223,157,101,145,217,149,226,223,52,16,91,100,190,147,188,23,139,210,11,146,191,243,8,98,97,22,176,69,242,222,218,104,191,189,65,253,253,150,37,22,234,137,249,64,222,241,86,118,
191,237,69,181,88,128,84,204,255,27,89,146,242,24,5,252,33,25,231,153,72,100,101,45,67,231,177,33,125,219,111,39,39,223,243,55,228,159,7,169,216,9,203,208,121,188,5,249,239,45,70,65,23,160,243,58,207,
82,90,203,158,200,15,238,73,210,223,207,2,203,24,51,232,116,130,192,154,135,46,196,171,23,180,137,39,242,34,86,68,254,84,11,145,160,186,7,77,228,71,148,28,211,254,73,223,71,208,82,199,60,228,16,158,53,
182,90,198,32,43,82,16,11,191,79,94,159,65,185,34,181,155,34,75,214,76,180,132,242,34,90,38,218,182,228,216,79,35,21,89,225,218,113,3,178,12,212,99,5,170,247,219,221,84,95,0,235,17,246,219,195,104,95,
135,11,224,148,18,125,99,11,224,247,144,229,165,66,249,186,115,65,100,205,70,81,107,207,35,81,186,125,201,177,7,11,224,95,145,207,79,25,81,26,88,17,45,145,46,68,169,3,194,241,86,182,174,102,176,200,60,
138,142,183,50,162,52,16,139,172,31,3,231,39,175,207,163,88,148,6,98,113,122,8,90,142,108,100,191,5,145,117,29,178,56,85,144,143,227,132,18,125,151,37,221,87,159,35,181,248,149,77,125,242,97,116,140,189,
76,29,129,85,116,226,157,130,212,220,125,232,71,48,198,152,70,88,17,89,21,214,64,225,214,237,196,169,104,9,101,62,18,52,243,107,62,31,11,188,29,57,250,62,134,38,227,50,140,68,119,255,193,34,241,52,154,
136,203,50,9,69,80,245,32,129,53,45,99,108,121,244,160,139,99,184,200,76,71,214,175,178,140,69,99,31,129,254,223,199,72,139,98,151,225,173,164,206,250,125,221,111,207,160,241,151,101,105,36,168,154,221,
111,171,147,230,37,107,116,191,45,129,150,183,154,221,111,147,73,253,200,94,71,130,167,145,253,182,22,169,229,176,47,199,219,124,180,223,230,149,236,219,147,244,13,150,182,151,147,239,47,75,95,247,91,
152,95,64,251,237,49,74,214,8,76,190,115,77,116,204,131,172,118,47,53,240,221,19,209,49,211,3,188,19,233,164,94,20,9,172,163,144,249,220,24,99,250,194,135,144,111,69,59,113,40,242,17,90,64,254,133,120,
41,52,113,151,189,216,5,70,32,81,57,29,45,189,53,202,68,116,241,120,188,96,108,121,132,139,222,124,154,219,231,75,144,166,22,120,189,137,254,147,209,69,235,9,6,127,191,77,66,2,175,217,253,54,5,89,131,
254,221,196,119,143,65,251,237,25,154,219,111,43,34,43,233,227,180,230,120,155,140,4,74,51,251,109,85,52,230,70,68,105,96,9,116,188,54,187,223,86,64,214,190,102,246,219,112,180,223,102,208,152,152,15,
140,71,75,154,123,34,81,108,140,49,102,16,104,54,243,116,127,244,239,107,9,180,86,142,189,213,251,173,204,114,234,64,124,119,95,251,123,191,181,230,187,141,49,198,24,99,140,49,198,24,99,140,49,198,24,
99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,
24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,198,24,99,140,49,
198,24,99,140,49,198,24,99,140,49,198,24,99,134,6,255,31,58,133,142,62,148,238,131,16,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* TabPreferences::directivity2_png = (const char*) resource_TabPreferences_directivity2_png;
const int TabPreferences::directivity2_pngSize = 35442;


//[EndFile] You can add extra defines here...
//[/EndFile]
