#ifndef _HPP
#define _HPP
#include "camera.hpp"
#include "color_pixel.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
#include "vector_2d.hpp"
#include "wrap-hwlib.hpp"

class OV7670 : public Camera {
  private:
    int test;
    void enableClock();

  public:
    OV7670();
    Image<GreyscalePixel> takeGreyImage();
    Image<ColorPixel> takeColorImage();
    void setResolution(Vector2D resolution);
    void setFPS(int fps);
};
#endif // _HPP