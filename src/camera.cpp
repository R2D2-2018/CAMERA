/**
 * @file
 * @brief     Implementations for camera class.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#include "camera.hpp"

Vector2D Camera::getResolution() {
    return resolution;
}

int Camera::getFPS() {
    return fps;
}