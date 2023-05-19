#pragma once
#include "Character.hpp"
#include "Team.hpp"
#include <vector>

using namespace std;
namespace ariel
{
}
class SmartTeam
{
private:
    Character *leader;
    std::vector<Character *> members;

    // Returns the living character in the group that is closest to the provided Point
    Character *closestLivingCharacter(const Point &position) const;

    // Chooses a new leader for the group
    void chooseNewLeader();

    // Returns the best target in the other group
    Character *chooseVictim(const SmartTeam &other) const;

public:
    // Constructor, requires a pointer to the initial leader
    SmartTeam(Character *leader);

    // Destructor
    ~SmartTeam();

    // Add a character to the group
    void add(Character *character);

    // Attacks another group
    void attack(SmartTeam &other);

    // Returns the number of living members in the group
    int stillAlive() const;

    // Prints the details of all members in the group
    void print() const;
};
