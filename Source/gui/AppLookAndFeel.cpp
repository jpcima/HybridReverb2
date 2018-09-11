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


#include "AppLookAndFeel.h"
#include "../../JuceLibraryCode/BinaryData.h"

Typeface::Ptr AppLookAndFeel::getTypefaceForFont(const Font &font)
{
    const String &name = font.getTypefaceName();
    const String &style = font.getTypefaceStyle();

    fprintf(stderr, "Query Typeface name='%s' style='%s'\n",
            name.toRawUTF8(), style.toRawUTF8());

#define BINARY_FONT(x) BinaryData::x##_ttf_gz, BinaryData::x##_ttf_gzSize

    Typeface::Ptr tf;
    if (name == Font::getDefaultSansSerifFontName()) {
        if (style == "Italic")
            tf = getOrCreateFont(fontSansItalic, BINARY_FONT(LiberationSansItalic));
        else if (style == "Bold")
            tf = getOrCreateFont(fontSansBold, BINARY_FONT(LiberationSansBold));
        else if (style == "Bold Italic")
            tf = getOrCreateFont(fontSansBoldItalic, BINARY_FONT(LiberationSansBoldItalic));
        else
            tf = getOrCreateFont(fontSansRegular, BINARY_FONT(LiberationSansRegular));
    }
    else if (name == Font::getDefaultSerifFontName()) {
        if (style == "Italic")
            tf = getOrCreateFont(fontSerifItalic, BINARY_FONT(LiberationSerifItalic));
        else if (style == "Bold")
            tf = getOrCreateFont(fontSerifBold, BINARY_FONT(LiberationSerifBold));
        else if (style == "Bold Italic")
            tf = getOrCreateFont(fontSerifBoldItalic, BINARY_FONT(LiberationSerifBoldItalic));
        else
            tf = getOrCreateFont(fontSerifRegular, BINARY_FONT(LiberationSerifRegular));
    }
    else if (name == Font::getDefaultMonospacedFontName()) {
        if (style == "Italic")
            tf = getOrCreateFont(fontMonoItalic, BINARY_FONT(LiberationMonoItalic));
        else if (style == "Bold")
            tf = getOrCreateFont(fontMonoBold, BINARY_FONT(LiberationMonoBold));
        else if (style == "Bold Italic")
            tf = getOrCreateFont(fontMonoBoldItalic, BINARY_FONT(LiberationMonoBoldItalic));
        else
            tf = getOrCreateFont(fontMonoRegular, BINARY_FONT(LiberationMonoRegular));
    }

    if (!tf) {
        fprintf(stderr, "Typeface not found, fallback\n");
        tf = LookAndFeel::getTypefaceForFont(font);
    }

    return tf;

#undef BINARY_FONT
}

Typeface::Ptr AppLookAndFeel::getOrCreateFont(
    Typeface::Ptr &font, const char *data, unsigned size)
{
    if (!font) {
        MemoryInputStream memStream(data, size, false);
        GZIPDecompressorInputStream gzStream(&memStream, false, GZIPDecompressorInputStream::gzipFormat);

        MemoryBlock memBlock;
        gzStream.readIntoMemoryBlock(memBlock);

        font = Typeface::createSystemTypefaceFor(
            memBlock.getData(), memBlock.getSize());

        if (!font)
            fprintf(stderr, "Could not load font data.\n");
        else
            fprintf(stderr, "Font loaded name='%s' style='%s'\n",
                    font->getName().toRawUTF8(), font->getStyle().toRawUTF8());
    }
    return font;
}
