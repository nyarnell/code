// Name: Nathaniel Yarnell
// Date: 2/1/2012
// Description: This file contains the implementation of the class checkbook.

#include <iostream>
#include "checkbook.h"
#include <fstream>
#include <string>

using namespace std;

//Contsructors
checkbook::checkbook()
{
	written=0, size=5, written_records=0;
	double deposit;
	Date date;
	ptr=new check[size];
	check temp;
	ifstream in_stream;
	in_stream.open("data.txt");
	in_stream >> balance; // first item in data file
	in_stream >> temp;
	while (! in_stream.eof())
	{
		if (written==size)
		{
			resize_checkbook();
		}
		ptr[written]=temp;
		written++;
		in_stream >> temp;
	}
	in_stream.close();
	deposits=new double[size];
	dates=new Date[size];
	in_stream.open("record.txt");
	in_stream >> date;
	while (! in_stream.eof())
	{
		if (written_records==size)
		{
			resize_deposits();
			resize_dates();
		}
		dates[written_records]=date;
		in_stream >> deposit; //they come in pairs, so we don't worry about eof
		deposits[written_records]=deposit;
		written_records++;
		in_stream >> date;
	}
	in_stream.close();
}

//Copy constructor
checkbook::checkbook(const checkbook& copy)
{
	size=copy.size;
	written=copy.written;
	balance=copy.balance;
	ptr=new check[size];
	for (int i=0; i<written; i++)
	{
		ptr[i]=copy.ptr[i];
	}
}

//Destructor
checkbook::~checkbook()
{
	delete[]ptr;
	delete[]deposits;
	delete[]dates;
}

int checkbook::get_written()
{
	return written;
}
void checkbook::deposit(double amount, Date date)
{
	balance+=amount;
	if (written_records==size)
		{
			resize_deposits();
			resize_dates();
		}
	dates[written_records]=date;
	deposits[written_records]=amount;
	written_records++;
	cout << "Account balance: $" << balance << endl;
}

void checkbook::write_check(check& check)
{
	if (written==size)
		{
			resize_checkbook();
		}
	ptr[written]=check;
	balance-=check.get_amount();
	written++;
}

void checkbook::display_checks()
{
	for (int i=0; i<written; i++)
	{
		cout << ptr[i] << endl;
	}
	cout << "Account balance: $" << balance << endl;
}

void checkbook::display_record()
{
	for (int i=0; i<written_records; i++)
	{
		cout << "Date: " << dates[i] << " - $" << deposits[i] << endl;
	}
}

void checkbook::search_checks(string name)
{
	for (int i=0; i<written; i++)
	{
		if (ptr[i].get_pay_to()==name)
		{
			cout << ptr[i] << endl;
		}
	}
}

void checkbook::sort_stuff(string method)
{
	check temp;
	int j, lownum;
	if (method=="name")
	{
		string low;
		for (int i=0; i<written; i++)
		{
			low=ptr[i].get_pay_to();
			lownum=i;
			//cout << "low is " << low << endl;
			for (j=i+1; j<written; j++)
			{
				//cout << written << " " << j << " " << size << endl;
				if (ptr[j].get_pay_to()<low)
				{
					//cout << ptr[j].get_pay_to() << " is lower than " << low;
					low=ptr[j].get_pay_to();
					lownum=j;
				}
			}
			//cout << i << " gets " << ptr[lownum].get_pay_to();
			temp=ptr[i];
			ptr[i]=ptr[lownum];
			ptr[lownum]=temp;
		}
	}
	if (method=="number")
	{
		int low;
		for (int i=0; i<written; i++)
		{
			low=ptr[i].get_number();
			lownum=i;
			//cout << "low is " << low << endl;
			for (j=i+1; j<written; j++)
			{
				//cout << written << " " << j << " " << size << endl;
				if (ptr[j].get_number()<low)
				{
					//cout << ptr[j].get_pay_to() << " is lower than " << low;
					low=ptr[j].get_number();
					lownum=j;
				}
			}
			//cout << i << " gets " << ptr[lownum].get_pay_to();
			temp=ptr[i];
			ptr[i]=ptr[lownum];
			ptr[lownum]=temp;
		}
	}
	if (method=="amount")
	{
		double low;
		for (int i=0; i<written; i++)
		{
			low=ptr[i].get_amount();
			lownum=i;
			//cout << "low is " << low << endl;
			for (j=i+1; j<written; j++)
			{
				//cout << written << " " << j << " " << size << endl;
				if (ptr[j].get_amount()<low)
				{
					//cout << ptr[j].get_pay_to() << " is lower than " << low;
					low=ptr[j].get_amount();
					lownum=j;
				}
			}
			//cout << i << " gets " << ptr[lownum].get_pay_to();
			temp=ptr[i];
			ptr[i]=ptr[lownum];
			ptr[lownum]=temp;
		}
	}
	if (method=="date")
	{
		Date low;
		for (int i=0; i<written; i++)
		{
			low=ptr[i].get_date();
			lownum=i;
			//cout << "low is " << low << endl;
			for (j=i+1; j<written; j++)
			{
				//cout << written << " " << j << " " << size << endl;
				if (ptr[j].get_date()<low)
				{
					//cout << ptr[j].get_pay_to() << " is lower than " << low;
					low=ptr[j].get_date();
					lownum=j;
				}
			}
			//cout << i << " gets " << ptr[lownum].get_pay_to();
			temp=ptr[i];
			ptr[i]=ptr[lownum];
			ptr[lownum]=temp;
		}
	}
}

void checkbook::output_checks()
{
	ofstream out_stream;
	out_stream.open("data.txt");
	out_stream << balance << " ";
	for (int i=0; i<written; i++)
	{
		out_stream << ptr[i];
	}
	out_stream.close();
}

void checkbook::output_record()
{
	ofstream out_stream;
	out_stream.open("record.txt");
	for (int i=0; i<written_records; i++)
	{
		out_stream << dates[i] << " " << deposits[i] << endl;
	}
	out_stream.close();
}

checkbook& checkbook::operator = (const checkbook &right_side)
{
	if (this!=&right_side)
	{
		for (int i=0; i<written; i++)
		{
			ptr[i]=right_side.ptr[i];
		}
		size=right_side.size;
		written=right_side.written;
		balance=right_side.balance;
	}
	return *this;
}

void checkbook::resize_checkbook()
{
	check *tmpptr;
	size+=5;
	tmpptr = new check[size];
	for (int i=0; i<written; i++)
	{
		tmpptr[i]=ptr[i];
	}
	ptr=tmpptr;
	//delete[]tmpptr;
}

void checkbook::resize_dates()
{
	Date *tmpptr;
	size+=5;
	tmpptr = new Date[size];
	for (int i=0; i<written_records; i++)
	{
		tmpptr[i]=dates[i];
	}
	dates=tmpptr;
	//delete[]tmpptr;
}

void checkbook::resize_deposits()
{
	double *tmpptr;
	size+=5;
	tmpptr = new double[size];
	for (int i=0; i<written_records; i++)
	{
		tmpptr[i]=deposits[i];
	}
	deposits=tmpptr;
	//delete[]tmpptr;
}