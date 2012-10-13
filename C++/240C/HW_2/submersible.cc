// Name: Nathaniel Yarnell
// Date: 4/20/2012
// Description: This file contains the implementation of the class submersible

#include "submersible.h"

void submersible::input(istream& ins)
{
	if (ins==cin)
	{
		id=5;
		top_speed=61;
		cup_holders=0;
		cout << "You are the world's only submersible pirate. You pirate and stuff. Cool." << endl;
		cout << "What's the name of your big bad pirate submersible?" << endl;
		cin >> name;
		cout << "What color is it?" << endl;
		cin >> color;
		cout << "What year was it made?" << endl;
		cin >> model_year;
		cout << "And how much did you pay for it?" << endl << "$";
		cin >> price;
		cout << "How many mateys ya got?" << endl;
		cin >> mateys;
		cout << "And how many wenches?" << endl;
		cin >> wenches;
		cout << "And parrots? You must have some parrots" << endl;
		cin >> parrots;
		cout << "And how much booty have ya pirated?" << endl;
		cin >> booty;
	}
	else
	{
		ins >> id >> name >> top_speed >> color >> cup_holders >> price >> model_year;
		ins >> mateys >> wenches >> parrots >> booty;
	}
}

void submersible::output(ostream& outs)
{
	if (outs==cout)
	{
		cout << endl << "Vehicle id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Top speed: " << top_speed << endl;
		cout << "Color: " << color << endl;
		cout << "Price: " << price << endl;
		cout << "Model year: " << model_year << endl;
		cout << "Mateys: " << mateys << endl;
		cout << "Wenches: " << wenches << endl;
		cout << "Parrots: " << parrots << endl;
		cout << "Booty: " << booty << endl;
	}
	else
	{
		outs << id << " " << name << " " << top_speed << " " << color  << " " << cup_holders << " " << price << " ";
		outs << " " << model_year << " " << mateys << " " << wenches << " " << parrots << " " << booty;
	}
}