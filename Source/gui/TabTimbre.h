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
#include "../ParamTimbre.h"

#include <fftw3.h>


// forward declarations
class MasterAndCommander;

class FreqPlot;

class LagrangeInterpolation;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabTimbre  : public Component,
                   public Slider::Listener
{
public:
    //==============================================================================
    TabTimbre (MasterAndCommander *m);
    ~TabTimbre();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    float* getFilter();
    int getFilterLen();
    void updateData();
    void setTimbre (ParamTimbre *param);
    void sliderDragEnded (Slider* sliderThatWasMoved) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    struct FftwfDeleter
    {
        void operator()(void *x) const noexcept { fftwf_free(x); }
    };
    struct FftwfPlanDeleter
    {
        void operator()(fftwf_plan x) const noexcept { fftwf_destroy_plan(x); }
    };

    MasterAndCommander* master;
    std::unique_ptr<ParamTimbre> paramTimbre;
    std::unique_ptr<LagrangeInterpolation> interpolator;
    std::unique_ptr<std::unique_ptr<Label>[]> labelFreq;
    std::unique_ptr<std::unique_ptr<Label>[]> labelTime;
    int numLabel;
    std::unique_ptr<std::unique_ptr<Label>[]> labelDbFreq;
    std::unique_ptr<std::unique_ptr<Label>[]> labelDbTime;
    int numLabelDb;
    std::unique_ptr<std::unique_ptr<Slider>[]> slider;
    int numSlider;
    int gridX;
    int gridY;
    int offsetX;
    int offsetY;
    float sampleRate;
    std::unique_ptr<float[]> level;
    int numLevel;
    float f0;
    std::unique_ptr<float[], FftwfDeleter> impulse;
    std::unique_ptr<float[], FftwfDeleter> window;
    std::unique_ptr<fftwf_complex[], FftwfDeleter> dftFreq;
    std::unique_ptr<fftwf_plan_s, FftwfPlanDeleter> fft;
    std::unique_ptr<fftwf_plan_s, FftwfPlanDeleter> ifft;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupComponent;
    std::unique_ptr<FreqPlot> freqPlot;
    std::unique_ptr<Slider> sliderSmooth;
    std::unique_ptr<Label> Smoothing;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabTimbre)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
