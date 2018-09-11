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
#include "Definitions.h"
#include "../SystemConfig.h"


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
                   FileChooserUseNative);

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
    Result zipResult = uncompressDatabaseTo(zip, presetDir,
        [self](double progress) {
            MessageManagerLock lock;
            MessageManager::callAsync(
                [self, progress]() {
                    if (!self)
                        return;

                    self.getComponent()->downloadDbComponent->setProgress(progress);
                }
            );
        });

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

Result HybridReverb2Editor::uncompressDatabaseTo(ZipFile &zip, const File &presetDir,
                                                 const std::function<void(double)> &onProgress)
{
    onProgress(0);

    bool found = false;
    String prefix;
    for (unsigned i = 0, n = zip.getNumEntries(); !found && i < n; ++i) {
        const ZipFile::ZipEntry *ent = zip.getEntry(i);
        const String &filename = ent->filename;
        if (filename == "HybridReverb2_presets.xml" || filename.endsWith("/HybridReverb2_presets.xml")) {
            unsigned prefix_size = (unsigned)filename.length() - (unsigned)strlen("HybridReverb2_presets.xml");
            prefix = filename.substring(0, prefix_size);
            found = true;
        }
    }

    if (!found)
        return Result::fail(TRANS("the database did not contain valid preset data."));

    for (unsigned i = 0, n = zip.getNumEntries(); i < n; ++i) {
        const ZipFile::ZipEntry *ent = zip.getEntry(i);
        const String &filename = ent->filename;
        if (filename.isEmpty() || filename.endsWithChar('/') || !filename.startsWith(prefix))
            continue;

        File targetFile = presetDir.getChildFile(filename.substring(prefix.length()));
        if (!targetFile.isAChildOf(presetDir))
            continue;

        std::unique_ptr<InputStream> istream(zip.createStreamForEntry(*ent));
        if (!istream)
            return Result::fail(TRANS("uncompression failed"));

        if (ent->isSymbolicLink) {
            String symlink(istream->readEntireStreamAsString());
            if (!File::createSymbolicLink(targetFile, symlink, true))
                return Result::fail(TRANS("write failed"));
        }
        else {
            targetFile.getParentDirectory().createDirectory();
            std::unique_ptr<FileOutputStream> ostream(targetFile.createOutputStream());
            if (!ostream)
                return Result::fail(TRANS("write failed"));

            ostream->setPosition(0);
            ostream->truncate();
            ostream->writeFromInputStream(*istream, -1);
            ostream->flush();

            const Result &res = ostream->getStatus();
            if (res.failed())
                return res;
        }

        onProgress((double)(i + 1) / n);
    }

    onProgress(1.0);
    return Result::ok();
}

void HybridReverb2Editor::paint(Graphics &g)
{
    g.fillAll(Colour(0xffffe000));
}
