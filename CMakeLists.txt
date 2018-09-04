cmake_minimum_required(VERSION 3.12)
project(GForce)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(LIB_SOURCES
        src/Math.cpp)

add_library(GForce ${LIB_SOURCES})
add_subdirectory(tests)
