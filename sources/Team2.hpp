#pragma once

#include "Team.hpp"
#include "Character.hpp"
#include <vector>

using namespace std;
namespace ariel
{

}

class Team2 : public Team
{
private:
    Character *leader;
    vector<Character *> members;

    // Returns the living character in the group that is closest to the provided Point
    Character *closestLivingCharacter(const Point &position) const;

    // Chooses a new leader for the group
    void chooseNewLeader();

public:
    // Constructor, requires a pointer to the initial leader
    Team2(Character *leader);

    // Destructor
    ~Team2();

    // Add a character to the group
    void add(Character *character);

    // Attacks another group
    void attack(Team *other) override;

    // Returns the number of living members in the group
    int stillAlive() const;

    // Prints the details of all members in the group
    void print() const override;
};
