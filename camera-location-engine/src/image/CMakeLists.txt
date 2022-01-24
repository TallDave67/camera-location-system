cmake_minimum_required(VERSION 3.18)
project(camera_location_engine-src-image)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_library(camera_location_engine-src-image
  image.cpp
)

target_compile_options(camera_location_engine-src-image PRIVATE
)

target_link_libraries(camera_location_engine-src-image ${OpenCV_LIBS})
