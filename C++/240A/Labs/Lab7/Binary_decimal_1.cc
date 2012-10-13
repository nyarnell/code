
//  Description: The program reads characters representing binary 
//               number (base 2) and  converting them into decimal 
//              (base 10) number. 
//                                                                    

#include <iostream>

using namespace std;


int main ()
{

 int num, total = 0;
 char ch;  
    
 cin.get(ch);   

  while ( ch != '\n') {  
//      num = static_cast<int> (ch) - static_cast<int> ('0');
num = ch;
      total = total * 2 + num;
      cin.get(ch); 
  }
  
   cout << total <<endl;
 
   
 return 0;
}

