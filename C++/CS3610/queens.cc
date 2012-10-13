#include<iostream>
#include<cstdlib>
//***************************************************************************
// File:    queens.cc
// Author:  Nathaniel Yarnell
// Date:    17 Sept 2012
//***************************************************************************
#include<ctime>
#include "queens.h"
using namespace std;

queens_pzl::queens_pzl(int queens)
{
	queens_count = queens;
		queens_inrow = new int[queens_count];
		sln_count = 0;
}

bool queens_pzl::legal_move(int k, int i)
{
	for(int j=0; j<k; j++)
		if ((queens_inrow[j] == i) || (abs(queens_inrow[j] - i) == abs(j-k)))
			return false;
			
		return true;
}

void queens_pzl::queensConfiguration(int k)
{
	for(int i=0; i<queens_count; i++)
	{
		if(legal_move(k, i))
		{
			queens_inrow[k] = i;
		
				if( k == queens_count -1)
				printConfiguration();
				else
				queensConfiguration(k+1);
		}
	}
}

void queens_pzl::printConfiguration()
{
	sln_count++;
	cout<<"(";
	for(int i=0; i<queens_count-1; i++)
		cout<<queens_inrow[i]<< ", ";
		
		cout<<queens_inrow[queens_count-1]<< ")" <<endl;
}

int queens_pzl::solutionsCount()
{
	return sln_count;
}		
		
	