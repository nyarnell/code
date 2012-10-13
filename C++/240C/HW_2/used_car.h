// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class used_car

#ifndef USED_CAR_H
#define USED_CAR_H
#include "vehicle.h"
class used_car: public vehicle{
	public:
		void input(istream& ins);
		void output(ostream& outs);
	private:
		bool air_conditioning;
		bool heat;
		bool windows;
		bool radio;
};

#endif