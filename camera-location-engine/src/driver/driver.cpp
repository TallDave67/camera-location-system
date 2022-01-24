#include "driver.h"
#include "drive_constants.h"
#include "image_constants.h"
#include <opencv2/opencv.hpp>

namespace Vision {
  Driver::Driver()
  {
  }

  Driver::~Driver()
  {
  }

  int Driver::init(const std::string & win_name, const std::string & image_path)
  {
    //mouse event handlers
    add_mouse_event_handler(cv::EVENT_LBUTTONDOWN, std::bind(&Driver::next_board_corner, 
      this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

    //key event handlers
    add_key_event_handler(KEY_RUN, std::bind(&Driver::determine_camera_location, this));
    add_key_event_handler(KEY_CLEAR, std::bind(&Driver::clear, this));
    add_key_event_handler(KEY_EXIT, std::bind(&Driver::exit, this));

    return image.init(win_name, image_path);
  }
  
  void Driver::run()
  {
    //show the image
    image.reset_image();
    image.show_image();

    //enter loop
    while(!is_exit())
    {
      int key = (char)cv::waitKey(0);
      handle_key_event(key);
    }
  }

  int Driver::next_board_corner(int x, int y, int flags, void* userdata)
  {
    if(image.is_max_board_corners())
    {
        image.clear_board_corners();
        image.reset_image();
        image.show_image();
    }

    image.add_board_corner(x, y);
    if(image.is_max_board_corners())
    {
        image.show_selected_board();
    }
    
    return 0;
  }
    
  int Driver::determine_camera_location()
  {
    /*
    if(next_board_corner == num_board_corners)
    {
        cout << "***** Determine camera location using our 4 board_corners as a jumping off point:" << endl;
        cout << "board_corners" << endl;
        for(int i = 0; i < num_board_corners; i++)
        {
            cout << "  " << board_corners[0][i] << endl;
        }

        mask_image();
        if(find_square_corners())
        {
            cout << "found square corners" << endl;
            create_object_points();
            get_rotation_translation_vectors();
            if(verify_rotation_translation_vectors())
            {
                cout << "rotation and translation vectors verified" << endl;
                get_rotation_matrix();
                get_camera_position();
                draw_camera_position();
            }
        }
    }
    */
    return 0;
  }

  int Driver::clear()
  {
    //deselect all board_corners and clear calibration results
    std::cout << "Deselect all board_corners and clear camera position results" << std::endl;
    image.clear_board_corners();
    image.reset_image();
    image.show_image();
    return 0;
  }

  int Driver::exit()
  {
    set_exit(true);
    return 0;
  }

  void Driver::compute_transformation_vectors()
  {
  }

  void Driver::verify_projected_points()
  {
  }
}