#include "greyscale_pixel.hpp"
#include "ycbcr.hpp"
GreyscalePixel::GreyscalePixel() : pixelValue(0) {
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

bool GreyscalePixel::operator==(const GreyscalePixel &rhs) const {
    return getPixel() == rhs.getPixel();
}