#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../src/vector-2d.cpp"
#include "../src/vector-2d.hpp"

#include "../src/mock.cpp"
#include "../src/mock.hpp"

#include "../src/camera.cpp"
#include "../src/camera.hpp"

#include "catch.hpp"

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