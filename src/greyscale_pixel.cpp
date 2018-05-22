#include "greyscale_pixel.hpp"
GreyscalePixel::GreyscalePixel() {
    pixelValue = 0;
}
void GreyscalePixel::setPixel(int Inputvalue) {
    pixelValue = Inputvalue;
}

int GreyscalePixel::getPixel() const {
    return pixelValue;
}

bool operator==(const GreyscalePixel &lhs, const GreyscalePixel &rhs) {
    if (lhs.getPixel() == rhs.getPixel()) {
        return true;
    } else {
        return false;
    }
}