/***************************************************************************
 *   Copyright (C) 2009 by Christian Borss                                 *
 *   christian.borss@rub.de                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef __PARAM_H__
#define __PARAM_H__

#include "JuceHeader.h"

///////////////////////
// Impulse responses //
///////////////////////

struct ParamImpulseResponses
{
    String ll;
    String lr;
    String rl;
    String rr;
};

//////////////
// Category //
//////////////

struct ParamCategory
{
    String cat_1;
    String cat_2;
    String cat_3;
    String cat_4;
};

////////////
// Timbre //
////////////

struct ParamTimbre
{
    ParamTimbre()
    {
    }

    ParamTimbre(float *y, float f, float r, float s)
    {
        for (int i = 0; i < num; i++)
            data[i] = y[i];
        freq   = f;
        ratio  = r;
        smooth = s;
    }

    enum { num = 25 };
    float data[num] = {};
    float freq = 62.5;
    float ratio = 1.25992104989487319;  // 2^(1/3)
    float smooth = 0.0;
};

////////////////
// Gain/Delay //
////////////////

struct ParamGainDelay
{
    float initialGap = 0.0;
    float length = -1.0;
    float preDelay = 0.0;
    float dryGain = 0.0;
    float wetGain = 0.0;
    float masterGain = 0.0;
};

//////////////
// Envelope //
//////////////

struct ParamEnvelope
{
    float db0ms = 0.0;
    float db20ms = 0.0;
    float db120ms = 0.0;
    float dbENDms = 0.0;
};

//////////////////////
// Partition wisdom //
//////////////////////

enum {
    NUM_PARTITIONWISDOM_ENTRIES = 10
};

struct ParamPartitionWisdom
{
    ParamPartitionWisdom()
    {
        for (int i = 0; i < NUM_PARTITIONWISDOM_ENTRIES; i++)
        {
            t_const[i]  = 1.0;
            t_linear[i] = 1.0;
        }
    }

    double t_const[NUM_PARTITIONWISDOM_ENTRIES];
    double t_linear[NUM_PARTITIONWISDOM_ENTRIES];
};

/////////////////
// Preferences //
/////////////////

enum {
    STRATEGY_UNIFORM = 0,
    STRATEGY_LOWEST
};

struct ParamPreferences
{
    String presetFile;
    int sflen = 64;
    int strategy = STRATEGY_UNIFORM;
};

////////////
// Preset //
////////////

struct ParamPreset
{
    String name;
    ParamImpulseResponses impulseResponses;
    ParamCategory category;
    ParamTimbre timbre;
    ParamGainDelay gainDelay;
    ParamEnvelope envelope;
    String notes;
    int catIndex[4] = {-1, -1, -1, -1};
};

#endif   // __PARAM_H__
