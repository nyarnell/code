
// given a number print a msg if it is evenly divisible
// by three. If it is not evenly divisible by three
// print a message and the remainder of the division
// This an example of compound statments 


#include <iostream>
using namespace std;

int main()
{
   int num,remainder;

   cout << " Enter an integer value  ";
   cin >> num;

   remainder = num % 3;

   if (remainder = 0)
   {                 
      cout <<"\n The num is " <<num << endl;
      cout <<" Evenly divides by 3 \n";
    } 
   else  // see what happens if you do not have the {}  
    {  
      cout <<"\n The remainder of the division is "<< remainder<<endl;
      cout << num <<" does not evenly divides by 3\n ";
    } 
   
      cout <<" End Of the Program \n\n";

 return (0);
}

 

