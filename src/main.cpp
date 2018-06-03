#include "wrap-hwlib.hpp"
extern "C" void __cxa_pure_virtual() {

    hwlib::cout << "Virtual function error" << hwlib::endl;
    while (1);
}
int main() {
    int main() {
        while(1){
            WDT->WDT_MR = WDT_MR_WDDIS;
            hwlib::wait_ms(50);
            auto HREF = hwlib::target::pin_out(hwlib::target::pins::d10);
            auto PCLK = hwlib::target::pin_out(hwlib::target::pins::d11);
            auto pin0 = hwlib::target::pin_out(hwlib::target::pins::d1);
            auto pin1 = hwlib::target::pin_out(hwlib::target::pins::d2);
            auto pin2 = hwlib::target::pin_out(hwlib::target::pins::d3);
            auto pin3 = hwlib::target::pin_out(hwlib::target::pins::d4);
            auto pin4 = hwlib::target::pin_out(hwlib::target::pins::d5);
            auto pin5 = hwlib::target::pin_out(hwlib::target::pins::d6);
            auto pin6 = hwlib::target::pin_out(hwlib::target::pins::d7);
            auto pin7 = hwlib::target::pin_out(hwlib::target::pins::d8);
            hwlib::pin_out * pins[] = {&pin0, &pin1, &pin2, &pin3, &pin4, &pin5, &pin6, &pin7};

            HREF.set(0);
            PCLK.set(0);
            HREF.set(1);
            PCLK.set(1);
            for( auto & p : pins ) {
                p->set(0);
            }
            PCLK.set(0);
            PCLK.set(1);
            for( auto & p : pins ) {
                p->set(0);
            }
            PCLK.set(0);
            HREF.set(0);

            }
    }
    return 0;
}
