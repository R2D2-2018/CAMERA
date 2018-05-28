#include "color_pixel.hpp"
ColorPixel::ColorPixel() {
}

void ColorPixel::setRed(int valueOfPixel) {
    red = valueOfPixel;
}

int ColorPixel::getRed() const {
    return red;
}

void ColorPixel::setBlue(int valueOfPixel) {
    blue = valueOfPixel;
}

int ColorPixel::getBlue() const {
    return blue;
}

void ColorPixel::setGreen(int valueOfPixel) {
    green = valueOfPixel;
}

int ColorPixel::getGreen() const {
    return green;
}

bool operator==(const ColorPixel &lhs, const ColorPixel &rhs) {
    if (lhs.getGreen() == rhs.getGreen() && lhs.getRed() == rhs.getRed() && lhs.getBlue() == rhs.getBlue()) {
        return true;
    } else {
        return false;
    }
}
