#ifndef CAMERA_LOCATION_ENGINE_IMAGE_CONSTANTS_H
#define CAMERA_LOCATION_ENGINE_IMAGE_CONSTANTS_H

constexpr int num_board_corners = 4;
constexpr int square_size = 25; //mm
constexpr int num_square_corners_horizontal = 9;
constexpr int num_square_corners_vertical = 6;

namespace Vision {
  enum class Result { NONE, SUCCESS, ERROR };
}

#endif //CAMERA_LOCATION_ENGINE_IMAGE_CONSTANTS_H
