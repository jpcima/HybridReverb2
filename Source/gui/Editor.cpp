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
#include "AppLookAndFeel.h"
#include "../model/SystemConfig.h"


HybridReverb2Editor::HybridReverb2Editor(
    HybridReverb2Processor *ownerFilter,
    ReadyListener *readyListener,
    const std::shared_ptr<SystemConfig> &systemConfig)
    : AudioProcessorEditor(ownerFilter),
      systemConfig(systemConfig),
      readyListener(readyListener)
{
    lf.reset(new AppLookAndFeel);
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
#if defined(USE_LOCAL_DATABASE)
        // go back to using the default presets
        fprintf(stderr, "Presets not found, falling back to default.\n");

        ParamPreferences prefs = systemConfig->getPreferences();
        prefs.presetFile = String();
        systemConfig->setPreferences(prefs);

        ec->setVisible(true);
        readyListener->onReadyEditor();
#else
        // prompt for database download
        fprintf(stderr, "Presets not found, asking to download.\n");

        dl->setCentrePosition(getBounds().getCentre());
        dl->setVisible(true);
#endif
    }
}

HybridReverb2Editor::~HybridReverb2Editor()
{
}

void HybridReverb2Editor::chooseDbFileAndLoad()
{
    if (asyncSetupStarted)
        return;

    asyncSetupStarted = true;

    FileChooser fc(TRANS("Please choose a file to load..."),
                   File::getSpecialLocation(File::userDocumentsDirectory),
                   "*.zip",
                   true);

    if (!fc.browseForFileToOpen())
    {
        asyncSetupStarted = false;
        return;
    }

    File chosenFile = fc.getResult();
    Component::SafePointer<HybridReverb2Editor> safeThis(this);

    fprintf(stderr, "Editor: about to launch setup\n");
    MouseCursor::showWaitCursor();

    Thread::launch(
        [safeThis, chosenFile]() { performAsyncSetup(safeThis, chosenFile); });
}

void HybridReverb2Editor::onSetupSuccess()
{
    fprintf(stderr, "Editor: setup success\n");
    downloadDbComponent->setVisible(false);
    editorComponent->setVisible(true);
    MouseCursor::hideWaitCursor();
    asyncSetupStarted = false;

    ParamPreferences prefs = systemConfig->getPreferences();
    prefs.presetFile = SystemConfig::getDefaultUserPresetFilename();
    systemConfig->setPreferences(prefs);

    readyListener->onReadyEditor();
}

void HybridReverb2Editor::onSetupFailure()
{
    fprintf(stderr, "Editor: setup failure\n");
    MouseCursor::hideWaitCursor();
    asyncSetupStarted = false;
}

void HybridReverb2Editor::performAsyncSetup(
    Component::SafePointer<HybridReverb2Editor> self, const File &zipFile)
{
    ZipFile zip(zipFile);

    File presetDir = SystemConfig::getDefaultUserDir();
    File presetFile = SystemConfig::getDefaultUserPresetFilename();

    fprintf(stderr, "EditorAsync: about to unzip\n");
    Result zipResult = zip.uncompressTo(presetDir);

    if (zipResult.failed())
    {
        fprintf(stderr, "EditorAsync: unzip failure\n");

        MessageManagerLock lock;
        MessageManager::callAsync(
            [self, zipFile, zipResult]()
                {
                    if (!self)
                        return;

                    String message = TRANS("Error extracting database file") + " \"" +
                        zipFile.getFullPathName() +
                        "\"" + TRANS(":") + "\n" +
                        zipResult.getErrorMessage();
                    AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                                TRANS("Error"), message);

                    self.getComponent()->onSetupFailure();
                });
        return;
    }

    if (!presetFile.exists())
    {
        fprintf(stderr, "EditorAsync: unzip bad contents\n");

        MessageManagerLock lock;
        MessageManager::callAsync(
            [self, zipFile]()
                {
                    if (!self)
                        return;

                    String message = TRANS("Error extracting database file") + " \"" +
                        zipFile.getFullPathName() +
                        "\"" + TRANS(":") + "\n" +
                        TRANS("the database did not contain valid preset data.");
                    AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                                TRANS("Error"), message);

                    self.getComponent()->onSetupFailure();
                });
        return;
    }

    fprintf(stderr, "EditorAsync: unzip success\n");

    MessageManagerLock lock;
    MessageManager::callAsync(
        [self]()
            {
                if (!self)
                    return;

                self.getComponent()->onSetupSuccess();
            });
}

void HybridReverb2Editor::paint(Graphics &g)
{
    g.fillAll(Colour(0xffffe000));
}
