#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../src/vector_2d.cpp"
#include "../src/mock.cpp"
#include "../src/camera.cpp"
#include "../src/greyscale_pixel.cpp"
#include "../src/vector_2d.cpp"
#include "../src/color_image.cpp"
#include "../src/color_pixel.cpp"
#include "../src/greyscale_image.cpp"
#include "../src/greyscale_pixel.cpp"

#include "catch.hpp"

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

TEST_CASE( "testing colorImage" ) {
    ColorImage kleurplaatje;
    ColorPixel redPixel;
    redPixel.setRed(127);
    Vector2D coordinate;
    coordinate.setX(120);
    coordinate.setY(125);
    kleurplaatje.setPixel(coordinate, redPixel);
    ColorPixel testPixel;
    testPixel.setRed(127);
    REQUIRE(kleurplaatje.getPixel(2,2) == testPixel);
    testPixel.setGreen(200);
    REQUIRE_FALSE(kleurplaatje.getPixel(coordinate) == testPixel);
}

TEST_CASE( "testing colorImage" ) {
    ColorImage image;
    GreyscalePixel pixel;
    pixel.set(95);
    Vector2D coordinate;
    coordinate.setX(120);
    coordinate.setY(125);
    kleurplaatje.setPixel(pixel);
    pixel testPixel;
    testPixel.set(95);
    REQUIRE(image.getPixel(2,2) == testPixel);
    testPixel.set(200);
    REQUIRE_FALSE(kleurplaatje.getPixel(coordinate) == testPixel);
}