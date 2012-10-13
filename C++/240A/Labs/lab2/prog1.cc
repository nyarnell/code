// 
//  program: prog1.cc
//  Name: Nathaniel Yarnell
//  Email: nathanielbyarnell@gmail.com
//
//  Description: This program adds and multiplies two integers INT1 and INT2,
//  and then returns to the command line which is bigger
// 
//  Date: 1/12/11
//

#include<iostream> 
using namespace std;

const int INT1 = 15; //First integer
const int INT2 = 20; //Second integer

int main()
{
  cout << "Sum of " << INT1 << " and " << INT2 << " is " << INT1+INT2 << endl;
  cout << "Product is " << INT1*INT2 << endl;
   
  if (INT1<INT2)
    cout << "INT2 is bigger" << endl;
  else
    cout << "INT1 is bigger" << endl;

  return (0);
}


