﻿cmake_minimum_required (VERSION 3.13 FATAL_ERROR)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(WIN32)
set(CMAKE_CXX_FLAGS_DEBUG "/std:c++20 /bigobj /RTCu /sdl /Z7")
set(CMAKE_CXX_FLAGS_RELEASE "/std:c++20 /O2 /Ot")
else()
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif(WIN32)

project ("SVM")

# Include sub-projects.
add_subdirectory ("SVM")
