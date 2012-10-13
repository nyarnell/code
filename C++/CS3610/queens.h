//***************************************************************************
// File:    queens.h 
// Author:  Nathaniel Yarnell
// Date:    17 Sept 2012
//***************************************************************************

#include <cstdlib>
#include<iostream>
#include<fstream>

using namespace std;

class queens_pzl
{
	public: 
		queens_pzl (int queens = 8);	//constructor
		bool legal_move(int k, int i); // if queen can be placed in row k or column i
		void queensConfiguration(int k); // determines solutions to n-queens
		void printConfiguration(); // output an n-tuple w/ solution pertaining to n-queens
		int solutionsCount(); // returns total number of solutions
		
	private:
		int sln_count;
		int queens_count;
		int *queens_inrow;
	};
	
	