// method 1 to properly convert ot uppercase/lowecase
 
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
   char ch;

   cout<<"Enter a sentence \n";
   cin.get(ch);

   while(ch != '\n'){
    cout<<static_cast<char>(toupper(ch));
    cin.get(ch);
  }

  cout<<"\n";

  cout<<"End of program  \n\n";

  return 0;
}

