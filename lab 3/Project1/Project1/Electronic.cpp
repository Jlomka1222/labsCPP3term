#include "Electronic.h"
#include <iostream>
void Electronic::printCharge() const
{
	std::cout << "Current charge is " << Charge << "%" << std::endl;
}

Electronic::Electronic(int Charge, const char* brend, int Time, int year_of_issue) :Clock(brend, Time, year_of_issue)
{
	this->Charge = Charge;
	if (this->Charge > 100)this->Charge = 100;
	else if (this->Charge < 0)this->Charge = 0;
}
void Electronic::setCharge(int power)
{
	this->Charge = power;
}

int Electronic::getCharge()const
{
	return this->Charge;
}
