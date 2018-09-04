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


#ifndef __IRPLOT_H__
#define __IRPLOT_H__


#include "JuceHeader.h"
#include "../ParamEnvelope.h"


enum IRPLOT_CONSTANTS { IRPLOT_GRID_X = 25,
                        IRPLOT_GRID_Y = 30 };


// forward declarations
class MasterAndCommander;


class IRPlot  : public Component
{
public:
    IRPlot (MasterAndCommander *m);
    ~IRPlot();

    void paint (Graphics& g);
    void resized();

    void samples2plot(float *imp1, float *imp2, float *imp3, float *imp4, int len, int fs);
    void setEnvelope(ParamEnvelope *param);

private:
    MasterAndCommander* master = nullptr;
    std::unique_ptr<ParamEnvelope> paramEnvelope;
    std::unique_ptr<float[]> plotMax, plotRMS, plotRMSAccu;
    std::unique_ptr<int[]> plotRMSCounter;
    int numPlotPoints = 0;
    int offsetX = 64,
        offsetY = 32;
    float lenEND = 0.0;

    float dBfloor(float x, float f);
    float dBfloor10(float x, float f);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IRPlot)
};


#endif   // __IRPLOT_H__
