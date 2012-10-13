
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//**********************************************************************
// function: Clock
// purpose:  The constructor stores the h, m and s as hrs, mins and secs
//           respectively. 
// parameters: h - the hours, m -  the minutes, s -  the seconds
// calls: check_time
//**********************************************************************
// Clock()
//**********************************************************************
// function: clock
// purpose:  default constructor hrs, mins and secs is set to zero
// parameters: none
// calls: none     
//**********************************************************************
// clock()
//**********************************************************************
// function: ==
// purpose: allow the direct comparison of Clock classes
// parameters: Clock& time1
//             Clock& time2
// calls: none
//**********************************************************************
// bool ==(Clock& time1, Clock& time2)
//**********************************************************************
// function: set_time
// purpose:  Set the time with the incoming parameters. 
// parameters: new_hrs - new value for hrs
//             new_min - new minutes for mins
//             new_sec - new seconds for secs
//             
// calls: check_time
//**********************************************************************
// void set_time(int new_hrs, int new_min, int new_sec)
//**********************************************************************
// function: increment_time
// purpose:  increment the clock one second every time though, and
//           increment minutes if seconds are > 59 and increment hours if
//           minutes are > 59 and increment hours to 0 if hours > 23
// parameters: none
// calls: none
//**********************************************************************
// void increment_time()
//**********************************************************************
// function: display
// purpose:  outputs the current time to the screen, in the following
//           format HH:MM::SS
// parameters: none
// calls: none
//**********************************************************************
// void display()
//**********************************************************************
// function: get_hours
// purpose:  return hrs
// parameters: none
// calls: none
//**********************************************************************
// int get_hours()
//**********************************************************************
// function: get_mins
// purpose:  return mins
// parameters: none
// calls: none
//**********************************************************************
// int get_mins()
//**********************************************************************
// function: get_secs
// purpose:  return the secs
// parameters: none
// calls: none
//**********************************************************************
// int get_secs()
//**********************************************************************
// function: check_time
// purpose:  If the time is not in the valid range 0 <= hours <= 23 
//           and 0 <= minutes <= 59 and 0 <= second <= 59 print
//           a message and exit the program.
// parameters: none
// calls: exit
//**********************************************************************
// void check_time()

class Clock
{
public:

  friend bool operator ==(Clock& time1, Clock& time2);

  // constructors

  Clock(int h, int m, int s);
  Clock();

  // Accessor
  void set_time(int new_hrs, int new_min, int new_sec);


  // mutators
  int get_hours(); 
  
  int get_mins();
  
  int get_secs();

  void snooze(Clock& time1);
    
  void increment_time();

  void display();
  
private:
  void check_time();
  int hrs;   // hours -     0 <= hrs <= 23  
  int mins;  // minutes -   0 <= min <= 59 
  int secs;  // seconds -   0 <= sec <= 59
};

int main()
{
  Clock SchoolClock, AlarmClock;
  int h, m, s, num;
   
  cout<<"The school clock display \n";
  SchoolClock.display();
  cout<<"What time do you want the alarm to go off?\n"<<"hour: ";
  cin>>h;
  cout<<"minutes: ";
  cin>>m;
  cout<<"seconds: ";
  cin>>s;

  AlarmClock.set_time(h, m, s);

  if (AlarmClock==SchoolClock)
  {
    cout<<"*****  WAKE UP SLEEPY HEAD!! *****\a"<<endl;
    exit(0);
  }

  do {
    SchoolClock.increment_time();
    SchoolClock.display();
    if (AlarmClock==SchoolClock)
    {
      cout<<"*****  WAKE UP SLEEPY HEAD!! *****\a"<<endl;
      do {
      cout<<"Would you like to snooze for 5 more minutes? Enter a positive number for yes, or -1 for no."<<endl;
      cin>>num;
      if (num==-1)
      {
        return 0;
      }
      else SchoolClock.snooze(SchoolClock);
      }while (num!=-1);
    }
  }while (!(AlarmClock==SchoolClock));
}

bool operator ==(Clock& time1, Clock& time2)
{
  return ((time1.get_secs()==time2.get_secs())&&(time1.get_mins()==time2.get_mins())&&(time1.get_hours()==time2.get_hours()));
}
Clock::Clock(int h, int m, int s)
{
  hrs=h;
  mins=m;
  secs=s;
  check_time();
}

Clock::Clock() : hrs(23), mins(58), secs(55) {}

void Clock::increment_time()
{
  if (secs<=58) // Using <=58 avoids having secs display as 60.
  {
    secs++;
  }
  else
  {
    secs=0;
    mins++;
  }
  if (mins>=60) // if min=60, it is because it was just incremented from 59.
  {             // thus, it can be set to 0 here to avoid having the clock
    mins=0;     // display 60 for the minutes place. The hours place uses a
    hrs++;      // similar logic.
  }
  if (hrs>=24)
  {
    hrs=0;
  }
}

void Clock::display()
{
  cout<<setfill('0')<<setw(2)<<hrs<<":"<<setw(2)<<mins<<":"<<setw(2)<<secs<<endl;
}

void Clock::set_time(int new_hrs, int new_min, int new_sec)
{
  hrs=new_hrs;
  mins=new_min;
  secs=new_sec;
  check_time();
}

int Clock::get_hours()
{
  return hrs;
}

int Clock::get_mins()
{
  return mins;
}

int Clock::get_secs()
{
  return secs;
}

void Clock::check_time()
{
  if (hrs<0 || hrs>23 || mins<0 || mins>59 || secs<0 || secs>59)
  {
    cout<<"Invalid Time. Aborting the program.";
    exit(1);
  }
}

void Clock::snooze(Clock& time1)
{
  for (int i=1;i<=300;i++)
  {
    time1.increment_time();
    time1.display();
  }
  cout<<"*****  WAKE UP SLEEPY HEAD!! *****\a"<<endl;
}
