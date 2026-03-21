cmake_minimum_required(VERSION 3.12 FATAL_ERROR)



# Default values.
set(ExeViewer_VERSION "1.0.0")           # Set program version.
set(CMAKE_CXX_STANDARD "23")        # Set cxx version for cmake build.
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Force to have required cxx version.


# Add default target.
add_executable(ExeViewer src/main.cpp)


project(ExeViewer VERSION ${ExeViewer_VERSION} LANGUAGES CXX) # Project basis.


# Includes.
target_include_directories(ExeViewer PRIVATE include)
target_include_directories(ExeViewer PRIVATE src)
