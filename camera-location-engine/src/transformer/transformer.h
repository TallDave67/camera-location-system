#ifndef _TRANSFORMER_H_
#define _TRANSFORMER_H_

#include <opencv2/opencv.hpp>

namespace Vision {
  class Transformer
  {
    public:
      Transformer();
      ~Transformer();

      void compute_rotation_matrix();

    private:
      cv::Mat rot_mat;
  };
}

#endif