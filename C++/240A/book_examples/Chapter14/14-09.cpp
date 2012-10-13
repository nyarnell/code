//DISPLAY 14.9 A Recursive Member Function
//Program to demonstrate the recursive member function update(years).
#include <iostream>
using namespace std;

//Class for a bank account:
class BankAccount
{
public:
    BankAccount(int dollars, int cents, double rate);
    //Initializes the account balance to $dollars.cents and
    //initializes the interest rate to rate percent.

    BankAccount(int dollars, double rate);
    //Initializes the account balance to $dollars.00 and
    //initializes the interest rate to rate percent.

    BankAccount( );
    //Initializes the account balance to $0.00 and
    //initializes the interest rate to 0.0%.

    void update( );
    //Postcondition: One year of simple interest
    //has been added to the account balance.

    void update(int years);
    //Postcondition: Interest for the number of years given has been added to the
    //account balance. Interest is compounded annually.

    double get_balance( );
    //Returns the current account balance.

    double get_rate( );
    //Returns the current account interest rate as a percentage.

    void output(ostream& outs);
    //Precondition: If outs is a file output stream, then outs has already
    //been connected to a file.
    //Postcondition: Balance & interest rate have been written to the stream outs.
private:
    double balance;
    double interest_rate;
    double fraction(double percent); //Converts a percentage to a fraction.
};
int main( )
{
    BankAccount your_account(100, 5);
    your_account.update(10);
    cout.setf(ios::fixed);

    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "If you deposit $100.00 at 5% interest, then\n"
         << "in ten years your account will be worth $" 
         << your_account.get_balance( ) << endl;
    return 0;
}

void BankAccount::update( )
{
    balance = balance + fraction(interest_rate)*balance;
}

void BankAccount::update(int years)
{
    if (years == 1)
    {
        update( );
    }
    else if (years > 1)
    {
        update(years - 1);
        update( );
    }
}
      
