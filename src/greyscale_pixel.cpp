#include "greyscale_pixel.hpp"
#include "ycbcr.hpp"
GreyscalePixel::GreyscalePixel() {
    pixelValue = 0;
}
void GreyscalePixel::setPixel(int Inputvalue) {
    pixelValue = Inputvalue;
}

int GreyscalePixel::getPixel() const {
    return pixelValue;
}
GreyscalePixel &GreyscalePixel::operator=(const YCbCr &rhs) {
    setPixel(rhs.getY());
    return *this;
}

bool operator==(const GreyscalePixel &lhs, const GreyscalePixel &rhs) {
    if (lhs.getPixel() == rhs.getPixel()) {
        return true;
    } else {
        return false;
    }
}
