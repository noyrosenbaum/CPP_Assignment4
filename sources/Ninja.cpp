#include "Ninja.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, const Point &loc, int hits, int speed)
    : Character(name, loc, hits), speed(speed) {}

void Ninja::move(const Character *target)
{
    if (isAlive())
    {
        Point newPos = location.moveTowards(location, target->getLocation(), speed);
        location = newPos;
    }
}

void Ninja::slash(Character *target)
{
    if (isAlive() && distance(target) <= 1)
    {
        target->hit(40);
    }
}
int Ninja::getSpeed() const
{
    return speed;
}

string Ninja::print() const
{
    stringstream ss;
    ss << 'N';
    if (!isAlive())
        ss << "(" << name << ")";
    else
        ss << name << " hit points: " << hits << " Location: (" << location.getX() << ", " << location.getY() << ")";
    return ss.str();
}
