#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "camera.hpp"
#include "catch.hpp"
#include "pi_cam.hpp"
#include "vector_2d.hpp"

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

TEST_CASE("Settings correctly stored", "[PiCam]") {
    PiCam piCam("/home/pi/Documents/", Vector2D(1280, 960), 60);

    REQUIRE(piCam.getPath() == std::string("/home/pi/Documents/"));
    REQUIRE(piCam.getFPS() == 60);
    REQUIRE(piCam.getResolution() == Vector2D(1280, 960));
}

TEST_CASE("Settings correctly changed", "[PiCam]") {
    PiCam piCam("/home/pi/Documents/", Vector2D(1280, 960), 60);

    piCam.setPath("/home/pi/Documents/new/");
    piCam.setFPS(50);
    piCam.setResolution(Vector2D(960, 720));

    REQUIRE(piCam.getPath() == std::string("/home/pi/Documents/new/"));
    REQUIRE(piCam.getFPS() == 50);
    REQUIRE(piCam.getResolution() == Vector2D(960, 720));
}

TEST_CASE("Default values work", "[PiCam]") {
    PiCam piCam("/home/pi/Documents/", Vector2D(1280, 960));

    REQUIRE(piCam.getFPS() == 30);
}

TEST_CASE("Path slashes are added", "[PiCam]") {
    PiCam piCam("home/pi/Documents", Vector2D(1280, 960));

    REQUIRE(piCam.getPath() == std::string("/home/pi/Documents/"));
}
