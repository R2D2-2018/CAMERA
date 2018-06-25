#ifndef PICAM_HPP
#define PICAM_HPP

#include <stdlib.h>
#include "camera.hpp"
#include "vector_2d.hpp"
#include "base64_encoder.hpp"

// namespace PiCam {

/**const struct types{
        const char* jpg = ".jpg";
        const char* png = ".png";
        const char* mp4 = ".mp4";
        const char* h264 = ".h264";
} fileTypes;*/

class PiCam : public Camera {
  private:
    std::string folderPath;
    Base64Encoder encoder;

    void correctPath();
    void clearCommandBuffer(std::stringstream &parser);
    std::string getSettings();

  public:
    PiCam(const char *folderPath, const Vector2D resolution, int fps = 30);

    void printSettings();

    void setPath(const char *newPath);

    void takeImage(const char *name, const char *fileType);
    void takeVideo(const char *name, const unsigned int &durationMs);
    std::string takeFromStream(const char *name); 
};
// } // namespace PICAM

#endif // PICAM_HPP
