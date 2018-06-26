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


#ifndef __PARAMPRESET_H__
#define __PARAMPRESET_H__


#include "ParamCategory.h"
#include "ParamEnvelope.h"
#include "ParamGainDelay.h"
#include "ParamImpulseResponses.h"
#include "ParamTimbre.h"


class ParamPreset
{
public:
    String name;
    ParamImpulseResponses impulseResponses;
    ParamCategory category;
    ParamTimbre timbre;
    ParamGainDelay gainDelay;
    ParamEnvelope envelope;
    String notes;
    int catIndex[4] = {-1, -1, -1, -1};
};


#endif   // __PARAMPRESET_H__
