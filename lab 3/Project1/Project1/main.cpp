#include <iostream>
#include "Clock.h"
#include "Mechanic.h"
#include "WallClock.h"
#include "Watch.h"
#include "FitnessTracker.h"

int main()
{
	WallClock Luch(false, false, "plastic", "Toplight", 12345, 2015);
	Luch.printInfo();
	Watch Rolex(true, "Yellow Gold Bezel", "Rolex", 33333, 2022);
	Rolex.printInfo();
	FitnessTracker MIband(55, "Xiaomi", 3333, 6.6, 2020);
	MIband.printInfo();
	return 0;
}