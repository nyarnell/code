// Name: Nathaniel Yarnell
// Date: 1/20/2012
// Description: This file contains the interface of the class dvd_library.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "dvd.h"
using namespace std;

class dvd_library
{
	public:
		dvd_library();
		void insert_movie(string name, string score, string type, int date, int length);
		void display_movies();
		void display_ratings(string rating);
		void search_movies(string name);
		void remove_movie(string name);
		void output_movies();
		void alphabetize_movies();
		void sort_movie_types();
		void sort_years();
	private:
		dvd library[200]; //an array called library of type dvd
		int used; //as used in this class, used represents the next open
				  //space in the array, or the number of spaces used + 1.
				  //This distinction is important to remember.
};
