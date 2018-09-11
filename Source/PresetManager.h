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


#ifndef __PRESETMANAGER_H__
#define __PRESETMANAGER_H__


#include "JuceHeader.h"
#include "Param.h"
#include "TextList.h"
#include <vector>


class PresetManager
{
public:
    PresetManager();
    ~PresetManager();

    int getNumPresets(void);
    int getCurrentPresetNum(void);
    void setCurrentPresetNum(int num);
    int getDefaultPresetNum(void);
    void setDefaultPresetNum(int num);
    std::vector<ParamPreset> getPresetDBcopy(void);
    void setPresetDB(const std::vector<ParamPreset> & newPresetDB);
    int readFile(const String &presetFilename);
    int save(void);
    int saveAs(const String &presetFile);
    int parseRoot(const XmlElement &element);
    ParamPreset parsePreset(const XmlElement &element, int catIndex[4]);
    ParamImpulseResponses parseImpulseResponses(const XmlElement &element);
    ParamCategory parseCategory(const XmlElement &element, int catIndex[4]);
    ParamEnvelope parseParamEnvelope(const XmlElement &element);
    ParamGainDelay parseParamGainDelay(const XmlElement &element);
    ParamTimbre parseParamTimbre(const XmlElement &element);

    const ParamPreset           & getPreset(int num);
    const String                & getName(int num);
    const ParamImpulseResponses & getImpulseResponses(int num);
    const ParamCategory         & getCategory(int num);
    const ParamTimbre           & getTimbre(int num);
    const ParamGainDelay        & getGainDelay(int num);
    const ParamEnvelope         & getEnvelope(int num);
    const String                & getNotes(int num);

    void setPreset           (int num, const ParamPreset & param);
    void setImpulseResponses (int num, const ParamImpulseResponses & param);
    void setCategory         (int num, const ParamCategory & param);
    void setEnvelope         (int num, const ParamEnvelope & param);
    void setGainDelay        (int num, const ParamGainDelay & param);
    void setTimbre           (int num, const ParamTimbre & param);

    const std::vector<String> & getList(int category);
    int getCategoryIndex(int num, int category);
    int getSimilarPreset(int current_preset, int cat, int cat_index);

    XmlElement* paramPresetToXML           (const ParamPreset           & param, int num);
    XmlElement* paramImpulseResponsesToXML (const ParamImpulseResponses & param);
    XmlElement* paramCategoryToXML         (const ParamCategory         & param);
    XmlElement* paramTimbreToXML           (const ParamTimbre           & param);
    XmlElement* paramGainDelayToXML        (const ParamGainDelay        & param);
    XmlElement* paramEnvelopeToXML         (const ParamEnvelope         & param);

private:
    static String getSubText(XmlElement *element);

    String presetFile;
    enum { maxPresets = 256 };
    std::unique_ptr<ParamPreset[]> preset;
    int numPresets = 0;
    int currentPresetNum = 1;
    int defaultPresetNum = 1;

    TextList vectorCat1;
    TextList vectorCat2;
    TextList vectorCat3;
    TextList vectorCat4;
    TextList vectorEmpty;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetManager)
};


#endif   // __PRESETMANAGER_H__
