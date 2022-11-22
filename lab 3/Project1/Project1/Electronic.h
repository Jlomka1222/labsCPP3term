#pragma once
#include "Clock.h"
class Electronic:
    public Clock
{
private:
    int Charge;
public:
    void printCharge()const;
    Electronic(int Charge, const char* brend, int Time, int year_of_issue);
    void setCharge(int);
    int getCharge()const;
};
