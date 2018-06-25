#include "base64_encoder.hpp"

int main() {

    std::string filePath("/home/arsalan/Documents/Build-Env/Build-environment/modules/CAMERA/binaries/Stream/test.jpg");
    Base64Encoder encoder(filePath);
    std::cout << encoder.encode();

    return 0;
}
