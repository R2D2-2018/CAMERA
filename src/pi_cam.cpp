/**
 * @file
 * @brief     Implementation for Pi camera
 * @author    Willem de Groot, Arsalan Anwari
 * @license   See LICENSE
 */
#include "pi_cam.hpp"

Camera::PiCam::PiCam(const char *folderPath, const Vector2D resolution, int fps)
    : Camera(fps, resolution), folderPath(std::string(folderPath)), buffer(resolution.getX() * resolution.getY() * 3) {
    correctPath();
}

void Camera::PiCam::correctPath() {
    if (folderPath.back() != '/') {
        folderPath += '/';
    }
    if (folderPath[0] != '/') {
        folderPath.insert(0, 1, '/');
    }
}

void Camera::PiCam::clearCommandBuffer(std::stringstream &parser) {
    parser.str(std::string());
    parser.clear();
}

std::string Camera::PiCam::getSettings() {
    std::stringstream result;
    result << " -fps " << fps << " -w " << resolution.getX() << " -h " << resolution.getY();
    return result.str();
}

void Camera::PiCam::printSettings() {
    std::cout << "Resolution: " << getResolution().print() << "\n"
              << "FPS: " << getFPS() << "\n"
              << "Store locaction: " << folderPath << "\n";
}

std::string Camera::PiCam::getPath() {
    return folderPath;
}

void Camera::PiCam::setPath(const char *newPath) {
    folderPath = std::string(newPath);
    correctPath();
}

void Camera::PiCam::takeImage(const char *name, const char *fileType) {
    std::stringstream command;
    command << "raspistill -o " << folderPath << name << "." << fileType;
    const char *result = command.str().c_str();
    system(result);
}

void Camera::PiCam::takeVideo(const char *name, const unsigned int &durationMs) {
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

void Camera::PiCam::startVideoFeed(std::function<void(std::string&)> & processingTask) {
	///< Open pipe to catch all output from raspivid
	///< Execute command
	///< Read all incoming data, convert to base64
	///< Output converted data
    std::stringstream command;
    command << "raspivid -o -" << getSettings() << " -t 0";
    std::vector<unsigned char> localBuffer(resolution.getX()*resolution.getY()*3);

    FILE* pipe = popen(command.str().c_str(), "r");
    if (!pipe) {
        std::cerr << "Couldn't run command." << std::endl;
        return;
    }

    bool running = true;
    while( running ){
        fread(&localBuffer[0] ,sizeof localBuffer[0], resolution.getX()*resolution.getY()*3, pipe);
        std::string result = encoder.encode(localBuffer);
        running = processingTask(result);
        localBuffer.clear();
    }
    
    pclose(pipe); 
}


std::string Camera::PiCam::takeEncodedVideoFrame(){
    takeImage("1", "jpg");
	
	std::string filePath = folderPath + "1" + ".jpg";
	encoder.setFilePath(filePath);
	return encoder.encode();

}
