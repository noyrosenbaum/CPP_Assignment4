#pragma once

#include "iostream"
#include "Character.hpp"

using namespace std;
namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bulletAmount;

    public:
        Cowboy(string name, Point location);
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        int getBulletAmount() const;
        string print();
    };
}
