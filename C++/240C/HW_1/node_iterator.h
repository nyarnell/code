// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class node_iterator

#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H
#include "Dnode.h"

template <class T>
class node_iterator{
	public:
		friend class List<T>;
		node_iterator(Dnode<T>* init=NULL) {currptr=init;}
		T operator *()
			{return currptr->data();}
		bool operator != (const node_iterator& other)
			{return currptr!=other.currptr;}
		bool operator == (const node_iterator& other)
			{return currptr==other.currptr;}
		node_iterator operator ++()
			{currptr=currptr->previous(); return *this;}
		node_iterator operator ++(int)
			{node_iterator original(currptr);
			currptr=currptr->previous();
			return original;}
		node_iterator operator --()
			{currptr=currptr->next();
			return *this;}
		node_iterator operator --(int)
			{node_iterator original(currptr);
			currptr=currptr->next();
			return original;}
	private:
		Dnode<T>* currptr;
};

#endif