// Name: Nathaniel Yarnell
// Date: 3/7/2012
// Description: This file contains the implementation of the class event.

#include <string>
#include <iostream>
#include <fstream>
#include "event.h"

using namespace std;

event::event()
{
	date;
	name="";
}

// Date event::get_date()
// {
	// return date;
// }

// string event::get_name()
// {
	// return name;
// }

// void event::set_date(string& newdate)
// {
	// date=newdate;
// }

// void event::set_name(string& newname)
// {
	
// }

istream& operator >> (istream& fin, event& event)
{
	if (fin==cin) //from keyboard
	{
		string temp;
		cout << endl << "Enter the event date in the format m/d/y: ";
		fin >> event.date;
		cout << endl << "Enter the name of the event: ";
		fin.ignore();
		getline(fin, temp);
		event.name=temp;
		cout << endl;
		return fin;
	}
	else //from file
	{
		fin >> event.date;
		fin.ignore();
		getline(fin, event.name);
		return fin;
	}
}
ostream& operator << (ostream& fout, event& event)
{
	if (fout==cout) //to monitor
	{
		fout << event.name << endl << event.date << endl;
		return fout;
	}
	else //to file
	{
		fout << event.date << endl << event.name << endl;
		return fout;
	}
}