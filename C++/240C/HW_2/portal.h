// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class portal

#ifndef PORTAL_H
#define PORTAL_H
#include "fuel_efficient.h"
#include "vehicle.h"
class portal: public vehicle, public fuel_efficient{
	public:
		void input(istream& ins);
		void output(ostream& outs);
	private:
		double radius;
};

#endif