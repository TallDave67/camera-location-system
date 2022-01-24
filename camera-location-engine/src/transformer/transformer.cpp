#include "transformer.h"

namespace Vision {
  Transformer::Transformer()
    : rot_mat {3, 3, cv::DataType<double>::type}
  {
  }

  Transformer::~Transformer()
  {
  }

  void Transformer::compute_rotation_matrix()
  {
  }
}
