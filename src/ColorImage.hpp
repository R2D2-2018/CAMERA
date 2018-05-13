#ifndef COLORIMAGE_HPP
#define COLORIMAGE_HPP
#include "Image.hpp"
#include "ColorPixel.hpp"
class ColorImage :public Image
{
private:
	ColorPixel pixels[640][480];
public:
	void setPixel(Vector2D position, ColorPixel value);
		ColorPixel getPixel(Vector2D position);
};

#endif // COLORIMAGE_HPP