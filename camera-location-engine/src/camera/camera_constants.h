#ifndef CAMERA_LOCATION_ENGINE_CAMERA_CONSTANTS_H
#define CAMERA_LOCATION_ENGINE_CAMERA_CONSTANTS_H

constexpr int cx = 1280;
constexpr int cy = 960;
constexpr double fx = 3751.937744140625;
constexpr double fy = 3821.9775390625;
constexpr double k1 = -1.2093325853347778;
constexpr double k2 = -1.041786551475525;
constexpr double k3 = 64.01393127441406;
constexpr double k4 = -0.5568028688430786;
constexpr double k5 = -3.6638600826263428;
constexpr double k6 = 78.03067016601562;
constexpr double p1 = -0.004819112829864025;
constexpr double p2 = -0.0027203019708395004;

/*
Aperture
height: 4.224 mm
width: 5.632 mm

Field of View
horizontal: 39°
vertical: 29.6°

FOV_Horizontal = 2 * atan(W/2/f)
f = (W/2)/tan(FOV_Horizontal/2)
f = (5.632/2)/tan((39 * (pi / 180))/2)
f = 7.952138686

FOV_Vertical = 2 * atan(H/2/f)
f = (H/2)/tan(FOV_Vertical/2)
f = (4.224/2)/tan((29.6 * (pi / 180))/2)
f = 7.993599163

Use average of 2 f values
f = 7.972868924
 */
constexpr double camera_focal_length = 7.972868924;

#endif //CAMERA_LOCATION_ENGINE_CAMERA_CONSTANTS_H
