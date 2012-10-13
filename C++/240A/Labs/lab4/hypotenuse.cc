//
// Program Name: Hypotenuse
//
// Name: Nathaniel Yarnell
// Email: nathanielbyarnell@gmail.com
//
// Description: This program demonstrates the use of predefined math functions
// and user-defined functions to calculate the length of the hypotenuse of a right triangle
//
// Date: 1/26/11
//

#include <iostream>
#include <cmath>
using namespace std;

double hypotenuse(double leg1_par, double leg2_par);
//Function Name: Hypotenuse
//Purpose: This function takes two inputs: the shortest legs of a right triangle, and
//calculates the hypotenuse
//Parameters: leg1_par, leg2_par
//Calls: 1

int main()
{
  double leg1, //One of the legs of a right triangle
         leg2; //Another legs of a right triangle!!!
    
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "Enter the 2 sides of a right triangle ";
  cin >> leg1 >> leg2;
  cout << "\nThe hypotenuse of a right triangle with the sides " << leg1 << " and " 
       << leg2 << " is " << hypotenuse (leg1, leg2) << endl;
return 0;
}

double hypotenuse(double leg1_par, double leg2_par)
{
  double leg3_par; //hypotenuse
  leg3_par = pow(leg1_par,2) + pow(leg2_par,2);
  leg3_par = sqrt(leg3_par);
  return (leg3_par);
}

