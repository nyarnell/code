#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
  Pair p1(3,4), p2,p3;
 
  // testing the constructors
   cout<<"Testing the default constructor  -->  ";
   p2.display(cout);   
   cout << endl << endl;

  cout<<"Testing the constructor with 2 arguments  -->  ";
  p1.display(cout);
  cout << endl << endl;  
   
  // testing the set functions
    cout<<"Testing the set function   -- >  ";
  
  p2.set_first(-5); 
    
  p2.set_second(-10);
  
  p2.display(cout);

  cout << endl << endl;
 
 // testing the sum function
   
  cout<<" testing the sum function \n";

  p3 = sum(p1,p2); 

  p1.display(cout);
  cout<<" + ";
  p2.display(cout);
  cout<<" = ";
  p3.display(cout);
  cout << endl << endl;
   
  Pair p4,p5;
   

  cout<<" testing the read function \n";
  
  p4.read(cin);

  p4.display(cout);
    
  cout<<endl<<endl;
  
 return 0;
  
}

