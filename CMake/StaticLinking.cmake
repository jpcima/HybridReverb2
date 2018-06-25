#
# Static linking
#
#
# Macro: FIND_STATIC_LIBRARY
#   Finds a static library. Same usage as FIND_LIBRARY.
#
# Macro: FIND_STATIC_LIBRARY_OF_LIBRARY
#   Finds the static version of a given library, which can specified either as
#   a name or an absolute path.
#

macro(find_static_library)
  set(_orig_CMAKE_FIND_LIBRARY_SUFFIXES "${CMAKE_FIND_LIBRARY_SUFFIXES}")
  if (WIN32)
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".a")
  else()
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
  endif()
  find_library(${ARGN})
  set(CMAKE_FIND_LIBRARY_SUFFIXES "${_orig_CMAKE_FIND_LIBRARY_SUFFIXES}")
  unset(_orig_CMAKE_FIND_LIBRARY_SUFFIXES)
endmacro()

macro(find_static_library_of_library VAR LIBRARY)
  set(_lib "${LIBRARY}")
  if(NOT _lib)
    set(${VAR} "${VAR}-NOTFOUND")
  elseif(NOT IS_ABSOLUTE "${_lib}")
    find_static_library(${VAR} "${_lib}")
  else()
    get_filename_component(_dir "${_lib}" DIRECTORY)
    get_filename_component(_name "${_lib}" NAME_WE)
    set(_path "${_dir}/${_name}${CMAKE_STATIC_LIBRARY_SUFFIX}")
    if(EXISTS "${_path}")
      set(${VAR} "${_path}" CACHE STRING "" FORCE)
    else()
      set(${VAR} "${VAR}-NOTFOUND" CACHE STRING "" FORCE)
    endif()
    unset(_dir)
    unset(_name)
    unset(_path)
  endif()
  unset(_lib)
endmacro()
