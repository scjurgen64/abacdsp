cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
include(GoogleTest)

# Create static library from implementation files
file(GLOB_RECURSE LIB_SOURCES
        CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/src/includes/**/*.cpp")

# Only create library if we have implementation files
if (LIB_SOURCES)
    add_library(audio_dsp_lib STATIC ${LIB_SOURCES})
    target_include_directories(audio_dsp_lib PUBLIC "${PROJECT_SOURCE_DIR}/src/includes")

    # Set C++20 standard for the library
    target_compile_features(audio_dsp_lib PUBLIC cxx_std_20)

    message(STATUS "Created audio_dsp_lib with ${CMAKE_MATCH_COUNT} source files")
    foreach (source ${LIB_SOURCES})
        message(STATUS "  - ${source}")
    endforeach ()
else ()
    message(STATUS "No implementation files found, library will be header-only")
endif ()

# Updated macro that links against the library
macro(package_add_test TESTNAME)
    if (${ARGC} EQUAL 2)
        # Check if the argument is a directory
        if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${ARGV1}")
            # Glob for test files in the directory
            file(GLOB_RECURSE TEST_SOURCES
                    CONFIGURE_DEPENDS
                    "${CMAKE_CURRENT_SOURCE_DIR}/${ARGV1}/*_test.cpp")
            if (NOT TEST_SOURCES)
                message(WARNING "No test files found in directory ${ARGV1}")
                return()
            endif ()
            set(SOURCE_FILES ${TEST_SOURCES})
        else ()
            # Treat as individual file
            set(SOURCE_FILES ${ARGN})
        endif ()
    else ()
        # Multiple arguments - treat as individual files
        set(SOURCE_FILES ${ARGN})
    endif ()

    add_executable(${TESTNAME} ${SOURCE_FILES})

    # Link against our library if it exists, otherwise just include directories
    if (TARGET audio_dsp_lib)
        target_link_libraries(${TESTNAME} audio_dsp_lib gtest gmock gtest_main)
    else ()
        target_link_libraries(${TESTNAME} gtest gmock gtest_main)
        target_include_directories(${TESTNAME} PRIVATE "${PROJECT_SOURCE_DIR}/src/includes")
    endif ()

    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

# Keep the old include_directories for backward compatibility if needed
# This is now redundant if you're using the library, but doesn't hurt
include_directories("${PROJECT_SOURCE_DIR}/src/includes")

mark_as_advanced(
        BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
        gmock_build_tests gtest_build_samples gtest_build_tests
        gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

# Macro to get all immediate subdirectories (non-recursive version)
macro(SUBDIRLIST result curdir)
    file(GLOB children RELATIVE ${curdir} ${curdir}/*)
    set(dirlist "")
    foreach (child ${children})
        if (IS_DIRECTORY ${curdir}/${child})
            list(APPEND dirlist ${child})
        endif ()
    endforeach ()
    set(${result} ${dirlist})
endmacro()

# Create a list to collect all test targets
set(ALL_TEST_TARGETS "")

# Automatically discover test directories and generate tests
# This preserves your original naming pattern: DirectoryNameTests
subdirlist(TEST_SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
foreach (subdir ${TEST_SUBDIRS})
    # Only process directories that contain test files
    file(GLOB_RECURSE test_files
            "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/*_test.cpp")
    if (test_files)
        # Create test name in your original format: DirectoryNameTests
        package_add_test(${subdir}Tests ${subdir})
        message(STATUS "Added test target: ${subdir}Tests for directory: ${subdir}")

        # Add this test target to our list
        list(APPEND ALL_TEST_TARGETS ${subdir}Tests)
    endif ()
endforeach ()

# Create the unit_tests target that builds all test executables
add_custom_target(unit_tests
        DEPENDS ${ALL_TEST_TARGETS}
        COMMENT "Building all unit test executables"
)

# Optional: Create a target that builds and runs all tests
add_custom_target(run_unit_tests
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        DEPENDS unit_tests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Building and running all unit tests"
)

