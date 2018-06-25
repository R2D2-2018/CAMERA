/**
 * @file
 * @brief     Implementation for virtual class Camera.
 * @author    Jari van Dam, Willem de Groot
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
    int fps;
    Vector2D resolution;

  public:
    Camera(int fps = 30, Vector2D resolution = Vector2D(640, 480)) : fps(fps), resolution(resolution) {
    }
    /**
     * @brief Set the desired resolution of the camera. Should be implemented
     * in the derived funcion.
     *
     * @param[in]     newResolution Desired resolution.
     */
    virtual void setResolution(Vector2D newResolution) {
        resolution = newResolution;
    }
    /**
     * @brief Get the resolution that is currently set.
     * Usually this function does not need implementation in derived function if the
     * stored integer is fine.
     *
     * @return  Vector2D    The current resolution
     */
    Vector2D getResolution() {
        return resolution;
    }
    /**
     * @brief Set the desired FPS(frames per second). Should be implemented in
     * the derived function.
     *
     * @param[in]     newFPS    The desired FPS (frames per second)
     */
    virtual void setFPS(int newFPS) {
        fps = newFPS;
    }
    /**
     * @brief Get the FPS(frames per second that is currently set.
     *
     * @return  int  The current FPS.
     */
    int getFPS() {
        return fps;
    }
};

#endif // CAMERA_HPP