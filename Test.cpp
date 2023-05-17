#include "doctest.h"
#include "sources/Team.hpp"
using namespace ariel;

TEST_CASE("Initialize a Point object")
{
    SUBCASE("constructor")
    {
        CHECK_NOTHROW(Point(0, 2));
        CHECK_THROWS(Point(2, 'a'));
        CHECK_NOTHROW(Point(2, -2));
        CHECK_NOTHROW(Point(-2, -2));
    }
    SUBCASE("distance")
    {
        Point p1(1, 2);
        Point p2(3, 4);
        Point p3(0,0);
        CHECK_NOTHROW(p1.distance(p2));
        CHECK_NOTHROW(p1.distance(p3));
        CHECK_EQ(p1.distance(p2), 2.8284271247461903);
    }
    SUBCASE("print")
    {
        Point p1(1, 2);
        CHECK_NOTHROW(p1.print());
    }
    SUBCASE("moveTowards")
    {
        Point p1(1, 2);
        Point p2(3, 4);
        CHECK_NOTHROW(p1.moveTowards(p1, p2, 1));
    }
}
TEST_CASE("Initialize a Characters object")
{
    Cowboy yair("yair", Point(1, 1));
    OldNinja itai("itai", Point(0, 1));
    TrainedNinja noy("noy", Point(1, 0));
    YoungNinja shir("shir", Point(2, -7));
    SUBCASE("get name")
    {
        CHECK_EQ(yair.getName(), "yair");
        CHECK_EQ(itai.getName(), "itai");
        CHECK_EQ(noy.getName(), "noy");
        CHECK_EQ(shir.getName(), " shir");
    }
    SUBCASE("get location")
    {
        CHECK_NOTHROW(yair.getLocation());
        CHECK_NOTHROW(itai.getLocation());
        CHECK_NOTHROW(noy.getLocation());
        CHECK_NOTHROW(shir.getLocation());
    }
    SUBCASE("alive")
    {
        CHECK_EQ(yair.isAlive(), 1);
        CHECK_EQ(itai.isAlive(), 1);
        CHECK_EQ(noy.isAlive(), 1);
        CHECK_EQ(shir.isAlive(), 1);
    }
}


