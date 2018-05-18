/**
 * @file
 * @brief     2 demisnional array of grey scale pixel wich form an image
 * @author    Ruben Rajan
 * @license   See LICENSE
 */
#ifndef GREYSCALE_IMAGE_HPP
#define GREYSCALE_Image_HPP
#include "image.hpp"
#include "greyscale_pixel.hpp"
#include "vector_2d.hpp"
class GreyscaleImage :public Image
{
private:
	GreyscalePixel pixels[640][480];
public:
	/**
     * @brief fucntion to set the intesity of a pixel
     *[blank]
    * fucntion to set the value in color of the given pixel with vector cordinates
     *[blank]
     * @param[in]	position	the coordinates of the pixel that will be set
     * @param[in]	value		the new intesity of the pixel
     */
	void setPixel(Vector2D position, GreyscalePixel value);
	/**
     * @brief get pixel value
     *
     * get the value of one pixel at a specific location
     *
     * @param[in]     position    vector cordinates of the pixel
     * @return the intesity of the pixel
     */
	GreyscalePixel getPixel(Vector2D position);
};
#endif // GREYSCALE_IMAGE_HPP