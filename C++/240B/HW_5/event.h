// Name: Nathaniel Yarnell
// Date: 3/7/2012
// Description: This file contains the interface of the class Event

#include <iostream>
#include "date.h"

using namespace std;

class event
{
	public:
		event();
		Date get_date() {return date;}
		string get_name() {return name;}
		void set_date(Date& newdate) {date=newdate;}
		void set_name(string& newname) {name=newname;}
		friend istream& operator >> (istream& fin, event& event);
		friend ostream& operator << (ostream& fout, event& event);
	private:
		Date date;
		string name;
};