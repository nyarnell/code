// method 2 to properly convert ot uppercase/lowecase
 
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
   char ch;

   cout<<"Enter a sentence \n";
   cin.get(ch);

   while(ch != '\n'){
    ch = toupper(ch);  
    cout<<ch;
    cin.get(ch);
  }

  cout<<endl;

  cout<<"End of program  \n\n";

  return 0;
}

