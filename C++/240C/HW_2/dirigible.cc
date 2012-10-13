// Name: Nathaniel Yarnell
// Date: 4/20/2012
// Description: This file contains the implementation of the class dirigible

#include "dirigible.h"

using namespace std;

void dirigible::input(istream& ins)
{
	if (ins==cin)
	{
		cout << endl << "You, Mr. Ebenezer Fancypants, heir to the Fancypants empire, have just arrived" << endl;
		cout << "at the world's most exclusive airship dealership, Le Buisson Ardent. Stepping out of" << endl;
		cout << "your ivory limousine, the staff of Le Buisson Ardent, who have gathered to herald" << endl;
		cout << "your coming, spontaneously burst into applause. You shrug. These sorts of things" << endl;
		cout << "happen to Mr. Ebenezer Fancypants. You do that awkward waving thing like the Queen" << endl;
		cout << "of England for a while, until a man shoulders through the throng to help you." << endl;
		cout << "\"Mr. Fancypants! How wonderful to see you. What can Le Buisson Ardent do you for?\"" << endl;
		cout << "Smiling, you reply: \"I've had enough of all the riffraff. I'm looking to soar above the" << endl;
		cout << "rotten stench of modernity. I heard you could help me.\"" << endl;
		cout << "Smiling graciously, he replies \"Oh yes Mr. Fancypants, we can certainly help you" << endl;
		cout << "avoid the common man.\" Whipping out a clipboard, he says \"Just a few questions, first\"" << endl;
		cout << "\"First of all, how many butlers will you be needing?\"" << endl;
		cout << "You stroke your chin thoughtfully, before replying: ";
		cin >> butlers;
		cout << endl << "\"" << butlers << " it is then, sir. And how many middle class cabins shall your" << endl;
		cout << "dirigible possess?\"" << endl;
		cout << "Pausing for a moment, you say: ";
		cin >> middle_class_cabins;
		cout << endl << "\"" << middle_class_cabins << " shall be wonderful. And what about deluxe suites, hm?\"" << endl;
		cout << "Thoughts of a flying mansion run through your head as you declare: ";
		cin >> deluxe_suites;
		cout << endl << "\"" << deluxe_suites << " sounds perfect, sir. As you know, Le Buisson Ardent is the only" << endl;
		cout << "business of its kind. Where there were once many airship makers, there is now only us. " << endl;
		cout << "Unfortunately, some compromises must be made. The top speed of your aircraft, you should know, " << endl;
		cout << "is twenty-five miles per hour. No way around it. And also unfortunately, your only color choice" << endl;
		cout << "is khaki. Apologies, sir.\"" << endl;
		color = "khaki";
		top_speed = 25;
		cout << "The last three things we need to decide upon are the cup-holders, the name, and the model year of" << endl;
		cout << "your ship.\"" << endl;
		cout << "You ask: \"Model year? but isn't this brand new?\"" << endl;
		cout << "He replies: \"Yes, sir, it is, but we offer a service where we paint a number on the side.\" He shrugs." << endl;
		cout << "\"People seem to think it's ironic or something. Anyway, what shall you name your ship?\"" << endl;
		cout << "You waste no time in deciding: ";
		cin >> name;
		cout << "\"And so it shall be. How many cup holders do you desire?\"" << endl;
		cout << "You decide quickly: ";
		cin >> cup_holders;
		cout << "\"And model year?\"" << endl;
		cin >> model_year;
		price = (middle_class_cabins*5000 + deluxe_suites*10000 + butlers*4000 + cup_holders*10);
		cout << "\"Excellent sir. With this, your order is complete. The cost will be $" << price << "\"" << endl;
		id = 1;
		fuel_efficiency = 120;
	}
	else
	{
		ins >> id >> name >> top_speed >> color >> cup_holders >> price >> model_year;
		ins >> middle_class_cabins >> deluxe_suites >>  butlers >> fuel_efficiency;
	}
}

void dirigible::output(ostream& outs)
{
	if (outs==cout)
	{
		cout << endl << "Vehicle id: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Top speed: " << top_speed << endl;
		cout << "Color: " << color << endl;
		cout << "Price: " << price << endl;
		cout << "Model year: " << model_year << endl;
		cout << "Middle class cabins: " << middle_class_cabins << endl;
		cout << "Deluxe suites: " << deluxe_suites << endl;
		cout << "Butlers: " << butlers << endl;
		cout << "Fuel efficiency: " << fuel_efficiency << endl;
	}
	else
	{
		outs << id << " " << name << " " << top_speed << " " << color  << " " << cup_holders << " " << price << " ";
		outs << " " << model_year << " " << middle_class_cabins << " " << deluxe_suites << " " << butlers << " ";
		outs << fuel_efficiency;
	}
}