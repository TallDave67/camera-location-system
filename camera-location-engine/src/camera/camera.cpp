#include "camera.h"
#include "camera_constants.h"

namespace Vision {
  Camera::Camera()
  {
  }

  Camera::~Camera()
  {
  }

  void Camera::init()
  {
    camera_intrinsics = (cv::Mat1d(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);
    distortion_coefficients = (cv::Mat1d(1, 8) << k1, k2, p1, p2, k3, k4, k5, k6);
  }

  void Camera::compute_position()
  {
  }

  cv::Mat & Camera::get_camera_intrinsics()
  {
    return camera_intrinsics;
  }

  cv::Mat & Camera::get_distortion_coefficients()
  {
    return distortion_coefficients;
  }
}