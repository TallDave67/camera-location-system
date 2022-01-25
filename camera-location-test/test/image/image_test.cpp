#include "gtest/gtest.h"
#include "image.h"

// Test
TEST(ImageTest, IsTrue) {
  EXPECT_EQ(1 == 1, true);
}

TEST(ImageTest, InitFailsWithoutImage) {
  Vision::Image image;
  auto [init, error] = image.init("test_window", "");
  EXPECT_EQ(init , false);
}

TEST(ImageTest, EmptyDataToFindBoardSquaresCausesException) {
  Vision::Image image;
  auto [find, error] = image.find_board_squares();
  std::cout << error << std::endl;
  EXPECT_EQ(find , false);
}
