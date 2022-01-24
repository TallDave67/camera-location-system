#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <opencv2/opencv.hpp>

namespace Vision {
  class Camera
  {
    public:
      Camera();
      ~Camera();

      void init();
      void compute_position();

      cv::Mat & get_camera_intrinsics();
      cv::Mat & get_distortion_coefficients();

    private:
      cv::Mat camera_intrinsics;
      cv::Mat distortion_coefficients;
  };
}

#endif
