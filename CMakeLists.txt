cmake_minimum_required(VERSION 2.8)

option(build_shared_lib "Build shared libraries (DLLs)." OFF)
option(use_shared_crt
  "Use shared (DLL) run-time lib even when built as static lib."
  OFF)

project(qcp)

set(target_name qcp)
set(executable 0)

if (MINGW)
    add_definitions(-std=c++11)
elseif (MSVC AND (MSVC_VERSION LESS 1800))
    message(FATAL_ERROR "To build qcp you need Visual Studio to support C++ vardic template.")
endif()

add_subdirectory(examples)

set(src_dir src include/qcp)

include_directories(include/qcp)
link_directories()

if (MSVC)
    set(GTEST_MSVC_SEARCH "MT")
    foreach(flag_var
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
       if(${flag_var} MATCHES "/MD")
          string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
   endif(${flag_var} MATCHES "/MD")
endforeach(flag_var)
endif()
find_package(gtest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
link_directories()

set(dependencies ${GTEST_LIBRARIES})

# TEMPLATE BELOW

set(src_files "")
foreach(dir IN LISTS src_dir)
    FILE(GLOB headers ${dir}/*.h)
    FILE(GLOB sources ${dir}/*.cpp ${dir}/*.c)

    STRING(REPLACE "/" "\\\\" srcgroup ${dir})

    if (${srcgroup} STREQUAL .)
        source_group("${target_name}" FILES ${headers} ${sources})
    else (${srcgroup} STREQUAL .)
        source_group("${srcgroup}" FILES ${headers} ${sources})
    endif()

    set(src_files ${src_files} ${headers} ${sources})
endforeach()

if (executable)
    add_executable(${target_name} ${src_files})
else()
	if (build_shared_lib)
		set(lib_type SHARED)
	else()
		set(lib_type STATIC)
	endif()
    add_library(${target_name} STATIC ${src_files})
endif()

if (${dependencies})
	target_link_libraries(${target_name} ${dependencies})
endif()

foreach (lib IN LISTS ignored_libs)
    set_target_properties(${target_name}
            properties
            link_flags /nodefaultlib:\"${lib}\")
endforeach()


