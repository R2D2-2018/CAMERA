#include "pi_cam.hpp"

int main() {

    PiCam cam("../binaries/Images/", Vector2D(640, 360), 30);
    cam.setPath("../binaries/Videos/");

    return 0;
}
