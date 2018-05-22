/**
 * @file
 * @brief     Implementation for virtual class Camera.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "color_pixel.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
#include "vector_2d.hpp"
class Camera {
  protected:
    int fps = 0;
    Vector2D resolution;

  public:
    Camera(){};
    virtual Image<GreyscalePixel> takeGreyImage() = 0;
    virtual Image<ColorPixel> takeColorImage() = 0;
    /**
     * @brief Set the desired resolution of the camera. Should be implemented
     * in the derived funcion.
     * [BLANK]
     *
     * [BLANK]
     * @param[in]     resolution Desired resolution.
     */
    virtual void setResolution(Vector2D resolution) = 0;
    /**
     * @brief Get the resolution that is currently set.
     * Usualy this function does not need implementation in derived function if the
     * stored integer is fine.
     * [BLANK]
     *
     * [BLANK]
     * @return The current resolution as a vector2d.
     */
    virtual Vector2D getResolution();
    /**
     * @brief Set the desired FPS(frames per second). Should be implemented in
     * the derived function.
     * [BLANK]
     *
     * [BLANK]
     * @param[in]     fps    The desired FPS (frames per second)
     */
    virtual void setFPS(int fps) = 0;
    /**
     * @brief Get the FPS(frames per second that is currently set.
     * [BLANK]
     *
     * [BLANK]
     * @return The current FPS).
     */
    virtual int getFPS();
};

#endif // CAMERA_HPP