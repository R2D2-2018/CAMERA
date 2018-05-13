#include "GreyscaleImage.hpp"




GreyscaleImage::GreyscaleImage()
{
}


void GreyscaleImage::setPixel(Vector2D position, GreyscalePixel value)
{
	pixels[position.getX][position.getY] = value;
}

GreyscalePixel GreyscaleImage::getPixel(Vector2D position)
{
	return pixels[position.getX][position.getY];
}
