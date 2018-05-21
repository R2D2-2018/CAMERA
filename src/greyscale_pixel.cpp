#include "greyscale_pixel.hpp"
GreyscalePixel::GreyscalePixel() {
    pixelValue = 0;
}
void GreyscalePixel::setPixel(int Inputvalue) {
    pixelValue = Inputvalue;
}

int GreyscalePixel::getPixel() {
    return pixelValue;
}