#ifndef _AGENT_H_
#define _AGENT_H_

#include "input.h"
#include "image.h"
#include "camera.h"
#include "transformer.h"
#include <string>
#include <opencv2/opencv.hpp>

namespace Vision {
  class Agent : public Input
  {
    public:
      Agent();
      ~Agent();

      int init(const std::string & win_name, const std::string & image_path);
      void run();

    private:
      //event handlers
      int add_next_board_corner(int x, int y, int flags, void* userdata);
      int determine_camera_location();
      int clear();
      int exit();

      void compute_transformation_vectors();
      bool verify_projected_points();
      void report_camera_position_to_ui();

      void report_error(std::string & error);
      void report_error_to_ui(std::string & error);

    private:
      Vision::Image image;
      Vision::Camera camera;
      Vision::Transformer transformer;
      //
      cv::Mat rot_vec;
      cv::Mat trans_vec;
      //
      std::vector<cv::Point2f> projected_points;     
  };
}

#endif