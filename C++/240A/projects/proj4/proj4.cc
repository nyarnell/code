//
// Program Name: proj4 - Euclid's Number
//
// Name: Nathaniel Yarnell
// Email: nathanielbyarnell@gmail.com
//
// Description: This program streams a list of numbers from gcd.dat,
// finds the greatest common divisor (gcd) of the two numbers, and
// outputs them to a file named gcd.out.
//
// Date: 2/8/2011
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void calculate_gcd(int num1, int num2, ofstream& fout);
//Function Name: calculate_gcd
//Purpose: This function accepts two positive whole integers and
//calculates their greatest common denominator, then outputs it to
//the command line.
//Paramters: big, small, fout
//Calls: none

int main()
{
  ifstream fin;
  ofstream fout;

  fin.open("gcd.dat");
  if (fin.fail())
  {
    cout<<"Input file opening failed.\n";
    exit(1);
  }

  fout.open("gcd.out");
  if (fout.fail())
  {
    cout<<"Output file opening failed.\n";
    exit(1);
  }
  int num1, num2;
  while (fin>>num1>>num2)
  {
    if (num1>num2)
      calculate_gcd(num1, num2, fout);
    else
      calculate_gcd(num2, num1, fout);
  }
  fin.close();
  fout.close();
}

void calculate_gcd(int num1, int num2, ofstream& fout)
{
  int r,
      big = num1,
      small = num2;
  do {
    r = big%small;
    if (r==0)
      {  
        fout<<small<<" is the Greatest Common Divisor of "
            <<num1<<" and "<<num2<<"."<<endl;
      }
      big = small;
      small = r;
  }while (r != 0);
}
