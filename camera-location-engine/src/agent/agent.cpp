#include "agent.h"
#include "agent_constants.h"
#include "image_constants.h"

namespace Vision {
  Agent::Agent() 
    : rot_vec {3, 1, cv::DataType<double>::type}
      ,trans_vec {3, 1, cv::DataType<double>::type}
  {
  }

  Agent::~Agent()
  {
  }

  int Agent::init(const std::string & win_name, const std::string & image_path)
  {
    //mouse event handlers
    add_mouse_event_handler(cv::EVENT_LBUTTONDOWN, std::bind(&Agent::add_next_board_corner, 
      this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

    //key event handlers
    add_key_event_handler(KEY_RUN, std::bind(&Agent::determine_camera_location, this));
    add_key_event_handler(KEY_CLEAR, std::bind(&Agent::clear, this));
    add_key_event_handler(KEY_EXIT, std::bind(&Agent::exit, this));

    if(image.init(win_name, image_path) == 0)
    {
      camera.init();
      return 0;
    }
    else
    {
      return -1;
    }
  }
  
  void Agent::run()
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

  int Agent::add_next_board_corner(int x, int y, int flags, void* userdata)
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
    
  int Agent::determine_camera_location()
  {
    if(image.is_max_board_corners())
    {
        std::cout << "***** Determine camera location using our 4 board_corners as a jumping off point:" << std::endl;
        image.report_board_corners();

        image.mask_outside_board();
        if(image.find_board_squares())
        {
            std::cout << "found square corners" << std::endl;
            image.create_object_points();
            compute_transformation_vectors();
            if(verify_projected_points())
            {
                std::cout << "rotation and translation vectors verified" << std::endl;
                transformer.compute_rotation_matrix(rot_vec);
                camera.compute_position(transformer.get_rotation_matrix(), trans_vec);
                report_camera_position();
            }
        }
    }

    return 0;
  }

  int Agent::clear()
  {
    //deselect all board_corners and clear calibration results
    std::cout << "Deselect all board_corners and clear camera position results" << std::endl;
    image.clear_board_corners();
    image.reset_image();
    image.show_image();
    return 0;
  }

  int Agent::exit()
  {
    set_exit(true);
    return 0;
  }

  void Agent::compute_transformation_vectors()
  {
    cv::solvePnP(image.get_object_points(), image.get_square_corners(), camera.get_camera_intrinsics(), camera.get_distortion_coefficients(), rot_vec, trans_vec);
    std::cout << "rot_vec: " << rot_vec << std::endl;
    std::cout << "trans_vec: " << trans_vec << std::endl;
  }

  bool Agent::verify_projected_points()
  {
    bool verified {true};
    cv::projectPoints(image.get_object_points(), rot_vec, trans_vec, camera.get_camera_intrinsics(), camera.get_distortion_coefficients(), projected_points);
    std::vector<cv::Point2f> & square_corners_ = image.get_square_corners();
    for(unsigned int i = 0; i < projected_points.size(); ++i)
    {
        //check that we get back our original image points (the projections)
        //when applying the RT transformations to our object points
        //within an acceptable pixel tolerance
        double x_diff = abs(square_corners_[i].x - projected_points[i].x);
        double y_diff = abs(square_corners_[i].y - projected_points[i].y);
        if(x_diff > pixel_projection_tolerance || y_diff > pixel_projection_tolerance)
        {
            verified = false;
            std::cerr << "could not recuperate original square corner points from object points using transformation vectors" << std::endl;
            std::cout << "ERROR: could not recuperate original square corner points from object points using transformation vectors" << std::endl;
            break;
        }
    }

    return verified;
  }

  void Agent::report_camera_position()
  {

  }
}