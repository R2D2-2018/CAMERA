#ifndef GREYSCALEIMAGE_HPP
#define GREYSCALEPIXEL_HPP
#include "Image.hpp"
#include "GreyscalePixel.hpp"
class GreyscaleImage :public Image
{
private:
	GreyscalePixel pixels[640][480];
public:
	void setPixel(Vector2D position, ColorPixel value);
	GreyscalePixel getPixel(Vector2D position);
};
#endif // GREYSCALEIMAGE_HPP