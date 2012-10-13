#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  cout<<"Decimal"<<setw(15)<<"Hexadecimal"<<setw(7)<<"Octal"<<endl<<endl;
  cout<<showbase<<setiosflags(ios::uppercase);
  
  int x;
  for (x=8; x<=25; x++)
  {
    cout<<left<<dec<<x;
    if (x>=8 && x<=9)
    {
      cout<<" ";
    }
    cout<<setw(15)<<right<<hex<<x<<setw(10)<<oct<<x<<endl;
  }
return 0;
}
   
