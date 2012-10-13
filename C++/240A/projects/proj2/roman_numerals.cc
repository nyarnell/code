//
// Program Name: roman_numerals
//
// Name: Nathaniel
// Email: nathanielbyarnell@gmail.com
//
// Description: This program takes an integer between 1000 and 3000 and
// translates it into roman numerals.
//
// Date modified: 1/19/2011
//

#include <iostream>
using namespace std;

const int SENTINAL = -1;

int main()
{
  int year; // the year to be translated
  int thousands_place; // thousands place in the year
  int hundreds_place; // hundreds place in the year
  int tens_place; // tens place in the year    
  int ones_place; // ones place in the year

  cout << "Enter a year (1000-3000) or -1 to quit ";
  cin >> year;

  if (year == SENTINAL)                           // The next 2 lines of code appear repeated in several places throughout this source code. I think a function call would eliminate
    return 0;                                     // the need to use this so much, but without it the sentinal value won't work throughout the code. There must be a more elegant way.
  while ((year > 3000) || (year < 1000))
    {
    cout << "Invalid year. Please enter (1000-3000) or -1 to quit. ";
    cin >> year;
      {
      if (year == SENTINAL)
        return 0;
      }
    }
  while ((year < 3000) || (year > 1000))  
  {
    thousands_place = year/1000;                       //These lines divide each 'place' into single digits and store them as variables with obvious names. 
    hundreds_place = (year%1000)/100;
    tens_place = ((year%1000)%100)/10;
    ones_place = (((year%1000)%100)%10)/1;

    switch (thousands_place)                           //These switch statements feel very brute forced. What would be more efficient?
    {
      case 1:
        cout << "M";
        break;
      case 2:
        cout << "MM";
        break;
      case 3:
        cout << "MMM";
        break;
    }

    switch (hundreds_place)
    {
       case 0:
        cout << "";
        break;
       case 1:
        cout << "C";
        break;
      case 2:
        cout << "CC";
        break;
      case 3:
        cout << "CC";
        break;
      case 4:
        cout << "CD";
        break;
      case 5:
        cout << "D";
        break;
      case 6:
        cout << "DC";
        break;
      case 7:
        cout << "DCC";
        break;
      case 8:
        cout << "DCCC";
        break;
      case 9:
        cout <<  "CM";
        break;
    }

    switch (tens_place)
    {
      case 0:
        cout << "";
        break;
      case 1:
        cout << "X";
        break;
      case 2:
        cout << "XX";
        break;
      case 3:
        cout << "XXX";
        break;
      case 4:
        cout << "XL";
        break;
      case 5:
        cout << "L";
        break;
      case 6:
        cout << "LX";
        break;
      case 7:
        cout << "LXX";
        break;
      case 8:
        cout << "LXXX";
        break;
      case 9:
        cout << "XC";
        break;
    }

    switch (ones_place)
    {
      case 0:
        cout << "";
        break;
      case 1:
        cout << "I";
        break;
      case 2:
        cout << "II";
        break;
      case 3:
        cout << "III";
        break;
      case 4:
        cout << "IV";
        break;
      case 5:
        cout << "V";
        break;
      case 6:
        cout << "VI";
        break;
      case 7:
        cout << "VII";
        break;
      case 8:
        cout << "VIII";
        break;
      case 9:
        cout << "IX";
        break;
    }

    cout << endl << "Enter a year (1000-3000) or -1 to quit ";
    cin >> year;
    
      if (year == SENTINAL)
        {
        return 0;
        }
      while ((year > 3000) || (year < 1000))
        {
        cout << "Invalid year. Please enter (1000-3000) or -1 to quit. ";
        cin >> year;
        }
        if (year == SENTINAL)
          return 0; 
  }
}
