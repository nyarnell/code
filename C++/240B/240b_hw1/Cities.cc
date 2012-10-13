// Name: Nathaniel Yarnell
// Date: 1/16/2012
// Description: This file contains the implementation of the class Cities.

#include <iostream>
#include <string>
#include <iomanip>
#include "Cities.h"
#include <fstream>
using namespace std;

Cities::Cities(string name, int pop, double size)
{
	city=name;
	population=pop;
	area=size;
}

Cities::Cities(): city(""), population(0), area(0.0) {}

void Cities::set_name(string name)
{
	city=name;
}

void Cities::set_pop(int pop)
{
	population=pop;
}

void Cities::set_area(double size)
{
	area=size;
}

string Cities::get_name() const
{
	return city;
}

int Cities::get_pop() const
{
	return population;
}

double Cities::get_area() const
{
	return area;
}

double Cities::get_pop_density()
{
	double ratio;
	ratio = population/area;
	return ratio;
}

Cities Cities::operator + (const Cities& city2)
{
	Cities temp;
	if (city=="")
	{
		temp.city = city2.get_name();
	}
	else
	{
		temp.city = city + " " + city2.get_name();
	}
	temp.population = population + city2.get_pop();
	temp.area = area + city2.get_area();
	return temp;
}

double Cities::operator / (const Cities& city2)
{
	double ratio;
	ratio = population/city2.get_pop();
	return ratio;
}

Cities Cities::operator * ( double mult)
{
	Cities temp;
	temp.city = city;
	temp.population = population*mult;
	temp.area = area*mult;
	return temp;
}

bool Cities::operator > (const Cities& city2)
{
	return population > city2.get_pop();
}

bool Cities::operator < (const Cities& city2)
{
	return population < city2.get_pop();
}

Cities Cities::operator - (const Cities& city2)
{
	Cities temp;
	if (city.find(city2.get_name())>=0)
	{
		temp.city = city.erase(city.find(city2.get_name()), city2.get_name().length());
	}
	else
	{
		temp.city = city + " - " + city2.get_name();
	}
	temp.population = population - city2.get_pop();
	temp.area = area - city2.get_area();
	return temp;
}

istream& operator >> (istream& fin, Cities& city)
{
	//string temp;
	//getline(fin, temp);
	//city.area=double(temp.substr(temp.find("area:")+6, temp.length()-temp.find("area:")+6));
	//city.population=int(temp.substr(temp.find("population:")+12, temp.find("area:")-2));
	//city.city=temp.substr(0, temp.find("population")-2);
	fin >> city.city >> city.population >> city.area;
	return fin;
}

ostream& operator << (ostream& fout, const Cities& city)
{
	fout << city.get_name() << " population: " << city.get_pop() << " area: " << city.get_area();
	return fout;
}