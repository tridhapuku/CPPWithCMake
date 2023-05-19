cmake_minimum_required(VERSION 3.0.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# add_library(math SHARED operations.cpp)
add_library(math STATIC operations.cpp)