// Name: Nathaniel Yarnell
// Date: 2/20/2012
// Description: This file contains the main function for the class student.

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main()
{
	bool x=true;
	string choice, title, id, score;
	double time;
	student sadface;
	while(x)
	{
		cout << "------------------------" << endl;
		cout << "a - set name or pid" << endl;
		cout << "b - insert a course" << endl;
		cout << "c - remove a course" << endl;
		cout << "d - view courses" << endl;
		cout << "e - view GPA, total hours, student name and pid" << endl;
		cout << "f - test constructor/assignment operator" << endl;
		cout << "x - exit" << endl;
		cout << "------------------------" << endl;
		cin >> choice;
		if (choice=="a")
		{
			cout << endl << "Enter your name: ";
			cin.ignore(); //newline
			getline(cin, title);
			cout << endl << "Enter your pid: ";
			cin >> id;
			cout << endl;
			sadface.set_name_pid(title, id);
		}
		if (choice=="b")
		{
			node* tmp = new node;
			cout << endl << "Enter the course name: ";
			cin >> title;
			cout << endl << "Enter your grade: ";
			cin >> score;
			cout << endl << "Enter the number of hours the course was: ";
			cin >> time;
			cout << endl;
			tmp->course=title;
			tmp->grade=score;
			tmp->hours=time;
			tmp->link=NULL;
			//cout << "nulltest" << endl;
			sadface.insert_course(tmp);
		}
		if (choice=="c")
		{
			cout << endl << "Enter the course name you want to remove: ";
			cin >> title;
			cout << endl;
			sadface.remove_course(title);
		}
		if (choice=="d")
		{
			sadface.view_courses();
		}
		if (choice=="e")
		{
			sadface.view_info();
		}
		if (choice=="f")
		{
			int x=0;
			while (x==0)
			{
				student despicable=sadface;
				despicable.view_courses();
				x=1;
			}
		}
		if (choice=="x")
		{
			sadface.output_student();
			return 0;
		}
	}
}