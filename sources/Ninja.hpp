#pragma once

#include "iostream"
#include "Character.hpp"

using namespace std;
namespace ariel
{

}
class Ninja : public Character
{
protected:
    int speed;

public:
    Ninja(string name, const Point &loc, int hits, int speed);
    void move(const Character *target);
    int getSpeed() const;
    void slash(Character *target);
    string print() const override;
};