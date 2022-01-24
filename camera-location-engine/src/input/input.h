#ifndef _INPUT_H_
#define _INPUT_H_

#include <functional>
#include <map>
#include <iostream>

namespace Vision {
  class Input
  {
    typedef std::function<int(int x, int y, int flags, void* userdata)> func_mouse_event_handler;
    typedef std::function<int()> func_key_event_handler;

    public:
      Input();
      ~Input();

      void handle_mouse_event(int event, int x, int y, int flags, void* userdata);
      void handle_key_event(int key);

      void add_mouse_event_handler(int event, func_mouse_event_handler handler);
      void add_key_event_handler(int event, func_key_event_handler handler);

      void set_exit(bool exit_);
      bool is_exit();

    private:
      std::map<int, func_mouse_event_handler> mouse_event_handlers;
      std::map<int, func_key_event_handler> key_event_handlers;
      bool exit;
  };
}

#endif

