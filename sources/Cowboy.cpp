#include "Cowboy.hpp"
#include "iostream"
#include <sstream>

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, const Point &loc)
    : Character(name, loc, 110), bullets(6) {}

void Cowboy::shoot(Character *target)
{
    if (isAlive() && bullets > 0)
    {
        target->hit(10);
        bullets--;
    }
}

bool Cowboy::hasboolets() const
{
    return bullets > 0;
}

void Cowboy::reload()
{
    if (!isAlive())
        throw runtime_error("Cowboy is dead");
    bullets = 6;
}

string Cowboy::print() const
{
    std::stringstream ss;
    ss << 'C';
    if (!isAlive())
        ss << "(" << name << ")";
    else
        ss << name << " hit points: " << hits << " Location: (" << location.getX() << ", " << location.getY() << ")";
    return ss.str();
}