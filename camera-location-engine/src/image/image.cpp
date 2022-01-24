#include "image.h"
#include "image_constants.h"

namespace Vision {
  Image::Image()
    : next_board_corner {0}
  {
  }
  
  Image::~Image()
  {
  }
  
  int Image::init(const std::string & win_name_, const std::string & image_path)
  {
    win_name = win_name_;
    image = cv::imread( image_path, 1 );
    if ( !image.data )
    {
        std::cout << "No image data" << std::endl;
        return -1;
    }

    cv::resize(image, image, cv::Size(image.cols/2, image.rows/2)); // to half size
    cv::namedWindow(win_name, cv::WINDOW_AUTOSIZE );

    //prepare our board_corners
    memset(board_corners, 0, num_board_corners * sizeof(cv::Point));

    return 0;
  }
  
  void Image::reset_image()
  {
    //clone the original image
    //into the image to be shown
    image_shown = image.clone();     
  }

  void Image::show_image()
  {
    //show the image
    cv::imshow(win_name, image_shown);      
  }

  void Image::show_selected_board()
  {
    const cv::Scalar color {0, 0, 255}; //BGR
    int thickness {3};
    int line_type {cv::LINE_8};
    int shift {0};

    //reset our image
    image_shown = image.clone();

    cv::line(image_shown, board_corners[0][0], board_corners[0][1], color, thickness, line_type, shift);
    cv::line(image_shown, board_corners[0][1], board_corners[0][2], color, thickness, line_type, shift);
    cv::line(image_shown, board_corners[0][2], board_corners[0][3], color, thickness, line_type, shift);
    cv::line(image_shown, board_corners[0][3], board_corners[0][0], color, thickness, line_type, shift);

    //show the new image
    cv::imshow(win_name, image_shown);
  }

  void Image::mask_outside_board()
  {
    const cv::Point* ppt[1] = {board_corners[0]};
    int npt[] {num_board_corners};
    const cv::Scalar black {0, 0, 0}; //BGR
    int line_type {cv::LINE_8};

    cv::Mat image_mask;
    image_mask = image.clone();
    const cv::Scalar white {255, 255, 255}; //BGR
    image_mask.setTo(white);

    cv::fillPoly( image_mask,
              ppt,
              npt,
              1,
              black,
              line_type );

    cv::bitwise_or(image, image_mask, image_shown);
    cv::imshow(win_name, image_shown);
  }
  
  bool Image::find_board_squares()
  {
    cv::Size pattern_size(num_square_corners_horizontal, num_square_corners_vertical); //interior number of board_corners
    cv::Mat gray;
    cv::cvtColor(image_shown,gray,cv::COLOR_BGR2GRAY);//source image

    //this will be filled by the detected board_corners
    //CALIB_CB_FAST_CHECK saves a lot of time on images that do not contain chessboard squares
    square_corners.clear();
    bool pattern_found = cv::findChessboardCorners(
      gray, pattern_size, square_corners,
      cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_NORMALIZE_IMAGE + cv::CALIB_CB_FAST_CHECK);

    if(pattern_found)
    {
        cv::cornerSubPix(
          gray, square_corners, cv::Size(11, 11), cv::Size(-1, -1),
          cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 30, 0.1));
        cv::drawChessboardCorners(image_shown, pattern_size, cv::Mat(square_corners), pattern_found);
        cv::imshow(win_name, image_shown);
    }
    else
    {
        std::cerr << "no chessboard squares found, cannot determine camera position" << std::endl;
        std::cout << "ERROR: no chessboard squares found, cannot determine camera position" << std::endl;
    }

    return pattern_found;
  }
  
  void Image::create_object_points()
  {
    // 3D coordinates of chessboard points
    std::cout << "world origin (0,0) is chosen to be at image's first square corner (" << square_corners[0].x << "," << square_corners[0].y << ")" << std::endl;
    std::cout << "coordinate system is right-handed (x right, y down, z forward)" << std::endl;
    object_points.clear();
    for(int y=0; y < num_square_corners_vertical; ++y)
        for(int x=0; x < num_square_corners_horizontal; ++x)
            object_points.push_back(cv::Point3f(x * square_size, y * square_size, 0));
  
  }

  void Image::report_results(const std::vector<std::stringstream> & header, const std::vector<std::stringstream> & body, enum Vision::Result result)
  {
    const cv::Scalar color {result == Vision::Result::ERROR ? 100. : 0., 0., result == Vision::Result::SUCCESS ? 100. : 0.}; //BGR
    int row = 10;
    int row_inc = 30;
    //
    for(auto const & t : header)
    {
      row += row_inc;
      cv::putText(
        image_shown,
        t.str(), //text
        cv::Point(20, row), //top-left position
        cv::FONT_HERSHEY_COMPLEX,
        1.0,
        color, //font color
        2);
    }
    //
    for(auto const & t : body)
    {
      row += row_inc;
      cv::putText(
        image_shown,
        t.str(), //text
        cv::Point(20, row), //top-left position
        cv::FONT_HERSHEY_COMPLEX_SMALL,
        1.0,
        color, //font color
        2);
    }

    cv::imshow(win_name, image_shown);
  }

  void Image::clear_board_corners()
  {
    memset(board_corners, 0, num_board_corners * sizeof(cv::Point));
    next_board_corner = 0;
  }

  bool Image::is_max_board_corners()
  {
    return (next_board_corner == num_board_corners);
  }

  void Image::add_board_corner(int x, int y)
  {
    if(next_board_corner < num_board_corners)
    {
      board_corners[0][next_board_corner].x = x;
      board_corners[0][next_board_corner].y = y;
      next_board_corner++;
    }    
  }

  void Image::report_board_corners()
  {
    std::cout << "board_corners" << std::endl;
    for(int i = 0; i < num_board_corners; i++)
    {
        std::cout << "  " << board_corners[0][i] << std::endl;
    }
  }

  std::vector<cv::Point2f> & Image::get_square_corners()
  {
    return square_corners;
  }

  std::vector<cv::Point3f> & Image::get_object_points()
  {
    return object_points;
  }
}
