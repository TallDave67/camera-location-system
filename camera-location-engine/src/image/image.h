#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "image_constants.h"
#include <string>
#include <sstream>
#include <tuple>
#include <opencv2/opencv.hpp>

namespace Vision {
  class Image
  {
    public:
      Image();
      ~Image();

      std::tuple<int,std::string> init(const std::string & win_name_, const std::string & image_path);

      void reset_image();
      void show_image();
      void show_selected_board();
      void mask_outside_board();
      std::tuple<bool,std::string> find_board_squares();
      void create_object_points();
      void report_results_to_ui(const std::vector<std::stringstream> & header, const std::vector<std::stringstream> & body, enum Vision::Result result);

      void clear_board_corners();
      bool is_max_board_corners();
      void add_board_corner(int x, int y);
      void report_board_corners();

      std::vector<cv::Point2f> & get_square_corners();
      std::vector<cv::Point3f> & get_object_points();

    private:
      //our window name
      std::string win_name;

      //our image
      cv::Mat image;
      cv::Mat image_shown;

      //our board_corners
      size_t next_board_corner;
      cv::Point board_corners[1][num_board_corners];

      //our square_corners
      std::vector<cv::Point2f> square_corners;
      std::vector<cv::Point3f> object_points;
  };
}

#endif
