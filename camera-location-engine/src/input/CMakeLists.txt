cmake_minimum_required(VERSION 3.21)
project(camera_location_engine-src-input)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
)

add_library(camera_location_engine-src-input
  input.cpp
)

target_compile_options(camera_location_engine-src-input PRIVATE
)
