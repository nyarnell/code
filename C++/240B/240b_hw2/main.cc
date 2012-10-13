// Name: Nathaniel Yarnell
// Date: 1/16/2012
// Description: This file contains the main function for the class dvd_library

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "dvd_library.h"
using namespace std;

int main()
{
	int x=1;
	string name, score, type, choice;
	int date, length;
	dvd_library collection; //input from file
	while(x==1)
	{
		cout << "------------------------" << endl;
		cout << "a - insert an additional movie." << endl;
		cout << "b - remove a movie that has become lost or destroyed." << endl;
		cout << "c - display all movies." << endl;
		cout << "d - display movies organized by type." << endl;
		cout << "e - display all the movies of a certain rating." << endl;
		cout << "f - search for movie by title." << endl;
		cout << "g - sort and disaply all movies alphabetically by title." << endl;
		cout << "h - sort and display all movies by the year made." << endl;
		cout << "x - enter x to exit." << endl;
		cout << "------------------------" << endl;
		cin >> choice;
		cout << endl;
		if (choice=="a") //insert an additional movie
		{
			cout << "Enter the movie's title with underscores for spaces: ";
			cin >> name;
			cout << "Enter the movie's rating: ";
			cin >> score;
			cout << "Enter the movie's genre: ";
			cin >> type;
			cout << "Enter the movie's release date: ";
			cin >> date;
			cout << "Enter the movie's length in minutes: ";
			cin >> length;
			collection.insert_movie(name, score, type, date, length);
		}
		if (choice=="b") //remove a movie that has become lost or destroyed
		{
			cout << "Enter the title of the movie you would like to remove: ";
			cin >> name;
			collection.remove_movie(name);
		}
		if (choice=="c") //display all movies
		{
			collection.display_movies();
		}
		if (choice=="d") //display movies organized by type
		{
			collection.sort_movie_types();
			collection.display_movies();
		}
		if (choice=="e") //display all movies of a certain rating
		{
			cout << "Enter a rating to search for: ";
			cin >> score;
			collection.display_ratings(score);
		}
		if (choice=="f") //search for a movie by title
		{
			cout << "Enter a movie title to search for: ";
			cin >> name;
			collection.search_movies(name);
		}
		if (choice=="g")//sort and display all movies alphabetically by title
		{
			collection.alphabetize_movies();
			collection.display_movies();
		}
		if (choice=="h")//search and display all movies by the year made
		{
			collection.sort_years();
			collection.display_movies();
		}
		if (choice=="x") //output to file
		{
			collection.output_movies();
			return 0;
		}
	}
}