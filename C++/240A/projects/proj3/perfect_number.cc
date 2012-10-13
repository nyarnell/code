//
// Program Name: Perfect Number
//
// Name: Nathaniel Yarnell
// Email: nathanielbyarnell@gmail.com
//
// Description: This program accepts integer input and then evaluates those integers
// to determine if they are 'perfect' numbers - equal to the sum of its perfect divsors.
//
// Date: 1/27/2011
//

#include <iostream>
using namespace std;

int sum_of_divisors(int num_par);
//Function Name: sum_of_divosors
//Purpose: This function accepts an integer
//and returns the sum of its perfect divisors.
//Paramters: num_par
//Calls: none

void get_number(int& num_par);
//Function Name: get_number
//Purpose: This function prompts the user for
//input and stores a value
//Parameters: num_par 
//Calls: none

void output_results(int num_par, int num);
//Function Name: output_results
//Purpose: This function calls sum_of_divisors, and then
//outputs the result to the command line
//Parameters: num_par, num
//Calls: none

int main()
{
  int num = 0; //initialize to avoid junk value
  do {
     get_number(num);
     if (num == -1)
       {
         return 0;
       }
     output_results(num, num);
     } while (num != -1);      //This code is necessary for the loop
}                              //statement but not for the program.
                               //Just to keep it looping.
void get_number(int& num_par)
{ 
  cout << "Enter a positive integer or -1 to exit" << endl;
  cin >> num_par; 
}

void output_results(int num_par, int num)
{
  if (sum_of_divisors(num_par) == num)
    cout << num << " is a perfect number" << endl;
  else
    cout << num << " is not a perfect number" << endl;
}

int sum_of_divisors(int num_par)
{     
  int sum = 0;
  for (int n=1; n<num_par; n++)
  {
    if (num_par%n==0)
    {
      sum+=n;
    }
  }
  return (sum);
}
