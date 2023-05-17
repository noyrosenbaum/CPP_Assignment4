#pragma once

#include "iostream"

using namespace std;
namespace ariel
{
}

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);
    double distance();
    void print();
    Point moveTowards();
    double getX();
    double getY();
};