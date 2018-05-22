/**
 * @file
 * @brief     implementations for mock class.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#include "mock.hpp"
#include "camera.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
Image<GreyscalePixel> Mock::takeGreyImage() {
    Image<GreyscalePixel> image;
    Vector2D position;
    GreyscalePixel value;
    value.setPixel(10);
    for (int i = 0; i < 10; i++) {
        position.setX(i);
        for (int j = 0; j < 10; j++) {
            position.setY(j);
            image.setPixel(position, value);
        }
    }
    return image;
}
Image<ColorPixel> Mock::takeColorImage() {
    Image<ColorPixel> image;
    return image;
}
void Mock::setResolution(Vector2D inputResolution) {
    resolution = inputResolution;
}

void Mock::setFPS(int inputFPS) {
    fps = inputFPS;
}
