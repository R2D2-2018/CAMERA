/**
 * @file
 * @brief     hpp of abstract data class pixel
 * @author    Ruben Rajan
 * @license   See LICENSE
 */
#ifndef COLOR_PIXEL_HPP
#define COLOR_PIXEL_HPP

class ColorPixel {

  private:
    int red, green, blue;

  public:
    ColorPixel();
    /**
     * @brief set the red intesity of the pixel
     *
     * @param[in]     valueOfPixel    new value of pixel
     */
    void setRed(const int valueOfPixel);
    /**
     * @brief return red intesity of the pixel
     *
     * @return red intesity of the pixel
     */
    int getRed() const;
    /**
     * @brief set the blue intesity of the pixel
     *
     * @param[in]     valueOfPixel    new value of pixel
     */
    void setBlue(const int valueOfPixel);
    /**
     * @brief return blue intesity of the pixel
     *
     * @return blue intesity of the pixel
     */
    int getBlue() const;
    /**
     * @brief set the green intesity of the pixel
     *
     * @param[in]     valueOfPixel    new value of pixel
     */
    void setGreen(const int valueOfPixel);
    /**
     * @brief return green intesity of the pixel
     *
     * @return green intesity of the pixel
     */
    int getGreen() const;
    /**
     * @brief Operator== for two color pixels
     *
     * @param[in]     &lhs One colorpixel to compare.
     * @param[in]     &rhs One colorpixel to compare/
     * @return True if equal, else false.
     */
    bool operator==(const ColorPixel &rhs) const;
};

#endif // COLOR_PIXEL_HPP