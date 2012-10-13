#include <iostream> 
using namespace std;
//*********************************************************************
// Function: get_data
// Purpose:  reads in the balance interest rate and term from the 
//           keyboard.
// Calls:    none
// Uses:     istream
//*********************************************************************
//void CDAccount::get_data( );
//*********************************************************************
// Function: calculate_balance
// Purpose:  calculate the interest and the balance has been updated 
// Calls:    none
// Uses:     none 
//*********************************************************************
//void CDAccount::calculate_balance( );
//*********************************************************************
// Function: get_balance
// Purpose:  returns the balance of the account.
// Calls:    none
// Uses:     none
//*********************************************************************
//double CDAccount::get_balance( );
//*********************************************************************
// Function: get_interest_rate
// Purpose:  returns the interest rate of the account.
// Calls:    none
// Uses:     none 
//*********************************************************************
//double CDAccount::get_interest_rate( );
//*********************************************************************
// Function: get_term
// Purpose:  returns the number of months until maturity.
// Calls:    none
// Uses:     none
//*********************************************************************
//int CDAccount::get_term( );

class CDAccount
{
 public:
  
   void get_data();
   void calculate_balance();

   // accessor functions

   double get_balance();
   double get_interest_rate();
   int get_term();

 private:

   double balance; //the balance of the account
   double interest_rate; //the interest rate
   int term; //months until maturity
};


int main()   
{

 CDAccount account1;

 account1.get_data();

 cout.setf(ios::fixed);
 cout.setf(ios::showpoint);
 cout.precision(2);
 
 cout <<"\nThe initial balance is $" <<account1.get_balance()<<endl;
 cout <<"The interest rate is  "<<account1.get_interest_rate() <<"%";
 cout <<" for "<<account1.get_term() <<" months \n\n";
 
 account1.calculate_balance();
 
 cout<<"When your CD matures you will have a balance of $"
     << account1.get_balance()<<endl;
 
 return 0;
}

void CDAccount::get_data()
{
  cout<<"Enter account balance: $";
  cin>>balance;
  cout<<"Enter account interest rate: ";
  cin>>interest_rate;
  cout<<"Enter the number of months until maturity (must be 12 or fewer months): ";
  cin>>term;
}

void CDAccount::calculate_balance( )
{
  double rate_fraction, interest;
  rate_fraction=interest_rate/100.0;
  interest=balance*rate_fraction*(term/12.0);
  balance=balance+interest;
}

double CDAccount::get_balance()
{
  return (balance);
}

double CDAccount::get_interest_rate()
{
  return (interest_rate);
}

int CDAccount::get_term()
{
  return (term);
}
