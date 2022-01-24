cmake_minimum_required(VERSION 3.18)
project(camera_location_engine-src-driver)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  ../image
  ../input
)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_library(camera_location_engine-src-driver
  driver.cpp
)

target_compile_options(camera_location_engine-src-driver PRIVATE
)

target_link_libraries(camera_location_engine-src-driver ${OpenCV_LIBS})