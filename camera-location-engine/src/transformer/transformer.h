#ifndef _TRANSFORMER_H_
#define _TRANSFORMER_H_

namespace Vision {
  class Transformer
  {
    public:
      Transformer();
      ~Transformer();

      void compute_rotation_matrix();
  };
}

#endif