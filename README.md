# HybridReverb2
Reverb effect using hybrid impulse convolution

[![Build Status](https://semaphoreci.com/api/v1/jpcima/hybridreverb2/branches/master/badge.svg)](https://semaphoreci.com/jpcima/hybridreverb2)

Original author: Christian Borß  
Current maintainer: [Jean Pierre Cimalando](https://github.com/jpcima)  
Contributor: [Olivier Humbert](https://github.com/trebmuh)

The goal of this project is to keep the HybridReverb2 project maintained and fix the issues.  
All information and original source code of HybridReverb2 is available on this [project page](http://www2.ika.ruhr-uni-bochum.de/HybridReverb2/).

## Introduction

(quoted from the original project page)

> HybridReverb2 is a convolution-based reverberation effect which combines the superior sound quality of a convolution reverb with the tuning capability of a feedback delay network. The sound quality of a convolution reverb depends on the quality of the used room impulse responses. HybridReverb2 comes with a set of room impulse responses which were synthesized with tinyAVE, an auralization software which was developed at the Institute of Communication Acoustics, Ruhr-Universität Bochum (Borß and Martin, 2009; Borß, 2009a). These room impulse responses are designed for a speaker setup with two front and two rear speakers (Borß, 2009b). For a full surround sound effect, you will need two plugins, one plugin which uses a "front" preset for the front channels and a second plugin which uses the corresponding "rear" preset for the rear channels.

> Enjoy,  
Christian Borß

## Downloads

[Windows development builds](http://jpcima.sdf1.org/software/development/HybridReverb2/)

[Impulse response database](http://www2.ika.ruhr-uni-bochum.de/HybridReverb2/HybridReverb2_large_database.zip) - free for non-commercial use

## Building

A CMake build file is provided to Linux users for the ability to build LV2 and cross-compile.  
The traditional Juce build process has build files for all platforms in the `Builds` folder. It supports all formats except LV2.

To perform a CMake-based build:

```
git submodule init
git submodule update
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

## Usage

The LV2 plugin is identified as `https://github.com/jpcima/HybridReverb2`.  
Load this in your favorite plugin hosting software. A free compatible plugin host is [Carla](https://github.com/falkTX/Carla).
