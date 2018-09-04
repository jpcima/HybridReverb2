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
#include "Definitions.h"
#include "../MasterAndCommander.h"
#include "../PresetManager.h"
#include "../Param.h"
//[/Headers]

#include "TabPresetEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabPresetEditor::TabPresetEditor (MasterAndCommander *m)
    : master (m),
      presetManager(0)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupPresetSelection.reset (new GroupComponent ("new group",
                                                    TRANS("Preset Selection")));
    addAndMakeVisible (groupPresetSelection.get());

    groupPresetSelection->setBounds (8, 8, 280, 500);

    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (false);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (false);
    textEditor->setText (String());

    textEditor->setBounds (24, 32, 248, 428);

    listBox.reset (new ListBox ("new listbox", this));
    addAndMakeVisible (listBox.get());
    listBox->setName ("new listbox");

    listBox->setBounds (27, 35, 242, 424);

    groupNotes.reset (new GroupComponent ("new group",
                                          TRANS("Notes")));
    addAndMakeVisible (groupNotes.get());

    groupNotes->setBounds (296, 232, 520, 232);

    label.reset (new Label ("new label",
                            TRANS("Tag:")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (296, 16, 144, 20);

    label2.reset (new Label ("new label",
                             TRANS("Category 1:")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (296, 40, 144, 20);

    label3.reset (new Label ("new label",
                             TRANS("Category 2:")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (296, 64, 144, 20);

    label4.reset (new Label ("new label",
                             TRANS("Category 3:")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (296, 88, 144, 20);

    label5.reset (new Label ("new label",
                             TRANS("Category 4:")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (296, 112, 144, 20);

    label6.reset (new Label ("new label",
                             TRANS("Wavefile: L->L")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (296, 136, 144, 20);

    label7.reset (new Label ("new label",
                             TRANS("Wavefile: L->R")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (296, 160, 144, 20);

    label8.reset (new Label ("new label",
                             TRANS("Wavefile: R->L")));
    addAndMakeVisible (label8.get());
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label8->setBounds (296, 184, 144, 20);

    label9.reset (new Label ("new label",
                             TRANS("Wavefile: R->R")));
    addAndMakeVisible (label9.get());
    label9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label9->setBounds (296, 208, 144, 20);

    textButtonChooserLL.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonChooserLL.get());
    textButtonChooserLL->setButtonText (TRANS("..."));
    textButtonChooserLL->addListener (this);

    textButtonChooserLL->setBounds (784, 136, 30, 20);

    textEditorFileLL.reset (new TextEditor ("textEditorFileLL"));
    addAndMakeVisible (textEditorFileLL.get());
    textEditorFileLL->setMultiLine (false);
    textEditorFileLL->setReturnKeyStartsNewLine (false);
    textEditorFileLL->setReadOnly (false);
    textEditorFileLL->setScrollbarsShown (true);
    textEditorFileLL->setCaretVisible (true);
    textEditorFileLL->setPopupMenuEnabled (true);
    textEditorFileLL->setText (String());

    textEditorFileLL->setBounds (440, 136, 340, 20);

    textEditorFileLR.reset (new TextEditor ("textEditorFileLR"));
    addAndMakeVisible (textEditorFileLR.get());
    textEditorFileLR->setMultiLine (false);
    textEditorFileLR->setReturnKeyStartsNewLine (false);
    textEditorFileLR->setReadOnly (false);
    textEditorFileLR->setScrollbarsShown (true);
    textEditorFileLR->setCaretVisible (true);
    textEditorFileLR->setPopupMenuEnabled (true);
    textEditorFileLR->setText (String());

    textEditorFileLR->setBounds (440, 160, 340, 20);

    textEditorFileRL.reset (new TextEditor ("textEditorFileRL"));
    addAndMakeVisible (textEditorFileRL.get());
    textEditorFileRL->setMultiLine (false);
    textEditorFileRL->setReturnKeyStartsNewLine (false);
    textEditorFileRL->setReadOnly (false);
    textEditorFileRL->setScrollbarsShown (true);
    textEditorFileRL->setCaretVisible (true);
    textEditorFileRL->setPopupMenuEnabled (true);
    textEditorFileRL->setText (String());

    textEditorFileRL->setBounds (440, 184, 340, 20);

    textEditorFileRR.reset (new TextEditor ("textEditorFileRR"));
    addAndMakeVisible (textEditorFileRR.get());
    textEditorFileRR->setMultiLine (false);
    textEditorFileRR->setReturnKeyStartsNewLine (false);
    textEditorFileRR->setReadOnly (false);
    textEditorFileRR->setScrollbarsShown (true);
    textEditorFileRR->setCaretVisible (true);
    textEditorFileRR->setPopupMenuEnabled (true);
    textEditorFileRR->setText (String());

    textEditorFileRR->setBounds (440, 208, 340, 20);

    textButtonChooserLR.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonChooserLR.get());
    textButtonChooserLR->setButtonText (TRANS("..."));
    textButtonChooserLR->addListener (this);

    textButtonChooserLR->setBounds (784, 160, 30, 20);

    textButtonChooserRL.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonChooserRL.get());
    textButtonChooserRL->setButtonText (TRANS("..."));
    textButtonChooserRL->addListener (this);

    textButtonChooserRL->setBounds (784, 184, 30, 20);

    textButtonChooserRR.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonChooserRR.get());
    textButtonChooserRR->setButtonText (TRANS("..."));
    textButtonChooserRR->addListener (this);

    textButtonChooserRR->setBounds (784, 208, 30, 20);

    textEditorNotes.reset (new TextEditor ("textEditorNotes"));
    addAndMakeVisible (textEditorNotes.get());
    textEditorNotes->setMultiLine (true);
    textEditorNotes->setReturnKeyStartsNewLine (true);
    textEditorNotes->setReadOnly (false);
    textEditorNotes->setScrollbarsShown (true);
    textEditorNotes->setCaretVisible (true);
    textEditorNotes->setPopupMenuEnabled (true);
    textEditorNotes->setText (String());

    textEditorNotes->setBounds (312, 256, 488, 192);

    textEditorTag.reset (new TextEditor ("textEditorTag"));
    addAndMakeVisible (textEditorTag.get());
    textEditorTag->setMultiLine (false);
    textEditorTag->setReturnKeyStartsNewLine (false);
    textEditorTag->setReadOnly (false);
    textEditorTag->setScrollbarsShown (true);
    textEditorTag->setCaretVisible (true);
    textEditorTag->setPopupMenuEnabled (true);
    textEditorTag->setText (String());

    textEditorTag->setBounds (440, 16, 190, 20);

    textEditorCat1.reset (new TextEditor ("textEditorCat1"));
    addAndMakeVisible (textEditorCat1.get());
    textEditorCat1->setMultiLine (false);
    textEditorCat1->setReturnKeyStartsNewLine (false);
    textEditorCat1->setReadOnly (false);
    textEditorCat1->setScrollbarsShown (true);
    textEditorCat1->setCaretVisible (true);
    textEditorCat1->setPopupMenuEnabled (true);
    textEditorCat1->setText (String());

    textEditorCat1->setBounds (440, 40, 340, 20);

    textEditorCat2.reset (new TextEditor ("textEditorCat2"));
    addAndMakeVisible (textEditorCat2.get());
    textEditorCat2->setMultiLine (false);
    textEditorCat2->setReturnKeyStartsNewLine (false);
    textEditorCat2->setReadOnly (false);
    textEditorCat2->setScrollbarsShown (true);
    textEditorCat2->setCaretVisible (true);
    textEditorCat2->setPopupMenuEnabled (true);
    textEditorCat2->setText (String());

    textEditorCat2->setBounds (440, 64, 340, 20);

    textEditorCat3.reset (new TextEditor ("textEditorCat3"));
    addAndMakeVisible (textEditorCat3.get());
    textEditorCat3->setMultiLine (false);
    textEditorCat3->setReturnKeyStartsNewLine (false);
    textEditorCat3->setReadOnly (false);
    textEditorCat3->setScrollbarsShown (true);
    textEditorCat3->setCaretVisible (true);
    textEditorCat3->setPopupMenuEnabled (true);
    textEditorCat3->setText (String());

    textEditorCat3->setBounds (440, 88, 340, 20);

    textEditorCat4.reset (new TextEditor ("textEditorCat4"));
    addAndMakeVisible (textEditorCat4.get());
    textEditorCat4->setMultiLine (false);
    textEditorCat4->setReturnKeyStartsNewLine (false);
    textEditorCat4->setReadOnly (false);
    textEditorCat4->setScrollbarsShown (true);
    textEditorCat4->setCaretVisible (true);
    textEditorCat4->setPopupMenuEnabled (true);
    textEditorCat4->setText (String());

    textEditorCat4->setBounds (440, 112, 340, 20);

    textButtonSave.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonSave.get());
    textButtonSave->setButtonText (TRANS("Save"));
    textButtonSave->addListener (this);

    textButtonSave->setBounds (426, 472, 125, 32);

    textButtonSaveAs.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonSaveAs.get());
    textButtonSaveAs->setButtonText (TRANS("Save as..."));
    textButtonSaveAs->addListener (this);

    textButtonSaveAs->setBounds (556, 472, 125, 32);

    textButtonApply.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonApply.get());
    textButtonApply->setButtonText (TRANS("Apply"));
    textButtonApply->addListener (this);

    textButtonApply->setBounds (686, 472, 125, 32);

    textButtonOpen.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonOpen.get());
    textButtonOpen->setButtonText (TRANS("Open..."));
    textButtonOpen->addListener (this);

    textButtonOpen->setBounds (296, 472, 125, 32);

    textButtonAdd.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonAdd.get());
    textButtonAdd->setButtonText (TRANS("Add"));
    textButtonAdd->addListener (this);

    textButtonAdd->setBounds (24, 468, 100, 24);

    textButtonDelete.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonDelete.get());
    textButtonDelete->setButtonText (TRANS("Delete"));
    textButtonDelete->addListener (this);

    textButtonDelete->setBounds (140, 468, 100, 24);


    //[UserPreSize]
    listBox->setRowHeight(18);
    selectedRow = 0;
    currentPresetNum = 1;
    defaultPresetNum = 1;

    textEditorTag->setEnabled(false);
    textEditorCat1->setEnabled(false);
    textEditorCat2->setEnabled(false);
    textEditorCat3->setEnabled(false);
    textEditorCat4->setEnabled(false);
    textEditorFileLL->setEnabled(false);
    textEditorFileLR->setEnabled(false);
    textEditorFileRL->setEnabled(false);
    textEditorFileRR->setEnabled(false);
    textEditorNotes->setEnabled(false);
    //[/UserPreSize]

    setSize (828, 548);


    //[Constructor] You can add your own custom stuff here..
//    master->print("TabPresetEditor::TabPresetEditor : Waiting for your commands, Sir!");
    textEditorTag->addListener (this);
    textEditorCat1->addListener (this);
    textEditorCat2->addListener (this);
    textEditorCat3->addListener (this);
    textEditorCat4->addListener (this);
    textEditorFileLL->addListener (this);
    textEditorFileLR->addListener (this);
    textEditorFileRL->addListener (this);
    textEditorFileRR->addListener (this);
    textEditorNotes->addListener (this);

    master->registerTabPresetEditor(this);
    //[/Constructor]
}

TabPresetEditor::~TabPresetEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupPresetSelection = nullptr;
    textEditor = nullptr;
    listBox = nullptr;
    groupNotes = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    label7 = nullptr;
    label8 = nullptr;
    label9 = nullptr;
    textButtonChooserLL = nullptr;
    textEditorFileLL = nullptr;
    textEditorFileLR = nullptr;
    textEditorFileRL = nullptr;
    textEditorFileRR = nullptr;
    textButtonChooserLR = nullptr;
    textButtonChooserRL = nullptr;
    textButtonChooserRR = nullptr;
    textEditorNotes = nullptr;
    textEditorTag = nullptr;
    textEditorCat1 = nullptr;
    textEditorCat2 = nullptr;
    textEditorCat3 = nullptr;
    textEditorCat4 = nullptr;
    textButtonSave = nullptr;
    textButtonSaveAs = nullptr;
    textButtonApply = nullptr;
    textButtonOpen = nullptr;
    textButtonAdd = nullptr;
    textButtonDelete = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabPresetEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffffe000));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabPresetEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TabPresetEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButtonChooserLL.get())
    {
        //[UserButtonCode_textButtonChooserLL] -- add your button handler code here..
        String dir = master->getDBdir();
        String filename = getWavFileChooserOpen(dir);
        if (filename != String())
        {
            if (filename.startsWith(dir) == true)
                filename = filename.substring(dir.length());
            presetDB_copy[selectedRow].impulseResponses.ll = filename;
            textEditorFileLL->setText(filename);
        }
        //[/UserButtonCode_textButtonChooserLL]
    }
    else if (buttonThatWasClicked == textButtonChooserLR.get())
    {
        //[UserButtonCode_textButtonChooserLR] -- add your button handler code here..
        String dir = master->getDBdir();
        String filename = getWavFileChooserOpen(dir);
        if (filename != String())
        {
            if (filename.startsWith(dir) == true)
                filename = filename.substring(dir.length());
            presetDB_copy[selectedRow].impulseResponses.lr = filename;
            textEditorFileLR->setText(filename);
        }
        //[/UserButtonCode_textButtonChooserLR]
    }
    else if (buttonThatWasClicked == textButtonChooserRL.get())
    {
        //[UserButtonCode_textButtonChooserRL] -- add your button handler code here..
        String dir = master->getDBdir();
        String filename = getWavFileChooserOpen(dir);
        if (filename != String())
        {
            if (filename.startsWith(dir) == true)
                filename = filename.substring(dir.length());
            presetDB_copy[selectedRow].impulseResponses.rl = filename;
            textEditorFileRL->setText(filename);
        }
        //[/UserButtonCode_textButtonChooserRL]
    }
    else if (buttonThatWasClicked == textButtonChooserRR.get())
    {
        //[UserButtonCode_textButtonChooserRR] -- add your button handler code here..
        String dir = master->getDBdir();
        String filename = getWavFileChooserOpen(dir);
        if (filename != String())
        {
            if (filename.startsWith(dir) == true)
                filename = filename.substring(dir.length());
            presetDB_copy[selectedRow].impulseResponses.rr = filename;
            textEditorFileRR->setText(filename);
        }
        //[/UserButtonCode_textButtonChooserRR]
    }
    else if (buttonThatWasClicked == textButtonSave.get())
    {
        //[UserButtonCode_textButtonSave] -- add your button handler code here..
        master->savePresetDB(presetDB_copy);
        //[/UserButtonCode_textButtonSave]
    }
    else if (buttonThatWasClicked == textButtonSaveAs.get())
    {
        //[UserButtonCode_textButtonSaveAs] -- add your button handler code here..
        String dir = master->getUserdir();
        String filename = getXmlFileChooserSave(dir);
        if (filename != String())
            master->savePresetDBas(presetDB_copy, filename);
        //[/UserButtonCode_textButtonSaveAs]
    }
    else if (buttonThatWasClicked == textButtonApply.get())
    {
        //[UserButtonCode_textButtonApply] -- add your button handler code here..
        master->setPresetDB(presetDB_copy);
        //[/UserButtonCode_textButtonApply]
    }
    else if (buttonThatWasClicked == textButtonOpen.get())
    {
        //[UserButtonCode_textButtonOpen] -- add your button handler code here..
        String dir = master->getUserdir();
        String filename = getXmlFileChooserOpen(dir);
        if (filename != String())
        {
            presetManager->readFile(filename);
            presetDB_copy.clear();
            presetDB_copy = presetManager->getPresetDBcopy();
            updateListBox();
            master->setPresetDB(presetDB_copy, false);
        }
        //[/UserButtonCode_textButtonOpen]
    }
    else if (buttonThatWasClicked == textButtonAdd.get())
    {
        //[UserButtonCode_textButtonAdd] -- add your button handler code here..
        ParamPreset newPreset;
        newPreset.name = TRANS("new preset");
        newPreset.category.cat_1 = TRANS("new category");
        newPreset.category.cat_2 = TRANS("new category");
        newPreset.category.cat_3 = TRANS("new category");
        newPreset.category.cat_4 = TRANS("new category");
        presetDB_copy.insert(presetDB_copy.begin() + selectedRow, newPreset);
        updateListBox();
        //[/UserButtonCode_textButtonAdd]
    }
    else if (buttonThatWasClicked == textButtonDelete.get())
    {
        //[UserButtonCode_textButtonDelete] -- add your button handler code here..
        if (presetDB_copy.size() > 0)
        {
            presetDB_copy.erase(presetDB_copy.begin() + selectedRow);
            updateListBox();
        }
        //[/UserButtonCode_textButtonDelete]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TabPresetEditor::setPresetManager(PresetManager *man)
{
    presetManager = man;
    presetDB_copy = presetManager->getPresetDBcopy();
    selectedRow = 0;
    updateListBox();
}


void TabPresetEditor::updateListBox()
{
    int dbSize = presetDB_copy.size();
    if (selectedRow > dbSize)
        selectedRow = dbSize;
    listBox->selectRow(selectedRow);
    listBoxItemClicked(selectedRow);
    for (int i = 0; i < dbSize; i++)
        listBox->repaintRow(i);
    listBox->updateContent();
}


void TabPresetEditor::onComponentSelected(void)
{
    //FIXME: remove this
    printf("TabPresetEditor selected\n");

    presetDB_copy = presetManager->getPresetDBcopy();
    defaultPresetNum = presetManager->getDefaultPresetNum();
    currentPresetNum = presetManager->getCurrentPresetNum();
    selectedRow = currentPresetNum - 1;
    updateListBox();
}


String TabPresetEditor::getWavFileChooserOpen(String dir)
{
    FileChooser fc(TRANS("Choose a WAV file to open..."),
                   dir,
                   "*.wav",
                   FileChooserUseNative);

    if (fc.browseForFileToOpen())
    {
        File chosenFile = fc.getResult();
        return chosenFile.getFullPathName();
    }

    return String();
}


String TabPresetEditor::getXmlFileChooserOpen(String dir)
{
    FileChooser fc(TRANS("Choose a XML file to open..."),
                   dir,
                   "*.xml",
                   FileChooserUseNative);

    if (fc.browseForFileToOpen())
    {
        File chosenFile = fc.getResult();
        return chosenFile.getFullPathName();
    }

    return String();
}


String TabPresetEditor::getXmlFileChooserSave(String dir)
{
    FileChooser fc(TRANS("Choose a XML file to save..."),
                   dir,
                   "*.xml",
                   FileChooserUseNative);

    if (fc.browseForFileToSave(true))
    {
        File chosenFile = fc.getResult();
        chosenFile.create();
        return chosenFile.getFullPathName();
    }
    else
        int debug_me = 1;

    return String();
}


int TabPresetEditor::getNumRows()
{
    if (presetManager == 0)
        return 0;

    return presetDB_copy.size() + 1;
}


void TabPresetEditor::paintListBoxItem(int rowNumber,
                                       Graphics &g,
                                       int width, int height,
                                       bool rowIsSelected)
{
    int num = rowNumber + 1;

    if (rowIsSelected)
        g.fillAll (Colour (0xffbbbbff));

    Font font(height - 2);
    g.setFont(font);

    if (num == defaultPresetNum)
        g.setColour(Colour(0xff800000));

    String text = String::formatted("%d: ", num);
    if (num <= presetDB_copy.size())
        text += presetDB_copy[rowNumber].name;
    else
        text += String(TRANS("<Empty>"));
    g.drawText(text,
               4, 0,
               width - 4, height,
               Justification::centredLeft,
               true);
}


void TabPresetEditor::listBoxItemClicked(int row)
{
    String text;

    selectedRow = row;

    if (row < presetDB_copy.size())
    {
        text = presetDB_copy[row].name;
        textEditorTag->setText(text);
        textEditorTag->setEnabled(true);

        ParamCategory cat = presetDB_copy[row].category;
        textEditorCat1->setText(cat.cat_1);
        textEditorCat2->setText(cat.cat_2);
        textEditorCat3->setText(cat.cat_3);
        textEditorCat4->setText(cat.cat_4);
        textEditorCat1->setEnabled(true);
        textEditorCat2->setEnabled(true);
        textEditorCat3->setEnabled(true);
        textEditorCat4->setEnabled(true);

        ParamImpulseResponses ir = presetDB_copy[row].impulseResponses;
        textEditorFileLL->setText(ir.ll);
        textEditorFileLR->setText(ir.lr);
        textEditorFileRL->setText(ir.rl);
        textEditorFileRR->setText(ir.rr);
        textEditorFileLL->setEnabled(true);
        textEditorFileLR->setEnabled(true);
        textEditorFileRL->setEnabled(true);
        textEditorFileRR->setEnabled(true);

        text = presetDB_copy[row].notes;
        textEditorNotes->setText(text);
        textEditorNotes->setEnabled(true);
    }
    else
    {
        textEditorTag->setText(String());
        textEditorTag->setEnabled(false);

        textEditorCat1->setText(String());
        textEditorCat2->setText(String());
        textEditorCat3->setText(String());
        textEditorCat4->setText(String());
        textEditorCat1->setEnabled(false);
        textEditorCat2->setEnabled(false);
        textEditorCat3->setEnabled(false);
        textEditorCat4->setEnabled(false);

        textEditorFileLL->setText(String());
        textEditorFileLR->setText(String());
        textEditorFileRL->setText(String());
        textEditorFileRR->setText(String());
        textEditorFileLL->setEnabled(false);
        textEditorFileLR->setEnabled(false);
        textEditorFileRL->setEnabled(false);
        textEditorFileRR->setEnabled(false);

        textEditorNotes->setText(String());
        textEditorNotes->setEnabled(false);
    }
}


void TabPresetEditor::listBoxItemClicked(int row, const MouseEvent &e)
{
    listBoxItemClicked(row);
}


void TabPresetEditor::listBoxItemDoubleClicked(int row, const MouseEvent &e)
{
    listBoxItemClicked(row, e);
}


void TabPresetEditor::deleteKeyPressed(int lastRowSelected)
{
    if (selectedRow < presetDB_copy.size())
    {
        presetDB_copy.erase(presetDB_copy.begin() + selectedRow);
        updateListBox();
    }
}


void TabPresetEditor::textEditorTextChanged (TextEditor &editor)
{
}


void TabPresetEditor::textEditorReturnKeyPressed (TextEditor &editor)
{
    String text = editor.getText();

    if (editor.getName() == String("textEditorTag"))
    {
        presetDB_copy[selectedRow].name = text;
    }
    else if (editor.getName() == String("textEditorCat1"))
    {
        presetDB_copy[selectedRow].category.cat_1 = text;
    }
    else if (editor.getName() == String("textEditorCat2"))
    {
        presetDB_copy[selectedRow].category.cat_2 = text;
    }
    else if (editor.getName() == String("textEditorCat3"))
    {
        presetDB_copy[selectedRow].category.cat_3 = text;
    }
    else if (editor.getName() == String("textEditorCat4"))
    {
        presetDB_copy[selectedRow].category.cat_4 = text;
    }
    else if (editor.getName() == String("textEditorFileLL"))
    {
        presetDB_copy[selectedRow].impulseResponses.ll = text;
    }
    else if (editor.getName() == String("textEditorFileLR"))
    {
        presetDB_copy[selectedRow].impulseResponses.lr = text;
    }
    else if (editor.getName() == String("textEditorFileRL"))
    {
        presetDB_copy[selectedRow].impulseResponses.rl = text;
    }
    else if (editor.getName() == String("textEditorFileRR"))
    {
        presetDB_copy[selectedRow].impulseResponses.rr = text;
    }
    else if (editor.getName() == String("textEditorNotes"))
    {
        presetDB_copy[selectedRow].notes = text;
    }
}


void TabPresetEditor::textEditorEscapeKeyPressed (TextEditor &editor)
{
}


void TabPresetEditor::textEditorFocusLost (TextEditor &editor)
{
    // focus change is interpreted as user input completion
    textEditorReturnKeyPressed(editor);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TabPresetEditor" componentName=""
                 parentClasses="public Component, public TextEditor::Listener, public ListBoxModel"
                 constructorParams="MasterAndCommander *m" variableInitialisers="master (m),&#10;presetManager(0)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="828" initialHeight="548">
  <BACKGROUND backgroundColour="ffffe000"/>
  <GROUPCOMPONENT name="new group" id="5bbb615c6111dfeb" memberName="groupPresetSelection"
                  virtualName="" explicitFocusOrder="0" pos="8 8 280 500" title="Preset Selection"/>
  <TEXTEDITOR name="new text editor" id="d542415b872610f0" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="24 32 248 428" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <GENERICCOMPONENT name="new listbox" id="90b42c658c2c4f06" memberName="listBox"
                    virtualName="" explicitFocusOrder="0" pos="27 35 242 424" class="ListBox"
                    params="&quot;new listbox&quot;, this"/>
  <GROUPCOMPONENT name="new group" id="feef6879e095fd42" memberName="groupNotes"
                  virtualName="" explicitFocusOrder="0" pos="296 232 520 232" title="Notes"/>
  <LABEL name="new label" id="2a92bdd8797a5c0c" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="296 16 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Tag:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d60f95ae51be6fc9" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="296 40 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Category 1:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="da0065a01bd61087" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="296 64 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Category 2:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5e4e7210d6b88d44" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="296 88 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Category 3:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="89087cb7602b5cf1" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="296 112 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Category 4:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="474b7e931bda8352" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="296 136 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Wavefile: L-&gt;L" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="63a88d206c97e029" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="296 160 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Wavefile: L-&gt;R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="63e75ec5961dcc92" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="296 184 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Wavefile: R-&gt;L" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="220822917c93aab0" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="296 208 144 20" edTextCol="ff000000"
         edBkgCol="0" labelText="Wavefile: R-&gt;R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="c9dea607df14f877" memberName="textButtonChooserLL"
              virtualName="" explicitFocusOrder="0" pos="784 136 30 20" buttonText="..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="textEditorFileLL" id="46c2d54dbfae1739" memberName="textEditorFileLL"
              virtualName="" explicitFocusOrder="0" pos="440 136 340 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="textEditorFileLR" id="f707b69bdbfdd0b9" memberName="textEditorFileLR"
              virtualName="" explicitFocusOrder="0" pos="440 160 340 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="textEditorFileRL" id="b6400ded9229175" memberName="textEditorFileRL"
              virtualName="" explicitFocusOrder="0" pos="440 184 340 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="textEditorFileRR" id="17bae52fab2672ad" memberName="textEditorFileRR"
              virtualName="" explicitFocusOrder="0" pos="440 208 340 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="5e63fc03d289e661" memberName="textButtonChooserLR"
              virtualName="" explicitFocusOrder="0" pos="784 160 30 20" buttonText="..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="126729682c326da3" memberName="textButtonChooserRL"
              virtualName="" explicitFocusOrder="0" pos="784 184 30 20" buttonText="..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="5a4b3d02c3c9b36a" memberName="textButtonChooserRR"
              virtualName="" explicitFocusOrder="0" pos="784 208 30 20" buttonText="..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="textEditorNotes" id="2e7167da16d79c0" memberName="textEditorNotes"
              virtualName="" explicitFocusOrder="0" pos="312 256 488 192" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="textEditorTag" id="27591352b6e79c34" memberName="textEditorTag"
              virtualName="" explicitFocusOrder="0" pos="440 16 190 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="textEditorCat1" id="eb6538ed8c693c7f" memberName="textEditorCat1"
              virtualName="" explicitFocusOrder="0" pos="440 40 340 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="textEditorCat2" id="4a356d146f0932bd" memberName="textEditorCat2"
              virtualName="" explicitFocusOrder="0" pos="440 64 340 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="textEditorCat3" id="da136f3e3d107a28" memberName="textEditorCat3"
              virtualName="" explicitFocusOrder="0" pos="440 88 340 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="textEditorCat4" id="f10d7c42ed179cbd" memberName="textEditorCat4"
              virtualName="" explicitFocusOrder="0" pos="440 112 340 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="6a7feedb9b89f7ad" memberName="textButtonSave"
              virtualName="" explicitFocusOrder="0" pos="426 472 125 32" buttonText="Save"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="f91685d349299ec3" memberName="textButtonSaveAs"
              virtualName="" explicitFocusOrder="0" pos="556 472 125 32" buttonText="Save as..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="98eaa2308e3dff56" memberName="textButtonApply"
              virtualName="" explicitFocusOrder="0" pos="686 472 125 32" buttonText="Apply"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="bb782d1bce6654d4" memberName="textButtonOpen"
              virtualName="" explicitFocusOrder="0" pos="296 472 125 32" buttonText="Open..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a317b7ab8939b36b" memberName="textButtonAdd"
              virtualName="" explicitFocusOrder="0" pos="24 468 100 24" buttonText="Add"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d19eab292b14a30a" memberName="textButtonDelete"
              virtualName="" explicitFocusOrder="0" pos="140 468 100 24" buttonText="Delete"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
