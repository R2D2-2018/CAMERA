#include "wrap-hwlib.hpp"

#include "camera.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
#include "mock.hpp"
#include "vector_2d.hpp"
#include "ycbcr.hpp"
int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    Mock camera;
    Vector2D position(5, 10);
    Image<GreyscalePixel> plaatje = camera.takeGreyImage();

    hwlib::cout << plaatje << hwlib::endl;
    return 0;
}