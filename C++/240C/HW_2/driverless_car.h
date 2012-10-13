// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class driverless_car

#ifndef DRIVERLESS_CAR_H
#define DRIVERLESS_CAR_H
#include "vehicle.h"
class driverless_car: public vehicle{
	public:
		void input(istream& ins);
		void output(ostream& outs);
	private:
		double megahurtz;
};

#endif