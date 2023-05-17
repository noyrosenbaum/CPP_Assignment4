#include "Team.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Team::Team(Character *captin) : captin(captin)
{
    this->add(captin);
}
void Team::add(Character *character) {}
void Team::attack(Team *enemy) {}
int Team::stillAlive()
{
    return 1;
}
void Team::print()
{

}
