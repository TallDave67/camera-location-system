cmake_minimum_required(VERSION 3.18)
project(camera_location_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  ../camera-location-engine/src
  ../camera-location-engine/src/agent
  ../camera-location-engine/src/camera
  ../camera-location-engine/src/image
  ../camera-location-engine/src/input
  ../camera-location-engine/src/transformer
)

set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BUILD_DIR}/lib")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# ***** Fetch googletest
include(FetchContent)
FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# ***** end of Fetch googletest

add_executable(camera_location_test 
  main.cpp 
  test/agent/agent_test.cpp
  test/camera/camera_test.cpp
  test/image/image_test.cpp
  test/input/input_test.cpp
  test/transformer/transformer_test.cpp
)

target_link_libraries(camera_location_test 
  ${OpenCV_LIBS}
  gtest_main
)
