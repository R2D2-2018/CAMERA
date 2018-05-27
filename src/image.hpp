/**
 * @file
 * @brief     Template class for an image.
 * @author    Ruben Rajan & Jari van Dam
 * @license   See LICENSE
 */
#ifndef IMAGE_HPP
#define IMAGE_HPP
#include "vector_2d.hpp"
#include "wrap-hwlib.hpp"
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
    friend hwlib::cout_using_uart_putc &operator<<(hwlib::cout_using_uart_putc &lhs, Image<T> &rhs) {
        for (int i = 0; i < rhs.getHeight(); i++) {
            lhs << "\n";
            for (int j = 0; j < rhs.getWidth(); j++) {
                Vector2D position(i, j);
                lhs << rhs.getPixel(position) << " ";
            }
        }
        return lhs;
    }
};

#endif // IMAGE_HPP