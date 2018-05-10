#include "camera.hpp"
#include "wrap-hwlib.hpp"

// void Camera::setResolution(Vector2D resolution) {
//     resolution = resolution;
// }

Vector2D Camera::getResolution() {
    return resolution;
}

// void Camera::setFPS(int fps) {
//     fps = fps;
// }

int Camera::getFPS() {
    return fps;
}