/**
 * @file
 * @brief     Implementation for Pi camera
 * @author    Willem de Groot, Arsalan Anwari
 * @license   See LICENSE
 */
#include "pi_cam.hpp"

PiCam::PiCam(const char *filePath, const Vector2D resolution, int fps) : Camera(fps, resolution), filePath(std::string(filePath)), buffer(resolution.getX()*resolution.getY()*3) {
    correctPath();
}

void PiCam::correctPath() {
    if (filePath.back() != '/') {
        filePath += '/';
    }
    if (filePath[0] != '/') {
        filePath.insert(0, 1, '/');
    }
}

void PiCam::clearCommandBuffer(std::stringstream &parser) {
    parser.str(std::string());
    parser.clear();
}

std::string PiCam::getSettings() {
    std::stringstream result;
    result << " -fps " << fps << " -w " << resolution.getX() << " -h " << resolution.getY();
    return result.str();
}

void PiCam::printSettings() {
    std::cout << "Resolution: " << resolution.print() << "\n"
              << "FPS: " << fps << "\n"
              << "Store locaction: " << filePath << "\n";
}

void PiCam::setPath(const char *newPath) {
    filePath = std::string(newPath);
    correctPath();
}

void PiCam::takeImage(const char *name, const char *fileType) {
    std::stringstream command;
    command << "raspistill -o " << filePath << name << "." << fileType;
    const char *result = command.str().c_str();
    system(result);
}

void PiCam::takeVideo(const char *name, const unsigned int &durationMs) {
    std::stringstream commandBuffer;

    ///< Use the raspivid command to capture video with the supplied arguments
    commandBuffer << "raspivid -o " << filePath << name << ".h264" << getSettings() << " -t " << std::to_string(durationMs);
    const char *result1 = commandBuffer.str().c_str();
    clearCommandBuffer(commandBuffer);
    system(result1);

    ///< The framerate is not stored in the produced .h264 file, so we then convert it to mp4 with the correct framerate
    commandBuffer << "MP4Box -add " << filePath << name << ".h264"
                  << " -fps " << std::to_string(fps) << " " << filePath << name << ".mp4";
    const char *result2 = commandBuffer.str().c_str();
    clearCommandBuffer(commandBuffer);
    system(result2);

    commandBuffer << "rm -rf " << filePath << name << ".h264";
    const char *result3 = commandBuffer.str().c_str();
    system(result3);
}

void PiCam::videoFeed() {
	///< Open pipe to catch all output from raspivid
	///< Execute command
	///< Read all incoming data, convert to base64
	///< Output converted data
    std::stringstream command;
    command << "raspivid -o -" << getSettings();
    std::array<char, 128> localbuffer;

    FILE* pipe = popen(command.str().c_str(), "r");
    if (!pipe) {
        std::cerr << "Couldn't run command." << std::endl;
        return;
    }
    while(fgets(localbuffer.data(), 128, pipe) != NULL) {
        buffer.push_back(*localbuffer.data());

    }
}