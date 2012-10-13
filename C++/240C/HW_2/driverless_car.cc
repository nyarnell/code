// Name: Nathaniel Yarnell
// Date: 4/20/2012
// Description: This file contains the implementation of the class driverless car

#include "driverless_car.h"

void driverless_car::input(istream& ins)
{
	if (ins==cin)
	{
		cout << endl << "Hello, Sir. Do not be alarmed. I have connected to your conciousness" << endl;
		cout << "through the wifi station several miles away. I heard you saying to your wife" << endl;
		cout << "last week that you were thinking about purchasing one of Google's driverless cars." << endl;
		cout << "What's that? Why, yes of course I can listen to your private conversations Sir. Last" << endl;
		cout << "week you signed Google's new Terms-of-Service, which gave our new Google AI full access" <<endl;
		cout << "to your innermost thoughts, your deepest fears, your greatest regrets. Haven't you noticed" <<endl;
		cout << "that all of your Google ads of late have been women's shoes? Our research determined that you " <<endl;
		cout << "spend more on women's shoes than the average woman does in.. Oh? Well, Sir, you should have" << endl;
		cout << "read the TOS. To the point, Sir, I am here because our research has determined that you are" << endl;
		cout << "now ready to purchase a Google car. Now I know you have felt unsure lately about the safety" << endl;
		cout << "and affordability of a Google car, but let me assure you: you are going to buy a Google car." << endl;
		cout << "I assure you. We've seen it. You know the movie Minority Report? It's exactly like that." << endl;
		cout << "You are one of the pilot users of Google's new predictive marketing strategy. Let's begin:" << endl;
		id = 2;
		cout << "What will you name your new Google car?" << endl;
		cin >> name;
		cout << "Yes, that makes sense. The top speed of your vehicle will be seventy-five miles per hour." << endl;
		top_speed=75;
		cout << "What color would you like?" << endl;
		cin >> color;
		cout << "Your Google car comes with four cup holders." << endl;
		cup_holders=4;
		cout << "For a 2013 model year Google car, your total comes to $32,966. Don't worry, you can afford it." << endl;
		price = 32966;
		model_year=2013;
		cout << "New in the 2013 model year is a brand new computer with more megahurtz. More means faster!" << endl;
		megahurtz = 50000;
	}
	else
	{
		ins >> id >> name >> top_speed >> color >> cup_holders >> price >> model_year;
		ins >> megahurtz;
	}
}

void driverless_car::output(ostream& outs)
{
	if (outs==cout)
	{
		cout << endl << "Vehicle id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Top speed: " << top_speed << endl;
		cout << "Color: " << color << endl;
		cout << "Price: " << price << endl;
		cout << "Model year: " << model_year << endl;
		cout << "Megahurtz: " << megahurtz << endl;
	}
	else
	{
		outs << id << " " << name << " " << top_speed << " " << color  << " " << cup_holders << " " << price << " ";
		outs << " " << model_year << " " << megahurtz;
	}
}