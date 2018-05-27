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
    void enableClock();
    bool pollHREF();
    hwlib::pin_in & pinPollHREF;
    hwlib::pin_in & pinPollPLCK;
    hwlib::pin_in * (&dataPins)[8];
  public:
    OV7670(hwlib::pin_in & pinPollHREF, hwlib::pin_in & pinPollPLCK, hwlib::pin_in * (&dataPins)[8]);
    Image<GreyscalePixel> takeGreyImage();
    Image<ColorPixel> takeColorImage();
    /**
   * @brief Short set the capture resolution
   * [BLANK]
   * @param[in]     resolution the new resolution of the camera
   */
    void setResolution(Vector2D resolution);
    /**
   * @brief Short set the fps of the camera
   * [BLANK]
   * @param[in]     fps the new fps value of the camera
   */
    void setFPS(int fps);
    /**
   * @brief caputere a line of pixe
   * [BLANK]
   * capture a line of pixels horizontal. it reads the raw bytes in a ycbcr422 format 
   * [BLANK]
   * @param[in]     rawData    array to place Ycbcr sensor data in
   * @param[in]     lengtht    lenght of array.
   */
    void capture(int rawData[], int lenght);
};
#endif // _HPP