#pragma once
#include "Mechanic.h"
class Watch :
    public Mechanic
{
private:
    bool winder;
public:
    void setWinder(bool);
    Watch(bool winder, const char* Material, const char* brend, int Time, int year_of_issue);
    void printInfo()const;
    bool getWinder()const;
};
