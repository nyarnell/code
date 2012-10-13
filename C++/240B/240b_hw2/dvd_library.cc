// Name: Nathaniel Yarnell
// Date: 1/20/2012
// Description: This file contains the implementation of the class dvd_library.

#include <iostream>
#include <string>
#include <iomanip>
#include "dvd_library.h"
#include <fstream>
using namespace std;

//Constructors

dvd_library::dvd_library()
{
	//dvd library[MAX_LIBRARY_SIZE];
	used=0;
	dvd temp;
	ifstream in_stream;
	in_stream.open("data.txt");
	in_stream >> temp;
	while (! in_stream.eof())
	{
		//in_stream >> temp; //dvd object
		library[used].set_title(temp.get_title());
		library[used].set_rating(temp.get_rating());
		library[used].set_movie_type(temp.get_movie_type());
		library[used].set_year(temp.get_year());
		library[used].set_run_time(temp.get_run_time());
		used++;
		in_stream >> temp; //dvd object
	}
	in_stream.close();
	cout << "Loaded " << used << " movies from data.txt." << endl;
}

void dvd_library::insert_movie(string name, string score, string type, int date, int length)
{
	dvd tmp(name, score, type, date, length);
	library[used]=tmp;
	used++;
}

void dvd_library::display_movies()
{
	int i=0;
	while (i<used)
	{
		cout << library[i];
		i++;
	}
}

void dvd_library::display_ratings(string rating)
{
	int i=0;
	while (i<used)
	{
		if (library[i].get_rating()==rating)
		{
			cout << library[i];
		}
		i++;
	}
}

void dvd_library::search_movies(string name)
{
	int x=0, i=0;
	while (i<used && x==0)
	{
		if (library[i].get_title()==name)
		{
			cout << "Movie found." << endl;
			cout << library[i];
			x=1;
		}
		i++;
	}
	if (x==0)
	{
		cout << "Movie not found." << endl;
	}
}

void dvd_library::remove_movie(string name)
{
//Takes the last movie and inserts it where the movie to be deleted is.
//decrements used so that the movie at the end will be overwritten.
	int x=0, i=0;
	while (i<used && x==0)
	{
		if (library[i].get_title()==name)
		{
			library[i].set_title(library[used-1].get_title());
			library[i].set_rating(library[used-1].get_rating());
			library[i].set_movie_type(library[used-1].get_movie_type());
			library[i].set_year(library[used-1].get_year());
			library[i].set_run_time(library[used-1].get_run_time());
			used--;
			cout << "Movie removed" << endl;
			x=1;
		}
		i++;
	}
	if (x==0)
	{
		cout << "Movie not found" << endl;
	}
}

void dvd_library::output_movies()
{
	int i=0;
	ofstream out_stream;
	out_stream.open("data.txt");
	while (i<used)
	{
		out_stream << library[i];
		i++;
	}
	out_stream.close();
	cout << used << " movies written to data.txt." << endl;
}

void dvd_library::alphabetize_movies()
{
	int n=0, loc=0, i=0;
	string tmp;
	dvd temp;
	while (i < used)
	{
		tmp=library[i].get_title(); //tmp gets i's title
		loc=i;
		n=i+1;
		while (n < used)
		{
			if (library[n].get_title()<tmp) // lower than candidate tmp
			{
				tmp=library[n].get_title();
				loc=n; //stores the location of the dvd object with the
			}		   //lowest alphabetical title
			n++;
		}
		//cout << tmp << " is lowest, set to " << i << endl;
		//who needs an overloaded =
		//cout << "temp gets " << i << endl;
		temp.set_title(library[i].get_title());
		temp.set_rating(library[i].get_rating());
		temp.set_movie_type(library[i].get_movie_type());
		temp.set_year(library[i].get_year());
		temp.set_run_time(library[i].get_run_time());
		//cout << i << " gets " << loc << endl;
		library[i].set_title(library[loc].get_title());
		library[i].set_rating(library[loc].get_rating());
		library[i].set_movie_type(library[loc].get_movie_type());
		library[i].set_year(library[loc].get_year());
		library[i].set_run_time(library[loc].get_run_time());
		//cout << loc << " gets temp" << endl;
		library[loc].set_title(temp.get_title());
		library[loc].set_rating(temp.get_rating());
		library[loc].set_movie_type(temp.get_movie_type());
		library[loc].set_year(temp.get_year());
		library[loc].set_run_time(temp.get_run_time());
		i++; //we assume i now has the dvd obj. with the lowest movie title
	}
	
}

void dvd_library::sort_years()			//quick and dirty, but I only had
{										//to change two calls.
	int n, tmp, loc=0, i=0;				//wonderfully inefficient
	dvd temp;
	while (i < used)
	{
		tmp=library[i].get_year();
		loc=i;
		n=i+1;
		while (n < used)
		{
			if (library[n].get_year()<=tmp)
			{
				tmp=library[n].get_year();
				loc=n; //stores the location of the dvd object with the
			}		   //lowest alphabetical genre
			n++;
		}
		//cout << tmp << " is lowest, set to " << i << endl;
		//who needs an overloaded =
		//cout << "temp gets " << i << endl;
		temp.set_title(library[i].get_title());
		temp.set_rating(library[i].get_rating());
		temp.set_movie_type(library[i].get_movie_type());
		temp.set_year(library[i].get_year());
		temp.set_run_time(library[i].get_run_time());
		//cout << i << " gets " << loc << endl;
		library[i].set_title(library[loc].get_title());
		library[i].set_rating(library[loc].get_rating());
		library[i].set_movie_type(library[loc].get_movie_type());
		library[i].set_year(library[loc].get_year());
		library[i].set_run_time(library[loc].get_run_time());
		//cout << loc << " gets temp" << endl;
		library[loc].set_title(temp.get_title());
		library[loc].set_rating(temp.get_rating());
		library[loc].set_movie_type(temp.get_movie_type());
		library[loc].set_year(temp.get_year());
		library[loc].set_run_time(temp.get_run_time());
		i++; //we assume i now has the dvd obj. with the lowest release date
	}
}

void dvd_library::sort_movie_types()		//quick and dirty, but I only had
{											//to change two calls.
	int n, loc=0, i=0;						//wonderfully inefficient
	string tmp;
	dvd temp;
	while (i < used)
	{
		tmp=library[i].get_movie_type();
		loc=i;
		n=i+1;
		while (n < used)
		{
			if (library[n].get_movie_type()<tmp)
			{
				tmp=library[n].get_movie_type();
				loc=n; //stores the location of the dvd object with the
			}		   //lowest alphabetical genre
			n++;
		}
		//cout << tmp << " is lowest, set to " << i << endl;
		//who needs an overloaded =
		//cout << "temp gets " << i << endl;
		temp.set_title(library[i].get_title());
		temp.set_rating(library[i].get_rating());
		temp.set_movie_type(library[i].get_movie_type());
		temp.set_year(library[i].get_year());
		temp.set_run_time(library[i].get_run_time());
		//cout << i << " gets " << loc << endl;
		library[i].set_title(library[loc].get_title());
		library[i].set_rating(library[loc].get_rating());
		library[i].set_movie_type(library[loc].get_movie_type());
		library[i].set_year(library[loc].get_year());
		library[i].set_run_time(library[loc].get_run_time());
		//cout << loc << " gets temp" << endl;
		library[loc].set_title(temp.get_title());
		library[loc].set_rating(temp.get_rating());
		library[loc].set_movie_type(temp.get_movie_type());
		library[loc].set_year(temp.get_year());
		library[loc].set_run_time(temp.get_run_time());
		i++; //we assume i now has the dvd obj. with the lowest movie rating
	}
	
}