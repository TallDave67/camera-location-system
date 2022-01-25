#include "gtest/gtest.h"
#include "image.h"

// Test
TEST(ImageTest, IsTrue) {
  EXPECT_EQ(1 == 1, true);
}

TEST(ImageTest, InitFailsWithoutImage) {
  Vision::Image image;
  auto [ret, error] = image.init("test_window", "");
  EXPECT_EQ(ret , -1);
}