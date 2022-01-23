#ifndef _DRIVER_H_
#define _DRIVER_H_

namespace Vision {
  class Driver
  {
    public:
      Driver();
      ~Driver();

      void run();

    private:
      void compute_transformation_vectors();
      void verify_projected_points();
  };
}

#endif