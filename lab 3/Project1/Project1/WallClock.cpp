#include "WallClock.h"
#include <iostream>
void WallClock::setPendulum(bool pend)
{
	Pendulum = pend;
	return;
}

WallClock::WallClock(bool Pendulum, bool Cuckoo, const char* Material, const char* brend, int Time, int year_of_issue) : Mechanic(Material, brend, Time, year_of_issue)
{
	this->Pendulum = Pendulum;
	this->Cuckoo = Cuckoo;
}



void WallClock::printInfo() const
{
	this->printBrend();
	this->printYear();
	this->printMaterial();
	this->printTime();
	if (Pendulum)
	{
		std::cout << "Clock has Pendulum" << std::endl;
	}
	else std::cout << "Clock has not Pendulum" << std::endl;
	if (Cuckoo)
	{
		std::cout << "Clock has Cuckoo\n" << std::endl;
	}
	else std::cout << "Clock has not Cuckoo\n" << std::endl;
}

bool WallClock::getPendulum() const
{
	return Pendulum;
}


bool WallClock::getCuckoo() const
{
	return Cuckoo;
}

void WallClock::setCuckoo(bool Cuckoo)
{
	this->Cuckoo = Cuckoo;
}