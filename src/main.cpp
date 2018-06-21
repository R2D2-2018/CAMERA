#include "pi_cam.hpp"

int main() {

    std::cout << "Hello world!" << std::endl;
    PiCam cam("/home/pi/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Images/", Vector2D(640, 360), 30);
    cam.setPath("/home/pi/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Videos/");

    return 0;
}