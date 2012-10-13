// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class Dnode
#ifndef DNODE_H
#define DNODE_H
#include <iostream>
using namespace std;

template<class T>
class Dnode{
	public:
		Dnode(
			T data = T(),
			Dnode *next = NULL,
			Dnode *prev = NULL)
			{datafield = data;
			nextptr = next;
			previousptr = prev;}
		~Dnode(){
			delete[]previousptr;
			delete[]nextptr;}
		Dnode* next() {return nextptr;}
		Dnode* previous() {return previousptr;}
		T data() {return datafield;}
		void set_next(Dnode *n) {nextptr=n;}
		void set_previous(Dnode *p) {previousptr=p;}
		void set_data(T d) {datafield=d;}
	private:
		T datafield;
		Dnode *previousptr;
		Dnode *nextptr;
};

#endif