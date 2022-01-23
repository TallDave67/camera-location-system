cmake_minimum_required(VERSION 3.21)
project(camera_location_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(src)
include_directories(
  src
  src/camera
  src/driver
  src/image
  src/input
  src/transformer
)

add_executable(camera_location_engine main.cpp)

target_link_libraries(camera_location_engine camera_location_engine-src)