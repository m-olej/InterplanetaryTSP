# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.23)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS sfml-system sfml-main sfml-window OpenGL sfml-network sfml-graphics Freetype OpenAL Vorbis FLAC sfml-audio)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Create imported target sfml-system
add_library(sfml-system STATIC IMPORTED)

set_target_properties(sfml-system PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "SFML_STATIC"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:winmm>"
)

# Create imported target sfml-main
add_library(sfml-main STATIC IMPORTED)

set_target_properties(sfml-main PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "SFML_STATIC"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/include"
)

# Create imported target sfml-window
add_library(sfml-window STATIC IMPORTED)

set_target_properties(sfml-window PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "SFML_STATIC"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "sfml-system;\$<LINK_ONLY:OpenGL>;\$<LINK_ONLY:winmm>;\$<LINK_ONLY:gdi32>"
)

# Create imported target OpenGL
add_library(OpenGL INTERFACE IMPORTED)

set_target_properties(OpenGL PROPERTIES
  INTERFACE_LINK_LIBRARIES "opengl32;glu32"
)

# Create imported target sfml-network
add_library(sfml-network STATIC IMPORTED)

set_target_properties(sfml-network PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "SFML_STATIC"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "sfml-system;\$<LINK_ONLY:ws2_32>"
)

# Create imported target sfml-graphics
add_library(sfml-graphics STATIC IMPORTED)

set_target_properties(sfml-graphics PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "SFML_STATIC"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "sfml-window;\$<LINK_ONLY:OpenGL>;\$<LINK_ONLY:Freetype>"
)

# Create imported target Freetype
add_library(Freetype INTERFACE IMPORTED)

set_target_properties(Freetype PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/headers/freetype2"
  INTERFACE_LINK_LIBRARIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/libs-mingw/x64/libfreetype.a"
)

# Create imported target OpenAL
add_library(OpenAL INTERFACE IMPORTED)

set_target_properties(OpenAL PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/headers/AL"
  INTERFACE_LINK_LIBRARIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/libs-mingw/x64/libopenal32.a"
)

# Create imported target Vorbis
add_library(Vorbis INTERFACE IMPORTED)

set_target_properties(Vorbis PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "OV_EXCLUDE_STATIC_CALLBACKS"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/headers;C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/headers"
  INTERFACE_LINK_LIBRARIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/libs-mingw/x64/libvorbisenc.a;C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/libs-mingw/x64/libvorbisfile.a;C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/libs-mingw/x64/libvorbis.a;C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/libs-mingw/x64/libogg.a"
)

# Create imported target FLAC
add_library(FLAC INTERFACE IMPORTED)

set_target_properties(FLAC PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "FLAC__NO_DLL"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/headers"
  INTERFACE_LINK_LIBRARIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/extlibs/libs-mingw/x64/libFLAC.a"
)

# Create imported target sfml-audio
add_library(sfml-audio STATIC IMPORTED)

set_target_properties(sfml-audio PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "SFML_STATIC"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-src/include"
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:OpenAL>;sfml-system;\$<LINK_ONLY:Vorbis>;\$<LINK_ONLY:FLAC>"
)

# Import target "sfml-system" for configuration "Debug"
set_property(TARGET sfml-system APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-system PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-build/lib/libsfml-system-s-d.a"
  )

# Import target "sfml-main" for configuration "Debug"
set_property(TARGET sfml-main APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-build/lib/libsfml-main-d.a"
  )

# Import target "sfml-window" for configuration "Debug"
set_property(TARGET sfml-window APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-window PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-build/lib/libsfml-window-s-d.a"
  )

# Import target "sfml-network" for configuration "Debug"
set_property(TARGET sfml-network APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-network PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-build/lib/libsfml-network-s-d.a"
  )

# Import target "sfml-graphics" for configuration "Debug"
set_property(TARGET sfml-graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-graphics PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-build/lib/libsfml-graphics-s-d.a"
  )

# Import target "sfml-audio" for configuration "Debug"
set_property(TARGET sfml-audio APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-audio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/Users/User/Desktop/Comb. Opt. Proj/GravityTravellingSalesman/cmake-build-debug/_deps/sfml-build/lib/libsfml-audio-s-d.a"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
