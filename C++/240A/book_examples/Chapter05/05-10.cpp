//DISPLAY 5.10 Driver Program
//Driver program for the function get_input.
#include <iostream>

void get_input(double& cost, int& turnover);
//Precondition: User is ready to enter values correctly. 
//Postcondition: The value of cost has been set to the 
//wholesale cost of one item. The value of turnover has been 
//set to the expected number of days until the item is sold.

int main( )
{
    using namespace std;
    double wholesale_cost;
    int shelf_time;
    char ans;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    do
    {
        get_input(wholesale_cost, shelf_time);

        cout << "Wholesale cost is now $" 
             << wholesale_cost << endl;
        cout << "Days until sold is now " 
             << shelf_time << endl;
       
        cout << "Test again?"
             << " (Type y for yes or n for no): ";
        cin >> ans;
        cout << endl;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
//Uses iostream:
void get_input(double& cost, int& turnover)
{
    using namespace std;
    cout << "Enter the wholesale cost of item: $";
    cin >> cost;
    cout << "Enter the expected number of days until sold: ";
    cin >> turnover;
}

