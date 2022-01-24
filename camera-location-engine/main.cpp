#include <iostream>
#include "agent.h"

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

  Vision::Agent agent;
  if(agent.init(win_name, image_path) == 0)
  {
    //set the callback object and function for any mouse event
    CameraLocationEngine::pInput = &agent;
    cv::setMouseCallback(win_name, CameraLocationEngine::MouseCallback, NULL);

    agent.run();
  }

  return 0;
}
