#include "color_pixel.hpp"

ColorPixel::ColorPixel() : red(0), green(0), blue(0) {
}

void ColorPixel::setRed(const int valueOfPixel) {
    red = valueOfPixel;
}

int ColorPixel::getRed() const {
    return red;
}

void ColorPixel::setBlue(const int valueOfPixel) {
    blue = valueOfPixel;
}

int ColorPixel::getBlue() const {
    return blue;
}

void ColorPixel::setGreen(const int valueOfPixel) {
    green = valueOfPixel;
}

int ColorPixel::getGreen() const {
    return green;
}

bool ColorPixel::operator==(const ColorPixel &rhs) const {
    return getGreen() == rhs.getGreen() && getRed() == rhs.getRed() && getBlue() == rhs.getBlue();
}