//DISPLAY 8.3 Robust Input Function 
//Demonstration program for improved version of get_int.
#include <iostream>
#include <cstdlib>
#include <cctype>

void read_and_clean(int& n);
//Reads a line of input. Discards all symbols except the digits. Converts
//the C string to an integer and sets n equal to the value of this integer. 
void new_line( );
//Discards all the input remaining on the current input line.
//Also discards the '\n' at the end of the line.

void get_int(int& input_number);
//Gives input_number a value that the user approves of.

int main( )
{
    using namespace std;
    int input_number;
    get_int(input_number);
    cout << "Final value read in = " << input_number << endl;
    return 0;
}

//Uses iostream and read_and_clean:
void get_int(int& input_number)
{
    using namespace std;
    char ans;
    do
    {
        cout << "Enter input number: ";
        read_and_clean(input_number);
        cout << "You entered " << input_number
              << " Is that correct? (yes/no): ";
        cin >> ans;
        new_line( );
    } while ((ans != 'y') && (ans != 'Y'));
}
//Uses iostream, cstdlib, and cctype:
void read_and_clean(int& n)

//The rest of the definition of read_and_clean is given in Display 8.2.

//Uses iostream:
void new_line( )

//The rest of the definition of new_line is given in Display 8.2.

