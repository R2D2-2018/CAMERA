#ifndef YCBCR_HPP
#define YCBCR_HPP

#include "image.hpp"
class YCbCr {
  private:
    int y = 0;
    int cb = 0;
    int cr = 0;

  public:
    /**
     * @brief Default constructor for YCbCr class.
     *
     */
    YCbCr();
    /**
     * @brief Simple constructor for YCbCr class.
     *
     * @param[in]     in_y    Y value.
     * @param[in]     in_cb   Cb value.
     * @param[in]     in_cr   Cr value.
     */
    YCbCr(int in_y, int in_cb, int in_cr);
    /**
     * @brief Set the Y value.
     *
     * @param[in]     int in_y The Y value.
     */
    void setY(int in_y);
    /**
     * @brief Get the Y value.
     *
     * @return The Y value.
     */
    int getY() const;
    /**
     * @brief Set the Cb value.
     *
     * @param[in]     int in_cb The Cb value.
     */
    void setCb(int in_cb);
    /**
     * @brief Get the Cb value.
     *
     * @return The Cb value.
     */
    int getCb() const;
    /**
     * @brief Set the Cr value.
     *
     * @param[in]     int in_cr The Cr value.
     */
    void setCr(int in_cr);
    /**
     * @brief Get the Cr value.
     *
     * @return The Cr value.
     */
    int getCr() const;
};
#endif // YCBCR_HPP