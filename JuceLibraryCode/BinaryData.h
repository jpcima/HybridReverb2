/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   I18nResource_fr;
    const int            I18nResource_frSize = 20737;

    extern const char*   partition_wisdom_xml;
    const int            partition_wisdom_xmlSize = 959;

    extern const char*   preferences_xml;
    const int            preferences_xmlSize = 173;

    extern const char*   LiberationMonoBold_ttf_gz;
    const int            LiberationMonoBold_ttf_gzSize = 171228;

    extern const char*   LiberationMonoBoldItalic_ttf_gz;
    const int            LiberationMonoBoldItalic_ttf_gzSize = 163575;

    extern const char*   LiberationMonoItalic_ttf_gz;
    const int            LiberationMonoItalic_ttf_gzSize = 160988;

    extern const char*   LiberationMonoRegular_ttf_gz;
    const int            LiberationMonoRegular_ttf_gzSize = 176185;

    extern const char*   LiberationSansBold_ttf_gz;
    const int            LiberationSansBold_ttf_gzSize = 193929;

    extern const char*   LiberationSansBoldItalic_ttf_gz;
    const int            LiberationSansBoldItalic_ttf_gzSize = 196867;

    extern const char*   LiberationSansItalic_ttf_gz;
    const int            LiberationSansItalic_ttf_gzSize = 199716;

    extern const char*   LiberationSansRegular_ttf_gz;
    const int            LiberationSansRegular_ttf_gzSize = 191908;

    extern const char*   LiberationSerifBold_ttf_gz;
    const int            LiberationSerifBold_ttf_gzSize = 199487;

    extern const char*   LiberationSerifBoldItalic_ttf_gz;
    const int            LiberationSerifBoldItalic_ttf_gzSize = 208505;

    extern const char*   LiberationSerifItalic_ttf_gz;
    const int            LiberationSerifItalic_ttf_gzSize = 207970;

    extern const char*   LiberationSerifRegular_ttf_gz;
    const int            LiberationSerifRegular_ttf_gzSize = 209087;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 15;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
