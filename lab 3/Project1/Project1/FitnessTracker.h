#pragma once
#include "Electronic.h"
class FitnessTracker :
    public Electronic
{
private:
    float travDis;
    int calories;
public:
    FitnessTracker(int Charge, const char* brend, int Time, float  travDis, int year_of_issue);
    void setTravDis(float km);
    float getTravDis()const;
    int getCalories()const;
    void printInfo()const;
};
