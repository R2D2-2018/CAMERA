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
    int pixelValue;

  public:
    GreyscalePixel();
    /**
     * @brief set the intesity of the pixel
     *
     * @param[in]     valueOfPixel    new value of pixel
     */
    void setPixel(int valueOfPixel);
    /**
     * @brief return blue intesity of the pixel
     *
     * @return blue intesity of the pixel
     */
    int getPixel() const;
    /**
     * @brief Convert a YCbCr pixel to a GreyscalePixel
     *
     * @param[in]    YCbCr &rhs Reference to the YCbCr pixel.
     * @return Greyscale pixel with the greyscale value of the YCbCr pixel
     */
    GreyscalePixel &operator=(const YCbCr &rhs);
    /**
     * @brief Write greyscalepixel to hwlib::cout
     *
     * @param[in]     hwlib :: cout_using_uart_putc lhs    The definition of the hwlib cout
     * @param[in]     GreyscalePixel rhs The pixel that must be printed.
     */
    template <class C>
    friend C &operator<<(C &lhs, const GreyscalePixel &rhs) {
        lhs << rhs.getPixel();
        return lhs;
    }

    bool operator==(const GreyscalePixel &rhs) const;
};

#endif // GREYSCALE_PIXEL_HPP