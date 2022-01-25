#ifndef _AGENT_H_
#define _AGENT_H_

#include "agent_constants.h"
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

      bool init(const std::string & win_name, const std::string & image_path);
      void run();

      std::tuple<bool,std::string> compute_transformation_vectors();
      std::tuple<bool,std::string> verify_projected_points();

      cv::Mat & get_rotation_vector();
      cv::Mat & get_translation_vector();

    private:
      //event handlers
      int add_next_board_corner(int x, int y, int flags, void* userdata);
      int determine_camera_location();
      int clear();
      int exit();

      void report_camera_position_to_ui();

      void report_error(const std::string & error, unsigned int channel = ERROR_CHANNEL_CERR | ERROR_CHANNEL_COUT | ERROR_CHANNEL_UI);
      void report_error_to_ui(const std::string & error);

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