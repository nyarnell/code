#include <iostream>
#include <iomanip>
using namespace std;

void simplify(int& tempmin, int& temphr);

int main()
{
int hrs1, hrs2, minutes1, minutes2, num, temphr, tempmin, totalhr=0, totalmin=0;
do {
cout<<"Enter the time you clocked in, hours first, with a space in between and press enter"<<endl;
cin>>hrs1>>minutes1;
cout<<"Enter the time you clocked out, hours first, with a space in between and press enter"<<endl;
cin>>hrs2>>minutes2;
cout<<"If you are done, type -1 and then enter, otherwise, type any other number."<<endl;
cin>>num;

temphr=hrs2-hrs1;
if (minutes2<minutes1)
{
  temphr=temphr-1;
  minutes2=minutes2+60;
}
tempmin=minutes2-minutes1;
simplify(tempmin, temphr);
cout<<setfill('0')<<"hours worked: "<<setw(2)<<temphr<<":"<<setw(2)<<tempmin<<endl;
totalhr=temphr+totalhr;
totalmin=tempmin+totalmin;
}while (num!=-1);
simplify(totalmin, totalhr);
cout<<"your total time worked is "<<setfill('0')<<setw(2)<<totalhr<<":"<<setw(2)<<totalmin<<endl;
return 0;
}
  
void simplify(int& tempmin, int& temphr)
{      
  if (tempmin >=60)
  {  
    temphr = temphr+(tempmin/60);
    tempmin = tempmin%60;
  }
}     
  


