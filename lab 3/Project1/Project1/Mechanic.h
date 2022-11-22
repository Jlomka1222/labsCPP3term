#pragma once
#include "Clock.h"
class Mechanic:
    public Clock
{
private:
    char Material[80];
public:
    void printMaterial()const;
    Mechanic(const char* Material, const char* brend, int Time, int year_of_issue);
    void setMaterial(const char* str);
    const char* getMaterial()const;
};
