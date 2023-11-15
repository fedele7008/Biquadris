# Check cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

# Project info
PROJECT(
    Biquadris
    VERSION 1.0
    DESCRIPTION "UWATERLOO CS 246 Project"
    LANGUAGES CXX)

# Locate executable file in build/bin/ directory
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Run recursive cmakes
ADD_SUBDIRECTORY(src)

# Copy arguments to bin
FILE(GLOB_RECURSE arg_files
    ${CMAKE_SOURCE_DIR}/sample_arg/*.txt
)

FOREACH(file ${arg_files})
    file(COPY ${file} DESTINATION ${CMAKE_BINARY_DIR}/bin)
ENDFOREACH()

