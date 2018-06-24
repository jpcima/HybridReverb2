/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== partition_wisdom.xml ==================
static const unsigned char temp_binary_data_0[] =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
"<proc_time>\n"
"  <const size=\"64\">0.000002778467</const>\n"
"  <const size=\"128\">0.000004970475</const>\n"
"  <const size=\"256\">0.000009060409</const>\n"
"  <const size=\"512\">0.000019167853</const>\n"
"  <const size=\"1024\">0.000035650128</const>\n"
"  <const size=\"2048\">0.000073372627</const>\n"
"  <const size=\"4096\">0.000155226611</const>\n"
"  <const size=\"8192\">0.000335697934</const>\n"
"  <const size=\"16384\">0.000746945187</const>\n"
"  <const size=\"32768\">0.001750952898</const>\n"
"  <linear size=\"64\">0.000000499790</linear>\n"
"  <linear size=\"128\">0.000001035634</linear>\n"
"  <linear size=\"256\">0.000002023408</linear>\n"
"  <linear size=\"512\">0.000003884983</linear>\n"
"  <linear size=\"1024\">0.000007923553</linear>\n"
"  <linear size=\"2048\">0.000016082964</linear>\n"
"  <linear size=\"4096\">0.000034496221</linear>\n"
"  <linear size=\"8192\">0.000077278108</linear>\n"
"  <linear size=\"16384\">0.000159484112</linear>\n"
"  <linear size=\"32768\">0.000384955239</linear>\n"
"</proc_time>\n";

const char* partition_wisdom_xml = (const char*) temp_binary_data_0;

//================== preferences.xml ==================
static const unsigned char temp_binary_data_1[] =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
"<preferences>\r\n"
"  <presetFile>HybridReverb2_presets.xml</presetFile>\r\n"
"  <sflen>256</sflen>\r\n"
"  <strategy>1</strategy>\r\n"
"</preferences>\r\n";

const char* preferences_xml = (const char*) temp_binary_data_1;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xaa69850e:  numBytes = 959; return partition_wisdom_xml;
        case 0xdfcfa250:  numBytes = 173; return preferences_xml;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "partition_wisdom_xml",
    "preferences_xml"
};

const char* originalFilenames[] =
{
    "partition_wisdom.xml",
    "preferences.xml"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
