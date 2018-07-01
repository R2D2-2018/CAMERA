/**
 * @file
 * @brief     Implementations for 2d vector class.
 * @author    Jari van Dam, Willem de Groot, Arsalan Anwari
 * @license   See LICENSE
 */
#include "vector_2d.hpp"
Vector2D::Vector2D(const int x, const int y) : x(x), y(y) {
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

std::string Vector2D::print() {
    std::stringstream result;
    result << '(' << getX() << ',' << getY() << ')';
    return result.str();
}

bool Vector2D::operator==(const Vector2D &rhs) const {
    return (getX() == rhs.getX()) && (getY() == rhs.getY());
}