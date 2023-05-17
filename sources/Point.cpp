#include "iostream"
#include <string>
#include "Point.hpp"

using namespace std;
namespace ariel
{
    Point::Point(double x, double y) : x(x), y(y){}
    double Point::getX() const
    {
        return this->x;
    }
    double Point::getY() const
    {
        return this->y;
    }
    double Point::distance(const Point &other)
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) * 1.0);
    }
    string Point::print()
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
    Point Point::moveTowards(const Point &source, const Point &dest, double distance)
    {
        return Point(0, 0);
    }
}
