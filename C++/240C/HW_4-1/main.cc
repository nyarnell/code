#include <iostream>

using namespace std;

void numfunc(int num);

void stars(int num);

void pyramid(int numstars, int num);

int main()
{
	numfunc(23);
	cout << endl;
	numfunc(18);
	cout << endl;
	numfunc(-2);
	pyramid(9, 0);
}

void numfunc(int num){
	if ( num>=0 ){
		if ( num%2==1 ) { numfunc(num-1); }
		else {
			numfunc(num-2);
			cout << num << " ";
		}
	}
}

void stars (int num){
	if ( num>=0 ){
		cout << "*";
		stars(num-1);
	}
}

void pyramid(int numstars, int currstar){
	if (currstar < numstars){
		stars(currstar);
		cout << endl;
		pyramid(numstars, currstar+1);
		if (numstars!=currstar+1) {
			stars(currstar);
			cout << endl;
		}
	}
}