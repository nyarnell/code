// Name: Nathaniel Yarnell
// Date: 4/20/2012
// Description: This file contains the implementation of the class flying car

#include "flying_car.h"

void flying_car::input(istream& ins)
{
	if (ins==cin)
	{
		id=4;
		cout << "Name?" << endl;
		cin >> name;
		top_speed = 245;
		cout << "Color?" << endl;
		cin >> color;
		cout << "Cup holders?" << endl;
		cin >> cup_holders;
		cout << "Model year?" << endl;
		cin >> model_year;
		price=50000;
		cout << "Can you even fly this thing? (enter 0 for no, 1 for yes)" << endl;
		cin >> FAA_license;
	}
	else
	{
		ins >> id >> name >> top_speed >> color >> cup_holders >> price >> model_year;
		ins >> FAA_license;
	}
}

void flying_car::output(ostream& outs)
{
	if (outs==cout)
	{
		cout << endl << "Vehicle id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Top speed: " << top_speed << endl;
		cout << "Color: " << color << endl;
		cout << "Price: " << price << endl;
		cout << "Model year: " << model_year << endl;
		cout << "FAA license: " << FAA_license << endl;
	}
	else
	{
		outs << id << " " << name << " " << top_speed << " " << color  << " " << cup_holders << " " << price << " ";
		outs << " " << model_year << " " << FAA_license;
	}
}