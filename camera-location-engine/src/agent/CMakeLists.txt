cmake_minimum_required(VERSION 3.18)
project(camera_location_engine-src-agent)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  ../camera
  ../image
  ../input
  ../transformer
)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_library(camera_location_engine-src-agent
  agent.cpp
)

target_compile_options(camera_location_engine-src-agent PRIVATE
)

target_link_libraries(camera_location_engine-src-agent ${OpenCV_LIBS})