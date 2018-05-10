#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "vector-2d.hpp"

class Camera {
  protected:
    int fps = 0;
    Vector2D resolution;

  public:
    Camera(){};
    virtual void setResolution(Vector2D resolution) = 0;
    virtual Vector2D getResolution();
    virtual void setFPS(int fps) = 0;
    virtual int getFPS();
};

#endif // CAMERA_HPP