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

#ifndef INSTALL_PREFIX
#define INSTALL_PREFIX "/usr/local"
#endif

SystemConfig::SystemConfig()
{
#ifdef _WINDOWS
    extractBasedirWindows();
    extractUserdirWindows();
    dbdir = basedir + String("\\RIR_Database\\");
#else
    extractBasedirUnix();
    extractUserdirUnix();
    dbdir = basedir + String("/RIR_Database/");
#endif

    File dstDir(userdir);
    if (dstDir.isDirectory() == false)
    {
        dstDir.createDirectory();
    }

#ifdef _WINDOWS
    String filenameDst = userdir + String("\\preferences.xml");
    String filenameSrc = basedir + String("\\preferences.xml");
#else
    String filenameDst = userdir + String("/preferences.xml");
    String filenameSrc = basedir + String("/preferences.xml");
#endif
    File preferencesDst(filenameDst);
    if (preferencesDst.existsAsFile() == false)
    {
        File preferencesSrc(filenameSrc);
        if (preferencesSrc.existsAsFile() == false)
        {
            String message = JUCE_T("Error: Preferences template file \"") +
                             filenameSrc +
                             JUCE_T("\" does not exist!");
            AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                        JUCE_T("Error"), message);
            return;
        }
        String content = preferencesSrc.loadFileAsString();
        preferencesDst.create();
        preferencesDst.replaceWithText(content);
    }

#ifdef _WINDOWS
    filenameDst = userdir + String("\\HybridReverb2_presets.xml");
    filenameSrc = basedir + String("\\HybridReverb2_presets.xml");
#else
    filenameDst = userdir + String("/HybridReverb2_presets.xml");
    filenameSrc = basedir + String("/HybridReverb2_presets.xml");
#endif
    File presetsDst(filenameDst);
    if (presetsDst.existsAsFile() == false)
    {
        File presetsSrc(filenameSrc);
        if (presetsSrc.existsAsFile() == false)
        {
            String message = JUCE_T("Error: Preset template file \"") +
                             filenameSrc +
                             JUCE_T("\" does not exist!");
            AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                        JUCE_T("Error"), message);
            return;
        }
        String content = presetsSrc.loadFileAsString();
        presetsDst.create();
        presetsDst.replaceWithText(content);
    }

    readPreferencesFile();
    readPartitionWisdomFile();
}

SystemConfig::~SystemConfig()
{
}


////////////////////////////////////////////////////////////////
//
//    public methods
//

const String & SystemConfig::getBasedir()
{
    return basedir;
}


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
    String filename = paramPreferences.presetFile;
    File file(filename);
    if (!file.existsAsFile())
    {
#ifdef _WINDOWS
        filename = userdir + String("\\") + paramPreferences.presetFile;
#else
        filename = userdir + String("/") + paramPreferences.presetFile;
#endif
        file = File(filename);
    }
    if (!file.existsAsFile())
        filename = paramPreferences.presetFile;

    return filename;
}


const ParamPreferences & SystemConfig::getPreferences()
{
    return paramPreferences;
}


void SystemConfig::readPreferencesFile()
{
#ifdef _WINDOWS
    String filename = userdir + String("\\preferences.xml");
#else
    String filename = userdir + String("/preferences.xml");
#endif
    File preferencesFile(filename);
    if (preferencesFile.existsAsFile() == false)
    {
        String message = JUCE_T("Error: Preferences file \"") +
                         filename +
                         JUCE_T("\" does not exist!");
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    JUCE_T("Error"), message);
        return;
    }

    XmlDocument xmlDoc(preferencesFile);
    std::unique_ptr<XmlElement> element(xmlDoc.getDocumentElement());

    if (!element)
    {
        String message = JUCE_T("Syntax error in preferences file \"") +
                         filename +
                         JUCE_T("\" :\n") +
                         xmlDoc.getLastParseError();
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    JUCE_T("Error"), message);
        return;
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

#ifdef _WINDOWS
    String filename = userdir + String("\\preferences.xml");
#else
    String filename = userdir + String("/preferences.xml");
#endif
    File preferencesFile(filename);
    if (preferencesFile.existsAsFile() == false)
    {
        String message = JUCE_T("Error: Preferences file \"") +
                         filename +
                         JUCE_T("\" does not exist!");
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    JUCE_T("Error"), message);
        return;
    }
    String content = String("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n") +
                     String("<preferences>\n") +
                     String("  <presetFile>") + paramPreferences.presetFile       + String("</presetFile>\n") +
                     String("  <sflen>")      + String(paramPreferences.sflen)    + String("</sflen>\n")      +
                     String("  <strategy>")   + String(paramPreferences.strategy) + String("</strategy>\n")   +
                     String("</preferences>");
    preferencesFile.replaceWithText(content);
}


const ParamPartitionWisdom & SystemConfig::getPartitionWisdom()
{
    return paramPartitionWisdom;
}


void SystemConfig::readPartitionWisdomFile()
{
#ifdef _WINDOWS
    String filename = basedir + String("\\partition_wisdom.xml");
#else
    String filename = basedir + String("/partition_wisdom.xml");
#endif
    File partitionWisdomFile(filename);
    if (partitionWisdomFile.existsAsFile() == false)
    {
        String message = JUCE_T("Error: Partition wisdom file \"") +
                         filename +
                         JUCE_T("\" does not exist!");
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    JUCE_T("Error"), message);
        return;
    }

    XmlDocument xmlDoc(partitionWisdomFile);
    std::unique_ptr<XmlElement> element(xmlDoc.getDocumentElement());

    if (!element)
    {
        String message = JUCE_T("Syntax error in partition wisdom file \"") +
                         filename +
                         JUCE_T("\" :\n") +
                         xmlDoc.getLastParseError();
        AlertWindow::showMessageBox(AlertWindow::WarningIcon,
                                    JUCE_T("Error"), message);
        return;
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

#ifdef _WINDOWS

void SystemConfig::extractBasedirWindows()
{
    TCHAR *programmfiles;
    size_t len;
    _tdupenv_s(&programmfiles, &len, _T("ProgramFiles"));
    len = _tcslen(programmfiles) + _tcslen(_T("\\HybridReverb2")) + 1;
    TCHAR *defaultDir = new TCHAR[len];
    defaultDir[0] = '\0';
    _tcscat_s(defaultDir, len, programmfiles);
    _tcscat_s(defaultDir, len, _T("\\HybridReverb2"));
    const String regkey("HKEY_LOCAL_MACHINE\\Software\\HybridReverb2\\BaseDir");
	basedir = PlatformUtilities::getRegistryValue(regkey, defaultDir);
    delete[] defaultDir;
    free(programmfiles);
}


void SystemConfig::extractUserdirWindows()
{
    TCHAR *appdata;
    size_t len;
    _tdupenv_s(&appdata, &len, _T("APPDATA"));
    char *cs = new char[len + 1];
    for (unsigned int i = 0; i < len; i++)
    cs[i] = (CHAR)appdata[i];
    cs[len] = '\0';
    userdir = String(cs) + _T("\\HybridReverb2");
    delete[] cs;
    free(appdata);
}

#else

void SystemConfig::extractBasedirUnix()
{
    String configFilename = String(getenv("HOME")) + "/.HybridReverb2/HybridReverb2.conf";
    File configFile(configFilename);

    if (!configFile.existsAsFile()) {
        configFilename = "/etc/HybridReverb2/HybridReverb2.conf";
        configFile = File(configFilename);
    }

    if (!configFile.existsAsFile())
    {
        basedir = INSTALL_PREFIX "/share/HybridReverb2";
        return;
    }

    FileInputStream configStream(configFile);
    String configLine;
    while (configStream.isExhausted() == false)
    {
        configLine = configStream.readNextLine();
        int pos = configLine.indexOfChar('#');
        if (pos >= 0)
            configLine = configLine.substring(0, pos);
        pos = configLine.indexOfChar('=');
        if (pos >= 0)
        {
            String variable = configLine.substring(0, pos).trim();
            String value = configLine.substring(pos + 1, configLine.length());
            if (variable == "basedir" || variable == "BaseDir")
                basedir = value.trim();
        }
    }
}


void SystemConfig::extractUserdirUnix()
{
    userdir = String(getenv("HOME")) + "/.HybridReverb2";
}

#endif


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
