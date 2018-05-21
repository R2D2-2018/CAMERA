/**
 * @file
 * @brief     Implementations for 2d vector class.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#include "vector_2d.hpp"
Vector2D::Vector2D(const int inputX, const int inputY) {
    x = inputX;
    y = inputY;
}
Vector2D::Vector2D() {
    x = 0;
    y = 0;
}
int Vector2D::getX() const {
    return x;
}

void Vector2D::setX(int inputX) {
    x = inputX;
}

int Vector2D::getY() const {
    return y;
}

void Vector2D::setY(int inputY) {
    y = inputY;
}

bool operator==(const Vector2D &lhs, const Vector2D &rhs) {
    if (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY()) {
        return true;
    } else {
        return false;
    }
}