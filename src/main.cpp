#include "pi_cam.hpp"

namespace Camera {
int main() {

    // EXAMPLE 1: Encode image
    // std::string filePath("/home/pi/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Images/1.jpg");
    // Base64Encoder encoder(filePath);
    // std::cout << encoder.encode();

    // EXAMPLE 2: get encoded video frame
    // PiCam cam("/home/pi/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Stream/", Vector2D(640, 360) );
    // std::cout << cam.takeEncodedVideoFrame();

    // EXAMPLE 3: Take image
    // PiCam cam("/home/pi/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Images/", Vector2D(640, 360) );
    // cam.takeImage("Hoi", "jpg");

    // EXAMPLE 4: Take video mp4
    // PiCam cam("/home/pi/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Images/", Vector2D(640, 360), 30 );
    // cam.takeVideo("Doei", 5000);

    // EXAMPLE 5: Start video feed
    PiCam cam("/home/pi/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Images/", Vector2D(640, 360), 30);
    cam.setPath("/home/pi/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Stream");
    std::function<bool(std::string &)> task = [](std::string &result) -> bool {
        std::cout << result;
        return true;
    };
    cam.startVideoFeed(task);

    return 0;
}
}
