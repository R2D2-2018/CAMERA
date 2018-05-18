/**
 * @file
 * @brief     an image is an abstract data type dat contains a 2 demensional arry of color pixels.
 * the pixels have an own abstract data type class.
 *
 * @author    Ruben Rajan
 * @license   See LICENSE
 */
#ifndef COLOR_IMAGE_HPP
#define COLOR_IMAGE_HPP
#include "color_pixel.hpp"
#include "image.hpp"
#include "vector_2d.hpp"
class ColorImage : public Image {
  private:
    ColorPixel pixels[640][480];

  public:
    /**
     * @brief fucntion to set the intesity of a pixel
     *[blank]
    * fucntion to set the value in color of the given pixel with vector cordinates
     *[blank]
     * @param[in]	position	the coordinates of the pixel that will be set
     * @param[in]	value		the new color value of the pixel
     */
    void setPixel(Vector2D position, ColorPixel value);
    /**
     * @brief get pixel value
     *
     * get the value of one pixel at a specific location
     *
     * @param[in]     position    vector cordinates of the pixel
     * @return the color value of the pixel
     */
    ColorPixel getPixel(Vector2D position);
};

#endif // COLOR_IMAGE_HPP