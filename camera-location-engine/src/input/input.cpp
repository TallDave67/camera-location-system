#include "input.h"
#include "input_constants.h"

namespace Vision {
  Input::Input()
    : exit(false)
  {
  }

  Input::~Input()
  {
  }

  void Input::handle_mouse_event(int event, int x, int y, int flags, void* userdata)
  {
    auto itr = mouse_event_handlers.find(event);
    if (itr != mouse_event_handlers.end())
    {
        // execute the handler function
        (itr->second)(x, y, flags, userdata);
    }
  }

  void Input::handle_key_event(int key)
  {
    auto itr = key_event_handlers.find(key);
    if (itr != key_event_handlers.end())
    {
        // execute the handler function
        (itr->second)();
    }
  }

  void Input::add_mouse_event_handler(int event, func_mouse_event_handler handler)
  {
    mouse_event_handlers.insert(std::make_pair(event, handler));
  }

  void Input::add_key_event_handler(int event, func_key_event_handler handler)
  {
    key_event_handlers.insert(std::make_pair(event, handler));
  }

  void Input::set_exit(bool exit_)
  {
    exit = exit_;
  }

  bool Input::is_exit()
  {
    return exit;
  }

}

