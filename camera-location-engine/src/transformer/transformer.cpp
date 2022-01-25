#include "transformer.h"

namespace Vision {
  Transformer::Transformer()
    : rot_mat {3, 3, cv::DataType<double>::type}
  {
  }

  Transformer::~Transformer()
  {
  }

  std::tuple<bool,std::string> Transformer::compute_rotation_matrix(cv::Mat & rot_vec)
  {
    bool computed = true;
    std::string error;

    rot_mat = cv::Mat::zeros(3, 3, cv::DataType<double>::type);
    try
    {
      cv::Rodrigues(rot_vec, rot_mat);
    }
    catch (const cv::Exception& e)
    {
      computed = false;
      error = e.what();
    }

    std::cout << "rot_mat: " << rot_mat << std::endl;
    return std::make_tuple(computed, error);
  }

  cv::Mat & Transformer::get_rotation_matrix()
  {
    return rot_mat;
  }

}
