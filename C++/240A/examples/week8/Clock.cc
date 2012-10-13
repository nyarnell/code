
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
//clock()
//**********************************************************************
// function: clock
// purpose:  default constructor hrs, mins and secs is set to zero
// parameters: none
// calls: none     
//**********************************************************************
// Clock()
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

  // constructors

  Clock(int h, int m, int s);
  Clock();

  // Accessor
  void set_time(int new_hrs, int new_min, int new_sec);


  // mutators
  int get_hours(); 
  
  int get_mins();
  
  int get_secs();

    
  void increment_time();

  void display();
  
private:
  void check_time();
  int hrs;   // hours -     0 <= hrs <= 23  
  int mins;  // minutes -   0 <= min <= 59 
  int secs;  // seconds -   0 <= sec <= 59
};
  
