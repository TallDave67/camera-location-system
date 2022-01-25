#include "gtest/gtest.h"
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  //We must invoke OpenCV code to get it linked in
  cv::waitKey(1);
  cv::imread("");
  try{cv::cornerSubPix(cv::Mat(),std::vector<cv::Point2f>(),cv::Size(0, 0),cv::Size(0, 0),cv::TermCriteria(cv::TermCriteria::MAX_ITER, 0, 0.0));}catch(const cv::Exception& e){}
  try{cv::solvePnP(std::vector<cv::Point3f>(),std::vector<cv::Point2f>(),cv::Mat(),cv::Mat(),cv::Mat(),cv::Mat());}catch(const cv::Exception& e){}
  try{cv::projectPoints(std::vector<cv::Point3f>(),cv::Mat(),cv::Mat(),cv::Mat(),cv::Mat(),std::vector<cv::Point2f>());}catch(const cv::Exception& e){}
  try{cv::findChessboardCorners(cv::Mat(),cv::Size(0, 0),std::vector<cv::Point2f>(),cv::CALIB_CB_FAST_CHECK);}catch(const cv::Exception& e){}
  try{cv::Rodrigues(cv::Mat(),cv::Mat());}catch(const cv::Exception& e){}

  //Init the google test framework and run all tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}