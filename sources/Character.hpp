#pragma once

#include "iostream"
#include <string>
#include "Point.hpp"

using namespace std;
namespace ariel
{
}

class Character
{
private:
    Point location;
    string name;
    int hits;

public:
    Character(string name, Point location, int hits);
    bool isAlive();
    double distance(Character &other);
    void hit(int hits);
    string getName();
    Point getLocation();
    int getHits();
    virtual void print();
};