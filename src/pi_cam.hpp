/**
 * @file
 * @brief     Header for Pi camera
 * @author    Willem de Groot, Arsalan Anwari
 * @license   See LICENSE
 */
#ifndef PICAM_HPP
#define PICAM_HPP

#include "camera.hpp"
#include "vector_2d.hpp"
#include <stdlib.h>

class PiCam : public Camera {
  private:
    std::string filePath;

    void correctPath();
    void clearCommandBuffer(std::stringstream &parser);
    std::string getSettings();

  public:
    PiCam(const char *filePath, const Vector2D resolution, int fps = 30);

    void printSettings();

    void setPath(const char *newPath);

    void takeImage(const char *name, const char *fileType);
    void takeVideo(const char *name, const unsigned int &durationMs);
};

#endif // PICAM_HPP
