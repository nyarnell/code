//
// program: prog5.cc
// Name: Nathaniel Yarnell
// Email: nathanielbyarnell@gmail.com
//
// Description: This program converts fahrenheit temperatures to celsius,
//  and celsius temperatures to fahrenheit
//
// Date: 1/12/11
//

#include <iostream>
using namespace std;

int main()
{
   double ctof;  // equivalent Celsius temperature
   double ftoc;  // equivalent Fahrenheit temperature.
 
   double fah = 56;  //declare and initialize at the same time - page 48
   double cel = 20;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);

   ctof = (9.0/5.0 * (cel + 32));
   ftoc = (5.0/9.0 * (fah - 32));

   cout << cel << " in Fahrenheit is " << ctof << endl;
   cout << fah << " in Celsius is " << ftoc << endl;

   return (0);
}
