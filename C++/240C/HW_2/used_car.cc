// Name: Nathaniel Yarnell
// Date: 4/20/2012
// Description: This file contains the implementation of the class used_car

#include "used_car.h"

void used_car::input(istream& ins)
{
	if (ins==cin)
	{
		char temp;
		cout << endl << "You walk onto the lot of the local used car dealership. All around you see" << endl;
		cout << "cars and trucks that have seen better days. A salesman notices potential prey, and" << endl;
		cout << "hurtles at you across the hot asphalt. Not to be intimidated, you proudly proclaim" << endl;
		cout << "that you are here to purchase your first automobile. The salesman pulls out a" << endl;
		cout << "clipboard and begins to ask you questions:" << endl;
		cout << "\"Are you looking for air conditioning?\" (enter y for yes, n for no)" << endl;
		cin >> temp;
		if (temp=='y')
		{
			cout << "\"Sorry, that's beyond your budget I'm afraid\"" << endl;
		}
		else
		{
			cout << "\"Good! You couldn't have it anyway.\"" << endl;
		}
		air_conditioning=false;
		cout << "\"Alright, now is heat important to you?\" (enter y for yes, n for no)" << endl;
		cin >> temp;
		if (temp=='y')
		{
			cout << "\"Well you should learn to dress warm. I'm afraid you can't afford it.\"" << endl;
		}
		else
		{
			cout << "\"A realist! A man of my own heart.\"" << endl;
		}
		heat=false;
		windows=true;
		radio=true;
		cout << "\"Looks like we have one match for a man with your meager budget. Top speed is 65 (though" << endl;
		cout << "I wouldn't try that if I were you). The color is... well, I wouldn't really call it a color." << endl;
		cout << "Comes with two cupholders, and is a 1984. Yours for only 2300\"" << endl;
		cout << "\"And as a special offer, you'll be receiving a free car radio! Hope you like AM.\"" << endl;
		cout << "Your head swirling with visions of yourself in your new car, you've barely listened to him, and " << endl;
		cout << "merely nod mildly. He quickly rushes off to get the paperwork." << endl;
		top_speed = 65;
		color = "ugly";
		cup_holders = 2;
		price = 2300;
		model_year = 1984;
		id=0;
		cout << "oh and what will you name the thing? ";
		cin >> name;
	}
	else
	{
		ins >> id >> name >> top_speed >> color >> cup_holders >> price >> model_year >> air_conditioning >> heat >> windows >> radio;
	}
}

void used_car::output(ostream& outs)
{
	if (outs==cout)
	{
		cout << endl << "Vehicle id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Top speed: " << top_speed << endl;
		cout << "Color: " << color << endl;
		cout << "Price: " << price << endl;
		cout << "Model year: " << model_year << endl;
		cout << "Air conditioning: " << air_conditioning << endl;
		cout << "Heat: " << heat << endl;
		cout << "Windows: " << windows << endl;
		cout << "Radio: " << radio << endl;
	}
	else
	{
		outs << id << " " << name << " " << top_speed << " " << color  << " " << cup_holders << " " << price << " ";
		outs << " " << model_year << " " << air_conditioning << " " << heat << " " << windows << " " << radio;
	}
}