// using the get 
#include <iostream>  // for cout
#include <fstream>  // for file I/O 
#include <cstdlib>  // for exit
using namespace std;

int main()
{
  ifstream fin;

  fin.open("test.dat");

  if (fin.fail())
  {
    cout<<"fail to open  \n";
    exit(1);
  }
  
  char ch;

  fin.get(ch);  //priming read - initialize

  while (!fin.eof()){
   cout.put(ch);  // same as using the cout<< ch;
   fin.get(ch); // read at the end - update
  }
 
  cout<<endl;

  fin.close();

  return 0;
}


 
