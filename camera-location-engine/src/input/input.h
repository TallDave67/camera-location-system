#ifndef _INPUT_H_
#define _INPUT_H_

namespace Vision {
  class Input
  {
    public:
      Input();
      ~Input();
      
      void handle_mouse_event();
      void handle_key_event();
  };
}

#endif

