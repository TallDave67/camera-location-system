#ifndef _IMAGE_H_
#define _IMAGE_H_

namespace Vision {
  class Image
  {
    public:
      Image();
      ~Image();

      void show_selected_board();
      void mask_outside_board();
      void find_board_squares();
      void report_results();
  };
}

#endif
