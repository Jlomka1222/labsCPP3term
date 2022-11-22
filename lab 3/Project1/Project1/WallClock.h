#pragma once
#include "Mechanic.h"
class WallClock :
    public Mechanic
{
private:
    bool Pendulum;
    bool Cuckoo;
public:
    void setPendulum(bool pend);
    WallClock(bool Pendulum, bool Cucko, const char* Material, const char* brend, int Time, int year_of_issue);
    void printInfo()const;
    bool getPendulum()const;
    void setCuckoo(bool cuckoo);
    bool getCuckoo()const;
};