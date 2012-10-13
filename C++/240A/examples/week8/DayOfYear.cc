// The programmer who uses the type DayOfYear doesn't have to know how 
// the member variables are stored.  On page 549 month is an int value
// In this program month is a string.   As you can see only the definitions
// of the member functions have changed to represent month as a string.

// There is no difference in the main function on page 549 and this program

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class DayOfYear
{
  public:
    void input();
    void output();
    void set(int new_month, int new_day);
    int get_month();
    int get_day();
  private:    
    void check_date();
    string month;     //month is not an int
    int day;
};


int main()
{
  DayOfYear today, bach_birthday;

  cout << "Enter today's date: \n";

  today.input();

  cout << "Today's date is ";

  today.output();

  bach_birthday.set(3,21);

  cout << "J. S. Bach's birthday is ";
  
  bach_birthday.output();

  if (today.get_month() == bach_birthday.get_month() &&
       today.get_day() == bach_birthday.get_day())
  
    cout << "Happy birthday Johann Sebastian!\n";
  else
    cout << "Happy unbirthday Johann Sebastian!\n";

  return 0;
}

void DayOfYear::set(int new_month, int new_day)
{
  if (new_month == 1)
    month = "Jan";
  else if (new_month == 2)
    month = "Feb";
  else if (new_month == 3)
    month = "Mar";
  else if (new_month == 4)
     month ="Apr";
  else if (new_month == 5)
     month = "May";

   // not complete - need to include the rest


   day = new_day;
   check_date();
}

int DayOfYear::get_month()
{
   if (month == "Jan")
     return 1;
   else if (month == "Feb")
     return 2;
   else if (month == "Mar")
     return 3;
   else if (month == "Apr")
      return 4;
   else if (month == "May")
      return 5;

  // need to include the rest
}

 int DayOfYear::get_day()
 {
   return day;
 }
  
void DayOfYear::output()
{
  cout<<"month = " <<get_month();
  cout <<", day = "<< day<<endl;
}


void DayOfYear :: input()
{
  int m, d;

  cout <<" Enter the month as a number  ";
  cin>> m;

  cout << "Enter the day of the month  ";
  cin >> d;
  
  set(m,d);

}

void DayOfYear :: check_date()
{
  if (get_month() < 1 || get_month() > 12 || day <1 || day > 31)
  {
   cout <<" Illegal date. Abort the program  \n";
   exit(1);
  }
}
