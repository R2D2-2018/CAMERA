#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "camera.hpp"
#include "catch.hpp"
#include "color_pixel.hpp"
#include "greyscale_pixel.hpp"
#include "image.hpp"
#include "mock.hpp"
#include "vector_2d.hpp"
#include "ycbcr.hpp"

TEST_CASE("Vector2D construct with x and y") {
    Vector2D vector(99, 21);

    REQUIRE(vector.getX() == 99);
    REQUIRE(vector.getY() == 21);
}
TEST_CASE("Vector2D operator == equal vectors") {
    Vector2D vector1;
    Vector2D vector2;
    vector1.setX(5);
    vector1.setY(8);

    vector2.setX(5);
    vector2.setY(8);

    REQUIRE(vector1 == vector2);
}

TEST_CASE("Vector2D operator == unequal vectors on x coordinate") {
    Vector2D vector1;
    Vector2D vector2;
    vector1.setX(5);
    vector1.setY(8);

    vector2.setX(1234);
    vector2.setY(8);

    REQUIRE_FALSE(vector1 == vector2);
}

TEST_CASE("Vector2D operator == unequal vectors on y coordinate") {
    Vector2D vector1;
    Vector2D vector2;
    vector1.setX(5);
    vector1.setY(8);

    vector2.setX(5);
    vector2.setY(9);

    REQUIRE_FALSE(vector1 == vector2);
}

TEST_CASE("Vector2D set normal values") {
    Vector2D vector;
    vector.setX(5);
    vector.setY(8);

    REQUIRE(vector.getX() == 5);
    REQUIRE(vector.getY() == 8);
}

TEST_CASE("Vector2D set negative values") {
    Vector2D vector;
    vector.setX(-21);
    vector.setY(-4);

    REQUIRE(vector.getX() == -21);
    REQUIRE(vector.getY() == -4);
}

TEST_CASE("Vector2D set values two times in a row") {
    Vector2D vector;
    vector.setX(21);
    vector.setY(4);

    REQUIRE(vector.getX() == 21);
    REQUIRE(vector.getY() == 4);

    vector.setX(14);
    vector.setY(9);

    REQUIRE(vector.getX() == 14);
    REQUIRE(vector.getY() == 9);
}

TEST_CASE("Camera mock set normal values") {
    Mock camera;
    Vector2D resolution;
    resolution.setX(50);
    resolution.setY(100);
    camera.setResolution(resolution);
    camera.setFPS(30);

    REQUIRE(camera.getResolution() == resolution);
    REQUIRE(camera.getFPS() == 30);
}

TEST_CASE("Camera mock set negative values") {
    Mock camera;
    Vector2D resolution;
    resolution.setX(-50);
    resolution.setY(-100);
    camera.setResolution(resolution);
    camera.setFPS(-30);

    REQUIRE(camera.getResolution() == resolution);
    REQUIRE(camera.getFPS() == -30);
}

TEST_CASE("testing colorImage") {
    Image<ColorPixel> colorimage;
    ColorPixel redPixel;
    redPixel.setRed(127);
    Vector2D coordinate;
    coordinate.setX(10);
    coordinate.setY(10);
    colorimage.setPixel(coordinate, redPixel);
    ColorPixel testPixel;
    testPixel.setRed(127);
    REQUIRE(colorimage.getPixel(coordinate) == testPixel);
    testPixel.setGreen(200);
    REQUIRE_FALSE(colorimage.getPixel(coordinate) == testPixel);
}

TEST_CASE("testing GreyscaleImage") {
    Image<GreyscalePixel> image;
    GreyscalePixel pixel;
    pixel.setPixel(95);
    Vector2D coordinate;
    coordinate.setX(5);
    coordinate.setY(8);
    image.setPixel(coordinate, pixel);
    GreyscalePixel testPixel;
    testPixel.setPixel(95);
    REQUIRE(image.getPixel(coordinate) == testPixel);
    testPixel.setPixel(200);
    REQUIRE_FALSE(image.getPixel(coordinate) == testPixel);
}

TEST_CASE("YCbCr default constructor", "[YCbCr]") {
    YCbCr image;
    image.setY(10);
    image.setCb(12);
    image.setCr(18);

    REQUIRE(image.getY() == 10);
    REQUIRE(image.getCb() == 12);
    REQUIRE(image.getCr() == 18);
}

TEST_CASE("YCbCr constructor with values", "[YCbCr]") {
    YCbCr image(5, 21, 231);

    REQUIRE(image.getY() == 5);
    REQUIRE(image.getCb() == 21);
    REQUIRE(image.getCr() == 231);
}

TEST_CASE("Greypixel defautl constructor") {
    GreyscalePixel greyPixel;
    greyPixel.setPixel(12);

    REQUIRE(greyPixel.getPixel() == 12);
}
TEST_CASE("YCbCr to Greyscale conversion", "[YCbCr],[Greyscale]") {
    YCbCr ycbcrPixel(93, 123, 21);
    GreyscalePixel greyPixel;

    greyPixel = ycbcrPixel;

    REQUIRE(greyPixel.getPixel() == 93);
}