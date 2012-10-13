//***************************************************************************
// File:    DayOfYear.h
// Purpose: A sample class that manages month and day.
// Author:  walter Savitch 
// Date:    02/20/11
//***************************************************************************

#include <iostream>
using namespace std;
//*********************************************************
// Function: DayOfYear
// Purpose:  Constructor initializes the month to new_month
//           day to new_day
// Params:   new_month - the value for the month
//           new_day  - the value for the day
// Calls:    none
// Uses:     none  
//*********************************************************
//DayOfYear::DayOfYear(int new_month, int new_day);
//*********************************************************
// Function: DayOfYear
// Purpose:  Constructor initializes the month and day to 0
// Params:   none
// Calls:    none
// Uses:     none
//*********************************************************
//DayOfYear::DayOfYear()
//*********************************************************************
// Function: input
// Purpose:  reads and stores a month and day from fin. if fin is a input
//           stream, then fin is already connected to a file.
// Params:   fin -- the input stream
// Calls:    none
// Uses:     istream
//*********************************************************************
//void DayOfYear:: input(istream& fin);
//*********************************************************************
// Function: output 
// Purpose:  display the month and day on fout. if fout is a  output stream
//           then fout is already  connected to a file
// Params:   fout -- the output stream
// Calls:    none
// Uses:     ostream
//*********************************************************************
//void DayOfYear::output(ostream& fout);
//********************************************************* 
// Function: get_month 
// Purpose:  returns the month 
// Params:   none 
// Calls:    none
// Uses:     none
//*********************************************************
// int DayOfYear::get_month()
//********************************************************* 
// Function: get_day 
// Purpose:  returns the day
// Params:   none 
// Calls:    none
// Uses:     none
//*********************************************************
// int DayOfYear::get_day()
//********************************************************* 
// Function: equal 
// Purpose:  returns true if the month and the day is
//           equal, false otherwise 
// Params:   d1 and d2 are the objects to compare 
// Calls:    get_month and get_day
// Uses:     none
//*********************************************************
// bool equal(DayOfYear d1,  DayOfYear d2);

class DayOfYear
{
  public:

     DayOfYear(int new_month, int new_day);
     //constructor

     DayOfYear();
     // default constructor;

     void input(istream& inp);
     void output(ostream& outp);
     
     int get_month();
     int get_day();


  private:
     int month;
     int day;

};

bool equal(DayOfYear d1,  DayOfYear d2); 

