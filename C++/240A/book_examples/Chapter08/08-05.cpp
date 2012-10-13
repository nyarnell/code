//DISPLAY 8.5 Program Using the Class string
//Demonstrates getline and cin.get.
#include <iostream>
#include <string> 

void new_line( );

int main( )
{
    using namespace std;

    string first_name, last_name, record_name; 
    string motto = "Your records are our records."; 

    cout << "Enter your first and last name:\n";
    cin >> first_name >> last_name;
    new_line( );

    record_name = last_name + ", " + first_name;
    cout << "Your name in our records is: ";
    cout << record_name << endl;

    cout << "Our motto is\n"
         << motto << endl;
    cout << "Please suggest a better (one-line) motto:\n";
    getline(cin, motto);
    cout << "Our new motto will be:\n";
    cout << motto << endl;

    return 0;
}

//Uses iostream:
void new_line( )
{
    using namespace std;

    char next_char;
    do
    {
        cin.get(next_char);
    } while (next_char != '\n');
}


