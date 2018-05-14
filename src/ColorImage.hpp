/**
 * @file
 * @brief     an image is an abstract data type dat contains a 2 demensional arry of color pixels.
 * the pixels have an own abstract data type class.
 * 
 * @author    Ruben Rajan
 * @license   See LICENSE
 */
#ifndef COLORIMAGE_HPP
#define COLORIMAGE_HPP
#include "Image.hpp"
#include "ColorPixel.hpp"
#include "vector-2d.hpp"
class ColorImage :public Image
{
private:
	ColorPixel pixels[640][480];
public:
/**
* @brief Short description of foo
 *
 * fucntion to set the value in color of the given pixel with vector cordinates
 * 
 * @param[in]	position	the coordinates of the pixel that will be set
 * @param[in]	value		the new color value of the pixel     
 */
	void setPixel(Vector2D position, ColorPixel value);
	/**
 * @brief Short description of foo
 * 
 * get the value of one pixel 
 * 
 * @param[in]     position    vector cordinates of the pixel
 * @return the color value of the pixel
 */
	ColorPixel getPixel(Vector2D position);
};

#endif // COLORIMAGE_HPP