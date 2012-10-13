// Name: Nathaniel Yarnell
// Date: 1/16/2012
// Description: This file contains the main function for Cities.cc

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Cities.h"
using namespace std;

int main()
{
string choice, name;
int pop;
double size;
Cities city1, city2, met;
int x=1;
	while (x==1)
	{
		cout<<"a - Enter data for City 1"<<endl;
		cout<<"b - Enter data for City 2"<<endl;
		cout<<"c - Add City 1 to the metropolis"<<endl;
		cout<<"d - Add City 2 to the metropolis"<<endl;
		cout<<"e - View the metropolis"<<endl;
		cout<<"f - Subtract City 1 from the metropolis"<<endl;
		cout<<"g - Subtract City 2 from the metropolis"<<endl;
		cout<<"h - Multiplty your metropolis by a decimal number"<<endl;
		cout<<"i - See the ratio of City 1 / City 2"<<endl;
		cout<<"j - Save the metropolis to a file"<<endl;
		cout<<"k - Retrieve the metropolis from a file"<<endl;
		cout<<"x - to exit"<<endl;
		cin>>choice;
		if (choice=="a")
		{
			cout<<"Enter a name, population as an integer, and area as a double ";
			cin>>city1;
		}
		if (choice=="b")
		{
			cout<<"Enter a name, population as an integer, and area as a double ";
			cin>>city2;
		}
		if (choice=="c")
		{
			met=met+city1;
		}
		if (choice=="d")
		{
			met=met+city2;
		}
		if (choice=="e")
		{
			cout<<met<<endl;
		}
		if (choice=="f")
		{
			met=met-city1;
		}
		if (choice=="g")
		{
			met=met-city2;
		}
		if (choice=="h")
		{
			cout<<"Enter a double to multiplty your metropolis by ";
			cin>>size;
			met=met*size;
		}
		if (choice=="i")
		{
			cout<<(city1.get_pop()/city2.get_pop())<<endl;
		}
		if (choice=="j")
		{
			ofstream out_stream;
			out_stream.open("data.txt");
			out_stream << met;
			out_stream.close();
		}
		if (choice=="k")
		{
			ifstream in_stream;
			in_stream.open("data.txt");
			in_stream >> met;
			in_stream.close();
		}
		if (choice=="x")
		{
		return 0;
		}
	}
}