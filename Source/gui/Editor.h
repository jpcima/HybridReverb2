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


#ifndef __EDITOR_H__
#define __EDITOR_H__

#include "JuceHeader.h"

class HybridReverb2Processor;
class EditorComponent;
class DownloadDbComponent;
class SystemConfig;

class HybridReverb2Editor : public AudioProcessorEditor
{
public:
    class ReadyListener;

    HybridReverb2Editor(
        HybridReverb2Processor *ownerFilter,
        ReadyListener *readyListener,
        const std::shared_ptr<SystemConfig> &systemConfig);
    ~HybridReverb2Editor();

    class ReadyListener
    {
    public:
        virtual ~ReadyListener() {}
        virtual void onReadyEditor() = 0;
    };

    void chooseDbFileAndLoad();

    void paint(Graphics &g) override;

private:
    void onSetupSuccess();
    void onSetupFailure();
    static void performAsyncSetup(
        Component::SafePointer<HybridReverb2Editor> self, const File &zipFile);

    static Result uncompressDatabaseTo(ZipFile &zip, const File &presetDir,
                                       const std::function<void(double)> &onProgress);

    std::shared_ptr<SystemConfig> systemConfig;
    std::unique_ptr<EditorComponent> editorComponent;
    std::unique_ptr<DownloadDbComponent> downloadDbComponent;
    ReadyListener *readyListener = nullptr;
    bool asyncSetupStarted = false;

    std::unique_ptr<LookAndFeel> lf;

private:
    //==========================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HybridReverb2Editor);
};

#endif
