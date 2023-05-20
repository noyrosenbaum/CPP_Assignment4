#pragma once

#include "iostream"
#include <string>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Character.hpp"
#include "TrainedNinja.hpp"
#include <vector>

using namespace std;
namespace ariel
{

}
class Team
{
private:
    Character *leader;
    vector<Cowboy *> cowboys;
    vector<Ninja *> ninjas;

    // Chooses a new leader for the Team
    void chooseNewLeader();

public:
    // Constructor, requires a pointer to the initial leader
    Team(Character *leader);

    // Destructor
    virtual ~Team();

    // Add a cowboy or a ninja to the Team
    void add(Character *character);

    // Returns the living character in the Team that is closest to the provided Point
    Character *closestLivingCharacter(const Point &position) const;

    // Attacks another Team
    virtual void attack(Team *other);

    // Returns the number of living members in the Team
    int stillAlive() const;

    // Prints the details of all members in the Team
    virtual void print() const;
};
