#pragma once
namespace ariel
{
}
class Point
{
private:
    double x;
    double y;

public:
    // Constructor
    Point(double x = 0, double y = 0);

    // Calculates the distance between two points
    double distance(const Point &other) const;

    // Prints the Point
    void print() const;

    // Returns the closest point to the destination point,
    // which is at most the given distance from the source point
    Point moveTowards(const Point &source, const Point &destination, double maxDistance) const;
    double getX() const;
    double getY() const;
};
