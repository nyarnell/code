// Name: Nathaniel Yarnell
// Date: 4/20/2012
// Description: This file contains the implementation of the class portal

#include "portal.h"

void portal::input(istream& ins)
{
	if (ins==cin)
	{
		id=3;
		top_speed = 99999;
		color = "colorless";
		cup_holders = 0;
		cout << "Well, what are you going to name this absurdity?" << endl;
		cin >> name;
		cout << "We're testing a pay-what-you-want scheme. So name your price (in whole dollars please)" << endl << "$";
		cin >> price;
		cout << "Unfortunately, the 2012 model year portals were pulled from shelves after the Jeff Goldblum incident." << endl;
		cout << "But newly available are the 2013 models, this time with a little bit less mad science." << endl;
		model_year=2013;
		radius = price*3.14;
		fuel_efficiency = 99999;
	}
	else
	{
		ins >> id >> name >> top_speed >> color >> cup_holders >> price >> model_year;
		ins >> radius >> fuel_efficiency;
	}
}

void portal::output(ostream& outs)
{
	if (outs==cout)
	{
		cout << endl << "Vehicle id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Top speed: " << top_speed << endl;
		cout << "Color: " << color << endl;
		cout << "Price: " << price << endl;
		cout << "Model year: " << model_year << endl;
		cout << "Radius: " << radius << endl;
		cout << "Fuel efficiency: " << fuel_efficiency << endl;
	}
	else
	{
		outs << id << " " << name << " " << top_speed << " " << color  << " " << cup_holders << " " << price << " ";
		outs << " " << model_year << " " << " " << radius << " " << fuel_efficiency;
	}
}