/**
 * @file
 * @brief     Template class for an image.
 * @author    Ruben Rajan & Jari van Dam
 * @license   See LICENSE
 */
#ifndef IMAGE_HPP
#define IMAGE_HPP
#include "vector_2d.hpp"
template <class T>
class Image {
  private:
    T pixels[10][10];

  public:
    Image() {
    }
    void setPixel(Vector2D position, T value) {
        pixels[position.getX()][position.getY()] = value;
    }
    T getPixel(Vector2D position) {
        return pixels[position.getX()][position.getY()];
    }
    int getWidth() {
        return sizeof pixels[0] / sizeof(T);
    }
    int getHeight() {
        return sizeof pixels / sizeof pixels[0];
    }
};

#endif // IMAGE_HPP