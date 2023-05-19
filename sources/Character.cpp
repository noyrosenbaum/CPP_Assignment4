#include "Character.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Character::Character(const Point &loc, int hits, const string &name)
    : location(loc), hits(hits), name(name) {}

bool Character::isAlive() const
{
    return hits > 0;
}
int Character::getHitPoints() const
{
    return hits;
}
double Character::distance(const Character &other) const
{
    return location.distance(other.location);
}

void Character::hit(int damage)
{
    hits -= damage;
    if (hits < 0)
        hits = 0;
}

string Character::getName() const
{
    return name;
}

Point Character::getLocation() const
{
    return location;
}
