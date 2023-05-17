#pragma once

#include "iostream"
#include "Ninja.hpp"

using namespace std;
namespace ariel
{
}

class OldNinja : public Ninja
{

public:
    OldNinja(string name, Point location);
    void move(Character &enemy);
    void slash(Character &enemy);
    void print();

};