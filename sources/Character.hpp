#pragma once

#include "iostream"
#include <string>
#include "Point.hpp"

using namespace std;
namespace ariel
{
    class Character
    {
    public:
        Point location;
        string name;
        int hits;
        Character(Point location, string name, int hits);
        bool isAlive();
        double distance(Character &other);
        void hit(int hits);
        string getName() const;
        Point getLocation() const;
        int getHits() const;
        virtual string print() = 0;
    };
}
