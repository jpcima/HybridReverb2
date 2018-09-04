//          Copyright Jean Pierre Cimalando 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "JuceHeader.h"

#define LITERAL_UTF8(x) u8##x
#define TRANS_UTF8(x) juce::translate(juce::CharPointer_UTF8(LITERAL_UTF8(x)))
