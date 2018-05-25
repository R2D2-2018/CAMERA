#include "wrap-hwlib.hpp"

#include "camera.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
#include "mock.hpp"
#include "vector_2d.hpp"
#include "ycbcr.hpp"
extern "C" void __cxa_pure_virtual() {

    hwlib::cout << "Virtual function error" << hwlib::endl;
    while (1)
        ;
}
int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    Vector2D resolution;
    resolution.setX(100);
    resolution.setY(150);
    Mock camera;
    camera.setFPS(5);
    camera.setResolution(resolution);

    camera.setFPS(421);

    auto image = camera.takeGreyImage();

    Vector2D position(5, 10);

    hwlib::cout << image.getPixel(position).getPixel() << hwlib::endl;

    Image<YCbCr> plaatje;
    hwlib::cout << plaatje.getPixel(position).getY() << hwlib::endl;

    GreyscalePixel zwartplaatjel;
    YCbCr kleurplaatje = plaatje.getPixel(position);
    zwartplaatjel = kleurplaatje;
    return 0;
}