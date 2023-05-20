#include "SmartTeam.hpp"
#include <limits>
using namespace std;
namespace ariel
{
}
SmartTeam::SmartTeam(Character *leader) : Team(leader)
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
    Character *closest = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (auto member : members)
    {
        if (member->isAlive() && position.distance(member->getLocation()) < minDistance)
        {
            closest = member;
            minDistance = position.distance(member->getLocation());
        }
    }

    return closest; // Add return statement
}

void SmartTeam::chooseNewLeader()
{
    if (leader->isAlive())
        return; // The leader is still alive

    leader = closestLivingCharacter(leader->getLocation());
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

void SmartTeam::attack(SmartTeam *other)
{
    chooseNewLeader();

    if (leader == nullptr)
        return;

    Character *victim = chooseVictim(*other);

    while (victim != nullptr)
    {
        for (auto member : members)
        {
            if (member->isAlive())
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
                if (cowboy != nullptr)
                {
                    if (cowboy->hasboolets())
                        cowboy->shoot(victim);
                    else
                        cowboy->reload();
                    continue;
                }

                Ninja *ninja = dynamic_cast<Ninja *>(member);
                if (ninja != nullptr)
                {
                    if (ninja->distance(victim) <= 1)
                        ninja->slash(victim);
                    else
                        ninja->move(victim);
                    continue;
                }
            }
        }

        if (!victim->isAlive())
            victim = other->closestLivingCharacter(leader->getLocation()); // Choose a new victim
    }
}

int SmartTeam::stillAlive() const
{
    int count = 0;
    for (auto member : members)
        if (member->isAlive())
            count++;
    return count; // Add return statement
}
