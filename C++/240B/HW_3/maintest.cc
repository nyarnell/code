// Name: Nathaniel Yarnell
// Date: 1/16/2012
// Description: This file contains the main function for the class dvd_library

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "check.h"
using namespace std;

int main()
{
	int num, dubs;
	string pay;
	double dollars;
	Date day;
	check test3, temp, temp2;
	ofstream out_stream;
	ifstream in_stream;
	in_stream.open("data.txt");
	in_stream >> temp;
	in_stream >> temp2;
	cout << temp;
	cout << temp2;
	in_stream.close();
	out_stream.open("data.txt");
	cout << "num: ";
	cin >> num;
	cout << "pay_to: ";
	cin >> pay;
	cout << "dollars: ";
	cin >> dollars;
	cout << "m/d/y: ";
	cin >> day;
	check test(num, day, pay, dollars);
	cout << test;
	check test2;
	cin >> test2;
	cout << test2;
	out_stream << test << test2 << test3;
	out_stream.close();

}