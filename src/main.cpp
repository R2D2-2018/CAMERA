#include "wrap-hwlib.hpp"

#include "camera.hpp"
#include "mock.hpp"
#include "vector_2d.hpp"
int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Hello world!" << hwlib::endl;
    Vector2D resolution;
    resolution.setX(100);
    resolution.setY(150);
    Mock camera;
    camera.setFPS(5);
    camera.setResolution(resolution);

    hwlib::cout << "resolution Y: " << camera.getResolution().getY() << " X: " << camera.getResolution().getX() << hwlib::endl;
    hwlib::cout << "fps: " << camera.getFPS() << hwlib::endl;

    camera.setFPS(421);
    hwlib::cout << "fps: " << camera.getFPS() << hwlib::endl;

    return 0;
}