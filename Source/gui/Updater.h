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

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../model/Parameter.h"
#include "../model/SampleData.h"
#include "../gui/TabMain.h"
#include "../gui/TabTimbre.h"
#include "../gui/IRPlot.h"

struct MetaUpdater : public AsyncUpdater
{
    int num = 0;
    String name;
    String notes;
    std::vector<String> categories[4];
    int categoryIndex[4] = {};
    Component::SafePointer<TabMain> tabMain;
    void handleAsyncUpdate() override;
};

struct EnvelopeUpdater : public AsyncUpdater
{
    ParamEnvelope param;
    Component::SafePointer<TabMain> tabMain;
    void handleAsyncUpdate() override;
};

struct TimbreUpdater : public AsyncUpdater
{
    ParamTimbre param;
    Component::SafePointer<TabTimbre> tabTimbre;
    void handleAsyncUpdate() override;
};

struct GainDelayUpdater : public AsyncUpdater
{
    ParamGainDelay param;
    ParamGainDelay min;
    ParamGainDelay max;
    Component::SafePointer<TabMain> tabMain;
    void handleAsyncUpdate() override;
};

struct IRPlotUpdater : public AsyncUpdater
{
    SampleData::Ptr sampleData;
    Component::SafePointer<IRPlot> irPlot;
    void handleAsyncUpdate() override;
};
