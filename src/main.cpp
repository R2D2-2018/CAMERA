#include "wrap-hwlib.hpp"

#include "camera.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
#include "mock.hpp"
#include "vector_2d.hpp"
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

    int cb[3];
    int cr[3];
    int y[3];
    int counter = 0;
    int const sensordataSize = 8;
                                   //[cb0 y0 cr0 y1 cb2 y2 cr2 y3 ]
    int sensorData[sensordataSize] = {23, 7, 9,  3,  5, 12, 23, 42};
    int saved_images = 0;
    int i = 1;
    int iy = 0;
    while(saved_images < 4){
            //std::cout << i;
            cb[counter] = sensorData[i-1];
            y[counter] = sensorData[i + iy];
            cr[counter] = sensorData[i+1];
            counter++;
            saved_images++; 
            if (iy == 2) {
                iy = 0;
                i += 4;
            } else{
                iy = 2;
            }
            }
    hwlib::cout << cb[0] << " " << cb[1] << " " << cb[3] << hwlib::endl;
    hwlib::cout << cr[0] << " " << cr[1] << " " << cr[3]<< hwlib::endl;
    hwlib::cout << y[0] << " " << y[1] << " " << y[3]<< hwlib::endl;
    return 0;
}