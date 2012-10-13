#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
 
 int gcd (int x, int y);
 
 int gcd(int x, int y)
 {
 	if( y == 0)
 	return x;
 	
 	
 	int g_cd;
 	g_cd = gcd(y, x%y);
 	return g_cd;
 	
 }
 
 int main()
 {
 	int answer = gcd(200, 500);
 	cout<<" execution 1: "<< answer<< endl;
 	int answer2 = gcd(380, 980);
 	cout<<" execution 2: "<< answer2<<endl;
 	int answer3 = gcd(248, 844);
 	cout<<" execution 3: "<<answer3<<endl;
 	
 	return(0);
 }