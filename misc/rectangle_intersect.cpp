// Implementing popular problem of determining if two rectangles intersect.
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../include/catch.hpp"
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

class Rectangle {
    private:
        Point p1_, p2_;

    public:
        Rectangle(Point p1, Point p2) : p1_(p1), p2_(p2) {}

        bool intersects(Rectangle &o) {
            bool disjoint = p1_.x > o.p2_.x || p2_.x < o.p1_.x ||
                            p2_.y > o.p1_.y || p1_.y < o.p2_.y;
            return !disjoint;
        }
};

// Unit Tests
SCENARIO("Intersecting Rectangles") {
    GIVEN("Two squares sharing two sides") {
        Rectangle rect1(Point(1,2), Point(2,1));
        Rectangle rect2(Point(1,3), Point(3,1));
        REQUIRE(rect1.intersects(rect2) == true);
        REQUIRE(rect2.intersects(rect1) == true);
    }
    GIVEN("Two rectangles sharing 1 side") {
        Rectangle rect1(Point(0,1), Point(1,0));
        Rectangle rect2(Point(1,4), Point(3,0));
        REQUIRE(rect1.intersects(rect2) == true);
        REQUIRE(rect2.intersects(rect1) == true);
    }    
    GIVEN("Two rectangles with 2 sides overlapping") {
        Rectangle rect1(Point(0,3), Point(3,0));
        Rectangle rect2(Point(2,8), Point(5,2));
        REQUIRE(rect1.intersects(rect2) == true);
        REQUIRE(rect2.intersects(rect1) == true);
    }
}

SCENARIO("Disjoint Rectangles") {
    GIVEN("Two non-overlapping squares") {
        Rectangle rect1(Point(0,2), Point(2,0));
        Rectangle rect2(Point(3,2), Point(5,0));
        REQUIRE(rect1.intersects(rect2) == false);
        REQUIRE(rect2.intersects(rect1) == false);
    }
    GIVEN("Two non-overlapping rectangles with different dimensions") {
        Rectangle rect1(Point(0,1), Point(2,0));
        Rectangle rect2(Point(-4,-2), Point(-3,-7));
        REQUIRE(rect1.intersects(rect2) == false);
        REQUIRE(rect2.intersects(rect1) == false);
    }
}
