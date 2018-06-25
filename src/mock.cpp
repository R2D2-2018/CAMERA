/**
 * @file
 * @brief     implementations for mock class.
 * @author    Jari van Dam, Willem de Groot
 * @license   See LICENSE
 */
#include "mock.hpp"
#include "camera.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"

Mock::Mock(int fps, Vector2D resolution) : Camera(fps, resolution) {
}

Mock::Mock() : Camera() {
}

Image<GreyscalePixel> Mock::takeGreyImage() {
    Image<GreyscalePixel> image;
    Vector2D position;
    GreyscalePixel value;
    value.setPixel(10);
    for (int i = 0; i < image.getHeight(); i++) {
        position.setX(i);
        for (int j = 0; j < image.getWidth(); j++) {
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