#ifndef YCBCR_HPP
#define YCBCR_HPP

#include "image.hpp"
class YCbCr {
  private:
    int y;
    int cb;
    int cr;

  public:
    YCbCr();
    YCbCr(int y, int cb, int cr);
    void setY(int y);
    int getY() const;
    void setCb(int cb);
    int getCb() const;
    void setCr(int cr);
    int getCr() const;
};
#endif // YCBCR_HPP