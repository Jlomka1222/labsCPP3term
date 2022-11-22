#include "Watch.h"
#include <iostream>
void Watch::setWinder(bool winder)
{
	this->winder = winder;
}

Watch::Watch(bool winder, const char* Material, const char* brend, int Time, int year_of_issue) :Mechanic(Material, brend, Time, year_of_issue)
{
	this->winder = winder;
}
void Watch::printInfo() const
{
	this->printBrend();
	this->printYear();
	this->printMaterial();
	this->printTime();
	if (winder)
	{
		std::cout << "Clock has autowinder\n" << std::endl;
	}
	else std::cout << "Clock has not autowinder\n" << std::endl;
}

bool Watch::getWinder()const
{
	return winder;
}