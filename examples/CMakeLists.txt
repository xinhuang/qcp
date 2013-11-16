cmake_minimum_required(VERSION 2.8)

set(target_name examples)
set(executable 1)

set(src_dir .)

include_directories(. ../qcp/include)
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

set(dependencies ${GTEST_LIBRARIES} qcp)

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
    add_library(${target_name} shared ${src_files})
endif()

target_link_libraries(${target_name} ${dependencies})

foreach (lib IN LISTS ignored_libs)
    set_target_properties(${target_name}
            properties
            link_flags /nodefaultlib:\"${lib}\")
endforeach()
