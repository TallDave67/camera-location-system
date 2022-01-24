#include <iostream>
#include "driver.h"

namespace CameraLocationEngine
{
  Vision::Input * pInput = nullptr;
  void MouseCallback(int event, int x, int y, int flags, void* userdata)
  {
    if(pInput)
    {
      pInput->handle_mouse_event(event, x, y, flags, userdata);
    }
  }
}

int main(int argc, char** argv)
{
  if ( argc != 2 )
  {
    std::cout << "usage: camera_location_engine <image_path>" << std::endl;
    return -1;
  }
  std::string win_name {"camera_location_engine"}; 
  std::string image_path {argv[1]};

  Vision::Driver driver;
  if(driver.init(win_name, image_path) == 0)
  {
    //set the callback object and function for any mouse event
    CameraLocationEngine::pInput = &driver;
    cv::setMouseCallback(win_name, CameraLocationEngine::MouseCallback, NULL);

    driver.run();
  }

  return 0;
}
