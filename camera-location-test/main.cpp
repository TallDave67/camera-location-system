#include "gtest/gtest.h"
#include "camera.h"

int main(int argc, char **argv) {
  //Instantiate each component in the system so their code is compiled in
  Vision::Camera camera;

  //Init the google test framework and run all tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}