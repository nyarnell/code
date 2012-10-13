// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class flying_car

#ifndef FLYING_CAR_H
#define FLYING_CAR_H
#include "vehicle.h"
class flying_car: public vehicle{
	public:
		void input(istream& ins);
		void output(ostream& outs);
	private:
		bool FAA_license;
};

#endif