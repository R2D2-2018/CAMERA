/**
 * @file
 * @brief     Implementations for 2d vector class.
 * @author    Jari van Dam
 * @license   See LICENSE
 */
#include "vector-2d.hpp"

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