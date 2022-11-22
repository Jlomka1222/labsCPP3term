#define _CRT_SECURE_NO_WARNINGS
#include "Clock.h"
#include <iostream>
#include <string>
void Clock::printTime() const
{
	int hours = Time / 3600;
	std::cout << "Current time:  " << hours << ":" << (Time - hours * 3600) / 60 << std::endl;
}

void Clock::printBrend()const
{
	std::cout << "Clock brend is ";
	for (int i = 0; i < strlen(Brend); i++)
	{
		std::cout << Brend[i];
	}
	std::cout << std::endl;
}

Clock::Clock(const char* brend, int Time, int year_of_issue)
{
	strcpy(Brend, brend);
	this->Time = Time;
	this->year_of_issue = year_of_issue;
}

Clock::~Clock()
{
}

int Clock::getTime()const
{
	return this->Time;
}

void Clock::setTime(int Time)
{
	this->Time = Time;
}

void Clock::setBrend(const char* str)
{
	strcpy(Brend, str);
}

const char* Clock::getBrend()const
{
	const char* str = Brend;
	return str;
}

void Clock::setYear(int year)
{
	this->year_of_issue = year;
}

int Clock::getYear()
{
	return this->year_of_issue;
}

void Clock::printYear()const
{
	std::cout << "Year of issue is " << year_of_issue << std::endl;
}