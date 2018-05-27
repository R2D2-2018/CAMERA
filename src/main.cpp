#include "wrap-hwlib.hpp"

#include "camera.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
#include "mock.hpp"
#include "ov7670.hpp"
#include "vector_2d.hpp"
extern "C" void __cxa_pure_virtual() {

    hwlib::cout << "Virtual function error" << hwlib::endl;
    while (1);
}
int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    auto pollHREF = hwlib::target::pin_in(hwlib::target::pins::d10);
    auto pollPCLK = hwlib::target::pin_in(hwlib::target::pins::d11);
    auto pin0 = hwlib::target::pin_in(hwlib::target::pins::d1);
    auto pin1 = hwlib::target::pin_in(hwlib::target::pins::d2);
    auto pin2 = hwlib::target::pin_in(hwlib::target::pins::d3);
    auto pin3 = hwlib::target::pin_in(hwlib::target::pins::d4);
    auto pin4 = hwlib::target::pin_in(hwlib::target::pins::d5);
    auto pin5 = hwlib::target::pin_in(hwlib::target::pins::d6);
    auto pin6 = hwlib::target::pin_in(hwlib::target::pins::d7);
    auto pin7 = hwlib::target::pin_in(hwlib::target::pins::d8);
    hwlib::pin_in * pins[] = {&pin0, &pin1, &pin2, &pin3, &pin4, &pin5, &pin6, &pin7};
    auto camera = OV7670(pollHREF, pollPCLK, pins);
    int rawData[3];
    camera.capture(rawData, 4);
    return 0;
}