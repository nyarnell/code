#include <iostream>

using namespace std;

struct node
{
	double data;
	node* link;
};

void funcstuff(node* course);

int main()
{
	node* stuff = new node;
	stuff->data=4.0;
	stuff->link=NULL;
	cout << stuff->data << endl;
	cout << stuff->link << endl;
	funcstuff(stuff);
}

void funcstuff(node* course)
{
	cout << course-> data << endl;
	cout << course-> link << endl;
}

void push(node* course, int num)
{
	node* tmp = new node;
	tmp->data=num;
	tmp->link=head;
	head=tmp;
}

node* pop()
{
	node* tmp = new node;
	tmp=head;
	head=head->link;
	return tmp;
}