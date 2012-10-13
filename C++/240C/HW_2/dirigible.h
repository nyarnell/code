// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class dirigible

#ifndef DIRIGIBLE_H
#define DIRIGIBLE_H
#include "fuel_efficient.h"
#include "vehicle.h"
class dirigible: public vehicle, public fuel_efficient{
	public:
		void input(istream& ins);
		void output(ostream& outs);
	private:
		int middle_class_cabins;
		int deluxe_suites;
		int butlers;
};

#endif