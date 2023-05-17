#pragma once

#include "iostream"
#include <string>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>

using namespace std;
namespace ariel
{
}

class Team
{
private:
    vector<Character *> members;
    Character *captin;

public:
    Team(Character *captin);
    virtual void add(Character *character);
    virtual void attack(Team *enemy);
    virtual int stillAlive();
    virtual void print();
};