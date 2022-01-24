cmake_minimum_required(VERSION 3.18)
project(camera_location_engine-src-transformer)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_library(camera_location_engine-src-transformer
  transformer.cpp
)

target_compile_options(camera_location_engine-src-transformer PRIVATE
)

target_link_libraries(camera_location_engine-src-transformer ${OpenCV_LIBS})