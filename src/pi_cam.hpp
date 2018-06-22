/**
 * @file
 * @brief     Header for Pi camera
 * @author    Willem de Groot, Arsalan Anwari
 * @license   See LICENSE
 */
#ifndef PICAM_HPP
#define PICAM_HPP

#include "camera.hpp"
#include "vector_2d.hpp"
#include <stdlib.h>
#include <vector>
#include <array>

class PiCam : public Camera {
  private:
    /**
     * @brief The folder where produced files will be saved.
     */
    std::string filePath;
    /**
     * @brief A buffer to store a frame in.
     * 
     * Not fully implemented yet, maybe it won't work like this, 
     * but this should contain a single frame 
     * that needs to be converted to base64 and sent to the recipient.
     */
    std::vector<char> buffer;

    /**
     * @brief Format a supplied path
     * 
     * If a slash is forgotten at the beginning or end of the supplied folder location, it is added here.
     */ 
    void correctPath();
    /**
     * @brief Empties supplied stringstream
     * 
     * Empties a stringstream, so it can be used again.
     * 
     * @param[in] parser  The stringstream that needs to be cleared.
     */
    void clearCommandBuffer(std::stringstream &parser);
    /**
     * @brief Gets fps and resolution arguments for raspvid
     * 
     * Outputs a string that contains the properly formatted fps and resolution arguments for raspvid.
     * 
     * @return string with commandline arguments
     */
    std::string getSettings();

  public:
    /**
     * @brief PiCam constructor
     * 
     * Constructor for Picam, if FPS is not supplied it is set to a default of 30.
     * 
     * @param[in] filepath  The location where the object will store the files it produces.
     * @param[in] resolution  The resolution to record images with.
     * @param[in] fps The framerate to record video with. Default is 30.
     */
    PiCam(const char *filePath, const Vector2D resolution, int fps = 30);
    /**
     * @brief Display current settings for the camera
     * 
     * This function prints the set resolution, fps and file location directly to std::cout
     */
    void printSettings();
    /**
     * @brief Change save path
     * 
     * This changes the path to the folder where files will be saved to the supplied new path
     * 
     * @param[in]  newPath The new save folder path
     */
    void setPath(const char *newPath);
    /**
     * @brief Take a picture
     * 
     * Take a picture and store it in the set folder under the supplied name with the supplied filetype
     * 
     * @param[in]  name  The name of the picture
     * @param[in]  fileType  Picture format (jpg or png)
     */
    void takeImage(const char *name, const char *fileType);
    /**
     * @brief Take a video
     * 
     * Take a video of supplied duration in set folder under supplied name.
     * 
     * @param[in] name  file name
     * @param[in] durationMs  for how long the camera needs to record
     */
    void takeVideo(const char *name, const unsigned int &durationMs);
    /**
     * @brief Creates a stream of video data
     * 
     * This function starts a video stream of undefined length (and converts it to base64).
     * !This is not yet tested and not complete!
     * 
     */
    void videoFeed();
};

#endif // PICAM_HPP
