//Name: Nathaniel Yarnell
//This is the implementation file fo the Class Pair.cc
#include <iostream>
#include "Pair.h"
using namespace std;

Pair::Pair(int f, int s)
{
  first = f;
  second = s;

}
  
Pair::Pair(): first(0),second(0)
{
}

void Pair:: set_first(int f)
{
  first = f;
}

void Pair::set_second(int s)
{
  second = s;
}

int Pair::get_first() const
{
  return first;
}

int Pair::get_second()const
{
  return second;
}


void Pair::display(ostream& outp)
{
  outp << "("<<first<<","<<second<<")";
}


void Pair :: read (istream& fin)
{
  char ch;  

  cout <<" Enter a pair in the follwoing format (2,3)  ";
  fin >> ch             // reads ( and discards it
      >>first       // reads the first value of the pair
      >>ch            // reads the comma
      >> second   // reads the second value of the pair
      >> ch;         // reads the ) and discards it;
 
}


Pair  sum(Pair p1, Pair p2)
{
  // need to use the accessor and the mutator functions b/c
  // sum is a non member function 

  Pair temp;
  temp.set_first( p1.get_first() + p2.get_first());
  temp.set_second ( p1.get_second() + p2.get_second());
 
  return(temp);
} 

    
