#ifndef MOCK_HPP
#define MOCK_HPP
#include "camera.hpp"
#include "vector-2d.hpp"
class Mock : public Camera {
  public:
    void setResolution(Vector2D input_resolution);
    void setFPS(int input_fps);
};
#endif // MOCK_HPP