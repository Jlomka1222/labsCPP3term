#define _CRT_SECURE_NO_WARNINGS
#include "Mechanic.h"
#include <iostream>
void Mechanic::printMaterial() const
{
	std::cout << "Clock is made of ";
	for (int i = 0; i < strlen(Material); i++)
	{
		std::cout << Material[i];
	}
	std::cout << std::endl;
}
Mechanic::Mechanic(const char* Material, const char* brend, int Time, int year_of_issue) :Clock(brend, Time, year_of_issue)
{
	strcpy(this->Material, Material);
}

void Mechanic::setMaterial(const char* str)
{
	strcpy(this->Material, str);
}

const char* Mechanic::getMaterial()const
{
	const char* str = Material;
	return str;
}