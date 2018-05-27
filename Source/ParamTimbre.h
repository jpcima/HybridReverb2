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


#ifndef __PARAMTIMBRE_H__
#define __PARAMTIMBRE_H__


#include "../JuceLibraryCode/JuceHeader.h"
#include <math.h>


class ParamTimbre
{
public:
    ParamTimbre()
    {
        data.reset(new float[num]);
        for (int i = 0; i < num; i++)
            data[i] = 0.0;
    }

    ParamTimbre(const ParamTimbre &other)
    {
        set(other.data.get(),
            other.num,
            other.freq,
            other.ratio,
            other.smooth);
    }

    ParamTimbre(float *y, int n, float f, float r, float s)
    {
        set(y, n, f, r, s);
    }

    ~ParamTimbre()
    {
    }

    ParamTimbre & operator = (const ParamTimbre &other)
    {
        set(other.data.get(),
            other.num,
            other.freq,
            other.ratio,
            other.smooth);
        return *this;
    }

    void set(float *y, int n, float f, float r, float s)
    {
        data.reset(new float[n]);
        for (int i = 0; i < n; i++)
            data[i] = y[i];
        num    = n;
        freq   = f;
        ratio  = r;
        smooth = s;
    }

    void set(ParamTimbre *param)
    {
        set(param->data.get(), param->num, param->freq, param->ratio, param->smooth);
    }

    std::unique_ptr<float[]> data;
    int num = 25;
    float freq = 62.5;
    float ratio = 1.25992104989487319;  // 2^(1/3)
    float smooth = 0.0;
};


#endif   // __PARAMTIMBRE_H__
