#include "Ninja.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Ninja::Ninja(const Point &loc, int hits, const string &name, int speed)
    : Character(loc, hits, name), speed(speed) {}

void Ninja::move(const Character &target)
{
    if (isAlive())
    {
        Point newPos = location.moveTowards(location, target.getLocation(), speed);
        location = newPos;
    }
}

void Ninja::slash(Character &target)
{
    if (isAlive() && distance(target) <= 1)
    {
        target.hit(40);
    }
}
int Ninja::getSpeed() const
{
    return speed;
}

void Ninja::print() const
{
    cout << 'N';
    if (!isAlive())
        cout << "(" << name << ")";
    else
        cout << name << " hit points: " << hits << " Location: (" << location.getX() << ", " << location.getY() << ")";
    cout << endl;
}
