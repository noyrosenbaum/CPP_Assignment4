#pragma once

#include "iostream"
#include "Character.hpp"

using namespace std;
namespace ariel
{

}
class Cowboy : public Character
{
private:
    int bullets;

public:
    Cowboy(string name, const Point &loc);
    void shoot(Character *target);
    bool hasboolets() const;
    void reload();
    string print() const override;
};