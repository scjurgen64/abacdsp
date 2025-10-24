# CMakeLists.txt for FDN Reverb Performance Test
cmake_minimum_required(VERSION 3.15)

project(FdnPerformanceTest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optimization flags for performance testing
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
endif()

# Include directories
include_directories(../../../src/includes)

# Find required packages
find_package(Threads REQUIRED)

# Create executable
add_executable(PerformanceFdn PerformanceFdnWalshAndBlockDelay.cpp)

# Link libraries
target_link_libraries(PerformanceFdn Threads::Threads)

# Architecture-specific optimizations
if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|amd64")
    # x86_64 architecture
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        target_compile_options(PerformanceFdn PRIVATE -march=native -mtune=native)
    elseif(MSVC)
        target_compile_options(PerformanceFdn PRIVATE /arch:AVX2)
    endif()
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|ARM64|arm64")
    # ARM64 architecture (Apple Silicon, etc.)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        target_compile_options(PerformanceFdn PRIVATE -mcpu=native)
    elseif(MSVC)
        # MSVC ARM64 doesn't need specific flags for NEON (always available)
    endif()
endif()

# Set build type to Release by default for performance testing
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Print architecture information
message(STATUS "Building for architecture: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
