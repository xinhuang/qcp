cmake_minimum_required(VERSION 2.8)

project(qcp)

if (MINGW)
    add_definitions(-std=c++11)
elseif (MSVC AND (MSVC_VERSION LESS 1800))
    message(FATAL_ERROR "To build qcp you need Visual Studio to support C++ vardic template.")
endif()

add_subdirectory(examples)
add_subdirectory(qcp)
