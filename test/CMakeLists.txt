cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
include(GoogleTest)

macro(package_add_test TESTNAME)
    # Check if we have exactly one additional argument (potentially a directory)
    if(${ARGC} EQUAL 2)
        # Check if the argument is a directory
        if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${ARGV1}")
            # Glob for test files in the directory
            file(GLOB_RECURSE TEST_SOURCES
                    CONFIGURE_DEPENDS
                    "${CMAKE_CURRENT_SOURCE_DIR}/${ARGV1}/*_test.cpp"
                    "${CMAKE_CURRENT_SOURCE_DIR}/${ARGV1}/*Test.cpp")
            if(NOT TEST_SOURCES)
                message(WARNING "No test files found in directory ${ARGV1}")
                return()
            endif()
            set(SOURCE_FILES ${TEST_SOURCES})
        else()
            # Treat as individual file
            set(SOURCE_FILES ${ARGN})
        endif()
    else()
        # Multiple arguments - treat as individual files
        set(SOURCE_FILES ${ARGN})
    endif()

    add_executable(${TESTNAME} ${SOURCE_FILES})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)
    gtest_discover_tests(${TESTNAME}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}")
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

# Rest of your configuration remains the same
include_directories("${PROJECT_SOURCE_DIR}/src/includes")

mark_as_advanced(
        BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
        gmock_build_tests gtest_build_samples gtest_build_tests
        gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)
package_add_test(AnalysisTests Analysis)
package_add_test(AudioTests Audio)
package_add_test(FiltersTests Filters)
package_add_test(NaiveGeneratorsTests NaiveGenerators)
package_add_test(NumbersTests Numbers)
package_add_test(ParametersTests Parameters)
package_add_test(WavetablesTests Wavetables)