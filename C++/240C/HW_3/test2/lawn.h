#ifndef LAWN_H
#define LAWN_H

#include <iostream>
#include <string>

using namespace std;

class Lawn{

	public:
		Lawn(); //default constructor

		int get_street_num() const{ return street_num; }
		string get_street() const{ return street; }
		double get_x_coord() const{ return x_coord; }
		double get_y_coord() const{ return y_coord; }
		int get_length() const{ return length; }
		int get_width() const{ return width; }
		double get_income() const{ return income; }
		double get_height() const{ return height; }
		double get_area() const{ return length*width; }
		double get_home_distance() const{ return home_distance; }

		void set_street_num(int n){ street_num = n; }
		void set_street(string s){street = s; }
		void set_x_coord(double x){ x_coord = x; }
		void set_y_coord(double y){ y_coord = y; }
		void set_length(int l){ length = l; }
		void set_width(int w){ width = w; }
		void set_income(double i){ income = i; }
		void set_height(double h){ height = h; }

		friend ostream& operator << (ostream& outs, const Lawn& lawn);
		friend istream& operator >> (istream& ins, Lawn& lawn);
		bool operator < (const Lawn &other) const;
		bool operator == (const Lawn &other) const;
		bool operator != (const Lawn &other) const;
		Lawn operator = (const Lawn &rhs);

  
	
	private:
		int street_num;
		string street;
		double x_coord, y_coord;
		int length, width;
		double income;
		double height;
		double home_distance;

};

#endif

