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


#ifndef __HybridConvolver__
#define __HybridConvolver__


#include "SampleData.h"
#include "JuceHeader.h"

extern "C" {
#include "libHybridConv/libHybridConv.h"
}


class HybridConvolver
{
public:
    HybridConvolver();
    virtual ~HybridConvolver() {}

    virtual void process(const float** inputs,
                         float** outputs,
                         int numOutput,
                         int numSamples) = 0;
    void process(AudioSampleBuffer& buffer);

protected:
    std::unique_ptr<float[]> m_inbuf;
    std::unique_ptr<float[]> m_outbuf;
    int m_bufpos = 0;
    int m_lenShort = 256;
    int m_lenMedium = 1024;
    int m_lenLong = 4096;
    int m_numFilter = 0;
    std::unique_ptr<int[]> m_routeIn;
    std::unique_ptr<int[]> m_routeOut;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HybridConvolver)
};


#endif // __HybridConvolver__
