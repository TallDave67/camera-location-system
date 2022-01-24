#ifndef _DRIVER_H_
#define _DRIVER_H_

#include "input.h"
#include "image.h"
#include <string>

namespace Vision {
  class Driver : public Input
  {
    public:
      Driver();
      ~Driver();

      int init(const std::string & win_name, const std::string & image_path);
      void run();

    private:
      //event handlers
      int next_board_corner(int x, int y, int flags, void* userdata);
      int determine_camera_location();
      int clear();
      int exit();

      void compute_transformation_vectors();
      void verify_projected_points();

      private:
        Vision::Image image;
  };
}

#endif