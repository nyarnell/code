// Name: Nathaniel Yarnell
// Date: 3/7/2012
// Description: This file contains the implementation of the class eventlist.

#include "node.h"

using namespace std;

class eventlist
{
	public:
		eventlist();
		eventlist(const eventlist& copy);
		~eventlist();
		void output_events();
		void add_event(node* event);
		void remove_event();
		void move_head();
		void move_tail();
	private:
		node* head;
		node* tail;
		node* current;
};