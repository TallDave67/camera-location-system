#include "transformer.h"

namespace Vision {
  Transformer::Transformer()
    : rot_mat {3, 3, cv::DataType<double>::type}
  {
  }

  Transformer::~Transformer()
  {
  }

  void Transformer::compute_rotation_matrix(cv::Mat & rot_vec)
  {
    cv::Rodrigues(rot_vec, rot_mat);
    std::cout << "rot_mat: " << rot_mat << std::endl;
  }

  cv::Mat & Transformer::get_rotation_matrix()
  {
    return rot_mat;
  }

}
