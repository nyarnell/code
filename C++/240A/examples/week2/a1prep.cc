//  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  
//  Program  - Sample program for assignment 1
//
//  Description - This program calculate the final price of an item. 
//                6% tax is applied to the bill after the item is 
//                discounted by 10%
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include <iostream>
using namespace std;

const double TAX_RATE = 0.06;   // sales tax  
const double DISCOUNT = 0.1;    // rate of discount 

int main()
{
  char ch1,ch2,ch3;    // three characters of the month  
  double price,       // Original price of the item  
         tax,        // Tax amount  
         sale_price, // price of the item after discount
         total;      // final price of the item 

  cout<<"Enter the first three characters of the month ";
  cin >> ch1 >> ch2 >> ch3;
  cout << "Enter the purchase price ";
  cin >> price;

  sale_price = price - (price * DISCOUNT);
  tax = sale_price  * TAX_RATE;
  total = sale_price + tax;

  cout << "\n\nMonth  : " << ch1 << ch2 << ch3 << endl;
  cout << "--------------\n\n";

 // magic formula 

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "Price        $ " << price << endl;
  cout << "Sale Price   $ " << sale_price <<endl;
  cout << "Tax          $ " << tax <<endl;
  cout << "Total        $ " << total<<endl;


  return (0);

}
