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
    Ninja(const Point &loc, int hits, const string &name, int speed);
    void move(const Character &target);
    int getSpeed() const;
    void slash(Character &target);
    void print() const override;
};