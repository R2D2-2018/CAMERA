#ifndef YCBCR_HPP
#define YCBCR_HPP

#include "image.hpp"
class YCbCr {
  private:
    int y = 0;
    int cb = 0;
    int cr = 0;

  public:
    YCbCr();
    YCbCr(int in_y, int in_cb, int in_cr);
    void setY(int in_y);
    int getY() const;
    void setCb(int in_cb);
    int getCb() const;
    void setCr(int in_cr);
    int getCr() const;
};
#endif // YCBCR_HPP