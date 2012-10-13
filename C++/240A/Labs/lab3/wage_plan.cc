// 
// Program Name: Wage Plan
//
// Author Name: Nathaniel Yarnell
// Email: nathanielbyarnell@gmail.com
//
// Description: This program determines the expected wages
// for a bicycle salesperson under two different wage plans
//
// Last changed: 1/19/2011
//

#include <iostream>
using namespace std;

const double RATE_PER_HOUR = 5.5; // hourly wage
const double TEN_COMMISSION = .1; // 10% sales commission
const double FIFTEEN_COMMISSION = .15; // 15% sales commission

int main()
{
  double weekly_sales, // total sales for the week
  	 plan_one_wages, // total wages under plan one
	 plan_two_wages; // total wages under plan two

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "Enter the weekly sales amount ";
  cin >> weekly_sales;
  cout << "Amount of sales $" << weekly_sales << endl;

  plan_one_wages = (RATE_PER_HOUR * 40) + (weekly_sales * TEN_COMMISSION);
    cout << "Plan 1 pays $" << plan_one_wages << endl;
  plan_two_wages = (weekly_sales * FIFTEEN_COMMISSION);
    cout << "Plan 2 pays $" << plan_two_wages << endl;

    if (plan_one_wages > plan_two_wages)
      cout << "Plan 1 is better" << endl;
    else if (plan_one_wages == plan_two_wages)
      cout << "Both plans pay the same" << endl;
    else if (plan_one_wages < plan_two_wages)
      cout << "Plan 2 is better" << endl;

return 0;
}

