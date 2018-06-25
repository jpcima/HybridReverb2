# HybridReverb2
Reverb effect using hybrid impulse convolution

[![Build Status](https://semaphoreci.com/api/v1/jpcima/hybridreverb2/branches/master/badge.svg)](https://semaphoreci.com/jpcima/hybridreverb2)

[Windows development builds](http://jpcima.sdf1.org/software/development/HybridReverb2/)

This project is for maintainance of the HybridReverb2 effect by Christian Borß.  
All information and original source code of HybridReverb2 is available on this [project page](http://www2.ika.ruhr-uni-bochum.de/HybridReverb2/).

A CMake build file is provided to Linux users for the ability to build LV2 and cross-compile.  
The traditional Juce build process has build files for all platforms in the `Builds` folder. It supports all formats except LV2.

Download the [impulse response database](http://www2.ika.ruhr-uni-bochum.de/HybridReverb2/HybridReverb2_large_database.zip) and extract it in `PREFIX`/share/HybridReverb2/.  
The LV2 plugin is identified as `https://github.com/jpcima/HybridReverb2`.
