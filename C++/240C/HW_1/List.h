// Name: Nathaniel Yarnell
// Date: 4/7/2012
// Description: This file contains the interface of the class List

template<class T>
class List;

#include "node_iterator.h"
#include "Dnode.h"

template<class T>
class List{
	
	public:
		typedef node_iterator<T> iterator;
		List(Dnode<T> *h = NULL, Dnode<T> *t = NULL)
			{head = h;
			tail = t;}
		~List();
		List(const List& copy);
		void front_insert(T item);
		void rear_insert(T item);
		void front_remove();
		void rear_remove();
		void output_list();
		List<T>& operator = (const List<T>& other);
		iterator begin(){return iterator(head);}
		iterator end() {return iterator(NULL);}
		iterator r_begin() {return iterator(tail);}
		iterator r_end() {return iterator(NULL);}
		void remove(iterator &it);
		void insert_before(iterator &it, T item);
		void insert_after(iterator &it, T item);
	private:
		Dnode<T> *head;
		Dnode<T> *tail;

};

#include "List.template"