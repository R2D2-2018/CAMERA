/**
 * @file
 * @brief     Header file for 2d vector class.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

class Vector2D {
  private:
    int x = 0;
    int y = 0;

  public:
    /**
     * @brief Return the x coordinate.
     * [BLANK]
     *
     * [BLANK]
     * @return X value of the vector.
     */
    int getX();
    /**
     * @brief Set the x value of the vector.
     * [BLANK]
     *
     * [BLANK]
     * @param[in] inputX    The desired x value.
     */
    void setX(int inputX);
    /**
     * @brief Return the y coordinate.
     * [BLANK]
     *
     * [BLANK]
     * @return y value of the vector.
     */
    int getY();
    /**
     * @brief Set the y value of the vector.
     * [BLANK]
     *
     * [BLANK]
     * @param[in] inputY  The desired y value.
     */
    void setY(int inputY);
};
#endif // VECTOR_2D_HPP