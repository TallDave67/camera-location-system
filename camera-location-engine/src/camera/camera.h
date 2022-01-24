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
      void compute_position(cv::Mat &rot_mat, cv::Mat & trans_vec);
 
      cv::Mat & get_camera_intrinsics();
      cv::Mat & get_distortion_coefficients();

      cv::Mat & get_camera_front_world();
      cv::Mat & get_camera_world();

    private:
      cv::Mat camera_intrinsics;
      cv::Mat distortion_coefficients;
      //
      cv::Mat camera_front_world;
      cv::Mat camera_world;
  };
}

#endif
