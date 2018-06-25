cmake_minimum_required(VERSION 3.5)

project(HybridReverb2 VERSION 2.0.2 LANGUAGES CXX C)
set(HybridReverb2_URI "https://github.com/jpcima/HybridReverb2")

set(HybridReverb2_VST2 "" CACHE STRING "Build VST2")
set(HybridReverb2_LV2 "" CACHE STRING "Build LV2")
set(HybridReverb2_Standalone "" CACHE STRING "Build Standalone")

option(HybridReverb2_ASSERTIONS "Enable assertions" OFF)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  set(HybridReverb2_STATIC_FFTW "ON" CACHE STRING "Use static FFTW")
else()
  set(HybridReverb2_STATIC_FFTW "OFF" CACHE STRING "Use static FFTW")
endif()

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")
include(GNUWarnings)
include(LinkHelpers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

enable_gnu_warning("all")
disable_gnu_warning("multichar")
# this one is all over JUCE code
disable_gnu_warning("class-memaccess")

if(CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$" OR
    CMAKE_SYSTEM_PROCESSOR STREQUAL "x86")
  if(CMAKE_C_COMPILER_ID MATCHES "^(GNU|Clang)$")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse")
  endif()
  if(CMAKE_CXX_COMPILER_ID MATCHES "^(GNU|Clang)$")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse")
  endif()
endif()

if(HybridReverb2_ASSERTIONS)
  add_definitions("-UNDEBUG")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(CMAKE_COMPILER_IS_GNUCXX)
    # on MinGW JUCE defines a _WINNT_VER which disables some needed definitions
    add_definitions("-DREPLACEFILE_IGNORE_ACL_ERRORS=0x4")
  endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

###
if(CMAKE_SYSTEM_NAME STREQUAL "Windows" OR
    CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  if(HybridReverb2_VST2 STREQUAL "")
    set(HybridReverb2_VST2 "ON" CACHE STRING "Build VST2" FORCE)
  endif()
  if(HybridReverb2_LV2 STREQUAL "")
    set(HybridReverb2_LV2 "OFF" CACHE STRING "Build LV2" FORCE)
  endif()
else()
  if(HybridReverb2_VST2 STREQUAL "")
    set(HybridReverb2_VST2 "ON" CACHE STRING "Build VST2" FORCE)
  endif()
  if(HybridReverb2_LV2 STREQUAL "")
    set(HybridReverb2_LV2 "ON" CACHE STRING "Build LV2" FORCE)
  endif()
endif()
if(HybridReverb2_Standalone STREQUAL "")
  set(HybridReverb2_Standalone "ON" CACHE STRING "Build Standalone" FORCE)
endif()

message("Build VST2: ${HybridReverb2_VST2}")
message("Build LV2: ${HybridReverb2_LV2}")
message("Build Standalone: ${HybridReverb2_Standalone}")

include("${CMAKE_SOURCE_DIR}/JUCE-targets.cmake")

add_library(HybridReverb2_core STATIC
  "JuceLibraryCode/BinaryData.cpp"
  "Source/gui/AppLookAndFeel.cpp"
  "Source/gui/Editor.cpp"
  "Source/gui/EditorComponent.cpp"
  "Source/gui/FreqPlot.cpp"
  "Source/gui/IRPlot.cpp"
  "Source/gui/TabAbout.cpp"
  "Source/gui/TabMain.cpp"
  "Source/gui/TabModulation.cpp"
  "Source/gui/TabPreferences.cpp"
  "Source/gui/TabPresetEditor.cpp"
  "Source/gui/TabTimbre.cpp"
  "Source/gui/DownloadDbComponent.cpp"
  "Source/libHybridConv/libHybridConv.c"
  "Source/HybridConvolver.cpp"
  "Source/HybridConvolverDual.cpp"
  "Source/HybridConvolverSingle.cpp"
  "Source/HybridConvolverTripple.cpp"
  "Source/HybridReverb2Processor.cpp"
  "Source/LagrangeInterpolator.cpp"
  "Source/Main.cpp"
  "Source/MasterAndCommander.cpp"
  "Source/Partitioner.cpp"
  "Source/PresetManager.cpp"
  "Source/SampleData.cpp"
  "Source/SystemConfig.cpp"
  "Source/TextList.cpp")
target_compile_definitions(HybridReverb2_core PRIVATE "INSTALL_PREFIX=\"${CMAKE_INSTALL_PREFIX}\"")
target_compile_definitions(HybridReverb2_core PRIVATE "NO_OMP") # OpenMP is not good for realtime
target_compile_definitions(HybridReverb2_core PRIVATE "JUCE_DEFINE_T_MACRO")
target_include_directories(HybridReverb2_core PRIVATE "Source")
target_link_libraries(HybridReverb2_core PUBLIC
  juce_core juce_events juce_data_structures
  juce_audio_basics juce_audio_devices juce_audio_formats juce_audio_processors juce_audio_utils
  juce_graphics juce_gui_basics juce_gui_extra)
set_property(TARGET HybridReverb2_core
  PROPERTY POSITION_INDEPENDENT_CODE ON)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$" OR
    CMAKE_SYSTEM_PROCESSOR STREQUAL "x86" OR
    CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
  target_compile_definitions(HybridReverb2_core PRIVATE "HYBRIDCONV_SSE")
endif()

find_path(FFTW_INCLUDE_DIR "fftw3.h")
if(FFTW_INCLUDE_DIR)
  message(STATUS "Found FFTW headers: ${FFTW_INCLUDE_DIR}")
else()
  message(FATAL_ERROR "Cannot find FFTW headers")
endif()
if(HybridReverb2_STATIC_FFTW)
  include(StaticLinking)
  find_static_library(FFTWF_LIBRARY "fftw3f")
else()
  find_library(FFTWF_LIBRARY "fftw3f")
endif()
if(FFTWF_LIBRARY)
  message(STATUS "Found FFTW library: ${FFTWF_LIBRARY}")
else()
  message(FATAL_ERROR "Cannot find the FFTW library")
endif()
target_link_libraries(HybridReverb2_core PRIVATE "${FFTWF_LIBRARY}")
target_include_directories(HybridReverb2_core PRIVATE "${FFTW_INCLUDE_DIR}")

macro(add_plugin NAME)
  add_library("${NAME}" MODULE "Source/Main.cpp" ${ARGN})
  set_property(TARGET "${NAME}" PROPERTY PREFIX "")
  if(CMAKE_SYSTEM_NAME STREQUAL "Windows" AND CMAKE_COMPILER_IS_GNUCXX)
    # forces the static link of standard libraries
    set_property(TARGET "${NAME}" APPEND_STRING
      PROPERTY LINK_FLAGS " -static-libgcc -static-libstdc++")
    # forces the static link of winpthread
    set_property(TARGET "${NAME}" APPEND_STRING
      PROPERTY LINK_FLAGS " -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,-Bdynamic,--no-whole-archive")
  endif()
endmacro()

if(HybridReverb2_VST2)
  add_plugin(HybridReverb2_VST2)
  target_link_libraries(HybridReverb2_VST2 PRIVATE juce_audio_plugin_client_VST2 HybridReverb2_core)
  if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$" OR
        CMAKE_SYSTEM_PROCESSOR STREQUAL "x86")
      target_sources(HybridReverb2_VST2 PRIVATE "${PROJECT_SOURCE_DIR}/Source/link/VST2-32.def")
    else()
      target_sources(HybridReverb2_VST2 PRIVATE "${PROJECT_SOURCE_DIR}/Source/link/VST2-64.def")
    endif()
  else()
    require_symbols(HybridReverb2_VST2 "VSTPluginMain")
  endif()
  if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set_target_properties(HybridReverb2_VST2 PROPERTIES
      PREFIX "" OUTPUT_NAME "HybridReverb2" SUFFIX ""
      LIBRARY_OUTPUT_DIRECTORY "vst2/HybridReverb2.vst/Contents/MacOS")
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/vst2/HybridReverb2.vst/Contents/")
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/vst2/HybridReverb2.vst/Contents/PkgInfo" "BNDL????")
    add_custom_target(HybridReverb2_VST2_InfoPlist ALL
      "${CMAKE_COMMAND}"
      "-DCONFIGURE_FILE_INPUT=${PROJECT_SOURCE_DIR}/juce/Builds/MacOSX/Info-VST.plist"
      "-DCONFIGURE_FILE_OUTPUT=${CMAKE_CURRENT_BINARY_DIR}/vst2/HybridReverb2.vst/Contents/Info.plist"
      "-DEXECUTABLE_NAME=HybridReverb2"
      "-P" "${PROJECT_SOURCE_DIR}/cmake/ConfigureFile.cmake"
      DEPENDS "${PROJECT_SOURCE_DIR}/juce/Builds/MacOSX/Info-VST.plist")
  endif()
  install(TARGETS HybridReverb2_VST2 DESTINATION "lib/vst")
endif()

if(HybridReverb2_LV2)
  add_plugin(HybridReverb2_LV2)
  target_link_libraries(HybridReverb2_LV2 PRIVATE juce_audio_plugin_client_LV2 HybridReverb2_core)
  require_symbols(HybridReverb2_LV2 "lv2_generate_ttl" "lv2_descriptor" "lv2ui_descriptor")
  set_property(TARGET HybridReverb2_LV2
    PROPERTY LIBRARY_OUTPUT_DIRECTORY "lv2/HybridReverb2.lv2")

  set(HybridReverb2_LV2_MANIFESTS
    "Source/resources/LV2/HybridReverb2_LV2.ttl"
    "Source/resources/LV2/manifest.ttl"
    "Source/resources/LV2/presets.ttl")
  add_custom_target(HybridReverb2_LV2_manifests_copy ALL
    COMMAND "${CMAKE_COMMAND}" "-E" "make_directory" "${CMAKE_CURRENT_BINARY_DIR}/lv2/HybridReverb2.lv2/"
    COMMAND "${CMAKE_COMMAND}" "-E" "copy" ${HybridReverb2_LV2_MANIFESTS} "${CMAKE_CURRENT_BINARY_DIR}/lv2/HybridReverb2.lv2/"
    DEPENDS ${HybridReverb2_LV2_MANIFESTS}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

  set(HybridReverb2_LV2_INSTALL_DIR "lib/lv2/HybridReverb2.lv2")
  install(TARGETS HybridReverb2_LV2 DESTINATION "${HybridReverb2_LV2_INSTALL_DIR}")
  install(FILES ${HybridReverb2_LV2_MANIFESTS} DESTINATION "${HybridReverb2_LV2_INSTALL_DIR}")
endif()

if(HybridReverb2_Standalone)
  add_executable(HybridReverb2_Standalone "Source/Main.cpp")
  target_link_libraries(HybridReverb2_Standalone PRIVATE juce_audio_plugin_client_Standalone HybridReverb2_core)
  if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$" OR
        CMAKE_SYSTEM_PROCESSOR STREQUAL "x86")
      require_symbols(HybridReverb2_Standalone "_WinMain@16")
    else()
      require_symbols(HybridReverb2_Standalone "WinMain")
    endif()
  else()
    require_symbols(HybridReverb2_Standalone "main")
  endif()
  set_property(TARGET HybridReverb2_Standalone PROPERTY OUTPUT_NAME "HybridReverb2")
  install(TARGETS HybridReverb2_Standalone DESTINATION "bin")
  install(FILES "Source/resources/hybridreverb2.desktop" DESTINATION "share/applications")
  install(FILES "Source/resources/HybridReverb2.png" DESTINATION "share/pixmaps")
endif()
