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


#include "PresetCollection.h"
#include "../gui/TabTimbre.h"
#include "../utility/XmlUtil.h"
#include <math.h>
#include <iostream>


PresetCollection::PresetCollection()
{
    preset.reset(new ParamPreset[maxPresets]);
}

PresetCollection::~PresetCollection()
{
}


////////////////////////////////////////////////////////////////
//
//    public methods
//

int PresetCollection::getNumPresets(void)
{
    return numPresets;
}


int PresetCollection::getCurrentPresetNum(void)
{
    return currentPresetNum;
}


void PresetCollection::setCurrentPresetNum(int num)
{
    currentPresetNum = num;
}


int PresetCollection::getDefaultPresetNum(void)
{
    return defaultPresetNum;
}


void PresetCollection::setDefaultPresetNum(int num)
{
    defaultPresetNum = num;
}


std::vector<ParamPreset> PresetCollection::getPresetDBcopy(void)
{
    return std::vector<ParamPreset>(
        preset.get(), preset.get() + numPresets);
}


void PresetCollection::setPresetDB(const std::vector<ParamPreset> & newPresetDB)
{
    numPresets = newPresetDB.size();
    if (numPresets > maxPresets)
        numPresets = maxPresets;

    for (int i = 0; i < numPresets; ++i)
        preset[i] = newPresetDB[i];
    for (int i = numPresets; i < maxPresets; ++i)
        preset[i] = ParamPreset();

    // reorganize "category index" for selection via the combo boxes
    vectorCat1.clear();
    vectorCat2.clear();
    vectorCat3.clear();
    vectorCat4.clear();
    for (int i = 0; i < numPresets; i++)
    {
        ParamCategory cat = preset[i].category;
        preset[i].catIndex[0] = vectorCat1.findOrCreate(cat.cat_1);
        preset[i].catIndex[1] = vectorCat2.findOrCreate(cat.cat_2);
        preset[i].catIndex[2] = vectorCat3.findOrCreate(cat.cat_3);
        preset[i].catIndex[3] = vectorCat4.findOrCreate(cat.cat_4);
    }
}


int PresetCollection::readFile(const String &presetFilename, String *error)
{
    File presetFile(presetFilename);
    this->presetFile = presetFilename;


    XmlDocument xmlDoc(presetFile);
    std::unique_ptr<XmlElement> xmlRoot(xmlDoc.getDocumentElement());

    if (!xmlRoot)
    {
        String message = TRANS("Error reading preset file") + " \"" +
            presetFile.getFullPathName() + "\"" + TRANS(":") + "\n" +
            xmlDoc.getLastParseError();
        if (error)
            *error = message;
        else
            fprintf(stderr, "%s\n", message.toRawUTF8());
        return -1;
    }

    defaultPresetNum = parseRoot(xmlRoot.get(), error);
    return defaultPresetNum;
}


int PresetCollection::save(String *error)
{
    XmlElement xmlRoot("root");

    XmlElement* xmlDefault;
    xmlRoot.addChildElement(xmlDefault = new XmlElement("default"));

    XmlElement* textElement;
    xmlDefault->addChildElement(textElement = XmlElement::createTextElement(String(defaultPresetNum)));

    for (int i = 0; i < numPresets; i++)
    {
        xmlRoot.addChildElement(paramPresetToXML(preset[i], i + 1));
    }

    String xmlDoc = xmlRoot.createDocument(String());
    File file(this->presetFile);
    if (!file.replaceWithText(xmlDoc))
    {
        String message = TRANS("Error writing preset file") + " \"" +
            file.getFullPathName() + "\"";
        if (error)
            *error = message;
        else
            fprintf(stderr, "%s\n", message.toRawUTF8());
        return -1;
    }

    return 0;
}


int PresetCollection::saveAs(const String &presetFile, String *error)
{
    this->presetFile = presetFile;
    return save(error);
}


int PresetCollection::parseRoot(XmlElement *element, String *error)
{
    int ret = 1;

    numPresets = 0;

    forEachXmlChildElement(*element, child)
    {
        if (numPresets < maxPresets && child->hasTagName("preset"))
        {
            ParamPreset &p = preset[numPresets++];
            for (int i = 0; i < 4; i++)
                catIndex[i] = -1;
            p = parsePreset(child);
            for (int i = 0; i < 4; i++)
                p.catIndex[i] = catIndex[i];
        }
        else if (child->hasTagName("default"))
        {
            String text = getSubText(child);
            ret = text.getIntValue();
        }
    }

    if (numPresets <= 0)
    {
        String message = TRANS("Error reading preset data: no presets");
        if (error)
            *error = message;
        else
            fprintf(stderr, "%s\n", message.toRawUTF8());
        return -1;
    }

    return ret;
}


const ParamPreset & PresetCollection::parsePreset(XmlElement *element)
{
    retPreset = emptyPreset;

    forEachXmlChildElement(*element, child)
    {
        if (child->hasTagName("name"))
            retPreset.name = getSubText(child);
        else if (child->hasTagName("impulse_responses"))
            retPreset.impulseResponses = parseImpulseResponses(child);
        else if (child->hasTagName("category"))
            retPreset.category = parseCategory(child);
        else if (child->hasTagName("param_envelope"))
            retPreset.envelope = parseParamEnvelope(child);
        else if (child->hasTagName("param_gain_delay"))
            retPreset.gainDelay = parseParamGainDelay(child);
        else if (child->hasTagName("param_timbre"))
            retPreset.timbre = parseParamTimbre(child);
        else if (child->hasTagName("notes"))
            retPreset.notes = getSubText(child);
    }

    return retPreset;
}


const ParamImpulseResponses & PresetCollection::parseImpulseResponses(XmlElement *element)
{
    retImpulseResponses = emptyImpulseResponses;

    forEachXmlChildElement(*element, child)
    {
        if (child->hasTagName("ll"))
            retImpulseResponses.ll = getSubText(child);
        else if (child->hasTagName("lr"))
            retImpulseResponses.lr = getSubText(child);
        else if (child->hasTagName("rl"))
            retImpulseResponses.rl = getSubText(child);
        else if (child->hasTagName("rr"))
            retImpulseResponses.rr = getSubText(child);
    }

    return retImpulseResponses;
}


const ParamCategory & PresetCollection::parseCategory(XmlElement *element)
{
    retCategory = emptyCategory;

    forEachXmlChildElement(*element, child)
    {
        if (child->hasTagName("cat_1"))
        {
            retCategory.cat_1 = getSubText(child);
            catIndex[0] = vectorCat1.findOrCreate(retCategory.cat_1);
        }
        else if (child->hasTagName("cat_2"))
        {
            retCategory.cat_2 = getSubText(child);
            catIndex[1] = vectorCat2.findOrCreate(retCategory.cat_2);
        }
        else if (child->hasTagName("cat_3"))
        {
            retCategory.cat_3 = getSubText(child);
            catIndex[2] = vectorCat3.findOrCreate(retCategory.cat_3);
        }
        else if (child->hasTagName("cat_4"))
        {
            retCategory.cat_4 = getSubText(child);
            catIndex[3] = vectorCat4.findOrCreate(retCategory.cat_4);
        }
    }

    return retCategory;
}


const ParamEnvelope & PresetCollection::parseParamEnvelope(XmlElement *element)
{
    retEnvelope = emptyEnvelope;
    int counter = 0;

    forEachXmlChildElement(*element, child)
    {
        if (child->hasTagName("gain"))
        {
            String text = getSubText(child);
            switch (counter) {
            case 0:
                retEnvelope.db0ms = text.getFloatValue();
                break;
            case 1:
                retEnvelope.db20ms = text.getFloatValue();
                break;
            case 2:
                retEnvelope.db120ms = text.getFloatValue();
                break;
            case 3:
                retEnvelope.dbENDms = text.getFloatValue();
                break;
            }
            counter++;
        }
    }

    return retEnvelope;
}


const ParamGainDelay & PresetCollection::parseParamGainDelay(XmlElement *element)
{
    retGainDelay = emptyGainDelay;

    forEachXmlChildElement(*element, child)
    {
        String text = getSubText(child);
        float value = text.getFloatValue();
        if (child->hasTagName("initial_gap"))
            retGainDelay.initialGap = value;
        else if (child->hasTagName("length"))
            retGainDelay.length = value;
        else if (child->hasTagName("pre_delay"))
            retGainDelay.preDelay = value;
        else if (child->hasTagName("dry_gain"))
            retGainDelay.dryGain = value;
        else if (child->hasTagName("wet_gain"))
            retGainDelay.wetGain = value;
        else if (child->hasTagName("master_gain"))
            retGainDelay.masterGain = value;
    }

    return retGainDelay;
}


const ParamTimbre & PresetCollection::parseParamTimbre(XmlElement *element)
{
    retTimbre = emptyTimbre;
    int counter = 0;

    forEachXmlChildElement(*element, child)
    {
        String text = getSubText(child);
        float value = text.getFloatValue();
        if (child->hasTagName("gain") && counter < retTimbre.num)
        {
            retTimbre.data[counter] = value;
            counter++;
        }
        else if (child->hasTagName("smooth"))
            retTimbre.smooth = value;
    }

    return retTimbre;
}


const ParamPreset & PresetCollection::getPreset(int num)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1];
}


const String & PresetCollection::getName(int num)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1].name;
}


const ParamImpulseResponses & PresetCollection::getImpulseResponses(int num)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1].impulseResponses;
}


const ParamCategory & PresetCollection::getCategory(int num)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1].category;
}


const ParamTimbre & PresetCollection::getTimbre(int num)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1].timbre;
}


const ParamGainDelay & PresetCollection::getGainDelay(int num)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1].gainDelay;
}


const ParamEnvelope & PresetCollection::getEnvelope(int num)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1].envelope;
}


const String & PresetCollection::getNotes(int num)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1].notes;
}


void PresetCollection::setPreset(int num, const ParamPreset & param)
{
    jassert(num > 0 && num <= numPresets);
    preset[num - 1] = param;
}


void PresetCollection::setImpulseResponses(int num, const ParamImpulseResponses & param)
{
    jassert(num > 0 && num <= numPresets);
    preset[num - 1].impulseResponses = param;
}


void PresetCollection::setCategory(int num, const ParamCategory & param)
{
    jassert(num > 0 && num <= numPresets);
    preset[num - 1].category = param;
}


void PresetCollection::setEnvelope(int num, const ParamEnvelope & param)
{
    jassert(num > 0 && num <= numPresets);
    preset[num - 1].envelope = param;
}


void PresetCollection::setGainDelay(int num, const ParamGainDelay & param)
{
    jassert(num > 0 && num <= numPresets);
    preset[num - 1].gainDelay = param;
}


void PresetCollection::setTimbre(int num, const ParamTimbre & param)
{
    jassert(num > 0 && num <= numPresets);
    preset[num - 1].timbre = param;
}


const std::vector<String> & PresetCollection::getList(int category)
{
    switch (category) {
    case 0:
        return vectorCat1.getList();
    case 1:
        return vectorCat2.getList();
    case 2:
        return vectorCat3.getList();
    case 3:
        return vectorCat4.getList();
    }
    return vectorEmpty.getList();
}


int PresetCollection::getCategoryIndex(int num, int category)
{
    jassert(num > 0 && num <= numPresets);
    return preset[num - 1].catIndex[category];
}


int PresetCollection::getSimilarPreset(int current_preset, int cat, int cat_index)
{
    int catIndex_wish[4];
    double closest_distance = 1e16;
    int best_preset = 0;
    double penalty[4];

    penalty[3] = 1.0;
    penalty[2] = numPresets;
    penalty[1] = numPresets * numPresets;
    penalty[0] = numPresets * numPresets * numPresets;

    jassert(current_preset > 0 && current_preset <= numPresets);
    for (int i = 0; i < 4; i++)
        catIndex_wish[i] = preset[current_preset - 1].catIndex[i];
    catIndex_wish[cat] = cat_index;

    for (int p = 0; p < numPresets; p++)
    {
        int *loop_catIndex = preset[p].catIndex;
        if (loop_catIndex[cat] == cat_index)
        {
            double distance = 0.0;
            for (int c = 0; c < 4; c++)
                distance += abs(catIndex_wish[c] - loop_catIndex[c]) * penalty[c];
            if (distance < closest_distance)
            {
                best_preset = p;
                closest_distance = distance;
            }
        }
    }

    return best_preset + 1;
}


XmlElement* PresetCollection::paramPresetToXML(const ParamPreset & param, int num)
{
    std::unique_ptr<XmlElement> xmlPreset(new XmlElement("preset"));

    XmlElement* xmlNum;
    xmlPreset->addChildElement(xmlNum  = new XmlElement("num"));

    xmlNum->addChildElement(XmlElement::createTextElement(String(num)));

    XmlElement* xmlName;
    xmlPreset->addChildElement(xmlName = new XmlElement("name"));
    xmlName->addChildElement(XmlElement::createTextElement(param.name));

    if (XmlElement* xmlIRs = paramImpulseResponsesToXML(param.impulseResponses))
        xmlPreset->addChildElement(xmlIRs);

    if (XmlElement* xmlCategory = paramCategoryToXML(param.category))
        xmlPreset->addChildElement(xmlCategory);

    if (XmlElement* xmlTimbre = paramTimbreToXML(param.timbre))
        xmlPreset->addChildElement(xmlTimbre);

    if (XmlElement* xmlGainDelay = paramGainDelayToXML(param.gainDelay))
        xmlPreset->addChildElement(xmlGainDelay);

    if (XmlElement* xmlEnvelope = paramEnvelopeToXML(param.envelope))
        xmlPreset->addChildElement(xmlEnvelope);

    XmlElement* xmlNotes;
    xmlPreset->addChildElement(xmlNotes = new XmlElement("notes"));
    xmlNotes->addChildElement(XmlElement::createTextElement(param.notes));

    return xmlPreset.release();
}


XmlElement* PresetCollection::paramImpulseResponsesToXML(const ParamImpulseResponses & param)
{
    if (param.ll == String() &&
        param.lr == String() &&
        param.rl == String() &&
        param.rr == String())
    return 0;

    std::unique_ptr<XmlElement> xmlIRs(new XmlElement("impulse_responses"));

    if (param.ll != String())
    {
        XmlElement* xmlWav;
        xmlIRs->addChildElement(xmlWav = new XmlElement("ll"));
        xmlWav->addChildElement(XmlElement::createTextElement(param.ll));
    }

    if (param.lr != String())
    {
        XmlElement* xmlWav;
        xmlIRs->addChildElement(xmlWav = new XmlElement("lr"));
        xmlWav->addChildElement(XmlElement::createTextElement(param.lr));
    }

    if (param.rl != String())
    {
        XmlElement* xmlWav;
        xmlIRs->addChildElement(xmlWav = new XmlElement("rl"));
        xmlWav->addChildElement(XmlElement::createTextElement(param.rl));
    }

    if (param.rr != String())
    {
        XmlElement* xmlWav;
        xmlIRs->addChildElement(xmlWav = new XmlElement("rr"));
        xmlWav->addChildElement(XmlElement::createTextElement(param.rr));
    }

    return xmlIRs.release();
}


XmlElement* PresetCollection::paramCategoryToXML(const ParamCategory & param)
{
    if (param.cat_1 == String() &&
        param.cat_2 == String() &&
        param.cat_3 == String() &&
        param.cat_4 == String())
    return 0;

    XmlElement* xmlCategory = new XmlElement("category");

    if (param.cat_1 != String())
    {
        XmlElement* xmlWav = new XmlElement("cat_1");
        XmlElement* textElement = XmlElement::createTextElement(param.cat_1);
        xmlWav->addChildElement(textElement);
        xmlCategory->addChildElement(xmlWav);
    }

    if (param.cat_2 != String())
    {
        XmlElement* xmlWav = new XmlElement("cat_2");
        XmlElement* textElement = XmlElement::createTextElement(param.cat_2);
        xmlWav->addChildElement(textElement);
        xmlCategory->addChildElement(xmlWav);
    }

    if (param.cat_3 != String())
    {
        XmlElement* xmlWav = new XmlElement("cat_3");
        XmlElement* textElement = XmlElement::createTextElement(param.cat_3);
        xmlWav->addChildElement(textElement);
        xmlCategory->addChildElement(xmlWav);
    }

    if (param.cat_4 != String())
    {
        XmlElement* xmlWav = new XmlElement("cat_4");
        XmlElement* textElement = XmlElement::createTextElement(param.cat_4);
        xmlWav->addChildElement(textElement);
        xmlCategory->addChildElement(xmlWav);
    }

    return xmlCategory;
}


XmlElement* PresetCollection::paramTimbreToXML(const ParamTimbre & param)
{
    bool enabledTimbre = false;
    for (int i = 0; enabledTimbre == false && i < param.num; i++)
    {
        if (param.data[i] != 0.0)
            enabledTimbre = true;
    }
    if (enabledTimbre == false)
        return 0;

    std::unique_ptr<XmlElement> xmlTimbre(new XmlElement("param_timbre"));

    String text = String(param.smooth);
    XmlElement* xmlSmooth;
    xmlTimbre->addChildElement(xmlSmooth = new XmlElement("smooth"));
    xmlSmooth->addChildElement(XmlElement::createTextElement(text));

    for (int i = 0; i < param.num; i++)
    {
        String text = String(param.data[i]);
        XmlElement* xmlGain;
        xmlTimbre->addChildElement(xmlGain = new XmlElement("gain"));
        xmlGain->addChildElement(XmlElement::createTextElement(text));
    }

    return xmlTimbre.release();
}


XmlElement* PresetCollection::paramGainDelayToXML(const ParamGainDelay & param)
{
    bool enabledGainDelay = false;
    if (fabs(param.initialGap) > 0.05)
        enabledGainDelay = true;
    if (param.length           >= 0.0)
        enabledGainDelay = true;
    if (fabs(param.preDelay)   > 0.05)
        enabledGainDelay = true;
    if (fabs(param.dryGain)    > 0.05)
        enabledGainDelay = true;
    if (fabs(param.wetGain)    > 0.05)
        enabledGainDelay = true;
    if (fabs(param.masterGain) > 0.05)
        enabledGainDelay = true;
    if (enabledGainDelay == false)
        return 0;

    std::unique_ptr<XmlElement> xmlGainDelay(new XmlElement("param_gain_delay"));

    if (fabs(param.initialGap) > 0.05)
    {
        String text = String(param.initialGap);
        XmlElement* xmlInitialGap;
        xmlGainDelay->addChildElement(xmlInitialGap = new XmlElement("initial_gap"));
        xmlInitialGap->addChildElement(XmlElement::createTextElement(text));
    }

    if (param.length >= 0.0)
    {
        String text = String(param.length);
        XmlElement* xmlLength;
        xmlGainDelay->addChildElement(xmlLength = new XmlElement("length"));
        xmlLength->addChildElement(XmlElement::createTextElement(text));
    }

    if (fabs(param.preDelay) > 0.05)
    {
        String text = String(param.preDelay);
        XmlElement* xmlPreDelay;
        xmlGainDelay->addChildElement(xmlPreDelay = new XmlElement("pre_delay"));
        xmlPreDelay->addChildElement(XmlElement::createTextElement(text));
    }

    if (fabs(param.dryGain) > 0.05)
    {
        String text = String(param.dryGain);
        XmlElement* xmlDryGain;
        xmlGainDelay->addChildElement(xmlDryGain = new XmlElement("dry_gain"));
        xmlDryGain->addChildElement(XmlElement::createTextElement(text));
    }

    if (fabs(param.wetGain) > 0.05)
    {
        String text = String(param.wetGain);
        XmlElement* xmlWetGain;
        xmlGainDelay->addChildElement(xmlWetGain = new XmlElement("wet_gain"));
        xmlWetGain->addChildElement(XmlElement::createTextElement(text));
    }

    if (fabs(param.masterGain) > 0.05)
    {
        String text = String(param.masterGain);
        XmlElement* xmlMasterGain;
        xmlGainDelay->addChildElement(xmlMasterGain = new XmlElement("master_gain"));
        xmlMasterGain->addChildElement(XmlElement::createTextElement(text));
    }

    return xmlGainDelay.release();
}


XmlElement* PresetCollection::paramEnvelopeToXML(const ParamEnvelope & param)
{
    bool enabledEnvelope = false;
    if (fabs(param.db0ms)   > 0.05)
        enabledEnvelope = true;
    if (fabs(param.db20ms)  > 0.05)
        enabledEnvelope = true;
    if (fabs(param.db120ms) > 0.05)
        enabledEnvelope = true;
    if (fabs(param.dbENDms) > 0.05)
        enabledEnvelope = true;
    if (enabledEnvelope == false)
        return 0;

    std::unique_ptr<XmlElement> xmlEnvelope(new XmlElement("param_envelope"));

    String text = String(param.db0ms);
    XmlElement* xmlGain;
    xmlEnvelope->addChildElement(xmlGain = new XmlElement("gain"));
    xmlGain->addChildElement(XmlElement::createTextElement(text));

    text = String(param.db20ms);
    xmlEnvelope->addChildElement(xmlGain = new XmlElement("gain"));
    xmlGain->addChildElement(XmlElement::createTextElement(text));

    text = String(param.db120ms);
    xmlEnvelope->addChildElement(xmlGain = new XmlElement("gain"));
    xmlGain->addChildElement(XmlElement::createTextElement(text));

    text = String(param.dbENDms);
    xmlEnvelope->addChildElement(xmlGain = new XmlElement("gain"));
    xmlGain->addChildElement(XmlElement::createTextElement(text));

    return xmlEnvelope.release();
}
