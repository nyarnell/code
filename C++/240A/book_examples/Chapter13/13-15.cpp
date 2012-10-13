//DISPLAY 13.15 Program Using the Node Class
// This program demonstrates the creation of a linked list
// using the Node class.  Five nodes are created, output, then
// destroyed.  
#include <iostream>
#include "Node.h"

using namespace std;
using namespace linkedlistofclasses;

// This function inserts a new node onto the head of the list
// and is a class-based version of the same function defined
// in Display 15.4.  
void head_insert(NodePtr &head, int the_number)
{
NodePtr temp_ptr;
// The constructor sets temp_ptr->link to head and
// sets the data value to the_number
temp_ptr = new Node(the_number, head); 
head = temp_ptr;
}

int main()
{
NodePtr head, tmp;

// Create a list of nodes 4->3->2->1->0
head = new Node(0, NULL);
for (int i=1; i<5; i++)
{
head_insert(head, i);
}
// Iterate through the list and display each value
tmp = head;
while (tmp != NULL)
{
cout << tmp->getData() << endl;
tmp = tmp->getLink();
}
// Delete all nodes in the list before exiting
// the program.
tmp = head;
while (tmp != NULL)
{
NodePtr nodeToDelete = tmp;
tmp = tmp->getLink();
delete nodeToDelete;
}
return 0;
}
