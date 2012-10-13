// This program finds the minimum and sum of all the
// numbers entered by the user

#include <iostream>
using namespace std;

void Get_Num (int& num);


void Find_Min (int& cur_min, int cur_num);


void Sum_All (int& cur_sum, int cur_num);
 

int main()
{
   int number, 
       minimum,
       sum = 0;
  
   cout<<" Address of number in the main "<< &number << endl << endl;

   Get_Num(number);
   
   minimum = number;

   while (number > 0 ) 
   {
        Find_Min(minimum,number);
        Sum_All(sum, number);
        Get_Num(number);
  }
    
  cout <<" Minimum number =  "<< minimum << endl;
  cout <<" The sum = " <<sum << endl;

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

void Sum_All (int& cur_sum, int cur_num)
{
  cur_sum=cur_sum + cur_num;
}
   

