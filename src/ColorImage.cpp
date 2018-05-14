#include "ColorImage.hpp"

void ColorImage::setPixel(Vector2D position, ColorPixel value) {
    pixels[position.getX()][position.getY()] = value;
}

ColorPixel ColorImage::getPixel(Vector2D position) {
    return pixels[position.getX()][position.getY()];
}
