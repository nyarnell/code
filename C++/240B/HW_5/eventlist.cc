// Name: Nathaniel Yarnell
// Date: 3/7/2012
// Description: This file contains the implementation of the class eventlist.

#include "eventlist.h"
#include <fstream>

using namespace std;

eventlist::eventlist()
{
	head=NULL;
	tail=NULL;
	current=NULL;
	event temp;
	Date date;
	string name;
	ifstream in_stream;
	in_stream.open("data.txt");
	if (!in_stream.eof())
	{
		head = new node;
		current = head;
		tail = head;
		cout << "whyplease stop";
		in_stream >> date;
		while (!in_stream.eof())
		{
			in_stream.ignore();
			getline(in_stream, name);
			temp.set_date(date);
			temp.set_name(name);
			tail->set_data(temp);
			if (!in_stream.eof())
			{
				tail->set_link(new node);
				tail = tail->link();
			}
			in_stream >> date;
		}
		tail->set_link(NULL);
	}
	cout << "ptest";
	in_stream.close();
}

eventlist::eventlist(const eventlist& copy)
{

}

eventlist::~eventlist()
{
	delete[]head;
	delete[]tail;
	delete[]current;
}

void eventlist::add_event(node* event)
{
	if (!head) //NULL
	{
		//head.set_data(event.data());
		//tail.set_data(event.data());
		//current.set_data(event.data());
		head=event;
		tail=event;
		current=event;
		//all links point to null from default parameter
	}
	else
	{
		tail->set_link(event);
		tail=tail->link();
	}
}

void eventlist::remove_event()
{
	if (!head->link()) // NULL
	{
		head=NULL;
		current=NULL;
		tail=NULL;
	}
	else if (current->data().get_name()==head->data().get_name())
	{
		head=head->link();
		current=current->link();
	}
	else
	{
		node* follower = new node;
		node* leader = new node;
		follower=head;
		leader=head->link();
		while (leader->link()!=NULL && leader->data().get_name()!=current->data().get_name())
		{
			follower=follower->link();
			leader=leader->link();
		}
		if (tail->data().get_name()==current->data().get_name())
		{
			tail=follower;
			tail->set_link(NULL);
		}
		else if (leader->link()==NULL)
		{
			cout << "Event not found!" << endl;
		}
		else // remove leader
		{
			follower->set_link(leader->link());
		}
	}
}

void eventlist::move_head()
{
	if (head!=current)
	{
		// if (head->link()==tail) //2 node list and current is tail
		// {
			// node* temp = new node;
			// temp.set_data(head.data());
			//temp.set_link(head.link());
			// head.set_data(tail.data());
			//head.set_link(tail.link());
			// tail.set_data(temp.data());
			//tail.set_link(temp.link());
		// }
		// node* follower = new node;
		// node* leader = new node;
		// follower=head;
		// leader=head->link();
		// while (follower->link()!=current)
		// {
			// follower=follower->link();
			// leader=leader->link();
		// }
		node* temp = new node;
		temp->set_data(head->data());
		//temp.set_link(head.link());
		head->set_data(current->data());
		//head.set_link(current.link());
		current->set_data(temp->data());
		current=head;
	}
}

void eventlist::move_tail()
{
	if (tail!=current)
	{
		node* temp = new node;
		temp->set_data(tail->data());
		tail->set_data(current->data());
		current->set_data(temp->data());
		current=tail;
	}
}

void eventlist::output_events()
{
	ofstream out_stream;
	out_stream.open("data.txt");
	while (head)
	{
		out_stream << head->data();
		head=head->link();
	}
	out_stream.close();
}