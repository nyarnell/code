
//* * * * * * * * * * * * * * * * * * * *
// program:  First program - candy_bars
//
// Author:   Walter Savitch
//
// Email - 
//
// Lab section - 
//
// Description -  This program inputs the
//                number of candy bars and
//                weight of one bar. The program
//                calculates the total weight.
//      
//* * * * * * * * * * * * * * * * * * * * * *

#include <iostream>
using namespace std;

int main()
{
  int number_of_bars;     // number of candy bars
  double one_weight;      // weight of one candy bar
  double total_weight;    // total weight of all the bars


  cout << " Enter the number of candy bars in a package and press enter  ";
  cin  >> number_of_bars;
  cout << " Enter the weight of one bar and press enter ";
  cin >> one_weight;

  total_weight = number_of_bars  * one_weight;
	
  cout <<" \n Number of Candy bars "<< number_of_bars <<endl <<endl;
  cout <<" Weight of one bar    "<< one_weight << " ounces \n";
  cout <<" Total weight is      "<< total_weight << " ounces \n\n";

  cout <<"  Try another brand \n ";
  cout << " Enter the number of candy bars in a package and press enter  ";
  cin  >> number_of_bars;
  cout << " Enter the weight of one bar and press enter ";
  cin >> one_weight;
  
  total_weight = number_of_bars  * one_weight;

  cout <<" \n Number of Candy bars "<< number_of_bars <<endl;
  cout <<" Weight of one bar    "<< one_weight << " ounces \n";
  cout <<" Total weight is      "<< total_weight << " ounces \n\n";


  cout <<" Perhaps an apple would be healthier  \n\n";

  return (0);
} 
  
   
