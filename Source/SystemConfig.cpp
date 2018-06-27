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


#include "SystemConfig.h"
#include "gui/TabTimbre.h"
#include "../JuceLibraryCode/BinaryData.h"
#include <math.h>
#include <stdlib.h>

namespace BinaryData {
    const char *getNamedResource(const char *resourceNameUTF8, int &dataSizeInBytes);
}

SystemConfig::SystemConfig(const String &customUserDir)
{
    File userdir = getDefaultUserDir();

    if(customUserDir.isNotEmpty())
        userdir = File(customUserDir);
    this->userdir = userdir.getFullPathName() + "/";

    userdir.createDirectory();

    File prefFile = userdir.getChildFile("preferences.xml");
    if (!prefFile.existsAsFile())
    {
        prefFile.create();
        prefFile.replaceWithData(
            BinaryData::preferences_xml, BinaryData::preferences_xmlSize);
    }

    File wisdomFile = userdir.getChildFile("partition_wisdom.xml");
    if (!wisdomFile.existsAsFile())
    {
        wisdomFile.create();
        wisdomFile.replaceWithData(
            BinaryData::partition_wisdom_xml, BinaryData::partition_wisdom_xmlSize);
    }

    readPreferencesFile();
    readPartitionWisdomFile();

    successfulLoad = true;
}

SystemConfig::~SystemConfig()
{
}


////////////////////////////////////////////////////////////////
//
//    public methods
//


String SystemConfig::getDBdir() const
{
    File dbdir = File(getPresetFilename())
        .getParentDirectory()
        .getChildFile("RIR_Database");
    return dbdir.getFullPathName() + "/";
}


String SystemConfig::getDefaultUserDir()
{
    return File::getSpecialLocation(File::userApplicationDataDirectory)
        .getChildFile("HybridReverb2").getFullPathName() + "/";
}


String SystemConfig::getDefaultUserPresetFilename()
{
    return File(getDefaultUserDir())
        .getChildFile("HybridReverb2_presets.xml").getFullPathName();
}


String SystemConfig::getDefaultPresetFilename()
{
#if defined(USE_LOCAL_DATABASE)
    return INSTALL_PREFIX "/share/HybridReverb2/HybridReverb2_presets.xml";
#else
    return getDefaultUserPresetFilename();
#endif
}


String SystemConfig::getPresetFilename() const
{
    const String &presetFilename = paramPreferences.presetFile;

    if (presetFilename.isEmpty())
        return getDefaultPresetFilename();

    if (File::isAbsolutePath(presetFilename))
        return File(presetFilename).getFullPathName();
    else
        return File(getDefaultUserDir())
            .getChildFile(presetFilename).getFullPathName();
}


void SystemConfig::readPreferencesFile()
{
    File prefFile = File(userdir).getChildFile("preferences.xml");

    std::unique_ptr<XmlDocument> xmlDoc(new XmlDocument(prefFile));
    std::unique_ptr<XmlElement> element(xmlDoc->getDocumentElement());

    if (!element)
    {
        String message = TRANS("Error reading preferences file") + " \"" +
                         prefFile.getFullPathName() +
                         "\"" + TRANS(":") + "\n" +
                         xmlDoc->getLastParseError();
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    TRANS("Error"), message);

        String xmlData(BinaryData::preferences_xml, BinaryData::preferences_xmlSize);
        xmlDoc.reset(new XmlDocument(xmlData));
        element.reset(xmlDoc->getDocumentElement());
        jassert(element);
    }

    forEachXmlChildElement(*element, child)
    {
        if (child->hasTagName("presetFile"))
        {
            paramPreferences.presetFile = getSubText(child);
        }
        else if (child->hasTagName("sflen"))
        {
            String text = getSubText(child);
            paramPreferences.sflen = text.getIntValue();
        }
        else if (child->hasTagName("strategy"))
        {
            String text = getSubText(child);
            paramPreferences.strategy = text.getIntValue();
        }
    }
}


void SystemConfig::writePreferencesFile()
{
    File prefFile = File(userdir).getChildFile("preferences.xml");
    prefFile.create();

    XmlElement root("preferences");
    XmlElement *element;
    root.addChildElement((element = new XmlElement("presetFile")));
    element->addTextElement(paramPreferences.presetFile);
    root.addChildElement((element = new XmlElement("sflen")));
    element->addTextElement(String(paramPreferences.sflen));
    root.addChildElement((element = new XmlElement("strategy")));
    element->addTextElement(String(paramPreferences.strategy));

    String content = root.createDocument(String());
    fprintf(stderr, "Save preferences: %s\n", prefFile.getFullPathName().toRawUTF8());
    prefFile.replaceWithText(content);
}


void SystemConfig::setPreferences(const ParamPreferences & param)
{
    paramPreferences = param;
    writePreferencesFile();
}


void SystemConfig::readPartitionWisdomFile()
{
    File wisdomFile = File(userdir).getChildFile("partition_wisdom.xml");

    std::unique_ptr<XmlDocument> xmlDoc(new XmlDocument(wisdomFile));
    std::unique_ptr<XmlElement> element(xmlDoc->getDocumentElement());

    if (!element)
    {
        String message = TRANS("Error reading wisdom file") + " \"" +
                         wisdomFile.getFullPathName() +
                         "\"" + TRANS(":") + "\n" +
                         xmlDoc->getLastParseError();
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    TRANS("Error"), message);

        String xmlData(BinaryData::partition_wisdom_xml, BinaryData::partition_wisdom_xmlSize);
        xmlDoc.reset(new XmlDocument(xmlData));
        element.reset(xmlDoc->getDocumentElement());
        jassert(element);
    }

    int num_const = 0;
    int num_linear = 0;
    forEachXmlChildElement(*element, child)
    {
        if (child->hasTagName("const") &&
            num_const < NUM_PARTITIONWISDOM_ENTRIES)
        {
            String value = getSubText(child);
            paramPartitionWisdom.t_const[num_const] = value.getDoubleValue();
            num_const++;
        }
        else if (child->hasTagName("linear") &&
                 num_linear < NUM_PARTITIONWISDOM_ENTRIES)
        {
            String value = getSubText(child);
            paramPartitionWisdom.t_linear[num_linear] = value.getDoubleValue();
            num_linear++;
        }
    }
}


////////////////////////////////////////////////////////////////
//
//    private methods
//

String SystemConfig::getSubText(XmlElement *element)
{
    forEachXmlChildElement(*element, child)
    {
        if (child->isTextElement())
        {
            return child->getText();
        }
    }
    return String();
}

void SystemConfig::setupLanguage()
{
    String lang = SystemStats::getUserLanguage();
    fprintf(stderr, "Language: %s\n", lang.toRawUTF8());

    lang = lang.dropLastCharacters(lang.length() - 2);
    lang = lang.toLowerCase();
    if (lang.isEmpty())
        return;

    fprintf(stderr, "Language code: %s\n", lang.toRawUTF8());

    String resourceName = "I18nResource_" + lang;

    unsigned trSize;
    const char *trData = BinaryData::getNamedResource(
        resourceName.toRawUTF8(), (int &)trSize);

    if (!trData)
    {
        fprintf(stderr, "No translation for language '%s'\n", lang.toRawUTF8());
        return;
    }

    std::unique_ptr<LocalisedStrings> ls(
        new LocalisedStrings(String::fromUTF8(trData, trSize), false));
    LocalisedStrings::setCurrentMappings(ls.get());
    ls.release();
}
