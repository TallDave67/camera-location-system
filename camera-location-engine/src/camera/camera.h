#ifndef _CAMERA_H_
#define _CAMERA_H_

namespace Vision {
  class Camera
  {
    public:
      Camera();
      ~Camera();

      void init_intrinsics();
      void compute_position();
  };
}

#endif
