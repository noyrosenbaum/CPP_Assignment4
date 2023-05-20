#include "Team.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;
using namespace ariel;

Team::Team(Character *leader) : leader(leader)
{
    // add the leader to the respective list based on its type
    if (dynamic_cast<Cowboy *>(leader))
    {
        cowboys.push_back(dynamic_cast<Cowboy *>(leader));
    }
    else
    {
        ninjas.push_back(dynamic_cast<Ninja *>(leader));
    }
}

Team::~Team()
{
    for (auto cowboy : cowboys)
        delete cowboy;
    for (auto ninja : ninjas)
        delete ninja;
    cowboys.clear();
    ninjas.clear();
}

void Team::add(Character *character)
{
    if (dynamic_cast<Cowboy *>(character))
    {
        cowboys.push_back(dynamic_cast<Cowboy *>(character));
    }
    else
    {
        ninjas.push_back(dynamic_cast<Ninja *>(character));
    }
}

Character *Team::closestLivingCharacter(const Point &position) const
{
    Character *closest = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    auto checkClosest = [&](Character *character)
    {
        if (character->isAlive() && position.distance(character->getLocation()) < minDistance)
        {
            closest = character;
            minDistance = position.distance(character->getLocation());
        }
    };

    for (auto cowboy : cowboys)
        checkClosest(cowboy);
    for (auto ninja : ninjas)
        checkClosest(ninja);

    return closest;
}

void Team::chooseNewLeader()
{
    if (leader->isAlive())
        return; // The leader is still alive

    leader = closestLivingCharacter(leader->getLocation());
}

void Team::attack(Team *other)
{
    chooseNewLeader(); // Ensure we have a living leader

    if (leader == nullptr)
        return; // No living members in the Team

    Character *victim = other->closestLivingCharacter(leader->getLocation());

    while (victim != nullptr)
    {
        for (auto cowboy : cowboys)
        {
            if (cowboy->isAlive())
            {
                if (cowboy->hasboolets())
                    cowboy->shoot(victim);
                else
                    cowboy->reload();
            }
        }

        for (auto ninja : ninjas)
        {
            if (ninja->isAlive())
            {
                if (ninja->distance(victim) <= 1)
                    ninja->slash(victim);
                else
                    ninja->move(victim);
            }
        }

        if (!victim->isAlive())
            victim = other->closestLivingCharacter(leader->getLocation()); // Choose a new victim
    }
}

int Team::stillAlive() const
{
    int count = 0;
    for (auto cowboy : cowboys)
        if (cowboy->isAlive())
            count++;
    for (auto ninja : ninjas)
        if (ninja->isAlive())
            count++;
    return count;
}

void Team::print() const
{
    for (auto cowboy : cowboys)
        cowboy->print();
    for (auto ninja : ninjas)
        ninja->print();
}
