// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class vehicle

#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>

using namespace std;

class vehicle{
	public:
		virtual void input(istream& ins)=0;
		virtual void output(ostream& outs)=0;
	protected:
		int id;
		string name;
		double top_speed;
		string color;
		int cup_holders;
		int price;
		int model_year;
};

#endif