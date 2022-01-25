#ifndef _TRANSFORMER_H_
#define _TRANSFORMER_H_

#include <opencv2/opencv.hpp>

namespace Vision {
  class Transformer
  {
    public:
      Transformer();
      ~Transformer();

      bool compute_rotation_matrix(cv::Mat & rot_vec);

      cv::Mat & get_rotation_matrix();

    private:
      cv::Mat rot_mat;
  };
}

#endif