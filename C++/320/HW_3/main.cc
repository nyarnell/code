//******************************************************************* 
//                                                                    
//  Program:     main.cc                                           
//                                                                     
//  Author:      Nathaniel Yarnell
//  Email:       nathanielbyarnell@gmail.com
//                                                                    
//  Lab Section: who needs labs
//                                                                    
//  Description: does the input and output               
//                                                                    
//  Date:        4/30/2012
//                                                                    
//*******************************************************************

#include "LexicalAnalyzer.h"
#include "syntactic_analyzer.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
	string str;
	cin >> str;
	while (!str.empty()){
		syntactic_analyzer sa(str);
		cout << sa.expr() << endl;
		cin >> str;
	}
	return 0;
}

/* I've literally tried a dozen combinations of this loop to try and get
it to stop on a newline character. I'm just an idiot I guess. */