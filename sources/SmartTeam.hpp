#pragma once

#include "Team.hpp"

using namespace std;
namespace ariel
{
}

class SmartTeam : public Team
{

public:
    SmartTeam(Character *captin);
    virtual void attack(Team &other);
};