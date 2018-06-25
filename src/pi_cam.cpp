#include "pi_cam.hpp"

// namespace PiCam {

PiCam::PiCam(const char *folderPath, const Vector2D resolution, int fps) : Camera(fps, resolution), folderPath(std::string(folderPath)) {
    correctPath();
}

void PiCam::correctPath() {
    if (folderPath.back() != '/') {
        folderPath += '/';
    }
    if (folderPath[0] != '/') {
        folderPath.insert(0, 1, '/');
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
              << "Store locaction: " << folderPath << "\n";
}

void PiCam::setPath(const char *newPath) {
    folderPath = std::string(newPath);
    correctPath();
}

void PiCam::takeImage(const char *name, const char *fileType) {
    std::stringstream command;
    command << "raspistill -o " << folderPath << name << "." << fileType;
    const char *result = command.str().c_str();
    system(result);
}

void PiCam::takeVideo(const char *name, const unsigned int &durationMs) {
    std::stringstream commandBuffer;

    ///< Use the raspivid command to capture video with the supplied arguments
    commandBuffer << "raspivid -o " << folderPath << name << ".h264" << getSettings() << " -t " << std::to_string(durationMs);
    const char *result1 = commandBuffer.str().c_str();
    clearCommandBuffer(commandBuffer);
    system(result1);

    ///< The framerate is not stored in the produced .h264 file, so we then convert it to mp4 with the correct framerate
    commandBuffer << "MP4Box -add " << folderPath << name << ".h264"
                  << " -fps " << std::to_string(fps) << " " << folderPath << name << ".mp4";
    const char *result2 = commandBuffer.str().c_str();
    clearCommandBuffer(commandBuffer);
    system(result2);

    commandBuffer << "rm -rf " << folderPath << name << ".h264";
    const char *result3 = commandBuffer.str().c_str();
    system(result3);
}

std::string PiCam::takeFromStream(const char *name){
	takeImage(name, "jpg");
	
	std::string filePath = folderPath + name + ".jpg";
	encoder.setFilePath(filePath);
	return encoder.encode();
	//return filePath;
} 

// }; // namespace PiCam
