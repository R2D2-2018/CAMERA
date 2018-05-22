/**
 * @file
 * @brief     abstract data class wich contain the grayscale intesity of one pixel
 * @author    Ruben Rajan
 * @license   See LICENSE
 */
#ifndef GREYSCALE_PIXEL_HPP
#define GREYSCALE_PIXEL_HPP
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
};

#endif // GREYSCALE_PIXEL_HPP