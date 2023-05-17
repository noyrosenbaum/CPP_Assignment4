#pragma once

#include "Team.hpp"

using namespace std;
namespace ariel
{
}

class Team2 : public Team
{

public:
    Team2(Character *captin);
    virtual void attack(Team &other);
};