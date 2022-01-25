#include "gtest/gtest.h"
#include "agent.h"

// Test
TEST(AgentTest, IsTrue) {
  EXPECT_EQ(1 == 1, true);
}

TEST(AgentTest, VerifyRotationVector) {
  Vision::Agent agent;
  cv::Mat rotation_vector = agent.get_rotation_vector();
  EXPECT_EQ(rotation_vector.at<double>(0, 0) , 0.0);
  EXPECT_EQ(rotation_vector.at<double>(0, 1) , 0.0);
  EXPECT_EQ(rotation_vector.at<double>(0, 2) , 0.0);
}

TEST(AgentTest, VerifyTranslationVector) {
  Vision::Agent agent;
  cv::Mat translation_vector = agent.get_translation_vector();
  EXPECT_EQ(translation_vector.at<double>(0, 0) , 0.0);
  EXPECT_EQ(translation_vector.at<double>(0, 1) , 0.0);
  EXPECT_EQ(translation_vector.at<double>(0, 2) , 0.0);
}