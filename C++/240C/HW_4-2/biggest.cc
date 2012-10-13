/*******************************************************************
    CS240C Spring 2012 Recursive homework #2
	Professor = John Dolan		My name = Nathaniel Yarnell
	May 14, 2012
    For this project you are to write the implementation of the function,
    find_largest. Compile and run you code. Put your name in the spot above
    and then save it one more time before printing out this file to hand 
    in. This is due in class on May 15th.
*********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node{
     int data;
     node *link;
};

int find_largest(node *head); // 5 points for this version OR
//void find_largest(node *head, int& big); // 4 points for this version

int main(){

srand(time(NULL));

node *head;
head = new node;
head->data = rand();
node *ptr = head;

// make a list of 50 random numbers
for(int i = 0;i<50; ++i){
     ptr->link = new node;
     ptr= ptr->link;
     ptr->data = rand();
     }
ptr->link = NULL;

// Your find_largest will find the largest number in this particular list.
cout << "The largest item in the list is: " << find_largest( head ) << endl;

return 0;
}

int find_largest(node *head){
	if ( NULL != head->link ){ 
		int num = find_largest(head->link);
		if ( num > head->data ) { return num; }
		else return head->data;
	}
	else return head->data;
}
