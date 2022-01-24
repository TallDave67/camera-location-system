cmake_minimum_required(VERSION 3.18)
project(camera_location_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  test
  test/agent
  test/camera
  test/image
  test/input
  test/transformer
)

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

add_executable(camera_location_test main.cpp)

target_link_libraries(camera_location_test ${OpenCV_LIBS} gtest_main)
