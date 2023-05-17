#include "Cowboy.hpp"
#include "iostream"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(location, name, 110), bulletAmount(6) {}
bool Cowboy::hasboolets()
{
    return bulletAmount > 0;
}
void Cowboy::shoot(Character *enemy) {}
void Cowboy::reload()
{
}
int Cowboy::getBulletAmount() const
{
    return bulletAmount;
}
string Cowboy::print()
{
    return "";
}
