#include <iostream>
#include <cmath>
#include "Point.hpp"
using namespace std;
namespace ariel
{
}

// Constructor
Point::Point(double x, double y) : x(x), y(y) {}

// Calculates the distance between two points
double Point::distance(const Point &other) const
{
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

// Prints the Point
void Point::print() const
{
    cout << "(" << x << ", " << y << ")" << endl;
}

// Returns the closest point to the destination point,
// which is at most the given distance from the source point
Point Point::moveTowards(const Point &source, const Point &destination, double maxDistance)
{
    if (maxDistance < 0)
    {
        throw std::invalid_argument("Distance cannot be negative");
    }

    double dist = source.distance(destination);
    if (dist <= maxDistance)
    {
        return destination;
    }
    else
    {
        double ratio = maxDistance / dist;
        double newX = source.x + (destination.x - source.x) * ratio;
        double newY = source.y + (destination.y - source.y) * ratio;
        return Point(newX, newY);
    }
}
double Point::getX() const
{
    return this->x;
}
double Point::getY() const
{
    return this->y;
}
