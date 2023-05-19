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
    Cowboy(const Point &loc, const string &name);
    void shoot(Character &target);
    bool hasboolets() const;
    void reload();
    void print() const override;
};