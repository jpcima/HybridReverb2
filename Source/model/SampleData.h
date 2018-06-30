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


#ifndef __SAMPLEDATA_H__
#define __SAMPLEDATA_H__


#include "../../JuceLibraryCode/JuceHeader.h"
#include "../model/Parameter.h"
#include <vector>

extern "C" {
#include "../libHybridConv/libHybridConv.h"
}


class SampleData : public ReferenceCountedObject
{
public:
    SampleData ();
    ~SampleData();

    typedef ReferenceCountedObjectPtr<SampleData> Ptr;

    int applyLoadFiles(const String &dir,
                       const String &fileLL,
                       const String &fileLR,
                       const String &fileRL,
                       const String &fileRR,
                       std::vector<String> *errors);
    int applyLoadFiles(String dir, ParamImpulseResponses *param,
                       std::vector<String> *errors);
    int loadSingleFile(String filename, int num, String *error);
    void applyGainDelay(SampleData *source, ParamGainDelay *param);
    void applyEnvelope(SampleData *source, ParamEnvelope *param);
    void applyTimbre(SampleData *source, int filterLen, float *filter);
    float *getData(int num);
    int getDataLen(void);
    int getSampleRate(void);
    bool hasData(int num);


private:
    std::unique_ptr<float[]> samplesLL, samplesLR, samplesRL, samplesRR;
    int bufferLen = 0;    // number of samples which fit into the sample buffers
    int dataLen = 0;    // number of samples in the sample buffers
    int fs = 0;
    bool available[4] = {false, false, false, false};

    void checkLength(int len);
    void applySingleTimbre(HConvSingle *hcSingle, float *in, float *out, int len);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleData)
};


#endif   // __SAMPLEDATA_H__
