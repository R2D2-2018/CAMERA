/**
 * @file
 * @brief     abstract data class wich contain the grayscale intesity of one pixel
 * @author    Ruben Rajan
 * @license   See LICENSE
 */
#ifndef GREYSCALE_PIXEL_HPP
#define GREYSCALE_PIXEL_HPP
#include "ycbcr.hpp"
class GreyscalePixel {

  private:
    int pixelValue = 0;

  public:
    GreyscalePixel();
    /**
     * @brief set the intesity of the pixel
     * [BLANK]
     * @param[in]     valueOfPixel    new value of pixel
     */
    void setPixel(int valueOfPixel);
    /**
     * @brief return blue intesity of the pixel
     * [BLANK]
     * @return blue intesity of the pixel
     */
    int getPixel() const;
    /**
     * @brief Convert a YCbCr pixel to a GreyscalePixel
     * [BLANK]
     *
     * [BLANK]
     * @param[in]    YCbCr &rhs Reference to the YCbCr pixel.
     * @return Greyscale pixel with the greyscale value of the YCbCr pixel
     */
    GreyscalePixel &operator=(const YCbCr &rhs);
};
bool operator==(const GreyscalePixel &lhs, const GreyscalePixel &rhs);
#endif // GREYSCALE_PIXEL_HPP