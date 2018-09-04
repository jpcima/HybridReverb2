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
#include "../ParamPreset.h"

// forward declarations
class MasterAndCommander;
class PresetManager;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabPresetEditor  : public Component,
                         public TextEditor::Listener,
                         public ListBoxModel,
                         public Button::Listener
{
public:
    //==============================================================================
    TabPresetEditor (MasterAndCommander *m);
    ~TabPresetEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setPresetManager (PresetManager *man);
    void updateListBox();
    void onComponentSelected(void);
    String getWavFileChooserOpen(String dir);
    String getXmlFileChooserOpen(String dir);
    String getXmlFileChooserSave(String dir);

    // ListBoxModel methods
    int getNumRows() override;
    void paintListBoxItem(int rowNumber,
                          Graphics &g,
                          int width, int height,
                          bool rowIsSelected) override;
    void listBoxItemClicked(int row);
    void listBoxItemClicked(int row, const MouseEvent &e) override;
    void listBoxItemDoubleClicked(int row, const MouseEvent &e) override;
    void deleteKeyPressed(int lastRowSelected) override;
//    Component * refreshComponentForRow(int rowNumber,
//                                       bool isRowSelected,
//                                       Component *existingComponentToUpdate);
//    void backgroundClicked();
//    void selectedRowsChanged(int lastRowSelected);
//    void returnKeyPressed(int lastRowSelected);
//    void listWasScrolled();
//    const String getDragSourceDescription(const SparseSet< int > &currentlySelectedRows);

    // TextEditorListener methods
    void textEditorTextChanged(TextEditor & editor) override;
    void textEditorReturnKeyPressed(TextEditor & editor) override;
    void textEditorEscapeKeyPressed(TextEditor & editor) override;
    void textEditorFocusLost(TextEditor & editor) override;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MasterAndCommander* master;
    PresetManager* presetManager;
    std::vector<ParamPreset> presetDB_copy;
    int selectedRow;
    int currentPresetNum;
    int defaultPresetNum;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupPresetSelection;
    std::unique_ptr<TextEditor> textEditor;
    std::unique_ptr<ListBox> listBox;
    std::unique_ptr<GroupComponent> groupNotes;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Label> label6;
    std::unique_ptr<Label> label7;
    std::unique_ptr<Label> label8;
    std::unique_ptr<Label> label9;
    std::unique_ptr<TextButton> textButtonChooserLL;
    std::unique_ptr<TextEditor> textEditorFileLL;
    std::unique_ptr<TextEditor> textEditorFileLR;
    std::unique_ptr<TextEditor> textEditorFileRL;
    std::unique_ptr<TextEditor> textEditorFileRR;
    std::unique_ptr<TextButton> textButtonChooserLR;
    std::unique_ptr<TextButton> textButtonChooserRL;
    std::unique_ptr<TextButton> textButtonChooserRR;
    std::unique_ptr<TextEditor> textEditorNotes;
    std::unique_ptr<TextEditor> textEditorTag;
    std::unique_ptr<TextEditor> textEditorCat1;
    std::unique_ptr<TextEditor> textEditorCat2;
    std::unique_ptr<TextEditor> textEditorCat3;
    std::unique_ptr<TextEditor> textEditorCat4;
    std::unique_ptr<TextButton> textButtonSave;
    std::unique_ptr<TextButton> textButtonSaveAs;
    std::unique_ptr<TextButton> textButtonApply;
    std::unique_ptr<TextButton> textButtonOpen;
    std::unique_ptr<TextButton> textButtonAdd;
    std::unique_ptr<TextButton> textButtonDelete;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabPresetEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
