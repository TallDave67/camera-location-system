cmake_minimum_required(VERSION 3.18)
project(camera_location_engine-src-camera)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
)

add_library(camera_location_engine-src-camera
  camera.cpp
)

target_compile_options(camera_location_engine-src-camera PRIVATE
)

