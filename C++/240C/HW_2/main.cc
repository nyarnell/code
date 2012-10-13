#include "vehicle.h"
#include "fuel_efficient.h"
#include "driverless_car.h"
#include "portal.h"
#include "used_car.h"
#include "dirigible.h"
#include "flying_car.h"
#include "submersible.h"
#include <list>
#include <fstream>
#include <iostream>

int main()
{
	list<vehicle*> garage;
	char k;
	ifstream ins;
	ins.open("data.txt");
	vehicle* temp;
	if (!ins.eof()){
	if (ins.peek()=='0')
	{
		temp = new used_car;
		temp->input(ins);
	}
	else if (ins.peek()=='1')
	{
		temp = new dirigible;
		temp->input(ins);
	}
	else if (ins.peek()=='2')
	{
		temp = new driverless_car;
		temp->input(ins);
	}
	else if (ins.peek()=='3')
	{
		temp = new portal;
		temp->input(ins);
	}
	else if (ins.peek()=='4')
	{
		temp = new flying_car;
		temp->input(ins);
	}
	else if (ins.peek()=='5')
	{
		temp = new submersible;
		temp->input(ins);
	}
	else
	{
		ins >> k;
	}
	while (!ins.eof())
	{
		garage.push_back(temp);
		if (ins.peek()==' '){ins.ignore();}
		if (ins.peek()=='0')
		{
			temp = new used_car;
			temp->input(ins);
		}
		else if (ins.peek()=='1')
		{
			temp = new dirigible;
			temp->input(ins);
		}
		else if (ins.peek()=='2')
		{
			temp = new driverless_car;
			temp->input(ins);
		}
		else if (ins.peek()=='3')
		{
			temp = new portal;
			temp->input(ins);
		}
		else if (ins.peek()=='4')
		{
			temp = new flying_car;
			temp->input(ins);
		}
		else if (ins.peek()=='5')
		{
			temp = new submersible;
			temp->input(ins);
		}
		else
		{
			ins >> k;
		}
		if (ins.peek()==' '){ins.ignore();}
	}
	}
	ins.close();
	while (true)
	{
		char x;
		cout << endl;
		cout << "-------------------------" << endl;
		cout << "a - purchase a vehicle" << endl;
		cout << "b - display your garage" << endl;
		cout << "c - exit" << endl;
		cout << "-------------------------" << endl;
		cin >> x;
		if (x=='a')
		{
			char y;
			cout << endl;
			cout << "-------------------------" << endl;
			cout << "0 - buy a used car" << endl;
			cout << "1 - buy a dirigible" << endl;
			cout << "2 - buy a driverless car" << endl;
			cout << "3 - buy a portal" << endl;
			cout << "4 - buy a flying car" << endl;
			cout << "5 - buy a submersible" << endl;
			cout << "-------------------------" << endl;
			cin >> y;
			if (y=='0')
			{
				used_car* temp = new used_car;
				temp->input(cin);
				garage.push_back(temp);
			}
			else if (y=='1')
			{
				dirigible* temp = new dirigible;
				temp->input(cin);
				garage.push_back(temp);
			}
			else if (y=='2')
			{
				driverless_car* temp = new driverless_car;
				temp->input(cin);
				garage.push_back(temp);
			}
			else if (y=='3')
			{
				portal* temp = new portal;
				temp->input(cin);
				garage.push_back(temp);
			}
			else if (y=='4')
			{
				flying_car* temp = new flying_car;
				temp->input(cin);
				garage.push_back(temp);
			}
			else if (y=='5')
			{
				submersible* temp = new submersible;
				temp->input(cin);
				garage.push_back(temp);
			}
		}
		else if (x=='b')
		{
			list<vehicle*>::iterator it=garage.begin();
			while (it!=garage.end())
			{
				(*it)->output(cout);
				++it;
			}
		}
		else if (x=='c')
		{
			ofstream outs;
			outs.open("data.txt");
			list<vehicle*>::iterator it=garage.begin();
			while (it!=garage.end())
			{
				(*it)->output(outs);
				outs << " ";
				++it;
			}
			outs.close();
			return 0;
		}
	}
}