// Name: Nathaniel Yarnell
// Date: 3/7/2012
// Description: This file contains the main function for the class eventlist.

#include "eventlist.h"
#include <string>

using namespace std;

int main()
{
	eventlist list;
	bool x=true;
	string choice, name;
	Date date;
	while (x)
	{
		cout << "------------------------" << endl;
		cout << "a - Add an event" << endl;
		cout << "b - View events" << endl;
		cout << "c - test copy constrcutor / assignment operator" << endl;
		cout << "d - quit";
		cout << "------------------------" << endl;
		cin >> choice;
		if (choice=="a")
		{
			node* temp = new node;
			cout << "Enter the event name: ";
			cin >> name;
			cout << endl << "Enter the event date with the format m/d/y:";
			cin >> date;
			cout << endl;
			temp->data().set_date(date);
			temp->data().set_name(name);
			list.add_event(temp);
		}
		if (choice=="b")
		{
		
		}
		if (choice=="c")
		{
		
		}
		if (choice=="d")
		{
			list.output_events();
			return 0;
		}
	}
}