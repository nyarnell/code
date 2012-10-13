// Name: Nathaniel Yarnell
// Date: 2/1/2012
// Description: This file contains the main function for the class checkbook.

#include <iostream>
#include <string>
#include "checkbook.h"
using namespace std;

int main()
{
	bool x=true;
	string choice;
	double amount;
	checkbook yourchecks;
	Date date;
	while(x)
	{
		cout << "------------------------" << endl;
		cout << "a - make a deposit" << endl;
		cout << "b - write a check" << endl;
		cout << "c - display all checks" << endl;
		cout << "d - search checks by name" << endl;
		cout << "e - sort checks by number" << endl;
		cout << "f - sort checks by name" << endl;
		cout << "g - sort checks by amount" << endl;
		cout << "h - sort by date" << endl;
		cout << "i - view record of deposits" << endl;
		cout << "x - exit" << endl;
		cout << "------------------------" << endl;
		cin >> choice;
		if (choice=="a")
		{
			cout << "How much would you like to deposit?" << endl << "$";
			cin >> amount;
			cout << endl << "What day is it today? (m/d/y) ";
			cin >> date;
			yourchecks.deposit(amount, date);
		}
		if (choice=="b")
		{
			check temp;
			temp.set_number(1001+yourchecks.get_written()); //keeps check numbers straight
			cin >> temp;
			yourchecks.write_check(temp);
		}
		if (choice=="c")
		{
			yourchecks.display_checks();
		}
		if (choice=="d")
		{
			cout << "Enter a name: ";
			cin >> choice;
			yourchecks.search_checks(choice);
		}
		if (choice=="e")
		{
			yourchecks.sort_stuff("number");
			yourchecks.display_checks();
		}
		if (choice=="f")
		{
			yourchecks.sort_stuff("name");
			yourchecks.display_checks();
		}
		if (choice=="g")
		{
			yourchecks.sort_stuff("amount");
			yourchecks.display_checks();
		}
		if (choice=="h")
		{
			yourchecks.sort_stuff("date");
			yourchecks.display_checks();
		}
		if (choice=="i")
		{
			yourchecks.display_record();
		}
		if (choice=="x")
		{
			yourchecks.output_checks();
			yourchecks.output_record();
			return 0;
		}
	}
}