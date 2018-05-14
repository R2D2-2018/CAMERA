#ifndef GREYSCALEIMAGE_HPP
#define GREYSCALEImage_HPP
#include "Image.hpp"
#include "GreyscalePixel.hpp"
#include "vector-2d.hpp"
class GreyscaleImage :public Image
{
private:
	GreyscalePixel pixels[640][480];
public:
	void setPixel(Vector2D position, GreyscalePixel value);
	GreyscalePixel getPixel(Vector2D position);
};
#endif // GREYSCALEIMAGE_HPP