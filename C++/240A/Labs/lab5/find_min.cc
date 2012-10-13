//
// Program Name: find_min.cc
//
// Name: Nathaniel Yarnell
// Email: nathanielbyarnell@gmail.com
//
//Description: This program asks the user for input in the form of whole, real
//numbers, and remembers which number was the lowest.
//
//Date: 2/2/11
//

#include <iostream>
using namespace std;

void Get_Num (int& num);
//Function Name:Get_Num
//Purpose: This function asks the user to enter a number
//or -1 to quit
//Parameters: num
//Calls: none

void Find_Min (int& cur_min, int cur_num);
//Function Name:Find_Mind
//Purpose: This function takes the value entered by the user
//and compares it to the lowest value entered so far. If the new value is
//less than the old value, the new value replaces the old value.
//Parameters: cur_min, int cur_num
//Calls: none
 
int main()
{
   int number, //number read from the key board
       minimum; // minimum number out of all the numbers
  
   Get_Num(number);
   
   minimum = number;

   while (number >= 0 ) 
   {  
      cout<< " Number is  "<< number << endl;
      Find_Min(minimum, number);
      Get_Num(number);
   }
    
  cout << "\n Minimum number =  "<<minimum << endl;
  

 return 0;
}

void Get_Num(int&  num)
{
  cout << "Enter a number and enter -1 to quit  ";
  cin >> num;
}

void Find_Min( int& cur_min , int cur_num)
{  
  if (cur_min > cur_num)
      cur_min = cur_num;
  
}
   


