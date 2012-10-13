// Name: Nathaniel Yarnell
// Date: 2/1/2012
// Description: This file contains the interface of the class check.

#include <iostream>
#include "date.h"
using namespace std;

class check
{
	public:
		check();
		check(int& num, Date& day, string& pay, double& dollars);
		void set_number(int num);
		void set_date(Date& day);
		void set_pay_to(string& pay);
		void set_amount(double& dollars);
		int get_number();
		Date get_date();
		string get_pay_to();
		double get_amount();
		friend istream& operator >> (istream& fin, check& check);
		friend ostream& operator << (ostream& fout, check& check);
		check& operator = (const check& right_side);
	private:
		int number;
		Date date;
		string pay_to;
		double amount;
};