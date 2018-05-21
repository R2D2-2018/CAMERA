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
     * @brief Default constructor for Vector2D.
     * [BLANK]
     *  Initializes with x and y set to 0.
     * [BLANK]
     */
    Vector2D();
    /**
     * @brief Vector2d constructor with x and y value.
     * [BLANK]
     *
     * [BLANK]
     * @param[in]     x    X value
     * @param[in]     y    Y value
     */
    Vector2D(const int x, const int y);
    /**
     * @brief Return the x coordinate.
     * [BLANK]
     *
     * [BLANK]
     * @return X value of the vector.
     */
    int getX() const;
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
    int getY() const;
    /**
     * @brief Set the y value of the vector.
     * [BLANK]
     *
     * [BLANK]
     * @param[in] inputY  The desired y value.
     */
    void setY(int inputY);
};

bool operator==(const Vector2D &lhs, const Vector2D &rhs);
#endif // VECTOR_2D_HPP