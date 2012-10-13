//DISPLAY 5.2 void Functions
//Program to convert a Fahrenheit temperature to a Celsius temperature.
#include <iostream>

void initialize_screen( );
//Separates current output from
//the output of the previously run program.

double celsius(double fahrenheit);
//Converts a Fahrenheit temperature
//to a Celsius temperature.

void show_results(double f_degrees, double c_degrees);
//Displays output. Assumes that c_degrees 
//Celsius is equivalent to f_degrees Fahrenheit.

int main( )
{
    using namespace std;
    double f_temperature, c_temperature;

    initialize_screen( );
    cout << "I will convert a Fahrenheit temperature"
         << " to Celsius.\n"
         << "Enter a temperature in Fahrenheit: ";
    cin >> f_temperature;

    c_temperature = celsius(f_temperature);

    show_results(f_temperature, c_temperature);
    return 0;
}

//Definition uses iostream:
void initialize_screen( )
{
    using namespace std;
    cout << endl;
    return;
}
double celsius(double fahrenheit)
{
    return ((5.0/9.0)*(fahrenheit - 32));
}
//Definition uses iostream:
void show_results(double f_degrees, double c_degrees)
{
    using namespace std;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << f_degrees 
         << " degrees Fahrenheit is equivalent to\n"
         << c_degrees << " degrees Celsius.\n";
    return;
}
