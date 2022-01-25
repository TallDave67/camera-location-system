#include "gtest/gtest.h"
#include "transformer.h"

// Test
TEST(TransformerTest, IsTrue) {
  EXPECT_EQ(1 == 1, true);
}

TEST(TransformerTest, EmptyRotationVectorCausesException) {
  Vision::Transformer transformer;
  cv::Mat vec;
  auto ret = transformer.compute_rotation_matrix(vec);
  EXPECT_EQ(ret , false);
}
