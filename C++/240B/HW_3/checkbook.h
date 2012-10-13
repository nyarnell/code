// Name: Nathaniel Yarnell
// Date: 2/1/2012
// Description: This file contains the interface of the class checkbook.

#include "check.h"

using namespace std;

class checkbook
{
	public:
		checkbook();
		checkbook(const checkbook& copy); 
		~checkbook();
		int get_written();
		void deposit(double amount, Date date);
		void write_check(check& check);
		void display_checks();
		void display_record();
		void search_checks(string name);
		void sort_stuff(string method);
		void output_checks();
		void output_record();
		checkbook& operator = (const checkbook& right_side);
	private:
		double *deposits;
		Date *dates;
		check *ptr;
		int size;
		int written;
		int written_records;
		double balance;
		void resize_checkbook();
		void resize_deposits();
		void resize_dates();
};