cmake_minimum_required(VERSION 3.20)

project(DataStructuresAndAlgorithms)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# declares a dependency on GoogleTest which is downloaded from GitHub
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

option(DEBUG_OUTPUT "option for debug out" OFF)
if (DEBUG_OUTPUT)
    add_definitions(-D_DEBUG)
endif()

# Enables testing for this directory and below
enable_testing()
include(GoogleTest)

add_subdirectory(DataStructures)
add_subdirectory(Algorithms)
add_subdirectory(tests)