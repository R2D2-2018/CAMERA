#include "ycbcr.hpp"
YCbCr::YCbCr() {
    ;
}
YCbCr::YCbCr(int in_y, int in_cb, int in_cr) {
    y = in_y;
    cb = in_cb;
    cr = in_cr;
}

void YCbCr::setY(int in_y) {
    y = in_y;
}

int YCbCr::getY() const {
    return y;
}

void YCbCr::setCb(int in_cb) {
    cb = in_cb;
}

int YCbCr::getCb() const {
    return cb;
}

void YCbCr::setCr(int in_cr) {
    cr = in_cr;
}

int YCbCr::getCr() const {
    return cr;
}
