// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class submersible

#ifndef SUBMERSIBLE_H
#define SUBMERSIBLE_H
#include "vehicle.h"
class submersible: public vehicle{
	public:
		void input(istream& ins);
		void output(ostream& outs);
	private:
		int mateys;
		int wenches;
		int parrots;
		double booty;
};

#endif