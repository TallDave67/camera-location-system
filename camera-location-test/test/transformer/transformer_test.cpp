#include "gtest/gtest.h"
#include "transformer.h"
#include <iostream>

// Test
TEST(TransformerTest, IsTrue) {
  EXPECT_EQ(1 == 1, true);
}

TEST(TransformerTest, EmptyRotationVectorCausesException) {
  Vision::Transformer transformer;
  cv::Mat vec;
  auto [computed, error] = transformer.compute_rotation_matrix(vec);
  std::cout << error << std::endl;
  EXPECT_EQ(computed , false);
}
