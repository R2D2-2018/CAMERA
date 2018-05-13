/**
 * @file
 * @brief     implementations for mock class.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#include "mock.hpp"

void Mock::setResolution(Vector2D inputResolution) {
    resolution = inputResolution;
}

void Mock::setFPS(int inputFPS) {
    fps = inputFPS;
}
