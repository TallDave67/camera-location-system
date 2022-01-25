#ifndef CAMERA_LOCATION_ENGINE_AGENT_CONSTANTS_H
#define CAMERA_LOCATION_ENGINE_AGENT_CONSTANTS_H

constexpr int KEY_RUN = 13; //Carriage Return Key
constexpr int KEY_CLEAR = 8; //Backspace Key
constexpr int KEY_EXIT = 27; //Escape Key

constexpr double pixel_projection_tolerance = 5.0;

//error reporting
#include <string>
const std::string error_label {"ERROR"};
constexpr unsigned int ERROR_CHANNEL_CERR = (1U<<0);
constexpr unsigned int ERROR_CHANNEL_COUT = (1U<<1);
constexpr unsigned int ERROR_CHANNEL_UI = (1U<<2);

#endif //CAMERA_LOCATION_ENGINE_AGENT_CONSTANTS_H
