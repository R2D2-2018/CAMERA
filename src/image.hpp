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
    /**
     * @brief Default constructor for the Image template
     *
     */
    Image() {
    }
    /**
     * @brief Set pixel value on a specific positon
     *
     * @param[in]     Vector2D postion  The positon of the pixel to be set.
     * @param[in]     Value of the pixel as a type T.
     * @return What will the function return
     */
    void setPixel(Vector2D position, T value) {
        pixels[position.getX()][position.getY()] = value;
    }
    /**
     * @brief Get pixel value on position.
     *
     * @param[in]     Vector2D position    The position of the pixel.
     * @return The value of the pixel as a type T.
     */
    T getPixel(Vector2D position) {
        return pixels[position.getX()][position.getY()];
    }
    /**
     * @brief Get the widt of the image.
     *
     * @return The width of the image.
     */
    int getWidth() {
        return sizeof pixels[0] / sizeof(T);
    }
    /**
     * @brief Get the height of the image.
     *
     * @return The height of the image.
     */
    int getHeight() {
        return sizeof pixels / sizeof pixels[0];
    }
    /**
     * @brief Print the image to the hwlib::cout.
     * Print each pixel in the image to the hwlib::cout using it's own implementation of the operator<<.
     * @param[in]     Hwlbi::cout_using_uart_putc lhs The ostream of hwlib.
     * @param[in]     Image<T> rhs   The image that will be printed.
     * @return hwlib::cout_using_uart_putc The ostream so that it can be chained.
     */
    template <class C>
    friend C &operator<<(C &lhs, Image<T> &rhs) {
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