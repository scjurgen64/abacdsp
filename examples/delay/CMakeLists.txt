# Alternative Approach: Separate CMakeLists.txt for standalone example

cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME "DelayExample")
set(FORMATS AU VST3 AUv3 Standalone)

# For standalone build, check if VERSION file exists
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION")
    file(STRINGS VERSION CURRENT_VERSION)
else()
    # Fallback version for standalone builds
    set(CURRENT_VERSION "0.1.0")
endif()

project(${PROJECT_NAME} VERSION ${CURRENT_VERSION})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_XCODE_GENERATE_SCHEME OFF)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.13" CACHE STRING "Support macOS down to High Sierra")
set_property(GLOBAL PROPERTY USE_FOLDERS YES)

option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Show all module sources in IDE projects" ON)

# Find JUCE - either in 3rdparty or system-wide
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/JUCE/CMakeLists.txt")
    # Building as part of main project
    add_subdirectory(../../3rdparty/JUCE ${CMAKE_CURRENT_BINARY_DIR}/JUCE)
    set(ABACDSP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../src/includes")
else()
    # Standalone build - look for installed JUCE
    find_package(JUCE CONFIG REQUIRED)

    # For standalone builds, you might need to specify where AbacDsp headers are
    set(ABACDSP_INCLUDE_DIR "/path/to/installed/abacdsp/include" CACHE PATH "AbacDsp include directory")
    if(NOT EXISTS ${ABACDSP_INCLUDE_DIR})
        message(WARNING "AbacDsp include directory not found. Set ABACDSP_INCLUDE_DIR")
    endif()
endif()

juce_add_plugin("${PROJECT_NAME}"
        VERSION "${CURRENT_VERSION}"
        ICON_BIG "logo.png"
        ICON_SMALL "logo.png"
        COMPANY_NAME "krachpedale"
        COMPANY_WEBSITE "https://krachpedale.de"
        COMPANY_EMAIL "info@krachpedale.de"
        BUNDLE_ID de.krachpedale.delayexample
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_MANUFACTURER_CODE KrPd
        PLUGIN_CODE DLX1
        FORMATS "${FORMATS}"
        PRODUCT_NAME "${PROJECT_NAME}")

target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_20)

# Collect source files
file(GLOB IncludeFiles "src/inc/*.h" "src/inc/*.cpp")
file(GLOB RootFiles "src/*.h" "src/*.cpp")
file(GLOB ImplFiles "src/impl/*.h" "src/impl/*.cpp")
set(SourceFiles ${IncludeFiles} ${RootFiles} ${ImplFiles})

# Exclude GenericImpl.h if needed
list(FILTER SourceFiles EXCLUDE REGEX ".*GenericImpl\\.h$")

# Include AbacDsp headers
target_include_directories("${PROJECT_NAME}" PUBLIC ${ABACDSP_INCLUDE_DIR})

target_sources("${PROJECT_NAME}" PRIVATE ${SourceFiles})
set_target_properties("${PROJECT_NAME}" PROPERTIES FOLDER "")

# Use local source tree for grouping
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src PREFIX "" FILES ${SourceFiles})

juce_add_binary_data(Assets SOURCES logo.png)
set_target_properties(Assets PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

foreach (target ${FORMATS} "All")
    if (TARGET ${PROJECT_NAME}_${target})
        set_target_properties(${PROJECT_NAME}_${target} PROPERTIES
                FOLDER "Targets"
                XCODE_GENERATE_SCHEME ON)
    endif ()
endforeach ()
set_target_properties(Assets PROPERTIES FOLDER "Targets")

target_compile_definitions("${PROJECT_NAME}"
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_USE_CUSTOM_PLUGIN_STANDALONE_APP=0
)

target_link_libraries("${PROJECT_NAME}"
        PRIVATE
        Assets
        juce::juce_audio_utils
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

# Compiler colors
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fcolor-diagnostics)
endif()

option(PACKAGE_TESTS "Build the tests" OFF)
if(PACKAGE_TESTS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/googletest")
    enable_testing()
    add_subdirectory(../../3rdparty/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)
    include(GoogleTest)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/unittests")
        add_subdirectory(src/unittests)
    endif()
endif()