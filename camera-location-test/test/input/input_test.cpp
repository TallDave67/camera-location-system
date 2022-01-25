#include "gtest/gtest.h"
#include "input.h"

// Test
TEST(InputTest, IsTrue) {
  EXPECT_EQ(1 == 1, true);
}

TEST(InputTest, IsExitFalse) {
  Vision::Input input;
  auto is_exit = input.is_exit();
  EXPECT_EQ(is_exit , false);
}

TEST(InputTest, IsExitTrue) {
  Vision::Input input;
  input.set_exit(true);
  auto is_exit = input.is_exit();
  EXPECT_EQ(is_exit , true);
}