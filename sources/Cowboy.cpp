#include "Cowboy.hpp"
#include "iostream"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(const Point &loc, const string &name)
    : Character(loc, 110, name), bullets(6) {}

void Cowboy::shoot(Character &target)
{
    if (isAlive() && bullets > 0)
    {
        target.hit(10);
        bullets--;
    }
}

bool Cowboy::hasboolets() const
{
    return bullets > 0;
}

void Cowboy::reload()
{
    bullets = 6;
}

void Cowboy::print() const
{
    std::cout << 'C';
    if (!isAlive())
        std::cout << "(" << name << ")";
    else
        std::cout << name << " hit points: " << hits << " Location: (" << location.getX() << ", " << location.getY() << ")";
    std::cout << std::endl;
}