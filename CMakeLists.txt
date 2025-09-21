cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME "AbacDsp")
file(STRINGS VERSION CURRENT_VERSION)

project(${PROJECT_NAME} VERSION ${CURRENT_VERSION})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

# Color our warnings and errors
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fcolor-diagnostics)
endif ()

include_directories(src/includes)
include_directories(3rdparty/AudioFile)
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(3rdparty)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()

    # Include CTest to generate DartConfiguration.tcl
    include(CTest)

    # Configure Valgrind for memory checking
    find_program(VALGRIND_PROGRAM NAMES valgrind)
    if(VALGRIND_PROGRAM)
        set(MEMORYCHECK_COMMAND ${VALGRIND_PROGRAM})
        set(MEMORYCHECK_COMMAND_OPTIONS
                "--leak-check=full --show-leak-kinds=all --fair-sched=yes --error-exitcode=1 --track-origins=yes --trace-children=yes")
        set(MEMORYCHECK_SUPPRESSIONS_FILE "${CMAKE_SOURCE_DIR}/valgrind.supp")
    endif()

    add_subdirectory(test)
endif()
