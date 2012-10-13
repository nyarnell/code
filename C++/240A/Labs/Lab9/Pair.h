//***************************************************************************
// File:    Pair.h
// Purpose: A sample class that demonstrates class concepts
// Author:  Nathaniel Yarnell
// Date:    3/1/2011
//***************************************************************************

//*********************************************************
// Function: Pair
// Purpose:  Constructor initializes first to f and second to s 
// Params:   f - first
//           s - second
// Calls:    none
// Uses:     none
//*********************************************************
//Pair::Pair(int f, int s);
//*********************************************************
// Function: Pair
// Purpose:  Constructor initializes first and second to 0
// Params:   none
// Calls:    none   
// Uses:     none
//*********************************************************
//DayOfYear::Pair();
//*********************************************************************
// Function: set_first
// Purpose:  sets the value of the first variable to f
// Params:   int f
// Calls:    none
// Uses:     none
//*********************************************************************
//void Pair::set_first(int f);
//*********************************************************************
// Function: set_second
// Purpose:  sets the value of the second variable to s
// Params:   int s
// Calls:    none
// Uses: none
//*
//void Pair::set_second(int s);
//*
// Function: get_first
// Purpose: returns the value of first
// Params: none
// Calls: none
// Uses: none
//*
//void Pair::get_first();
//*
// Function: get_second
// Purpose: returns the value of second
// Params: none
// Calls: none
// Uses: none
//*
//void Pair::get_second();
//*
// Function: display
// Purpose: displays the value of an object
// Params: ostream& outp
// Calls: <iostream>, namespace std;
// Uses:
//*
//void display (ostream& outp);
//*
// Function: read
// Purpose: gets two variables from the keyboard and assigns them
// Params: istream& fin
// calls: <iostream>, namespact std;
// uses: none
//*
// void read (istream& fin);
//*
// Function: sum
// Purpose: adds two Pair objects
// Params: Pair p1, Pair p2
// Calls: none
// uses: none
//*
//Pair sum (Pair p1, Pair p2);
//I love writing comments all day.

#include <iostream>
using namespace std;

class Pair
{
  public:
    // constructors
    Pair(int f, int s);
    Pair();

   // mutator

   void set_first(int f);
   void set_second(int s);


  // accessor
    int get_first() const;
    int get_second() const;

  void display(ostream& outp);
  void read(istream& fin);


 private:
   int first;
   int second;
};
Pair sum(Pair p1, Pair p2);

