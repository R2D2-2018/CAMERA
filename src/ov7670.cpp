#include "ov7670.hpp"
#include "image.hpp"
#include "vector_2d.hpp"
OV7670::OV7670() {
    // constructor
    enableClock();
}

void OV7670::enableClock() {
    // Clock Set-up on pin: DAC1 wiht frequency of 10.5MHz
    REG_PMC_PCER1 |= PMC_PCER1_PID36; // Enable PWM
    REG_PIOB_ABSR |= PIO_ABSR_P16;    // Set PWM pin perhipheral type A or B, in this case B
    REG_PIOB_PDR |= PIO_PDR_P16;      // Set PWM pin to an output
    REG_PWM_CLK = 0;                  // choose clock rate, 0 -> full MCLK as reference 84MHz
    REG_PWM_CMR6 = 0 << 9;            // select clock and polarity for PWM channel (pin7) -> (CPOL = 0)
    REG_PWM_CPRD6 = 8;                // initialize PWM period -> T = value/84MHz (value: up to 16bit), value=8 -> 10.5MHz
    REG_PWM_CDTY6 = 4;                // initialize duty cycle, REG_PWM_CPRD6 / value = duty cycle, for 8/4 = 50%
    REG_PWM_ENA = PWM_ENA_CHID0;      // Enable the PWM channel
    hwlib::cout << "Clock enabled " << hwlib::endl;
}

Image<GreyscalePixel> OV7670::takeGreyImage() {
    hwlib::cout << "Take image" << hwlib::endl;
    Image<GreyscalePixel> image;
    return image;
}
Image<ColorPixel> OV7670::takeColorImage() {
    hwlib::cout << "Coloroimage not implemented" << hwlib::endl;
    Image<ColorPixel> image;
    return image;
}

void OV7670::setResolution(Vector2D resolution) {
    hwlib::cout << "Set resolution not implemented" << hwlib::endl;
}

void OV7670::setFPS(int fps) {
    hwlib::cout << "Set fps not implemented" << hwlib::endl;
}