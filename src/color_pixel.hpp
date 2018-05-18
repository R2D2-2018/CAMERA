/**
 * @file
 * @brief     hpp of abstract data class pixel
 * @author    Ruben Rajan
 * @license   See LICENSE
 */
#ifndef COLOR_PIXEL_HPP
#define COLOR_PIXEL_HPP
class ColorPixel
{

private:
	int red = 0,
		green = 0,
		blue = 0;
public:
	ColorPixel();
	/**
	 * @brief set the red intesity of the pixel
	 * [BLANK]
	 * @param[in]     valueOfPixel    new value of pixel
	 */
	void setRed(int valueOfPixel);
	/**
	 * @brief return red intesity of the pixel
	 * [BLANK]
	 * @return red intesity of the pixel
	 */
	int getRed();
	/**
	 * @brief set the blue intesity of the pixel
	 * [BLANK]
	 * @param[in]     valueOfPixel    new value of pixel
	 */
	void setBlue(int valueOfPixel);
	/**
	 * @brief return blue intesity of the pixel
	 * [BLANK]
	 * @return blue intesity of the pixel
	 */
	int getBlue( );
	/**
	 * @brief set the green intesity of the pixel
	 * [BLANK]
	 * @param[in]     valueOfPixel    new value of pixel
	 */
	void setGreen(int valueOfPixel);
	/**
	 * @brief return green intesity of the pixel
	 * [BLANK]
	 * @return green intesity of the pixel
	 */
	int getGreen();
};

#endif // COLOR_PIXEL_HPP