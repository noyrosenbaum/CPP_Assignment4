#pragma once

#include "iostream"
#include <string>
#include "Point.hpp"

using namespace std;
namespace ariel
{
}
class Character
{
protected:
    Point location;
    int hits;
    string name;

public:
    Character(const Point &loc, int hits, const string &name);
    bool isAlive() const;
    double distance(const Character &other) const;
    void hit(int damage);
    string getName() const;
    Point getLocation() const;
    int getHitPoints() const;
    virtual void print() const = 0; 
};
