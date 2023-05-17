#pragma once

#include "iostream"
#include <bits/stdc++.h>

using namespace std;
namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(double x, double y);
        double distance(const Point &other);
        string print();
        static Point moveTowards(const Point &source, const Point &dest, double distance);
        double getX() const;
        double getY() const;
    };
}
