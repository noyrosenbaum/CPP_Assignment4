#pragma once

#include "iostream"
#include "Ninja.hpp"

using namespace std;
namespace ariel
{
}

class YoungNinja : public Ninja
{

public:
    YoungNinja(string name, Point location);
    void move(Character &enemy);
    void slash(Character &enemy);
    void print();

};