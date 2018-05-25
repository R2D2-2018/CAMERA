#include "ycbcr.hpp"
YCbCr::YCbCr() {
    ;
}
YCbCr::YCbCr(int y, int cb, int cr) {
    y = y;
    cb = cb;
    cr = cr;
}

void YCbCr::setY(int y) {
    y = y;
}

int YCbCr::getY() const {
    return y;
}

void YCbCr::setCb(int cb) {
    cb = cb;
}

int YCbCr::getCb() const {
    return cb;
}

void YCbCr::setCr(int cr) {
    cr = cr;
}

int YCbCr::getCr() const {
    return cr;
}
