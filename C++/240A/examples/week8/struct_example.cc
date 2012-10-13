#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

// updating a single member from a struct

using namespace std;

   struct Accounts
   {
     string first;  // first name
     string last;   // last anme
     double balance; // the account balance
     double taken;   // amount withdrawn
   };


//*********************************************************************
// Function:   getdata
// Purpose:    this function takes values for every member of the struct
//             from the stream inp
// Parameters: ac.first, ac.last, ac.balance and ac.taken have been given 
//             values from a data file
// Calls:      None
//*********************************************************************

void getdata(Accounts& ac, ifstream& inp);

//*********************************************************************
// Function:   calc_balance
// Purpose:    this function updates the balance of the account
// Parameters: ac.balance will be updated by subtracting ac.taken
// Calls:      None
//*********************************************************************

double calc_balance(Accounts ac);

//*********************************************************************
// Function:   print
// Purpose:    prints the all the information in a nice table form after
//             updating the balance
// Parameters: ac.first, ac.last printed with left justification and
//             ac.balance and ac.taken with right justification
// Calls:      iomanip
//*********************************************************************

void print(Accounts ac, ostream& fout);

void print_headings (ostream& fout);

int main()
{
 
   Accounts ac1;

   ifstream fin ("bank.dat"); // declare and open at the same time
   
   if (!fin){                // same as fin.fail()
    cout<<" fail to open \n";
    exit(1);
   }


   getdata(ac1,fin);  // priming read

   print_headings(cout);
   
   while (!fin.eof())
   {
     ac1.balance = calc_balance(ac1);
     print(ac1,cout);
     getdata(ac1,fin);	// update
    } 

  fin.close();
  return 0;
}

void print_headings(ostream& fout)
{
   fout<<endl<<endl;
   fout <<setw(5)<<"FIRST"<<setw(8)<<"LAST"<<setw(14) << "BALANCE"
        <<setw(12)<<"WITHDRAW"<<endl<<endl;
}


void print(Accounts ac, ostream& fout)
{

   fout.setf(ios::fixed);
   fout.setf(ios::showpoint);
   fout.precision(2);
     
   fout<<left<<setw(8)<<ac.first<<setw(10)<<ac.last;
   fout<<right<<setw(10)<<ac.balance; 
   fout <<setw(10)<<ac.taken<<endl<<endl;   
   
}


void getdata(Accounts & ac, ifstream& inp)
{
   inp >> ac.first >> ac.last;
   inp >> ac.balance >> ac.taken;     
}

double  calc_balance(Accounts ac)
{
  return( ac.balance - ac.taken);
}   
  
