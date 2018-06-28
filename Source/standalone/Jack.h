//          Copyright Jean Pierre Cimalando 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../HybridReverb2Processor.h"
#include "../model/SystemConfig.h"
#include "../gui/Editor.h"
#if defined(WITH_NSM_SESSION_SUPPORT)
#include "nsm.h"
#endif
#include <jack/jack.h>
#include <jack/midiport.h>
#include <memory>
#include <thread>
#include <system_error>
#include <signal.h>
#include <unistd.h>

namespace juce {
    extern const char *const *juce_argv;
    extern int juce_argc;
}

extern AudioProcessor* JUCE_CALLTYPE createPluginFilter(const String &userDir);

#if defined(WITH_NSM_SESSION_SUPPORT)
struct NsmClientDeleter {
    void operator()(nsm_client_t *x) { nsm_free(x); }
};
typedef std::unique_ptr<nsm_client_t, NsmClientDeleter> nsm_client_u;
#endif
