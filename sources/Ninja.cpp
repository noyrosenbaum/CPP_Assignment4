#include "Ninja.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point location, int speed, int hits) : Character(location, name, hits), speed(speed){};
void Ninja::move(Character *enemy) {}
void Ninja::slash(Character *enemy) {}
int Ninja::getSpeed() const
{
    return speed;
}
string Ninja::print()
{
    return "";
}
