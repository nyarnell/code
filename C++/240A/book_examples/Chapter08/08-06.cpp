//DISPLAY 8.6 A string Object Can Behave Like an Array
//Demonstrates using a string object as if it were an array.
#include <iostream>
#include <string> 
using namespace std;

int main( )
{
    string first_name, last_name; 

    cout << "Enter your first and last name:\n";
    cin >> first_name >> last_name;

    cout << "Your last name is spelled:\n";
    int i;
    for (i = 0; i < last_name.length( ); i++)
    {
        cout << last_name[i] << " ";
        last_name[i] = '-';
    }
    cout << endl;
    for (i = 0; i < last_name.length( ); i++)
        cout << last_name[i] << " "; //Places a "-" under each letter.
    cout << endl;

    cout << "Good day " << first_name << endl;
    return 0;
}

