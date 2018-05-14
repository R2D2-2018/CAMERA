/**
 * @file
 * @brief     Header file for camera mock.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#ifndef MOCK_HPP
#define MOCK_HPP
#include "Image.hpp"
#include "camera.hpp"
#include "vector-2d.hpp"

class Mock : public Camera {
  public:
    Image takeImage();
    /**
     * @brief Set the desired resolution as a vecotr2D.
     * [BLANK]
     *
     * [BLANK]
     * @param[in]     inputResolution  The desired resolution as a Vector@d.
     */
    void setResolution(Vector2D inputResolution);
    /**
     * @brief Set the desired FPS.
     * [BLANK]
     *
     * [BLANK]
     * @param[in]     inputFPS    The desired FPS.
     */
    void setFPS(int inputFPS);
};
#endif // MOCK_HPP