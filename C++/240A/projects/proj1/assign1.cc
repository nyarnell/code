//
//	Program Name: Monthly Sales Tax
//
//	Name: Nathaniel Yarnell
//	Email: nathanielbyarnell@gmail.com
//
//	Description: This program will create a monthly sales tax report
//	listing the sales for the month and the amount of sales tax collected
//
//	Date: 1/9/11
//

#include <iostream>
using namespace std;

const double STATE_TAX = .04;   // Sales tax for the state
const double COUNTY_TAX = .02;  // Sales tax for the county

int main ()
{
  char ch1,ch2,ch3; // Three characters of the month
  int year;	      // The current year
  double total_collected, // The total amount collected
	 sales,		  // Sales adjusted for taxes
	 county_sales_tax, // Total county sales tax
	 state_sales_tax, // Total state sales tax
	 total_sales_tax; // County and state sales tax combined

  cout << "Enter the first three characters of the month ";
  cin >> ch1 >> ch2 >> ch3;
  cout << "Enter the year ";
  cin >> year;
  cout << "Enter the total sales ";
  cin >> total_collected;

  cout << "\nMonth: " << ch1 << ch2 << ch3 << endl;
  cout << "Year: " << year << endl;

  cout.setf(ios::fixed); //magic formula
  cout.setf(ios::showpoint);
  cout.precision(2);

	county_sales_tax = total_collected * COUNTY_TAX;
	state_sales_tax = total_collected * STATE_TAX;
	total_sales_tax = county_sales_tax + state_sales_tax;
	sales = total_collected - total_sales_tax;

  cout << "\nTotal collected  $" << total_collected << endl;
  cout << "Sales            $" << sales << endl;
  cout << "County Sales Tax $" << county_sales_tax << endl;
  cout << "State Sales Tax  $" << state_sales_tax << endl;
  cout << "Total Sales Tax  $" << total_sales_tax << endl;

  return 0;
}
