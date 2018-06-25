/**
 * @file
 * @brief     Header file for camera mock.
 * @author    Jari van Dam, Willem de Groot
 * @license   See LICENSE
 */
#ifndef MOCK_HPP
#define MOCK_HPP
#include "camera.hpp"
#include "color_pixel.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
#include "vector_2d.hpp"
class Mock : public Camera {
  public:
    Mock(int fps, Vector2D resolution);
    Mock();
    Image<GreyscalePixel> takeGreyImage();
    Image<ColorPixel> takeColorImage();
};
#endif // MOCK_HPP