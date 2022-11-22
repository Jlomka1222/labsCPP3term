#include "FitnessTracker.h"
#include <iostream>

FitnessTracker::FitnessTracker(int Charge, const char* brend, int Time, float travDis, int year_of_issue) :Electronic(Charge, brend, Time, year_of_issue)
{
	this->travDis = travDis;
	this->calories = travDis * 55;
}

void FitnessTracker::setTravDis(float km)
{
	this->travDis = km;
}

float FitnessTracker::getTravDis()const
{
	return this->travDis;
}

int FitnessTracker::getCalories()const
{
	return this->travDis * 55;
}

void FitnessTracker::printInfo() const
{
	this->printBrend();
	this->printYear();
	this->printCharge();
	this->printTime();
	std::cout << "You have passed " << travDis << " kilometers" << std::endl;
	std::cout << "You have burned " << calories << " calories\n" << std::endl;

}