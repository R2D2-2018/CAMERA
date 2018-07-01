/**
 * @file
 * @brief     Header file for 2d vector class.
 * @author    Jari van Dam, Willem de Groot, Arsalan Anwari
 * @license   See LICENSE
 */
#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

#include <iostream>
#include <sstream>
#include <string>

class Vector2D {
  private:
    int x;
    int y;

  public:
    /**
     * @brief Vector2D constructor with x and y value.
     *
     * @param[in]     x    X value
     * @param[in]     y    Y value
     */
    Vector2D(const int x = 0, const int y = 0);
    /**
     * @brief Return the x coordinate.
     *
     * @return X value of the vector.
     */
    int getX() const;
    /**
     * @brief Set the x value of the vector.
     *
     * @param[in] inputX    The desired x value.
     */
    void setX(int inputX);
    /**
     * @brief Return the y coordinate.
     *
     * @return y value of the vector.
     */
    int getY() const;
    /**
     * @brief Set the y value of the vector.
     *
     * @param[in] inputY  The desired y value.
     */
    void setY(int inputY);
    /**
     * @brief returns a string representation of the current values.
     *
     * @return    std::string representation of the current values.
     */
    std::string print();
    /**
     * @brief comparison operator implementation for the Vector2D class.
     *
     * @return    bool    whether or not the values of both vectors are the same.
     */
    bool operator==(const Vector2D &rhs) const;
};

#endif // VECTOR_2D_HPP