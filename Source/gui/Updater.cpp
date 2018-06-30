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

#include "Updater.h"

void MetaUpdater::handleAsyncUpdate()
{
    fprintf(stderr, "Async update: Meta\n");

    TabMain *tabMain = this->tabMain.getComponent();
    if (!tabMain)
        return;

    tabMain->setNum(num);
    tabMain->setID(name);
    tabMain->setNotes(notes);

    for (int i = 0; i < 4; i++)
    {
        tabMain->setComboText(i, categories[i]);
        tabMain->setComboIndex(i, categoryIndex[i]);
    }
}

void EnvelopeUpdater::handleAsyncUpdate()
{
    fprintf(stderr, "Async update: Envelope\n");

    TabMain *tabMain = this->tabMain.getComponent();
    if (!tabMain)
        return;

    tabMain->setEnvelope(&param);
}

void TimbreUpdater::handleAsyncUpdate()
{
    fprintf(stderr, "Async update: Timbre\n");

    TabTimbre *tabTimbre = this->tabTimbre.getComponent();
    if (!tabTimbre)
        return;

    tabTimbre->setTimbre(&param);
}

void GainDelayUpdater::handleAsyncUpdate()
{
    fprintf(stderr, "Async update: Gain Delay\n");

    TabMain *tabMain = this->tabMain.getComponent();
    if (!tabMain)
        return;

    tabMain->setGainDelayRange(&min, &param, &max);
}

void IRPlotUpdater::handleAsyncUpdate()
{
    fprintf(stderr, "Async update: IR Plot\n");

    IRPlot *irPlot = this->irPlot.getComponent();
    if (!irPlot)
        return;

    SampleData *data = sampleData.get();
    if (!data)
        return;

    irPlot->samples2plot(data->getData(0),
                         data->getData(1),
                         data->getData(2),
                         data->getData(3),
                         data->getDataLen(),
                         data->getSampleRate());
}
