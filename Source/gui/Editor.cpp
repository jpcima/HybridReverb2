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


#include "Editor.h"
#include "EditorComponent.h"
#include "DownloadDbComponent.h"
#include "../SystemConfig.h"


HybridReverb2Editor::HybridReverb2Editor(
    HybridReverb2Processor *ownerFilter,
    ReadyListener *readyListener,
    const std::shared_ptr<SystemConfig> &systemConfig)
    : AudioProcessorEditor(ownerFilter),
      systemConfig(systemConfig),
      readyListener(readyListener)
{
    lf.reset(new LookAndFeel_V3);
    LookAndFeel::setDefaultLookAndFeel(lf.get());

    EditorComponent *ec = new EditorComponent(ownerFilter);
    editorComponent.reset(ec);
    addChildComponent(ec);

    DownloadDbComponent *dl = new DownloadDbComponent(this);
    downloadDbComponent.reset(dl);
    addChildComponent(dl);

    setSize(ec->getWidth(), ec->getHeight());

    File presetFile(systemConfig->getPresetFilename());
    if (presetFile.exists())
    {
        ec->setVisible(true);
        readyListener->onReadyEditor();
    }
    else
    {
        dl->setCentrePosition(getBounds().getCentre());
        dl->setVisible(true);
    }
}

HybridReverb2Editor::~HybridReverb2Editor()
{
}

void HybridReverb2Editor::chooseDbFileAndLoad()
{
    FileChooser fc(TRANS("Please choose a file to load..."),
                   File::getSpecialLocation(File::userDocumentsDirectory),
                   "*.zip",
                   true);

    if (!fc.browseForFileToOpen())
        return;

    File chosenFile = fc.getResult();
    SystemConfig &cfg = *systemConfig;

    ZipFile zip(chosenFile);
    Result zipResult = zip.uncompressTo(cfg.getUserdir());

    if (zipResult.failed())
    {
        String message = TRANS("Error extracting database file") + " \"" +
                         chosenFile.getFullPathName() +
                         "\" :\n" +
                         zipResult.getErrorMessage();
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    TRANS("Error"), message);
        return;
    }

    File presetFile(systemConfig->getPresetFilename());
    if (!presetFile.exists())
    {
        String message = TRANS("Error extracting database file") + " \"" +
                         chosenFile.getFullPathName() +
                         "\" :\n" +
                         TRANS("the database did not contain valid preset data.");
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    TRANS("Error"), message);
        return;
    }

    downloadDbComponent->setVisible(false);
    editorComponent->setVisible(true);
    readyListener->onReadyEditor();
}

void HybridReverb2Editor::paint(Graphics &g)
{
    g.fillAll(Colour(0xffffe000));
}
