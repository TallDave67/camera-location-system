#include "gtest/gtest.h"
#include "camera_constants.h"
#include "camera.h"

// Tests
TEST(CameraTest, IsTrue) {
  EXPECT_EQ(1 == 1, true);
}

TEST(CameraTest, VerifyCameraIntrinsics) {
  Vision::Camera camera;
  camera.init();
  cv::Mat camera_intrinsics = camera.get_camera_intrinsics();
  EXPECT_EQ(camera_intrinsics.at<double>(0, 0) , fx);
  EXPECT_EQ(camera_intrinsics.at<double>(0, 1) , 0);
  EXPECT_EQ(camera_intrinsics.at<double>(0, 2) , cx);
  EXPECT_EQ(camera_intrinsics.at<double>(1, 0) , 0);
  EXPECT_EQ(camera_intrinsics.at<double>(1, 1) , fy);
  EXPECT_EQ(camera_intrinsics.at<double>(1, 2) , cy);
  EXPECT_EQ(camera_intrinsics.at<double>(2, 0) , 0);
  EXPECT_EQ(camera_intrinsics.at<double>(2, 1) , 0);
  EXPECT_EQ(camera_intrinsics.at<double>(2, 2) , 1);
}