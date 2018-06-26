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
#include "FreqPlot.h"
#include "../LagrangeInterpolator.h"
#include <fftw3.h>
//[/Headers]

#include "TabTimbre.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabTimbre::TabTimbre (MasterAndCommander *m)
    : master (m)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponent.reset (new GroupComponent ("new group",
                                              TRANS("Wet Timbre")));
    addAndMakeVisible (groupComponent.get());

    groupComponent->setBounds (8, 8, 808, 500);

    freqPlot.reset (new FreqPlot (master));
    addAndMakeVisible (freqPlot.get());
    freqPlot->setName ("new component");

    freqPlot->setBounds (24, 32, 776, 460);

    sliderSmooth.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderSmooth.get());
    sliderSmooth->setRange (0, 8, 1);
    sliderSmooth->setSliderStyle (Slider::IncDecButtons);
    sliderSmooth->setTextBoxStyle (Slider::TextBoxLeft, false, 32, 24);
    sliderSmooth->addListener (this);

    sliderSmooth->setBounds (224, 448, 72, 24);

    Smoothing.reset (new Label ("new label",
                                TRANS("Smoothing Factor:")));
    addAndMakeVisible (Smoothing.get());
    Smoothing->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Smoothing->setJustificationType (Justification::centredLeft);
    Smoothing->setEditable (false, false, false);
    Smoothing->setColour (TextEditor::textColourId, Colours::black);
    Smoothing->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Smoothing->setBounds (96, 448, 128, 24);


    //[UserPreSize]
    gridX = 28;
    gridY = 25;
    offsetX = 52 + 40 + 8;
    offsetY = 36 + 8;

    sampleRate = 48000.0;
    numLevel = 2048;
    level.reset(new float[numLevel]);
    f0 = sampleRate / float(2 * numLevel);
    for (int n = 0; n < numLevel; n++)
    {
        float f = (n + 1.0) * f0;
        level[n] = 0.0;
    }

    int size = sizeof(float) * 2 * numLevel;
    impulse.reset((float *)fftwf_malloc(size));
    for (int i = 0; i < 2 * numLevel; i++)
        impulse[i] = 0.0;
    impulse[numLevel] = 1.0;

    size = sizeof(float) * 2 * numLevel;
    window.reset((float *)fftwf_malloc(size));
    for (int i = 0; i < 2 * numLevel; i++)
        window[i] = 1.0 / (2.0 * numLevel);

    size = sizeof(fftwf_complex) * (numLevel + 1);
    dftFreq.reset((fftwf_complex*)fftwf_malloc(size));
    for (int i = 0; i < numLevel + 1; i++)
    {
        dftFreq[i][0] = 1.0;
        dftFreq[i][1] = 0.0;
    }

    fft.reset(fftwf_plan_dft_r2c_1d(2 * numLevel, impulse.get(), dftFreq.get(),
                                    FFTW_ESTIMATE|FFTW_PRESERVE_INPUT));
    ifft.reset(fftwf_plan_dft_c2r_1d(2 * numLevel, dftFreq.get(), impulse.get(),
                                     FFTW_ESTIMATE|FFTW_PRESERVE_INPUT));

    numSlider = 25;
    slider.reset(new std::unique_ptr<Slider>[numSlider]);
    for (int i = 0; i < numSlider; i++)
    {
        slider[i].reset(new Slider (("new slider")));
        addAndMakeVisible (slider[i].get());
        slider[i]->setRange (-100, 20, 1);
        slider[i]->setSliderStyle (Slider::LinearVertical);
        slider[i]->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 16);
        slider[i]->setColour (Slider::thumbColourId, Colour (0xffb00000));
        slider[i]->setColour (Slider::trackColourId, Colour (0x60a08080));
        slider[i]->setColour (Slider::rotarySliderFillColourId, Colour (0x7f800000));
        slider[i]->setColour (Slider::textBoxTextColourId, Colours::maroon);
        slider[i]->setColour (Slider::textBoxHighlightColourId, Colour (0x40ff0000));
        slider[i]->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
        slider[i]->addListener (this);
        slider[i]->setDoubleClickReturnValue (true, 0.0);
    }
    numLabel = 9;
    const char *freqs[] =
    {
        "62.5 Hz", "125 Hz", "250 Hz", "500 Hz",
        "1 kHz", "2 kHz", "4 kHz", "8 kHz",
        "16 kHz",
    };
    labelFreq.reset(new std::unique_ptr<Label>[numLabel]);
    for (int i = 0; i < numLabel; ++i)
    {
        labelFreq[i].reset(new Label ("new label", freqs[i]));
        addAndMakeVisible (labelFreq[i].get());
        labelFreq[i]->setFont (Font (15.0000f, Font::plain));
        labelFreq[i]->setJustificationType (Justification::centred);
        labelFreq[i]->setEditable (false, false, false);
        labelFreq[i]->setColour (TextEditor::textColourId, Colours::black);
        labelFreq[i]->setColour (TextEditor::backgroundColourId, Colour (0x0));
    }
    const char *times[] =
    {
        "-40 ms", "-30 ms", "-20 ms", "-10 ms",
        "0 ms", "10 ms", "20 ms", "30 ms",
        "40 ms",
    };
    labelTime.reset(new std::unique_ptr<Label>[numLabel]);
    for (int i = 0; i < numLabel; i++)
    {
        labelTime[i].reset(new Label ("new label", times[i]));
        addAndMakeVisible (labelTime[i].get());
        labelTime[i]->setFont (Font (15.0000f, Font::plain));
        labelTime[i]->setJustificationType (Justification::centred);
        labelTime[i]->setEditable (false, false, false);
        labelTime[i]->setColour (TextEditor::textColourId, Colours::black);
        labelTime[i]->setColour (TextEditor::backgroundColourId, Colour (0x0));
    }
    numLabelDb = 7;
    const char *db[] =
    {
        "20 dB", "0 dB", "-20 dB", "-40 dB",
        "-60 dB", "-80 dB", "-100 dB",
    };
    labelDbFreq.reset(new std::unique_ptr<Label>[numLabelDb]);
    for (int i = 0; i < numLabelDb; i++)
    {
        labelDbFreq[i].reset(new Label ("new label", db[i]));
        addAndMakeVisible (labelDbFreq[i].get());
        labelDbFreq[i]->setFont (Font (15.0000f, Font::plain));
        labelDbFreq[i]->setJustificationType (Justification::centredRight);
        labelDbFreq[i]->setEditable (false, false, false);
        labelDbFreq[i]->setColour (TextEditor::textColourId, Colours::black);
        labelDbFreq[i]->setColour (TextEditor::backgroundColourId, Colour (0x0));
    }
    labelDbTime.reset(new std::unique_ptr<Label>[numLabelDb]);
    for (int i = 0; i < numLabelDb; i++)
    {
        labelDbTime[i].reset(new Label ("new label", db[i]));
        addAndMakeVisible (labelDbTime[i].get());
        labelDbTime[i]->setFont (Font (15.0000f, Font::plain));
        labelDbTime[i]->setJustificationType (Justification::centredRight);
        labelDbTime[i]->setEditable (false, false, false);
        labelDbTime[i]->setColour (TextEditor::textColourId, Colours::black);
        labelDbTime[i]->setColour (TextEditor::backgroundColourId, Colour (0x0));
    }

    //[/UserPreSize]

    setSize (828, 548);


    //[Constructor] You can add your own custom stuff here..
//    master->print("TabTimbre::TabTimbre : Waiting for your commands, Sir!");

    // FIXME: this is for debugging only
    float data[ParamTimbre::num];
    float freq   = 62.5;
    float ratio  = pow(2.0, 1.0/3.0);
    float smooth = 0.0;
    for (int i = 0; i < ParamTimbre::num; i++)
        data[i] = 0.0;
    paramTimbre.reset(new ParamTimbre(data, freq, ratio, smooth));
    interpolator.reset(new LagrangeInterpolation(data, ParamTimbre::num, freq, ratio));

    freqPlot->init(gridX, gridY, offsetX - 24, offsetY - 32 + 24,
                   numSlider, freq, ratio,
                   numLevel, f0);

    master->registerTabTimbre(this);
    //[/Constructor]
}

TabTimbre::~TabTimbre()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    freqPlot = nullptr;
    sliderSmooth = nullptr;
    Smoothing = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabTimbre::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffffe000));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabTimbre::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    for (int i = 0; i < numSlider; i++)
    {
        int x = offsetX + i * gridX - gridX / 2;
        int y = offsetY;
        int width = gridX;
        int height = 6 * gridY + 32;
        slider[i]->setBounds (x, y, width, height);
    }
    for (int i = 0; i < numLabel; i++)
    {
        int x = offsetX + (3 * i - 1) * gridX;
        int y = offsetY + 6 * gridY + 32;
        int width = 2 * gridX;
        int height = 16;
        labelFreq[i]->setBounds (x, y, width, height);
    }
    for (int i = 0; i < numLabelDb; i++)
    {
        int x = offsetX - 72;
        int y = offsetY + i * gridY + 17;
        int width = 64;
        int height = 16;
        labelDbFreq[i]->setBounds (x, y, width, height);
    }
    int offsetTimeX = offsetX - 24;
    int offsetTimeY = offsetY - 32 + 24 + 192;
    float tTotal = 1.0 / f0;
    int wMax = 776 - offsetTimeX - 28;
    int pixel_5ms = floor(0.005 * wMax / tTotal);
    int posOrigin = offsetTimeX + roundf(pixel_5ms * 0.5 * tTotal / 0.005);
    for (int i = 0; i < numLabel; i++)
    {
        int x = posOrigin + (2 * i - 9) * pixel_5ms;
        int y = offsetTimeY + 6 * gridY + 32;
        int width = 2 * pixel_5ms;
        int height = 16;
        labelTime[i]->setBounds (x + 24, y + 8, width, height);
    }
    for (int i = 0; i < numLabelDb; i++)
    {
        int x = offsetTimeX - 48;
        int y = offsetTimeY + i * gridY + 25;
        int width = 64;
        int height = 16;
        labelDbTime[i]->setBounds (x, y, width, height);
    }
    //[/UserResized]
}

void TabTimbre::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderSmooth.get())
    {
        //[UserSliderCode_sliderSmooth] -- add your slider handling code here..
        double expo = 0.0;
        float value = sliderThatWasMoved->getValue();
        paramTimbre->smooth = value;
        if (value > 0.0)
            expo = pow(2.0, value - 1.0);
        for (int i = 0; i < 2 * numLevel; i++)
        {
            double alpha = 2.0 * M_PI * i / double(2 * numLevel);
            window[i] = pow(0.5 * (1.0 - cos(alpha)), expo) / (2.0 * numLevel);
        }
        //[/UserSliderCode_sliderSmooth]
    }

    //[UsersliderValueChanged_Post]
    for (int i = 0; i < numSlider; i++)
    {
        if (sliderThatWasMoved == slider[i].get())
        {
            paramTimbre->data[i] = sliderThatWasMoved->getValue();
            interpolator->update(paramTimbre->data);
        }
    }

    updateData();
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

float* TabTimbre::getFilter()
{
    return impulse.get();
}


int TabTimbre::getFilterLen()
{
    return 2 * numLevel;
}


void TabTimbre::updateData()
{
    float sign = -1.0;
    for (int n = 0; n < numLevel; n++)
    {
        float db        = interpolator->interpolate((n + 1.0) * f0);
        float gain      = powf(10.0, db / 20.0);
        dftFreq[n+1][0] = sign * gain;
        dftFreq[n+1][1] = 0.0;
        sign = -sign;
    }
    dftFreq[0][0] = -dftFreq[1][0];
    dftFreq[0][1] = 0.0;
    fftwf_execute(ifft.get());
    for (int n = 0; n < 2 * numLevel; n++)
    {
        impulse[n] *= window[n];
    }
    fftwf_execute(fft.get());
    for (int n = 0; n < numLevel; n++)
    {
        level[n] = 20.0 * log10f(fabs(dftFreq[n+1][0]));
    }

    freqPlot->setLevel(level.get());
    freqPlot->setImpulse(impulse.get());
}


void TabTimbre::setTimbre (ParamTimbre *param)
{
    *paramTimbre = *param;
    for (int i = 0; i < paramTimbre->num; i++)
    {
        slider[i]->setDoubleClickReturnValue(true, paramTimbre->data[i]);
        slider[i]->setValue (paramTimbre->data[i]);
    }
    sliderSmooth->setValue(paramTimbre->smooth);
    interpolator->update(paramTimbre->data);
    updateData();
}


void TabTimbre::sliderDragEnded (Slider* sliderThatWasMoved)
{
    master->onValueChangedTimbre(paramTimbre.get());
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TabTimbre" componentName=""
                 parentClasses="public Component" constructorParams="MasterAndCommander *m"
                 variableInitialisers="master (m)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="828"
                 initialHeight="548">
  <BACKGROUND backgroundColour="ffffe000"/>
  <GROUPCOMPONENT name="new group" id="2cc4bc9befb38382" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 8 808 500" title="Wet Timbre"/>
  <GENERICCOMPONENT name="new component" id="59ae0e7d51155289" memberName="freqPlot"
                    virtualName="" explicitFocusOrder="0" pos="24 32 776 460" class="FreqPlot"
                    params="master"/>
  <SLIDER name="new slider" id="f2d6b6f5cd951d81" memberName="sliderSmooth"
          virtualName="" explicitFocusOrder="0" pos="224 448 72 24" min="0.00000000000000000000"
          max="8.00000000000000000000" int="1.00000000000000000000" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="32"
          textBoxHeight="24" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="238e7bbb6d133177" memberName="Smoothing"
         virtualName="" explicitFocusOrder="0" pos="96 448 128 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Smoothing Factor:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
