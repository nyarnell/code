// Name: Nathaniel Yarnell
// Date: 1/20/2012
// Description: This file contains the interface of the class dvd.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class dvd
{
	public:
		dvd();
		dvd(string name, string score, string type, int date, int length);
		void set_title(string name);
		void set_rating(string score);
		void set_movie_type(string type);
		void set_year(int date);
		void set_run_time(int length);
		string get_title();
		string get_rating();
		string get_movie_type();
		int get_year();
		int get_run_time();
		friend istream& operator >> (istream& fin, dvd& dvd);
		friend ostream& operator << (ostream& fout, const dvd& dvd);
	private:
		string title;
		string rating;
		string movie_type;
		int year;
		int run_time;
};