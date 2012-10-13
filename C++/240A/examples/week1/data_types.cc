/*Data Types

  Integer types: 
	char 
	short 
	int 
	bool 
	long 
	long long 
Note: the char type can be used as a one 
byte integer, and the bool type is stored in 
1 byte. 
Any of the integer types may be signed or unsigned.
 
Floating point types: 
	float 
	double 
	long double 
The following program shows the size in 
bytes of each of these types using g++ on 
prime. 

*/

#include <iostream>

using namespace std;

int main()
{
  cout << "Data Type       Size in bytes\n";
  cout << "------------------------------\n";
  
  cout << "char            " << sizeof(char) << endl << endl;
  cout << "short           " << sizeof(short) << endl << endl;
  cout << "int             " << sizeof(int) << endl << endl;
  cout << "bool            " << sizeof(bool) << endl << endl;
  cout << "long            " << sizeof(long) << endl << endl;
  cout << "long long       " << sizeof(long long) << endl << endl;
  cout << "float           " << sizeof(float) << endl << endl;
  cout << "double          " << sizeof(double) << endl << endl;
  cout << "long double     " << sizeof(long double) << endl << endl;

  return(0);
}
 

