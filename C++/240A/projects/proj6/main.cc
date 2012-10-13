// Include the header block

#include <iostream>
#include <iomanip>
#include "MyTime.h"  // include the .h file
using namespace std;

int main()
{
  MyTime m1(2, 11), m2;
cout<<"default constructor "<<m2<<endl;
cout<<"constructor with two args "<<m1<<endl;
cout<<"Enter the time you spent on the project today, hours first, with a space in between.\n";
cin>>m2;
cout<<"The time you entered is "<<m2<<endl<<endl;
cout<<m1<<" + "<<m2<<" = "<<m1+m2<<endl;
cout<<m2<<" + "<<30<<" = "<<m2+30<<endl;
cout<<30<<" + "<<m2<<" = "<<30+m2<<endl;
cout<<m1<<" - "<<m2<<" = "<<m1-m2<<endl;
cout<<m2<<" - "<<30<<" = "<<m2-30<<endl;
cout<<30<<" - "<<m2<<" = "<<30-m2<<endl;
cout<<m2<<" * "<<2<<" = "<<m2*2<<endl;
cout<<2<<" * "<<m2<<" = "<<2*m2<<endl;
  cout<<"Testing == operator \n";
  if (m1 == m2)
    cout<<m1<<" is equal to "<<m2<<endl<<endl;
  else
    cout<<m1<<" is not equal to "<<m2<<endl<<endl;

cout<<m1<<endl;
m1.AddMin(30);
cout<<m1<<endl;
m1.AddHr(1);
cout<<m1<<endl;
m1.Reset(0,0);
cout<<m1<<endl;

  cout<<"Testing < operator \n";
  if (m1<m2)
    cout<<m1<<" is less than "<<m2<<endl;
  else if (m1>m2)
    cout<<m1<<" is greater than "<<m2<<endl;
  else
    cout<<m1<<" is equal to "<<m2<<endl;

  return(0);
}


