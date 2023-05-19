#include "Team2.hpp"
#include "Character.hpp"
#include <limits>

using namespace std;
namespace ariel
{
}

Team2::Team2(Character *leader) : leader(leader)
{
    members.push_back(leader);
}

Team2::~Team2()
{
    for (auto member : members)
        delete member;
}

void Team2::add(Character *character)
{
    members.push_back(character);
}

Character *Team2::closestLivingCharacter(const Point &position) const
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

    return closest;
}

void Team2::chooseNewLeader()
{
    if (leader->isAlive())
        return; // The leader is still alive

    leader = closestLivingCharacter(leader->getLocation());
}

void Team2::attack(Team2 &other)
{
    chooseNewLeader(); // Ensure we have a living leader

    if (leader == nullptr)
        return; // No living members in the group

    Character *victim = other.closestLivingCharacter(leader->getLocation());

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
                        cowboy->shoot(*victim);
                    else
                        cowboy->reload();
                    continue;
                }

                Ninja *ninja = dynamic_cast<Ninja *>(member);
                if (ninja != nullptr)
                {
                    if (ninja->distance(*victim) <= 1)
                        ninja->slash(*victim);
                    else
                        ninja->move(*victim);
                    continue;
                }
            }
        }

        if (!victim->isAlive())
            victim = other.closestLivingCharacter(leader->getLocation()); // Choose a new victim
    }
}

int Team2::stillAlive() const
{
    int count = 0;
    for (auto member : members)
        if (member->isAlive())
            count++;
    return count;
}

void Team2::print() const
{
    for (auto member : members)
        member->print();
}