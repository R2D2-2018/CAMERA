#ifndef COLORPIXEL_HPP
#define COLORPIXEL_HPP
#include "vector-2d.hpp"
class ColorPixel
{

private:
	int red = 0,
		green = 0,
		blue = 0;
public:
	ColorPixel();
	void setRed(int valueOfPixel);
	int getRed();
	void setBlue(int valueOfPixel);
	int getBlue( );
	void setGreen(int valueOfPixel);
	int getGreen();
};

#endif // COLORPIXEL_HPP