cmake_minimum_required(VERSION 3.21)
project(camera_location_engine-src-image)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
)

add_library(camera_location_engine-src-image
  image.cpp
)

target_compile_options(camera_location_engine-src-image PRIVATE
)

