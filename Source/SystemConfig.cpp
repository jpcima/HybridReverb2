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
#include <math.h>
#include <stdlib.h>

SystemConfig::SystemConfig()
{
    File userdir = File
        ::getSpecialLocation(File::userApplicationDataDirectory)
        .getChildFile("HybridReverb2");
    this->userdir = userdir.getFullPathName() + "/";

    File dbdir = userdir.getChildFile("RIR_Database");
    this->dbdir = dbdir.getFullPathName() + "/";

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


const String & SystemConfig::getUserdir()
{
    return userdir;
}


const String & SystemConfig::getDBdir()
{
    return dbdir;
}


String SystemConfig::getPresetFilename()
{
    String presetFilename = paramPreferences.presetFile;
    if (presetFilename.isEmpty())
        presetFilename = "HybridReverb2_presets.xml";
    return File(userdir).getChildFile(presetFilename).getFullPathName();
}


const ParamPreferences & SystemConfig::getPreferences()
{
    return paramPreferences;
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
                         "\" :\n" +
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


void SystemConfig::setPreferences(const ParamPreferences & param)
{
    paramPreferences = param;

    File prefFile = File(userdir).getChildFile("preferences.xml");
    prefFile.create();

    String content = String("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n") +
                     String("<preferences>\n") +
                     String("  <presetFile>") + paramPreferences.presetFile       + String("</presetFile>\n") +
                     String("  <sflen>")      + String(paramPreferences.sflen)    + String("</sflen>\n")      +
                     String("  <strategy>")   + String(paramPreferences.strategy) + String("</strategy>\n")   +
                     String("</preferences>");
    prefFile.replaceWithText(content);
}


const ParamPartitionWisdom & SystemConfig::getPartitionWisdom()
{
    return paramPartitionWisdom;
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
                         "\" :\n" +
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
