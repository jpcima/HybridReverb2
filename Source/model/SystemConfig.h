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


#ifndef __SYSTEMCONFIG_H__
#define __SYSTEMCONFIG_H__


#include "../../JuceLibraryCode/JuceHeader.h"
#include "../model/Parameter.h"


class SystemConfig : public ReferenceCountedObject
{
public:
    explicit SystemConfig(const String &customUserDir);
    ~SystemConfig();

    typedef ReferenceCountedObjectPtr<SystemConfig> Ptr;

    const String &getUserdir() const
        { return userdir; }
    String getDBdir() const;

    static String getDefaultUserDir();
    static String getDefaultUserPresetFilename();
    static String getDefaultPresetFilename();

    String getPresetFilename() const;
    void readPreferencesFile();
    void writePreferencesFile();
    void setPreferences(const ParamPreferences & param);
    void readPartitionWisdomFile();

    const ParamPreferences & getPreferences() const
        { return paramPreferences; }
    const ParamPartitionWisdom & getPartitionWisdom()
        { return paramPartitionWisdom; }

    void setupLanguage();

private:
    bool successfulLoad = false;
    String userdir;
    ParamPreferences paramPreferences;
    ParamPartitionWisdom paramPartitionWisdom;
};


#endif   // __SYSTEMCONFIG_H__
