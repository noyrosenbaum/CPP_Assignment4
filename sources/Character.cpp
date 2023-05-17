#include "Character.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Character::Character(Point location, string name, int hits) : location(location), name(name), hits(hits) {}

bool Character::isAlive()
{
    return hits > 0;
}
double Character::distance(Character &other)
{
    return 1;
}
void Character::hit(int hits) {}
string Character::getName() const
{
    return name;
}
Point Character::getLocation() const
{
    return location;
}
int Character::getHits() const
{
    return hits;
}
string Character::print()
{
    return "";
}
