//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/vector_2d.cpp"
#include "../src/color_image.cpp"
#include "../src/color_pixel.cpp"
#include "../src/greyscale_image.cpp"
#include "../src/greyscale_pixel.cpp"

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