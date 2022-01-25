#include "transformer.h"

namespace Vision {
  Transformer::Transformer()
    : rot_mat {3, 3, cv::DataType<double>::type}
  {
  }

  Transformer::~Transformer()
  {
  }

  bool Transformer::compute_rotation_matrix(cv::Mat & rot_vec)
  {
    bool ret = true;
    rot_mat = cv::Mat::zeros(3, 3, cv::DataType<double>::type);
    try
    {
      cv::Rodrigues(rot_vec, rot_mat);
    }
    catch (const cv::Exception& e2)
    {
      ret = false;
    }

    std::cout << "rot_mat: " << rot_mat << std::endl;
    return ret;
  }

  cv::Mat & Transformer::get_rotation_matrix()
  {
    return rot_mat;
  }

}
