// Name: Nathaniel Yarnell
// Date: 1/16/2012
// Description: This file contains the interface of the class Cities

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Cities
{
	public:
		Cities();
		Cities(string name, int pop, double size);
		void set_name(string name);
		void set_pop(int pop);
		void set_area(double size);
		string get_name() const;
		int get_pop() const;
		double get_area() const;
		double get_pop_density();
		Cities operator + (const Cities& city2);
		double operator / (const Cities& city2);
		Cities operator * (double mult);
		bool operator > (const Cities& city2);
		bool operator < (const Cities& city2);
		Cities operator - (const Cities& city2);
		friend istream& operator >> (istream& fin, Cities& city);
		friend ostream& operator << (ostream& fout, const Cities& city);
	private:
		string city;
		int population;
		double area;
};