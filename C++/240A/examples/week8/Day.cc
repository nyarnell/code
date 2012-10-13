// This program the user set the today's day using the constructor 
// and enters the bithday day from the keyboard.  Wish happy
// birthday when today is equal to the birthday  

// No input validation or  documentation -  too tired

#include <iostream>
#include <cstdlib> 
using namespace std;

class Day
{
  public:
    //constructors
     Day(int d);
     Day();
 
    // mutator 
     void set_day(int d);
    
     void increment_day();

     void output_day();

     // accessor
     int get_day();

 private:
     int day; //  >= 1 and <= 31
};


 int main()
{
   Day today(10);  
   Day birthday;

   int bday;

   today.output_day();

   cout<< "Enter the day of the birthday  -->  ";
   cin >> bday;

   birthday.set_day(bday);

   while (today.get_day() != birthday.get_day())
  {
     today.output_day();

     cout << abs(today.get_day() - birthday.get_day()) 
          << " day(s) is left for your BDAY \n\n";     // not in proj5

     today.increment_day();
     system("sleep 2");  // optional 
  }

  cout <<"\n\n     Finally it's your birthday  \n";
  cout <<"\n\n ****    Happy Birthday !!  ****   \n";

 return 0;
}


Day:: Day(int d)
{
  day = d;
}

 
Day::Day()
{
  day = 1;
}
     
  
void Day:: set_day(int d)
{
   day = d;
}
    
void Day:: increment_day()
{
   day++;
}
   
void Day:: output_day()
{
 
  cout<< "Today is  " << day <<endl<<endl;
}
  
int Day:: get_day()
{
   return day;
}
   

