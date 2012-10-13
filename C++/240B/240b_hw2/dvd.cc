// Name: Nathaniel Yarnell
// Date: 1/20/2012
// Description: This file contains the implementation of the class dvd.

#include <iostream>
#include <string>
#include <iomanip>
#include "dvd.h"
#include <fstream>
using namespace std;

//Contsructors

dvd::dvd(): title(""), rating(""), movie_type(""), year(0), run_time(0) {}

dvd::dvd(string name, string score, string type, int date, int length)
{
	title=name;
	rating=score;
	movie_type=type;
	year=date;
	run_time=length;
}

//Mutator functions

void dvd::set_title(string name)
{
	title=name;
}

void dvd::set_rating(string score)
{
	rating=score;
}

void dvd::set_movie_type(string type)
{
	movie_type=type;
}

void dvd::set_year(int date)
{
	year=date;
}

void dvd::set_run_time(int length)
{
	run_time=length;
}

//Accessor functions

string dvd::get_title()
{
	return title;
}

string dvd::get_rating()
{
	return rating;
}

string dvd::get_movie_type()
{
	return movie_type;
}

int dvd::get_year()
{
	return year;
}

int dvd::get_run_time()
{
	return run_time;
}

//Overloaded input/output functions

istream& operator >> (istream& fin, dvd& dvd)
{
	fin >> dvd.title >> dvd.rating >> dvd.movie_type >> dvd.year >> dvd.run_time;
	return fin;
}

ostream& operator << (ostream& fout, const dvd& dvd)
{
	if (fout==cout)
	{
		fout << "Title: " << dvd.title << endl;
		fout << "Rating: " << dvd.rating << endl;
		fout << "Genre: " << dvd.movie_type << endl;
		fout << "Release Date: " << dvd.year << endl;
		fout << "Length: " << dvd.run_time << " minutes" << endl;
		fout << endl;
		return fout;
	}
	else
	{
		fout << dvd.title << " " << dvd.rating << " " << dvd.movie_type << " ";
		fout << dvd.year << " " << dvd.run_time << endl;
		return fout;
	}
}