#include "SmartTeam.hpp"
#include <limits>
using namespace std;
namespace ariel
{
}
SmartTeam::SmartTeam(Character *leader) : leader(leader)
{
    members.push_back(leader);
}

SmartTeam::~SmartTeam()
{
    for (auto member : members)
        delete member;
}

void SmartTeam::add(Character *character)
{
    members.push_back(character);
}

Character *SmartTeam::closestLivingCharacter(const Point &position) const
{
    // The same as in Group2
}

void SmartTeam::chooseNewLeader()
{
    // The same as in Group2
}

Character *SmartTeam::chooseVictim(const SmartTeam &other) const
{
    // Select a character with low hit points first
    for (auto character : other.members)
    {
        if (character->isAlive() && character->getHitPoints() <= 10)
        {
            return character;
        }
    }
    // If no character has low hit points, choose the closest one
    return other.closestLivingCharacter(leader->getLocation());
}

void SmartTeam::attack(SmartTeam &other)
{
    chooseNewLeader();

    if (leader == nullptr)
        return;

    Character *victim = chooseVictim(other);

    // The rest of the code is the same as in Group2
}

int SmartTeam::stillAlive() const
{
    // The same as in Group2
}

void SmartTeam::print() const
{
    // The same as in Group2
}