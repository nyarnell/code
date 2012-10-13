// Name: Nathaniel Yarnell
// Date: 2/1/2012
// Description: This file contains the implementation of the class check.

#include <iostream>
#include <string>
#include <typeinfo>
#include "check.h"
using namespace std;

//Constructors

check::check(): number(0), date(), pay_to(""), amount(0.0) {}

check::check(int& num, Date& day, string& pay, double& dollars)
{
	number=num;
	date=day;
	pay_to=pay;
	amount=dollars;
}

//Mutator functions

void check::set_number(int num)
{
	number=num;
}

void check::set_date(Date& day)
{
	date=day;
}

void check::set_pay_to(string& pay)
{
	pay_to=pay;
}

void check::set_amount(double& dollars)
{
	amount=dollars;
}

//Accessor functions

int check::get_number()
{
	return number;
}

Date check::get_date()
{
	return date;
}

string check::get_pay_to()
{
	return pay_to;
}

double check::get_amount()
{
	return amount;
}

//Overloaded input/output functions

istream& operator >> (istream& fin, check& check)
{
	if (fin==cin) //from keyboard
	{	
		string temp;
		cout << endl << "Enter the check date in the format m/d/y: ";
		fin >> check.date;
		cout << endl << "Enter the check pay-to-the-order-of. (Use underscores";
		cout << endl << "for spaces or may god help your soul): ";
		fin.ignore(); //newline character
		getline (fin,temp);
		check.pay_to=temp;
		cout << endl << "Enter the check amount: $";
		fin >> check.amount;
		cout << endl;
		return fin;
	}
	else //from file
	{	
		fin >> check.number >> check.date >> check.pay_to >> check.amount;
		return fin;
	}
}

ostream& operator << (ostream& fout, check& check)
{
	if (fout==cout) //to monitor
	{
		fout << "Check # " << check.number << endl;
		fout << "Date: " << check.date << endl;
		fout << "Pay-to-the-order-of: " << check.pay_to << endl;
		fout << "Amount: $" << check.amount << endl;
		return fout;
	}
	else //to file
	{
		fout << check.number << " " << check.date << " ";
		fout << check.pay_to << " " << check.amount << endl;
		return fout;
	}
}

check& check::operator = (const check &right_side)
{
	if (this!=&right_side)
	{
		number=right_side.number;
		date=right_side.date;
		pay_to=right_side.pay_to;
		amount=right_side.amount;
	}
	return *this;
}