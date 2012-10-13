//DISPLAY 12.9 Placing a Class in a NamespaceApplication Program
//This is the application file: timedemo.cpp. This program
//demonstrates hiding the helping functions in an unnamed namespace.

#include <iostream>
#include "dtime.h"

void read_hour(int& the_hour);

int main( )
{
    using namespace std;

    using namespace dtimesavitch;

    int the_hour;
    read_hour(the_hour);

    DigitalTime clock(the_hour, 0), old_clock;

    old_clock = clock;
    clock.advance(15);
    if (clock == old_clock)
        cout << "Something is wrong.";
    cout << "You entered " << old_clock << endl;
    cout << "15 minutes later the time will be "
         << clock << endl;

    clock.advance(2, 15);
    cout << "2 hours and 15 minutes after that\n"
         << "the time will be "
         << clock << endl;

    return 0;
}
void read_hour(int& the_hour)
{
     using namespace std;

     cout << "Let's play a time game.\n"
          << "Let's pretend the hour has just changed.\n"

Placing a Class in a NamespaceApplication Program (part 2 of 2 )
         << "You may write midnight as either 0 or 24,\n"
         << "but I will always write it as 0.\n"
         << "Enter the hour as a number (0 to 24): ";
     cin >> the_hour;
     if (the_hour == 24)
        the_hour = 0;
}
