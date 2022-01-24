cmake_minimum_required(VERSION 3.18)
project(camera_location_engine-src)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(camera)
add_subdirectory(driver)
add_subdirectory(image)
add_subdirectory(input)
add_subdirectory(transformer)
include_directories(
  camera
  driver
  image
  input
  transformer
)

add_library(camera_location_engine-src
  src_main.cpp
)

target_compile_options(camera_location_engine-src PRIVATE
)

target_link_libraries(camera_location_engine-src
  camera_location_engine-src-camera
  camera_location_engine-src-driver
  camera_location_engine-src-image
  camera_location_engine-src-input
  camera_location_engine-src-transformer
)
