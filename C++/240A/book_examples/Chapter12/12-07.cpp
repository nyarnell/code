//DISPLAY 12.7 Placing a Class in a NamespaceImplementation File
//Implementation file dtime.cpp (your system may require some 
//suffix other than .cpp): This is the IMPLEMENTATION of the ADT DigitalTime.
//The interface for the class DigitalTime is in the header file dtime.h.
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "dtime.h"
using namespace std;

namespace
{
    //These function declarations are for use in the definition of 
    //the overloaded input operator >>:

    void read_hour(istream& ins, int& the_hour);
    //Precondition: Next input in the stream ins is a time in 24-hour notation,
    //like 9:45 or 14:45.
    //Postcondition: the_hour has been set to the hour part of the time. 
    //The colon has been discarded and the next input to be read is the minute.

    void read_minute(istream& ins, int& the_minute);
    //Reads the minute from the stream ins after read_hour has read the hour.

    int digit_to_int(char c);
    //Precondition: c is one of the digits '0' through '9'.
    //Returns the integer for the digit; for example, digit_to_int('3') 
    //returns 3.
}//unnamed namespace


namespace dtimesavitch
{
    bool operator ==(const DigitalTime& time1, const DigitalTime& time2)
       //The rest of the definition of = = is the same as in Display 12.2.

    DigitalTime::DigitalTime( )
       //The rest of the definition of this constructor is the same as in Display 12.2.

    DigitalTime::DigitalTime(int the_hour, int the_minute)
       //The rest of the definition of this constructor is the same as in Display 12.2.
    void DigitalTime::advance(int minutes_added)
       //The rest of the definition of this advance function is the same as in Display 12.2.

    void DigitalTime::advance(int hours_added, int minutes_added)
        //The rest of the definition of this advance function is the same as in Display 12.2.

    ostream& operator <<(ostream& outs, const DigitalTime& the_object)
       //The rest of the definition of << is the same as in Display 12.2.

    //Uses iostream and functions in the unnamed namespace:
    istream& operator >>(istream& ins, DigitalTime& the_object)
    {
        read_hour(ins, the_object.hour);
        read_minute(ins, the_object.minute);
        return ins;
    }
} //dtimesavitch


namespace
{
    int digit_to_int(char c)
        //The rest of the definition of digit_to_int is the same as in Display 12.2.>

    void read_minute(istream& ins, int& the_minute)
       //The rest of the definition of read_minute is the same as in Display 12.2.>

    void read_hour(istream& ins, int& the_hour)
       //The rest of the definition of read_hour is the same as in Display 12.2.

}//unnamed namespace
