#include "GreyscalePixel.hpp"



GreyscalePixel::GreyscalePixel()
{
}


void GreyscalePixel::setPixel(int Inputvalue)
{
	pixelValue = Inputvalue;
}

int GreyscalePixel::getPixel()
{
	return pixelValue;
}