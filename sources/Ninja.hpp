#pragma once

#include "iostream"
#include "Character.hpp"

using namespace std;
namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string name, Point location, int speed, int hits);
        virtual void move(Character *enemy);
        virtual void slash(Character *enemy);
        int getSpeed() const;
        string print();
    };
}
