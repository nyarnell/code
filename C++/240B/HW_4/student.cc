// Name: Nathaniel Yarnell
// Date: 2/17/2012
// Description: This file contains the implementation of the class student.

#include <iostream>
#include <string>
#include <fstream>
#include "student.h"

using namespace std;

student::student()
{
	string title, num;
	double time;
	node* tmp = new node;
	name="";
	pid="";
	gpa=0.0;
	total_hours=0.0;
	head=NULL;
	//tmp=head;
	ifstream ins;
	ins.open("data.txt");
	if (!ins.eof()) //blank file
	{
		//cout << "test" << endl;
		getline(ins, name);
		//cout << name << "testname" << endl;
		ins >> pid >> gpa >> total_hours;
		//cout << pid << gpa << total_hours << "testdata" << endl;
		//if (ins.peek()=='\n') {ins.ignore();}
		head = new node;
		tmp=head;
		//tmp = new node;
		ins >> title;
		//cout << "titletest" << endl;
		while (!ins.eof())
		{
			//cout << "instest" << endl;
			tmp->course=title;
			ins >> tmp->grade;
			ins >> tmp->hours;
			if (!ins.eof()) 
			{
				tmp->link= new node;
				tmp=tmp->link;	
			}
			//tmp=tmp->link;
			ins >> title;
		}
		//cout << "linktest" << endl;
		tmp=NULL;
		//cout << "nulltest" << endl;
		
	}
	//cout << "test" << endl;
	ins.close();
}

student::~student()
{
	delete[]head;
	cout << endl << "yum ram" << endl;
}

student::student(const student& copy)
{
	name=copy.name;
	pid=copy.pid;
	gpa=copy.gpa;
	total_hours=copy.total_hours;
	node* s_ptr; 
	node* d_ptr;
	if (copy.head==NULL){head=NULL;}
	else
	{
		s_ptr=copy.head;
		head = new node;
		head->course=s_ptr->course;
		head->grade=s_ptr->grade;
		head->hours=s_ptr->hours;
		head->link=NULL;
		d_ptr=head;
		s_ptr=s_ptr->link;
		while (s_ptr!=NULL)
		{
			d_ptr->link = new node;
			d_ptr=d_ptr->link;
			d_ptr->course=s_ptr->course;
			d_ptr->grade=s_ptr->grade;
			d_ptr->hours=s_ptr->hours;
			s_ptr=s_ptr->link;
		}
		d_ptr->link=NULL;
	}
}

void student::set_name_pid(string title, string id)
{
	name=title;
	pid=id;
}

void student::view_info()
{
	cout << "Name: " << name << endl;
	cout << "PID: " << pid << endl;
	cout << "Total hours: " << total_hours << endl;
	cout << "GPA: " << gpa << endl << endl;
}

void student::view_courses()
{
	node* tmp=head;
	if (tmp==NULL)
	{
		cout << "No courses!" << endl;
	}
	while (tmp!=NULL)
	{
		cout << endl << "Course: " << tmp->course << endl;
		cout << "Grade: " << tmp->grade << endl;
		cout << "Hours: " << tmp->hours << endl;
		tmp=tmp->link;
	}
}

void student::insert_course(node* course) //copy constructor used
{
	if (head==NULL) // empty list
	{
		head=course;
	}
	else
	{
		if (head->course>course->course) // course is first
		{
			course->link=head;
			head=course;
		}
		else if (head->link==NULL) // head goes first but is the only node
		{
			head->link=course;
		}
		else // staggered pointers
		{
			node* follower = new node;
			node* leader = new node;
			follower=head;
			leader=head->link; // we know head->course<course->course
			while (leader->course<course->course && leader->link!=NULL)
			{
				follower=follower->link;
				leader=leader->link;
			}
			if (leader->link==NULL) // course is last
			{
				leader->link=course;
			}
			else
			{
				course->link=follower->link;
				follower->link=course;
			}
		}
	}
	calc_gpa();
}

void student::remove_course(string classname)
{
	if (head==NULL) // empty list
	{
		cout << "No courses to remove!" << endl;
	}
	else
	{
		if (head->course==classname) // head needs to be removed
		{
			head=head->link;
		}
		else
		{
			node* follower = new node;
			node* leader = new node;
			follower=head;
			leader=head->link;
			while (leader!=NULL && leader->course!=classname)
			{
				follower=follower->link;
				leader=leader->link;
			}
			if (leader==NULL)
			{
				cout << "Course not found =[" << endl;
			}
			else // found
			{
				follower->link=leader->link; // removes leader
			}
		}
	}
	calc_gpa();
}

void student::calc_gpa()
{
	double overall, score;
	node* temp=head;
	total_hours=0;
	while (temp!=NULL)
	{
		if (temp->grade=="A" or temp->grade=="a") {score=4.0;}
		if (temp->grade=="A-" or temp->grade=="a-") {score=3.66;}
		if (temp->grade=="B+" or temp->grade=="b+") {score=3.33;}
		if (temp->grade=="B" or temp->grade=="b") {score=3.0;}
		if (temp->grade=="B-" or temp->grade=="b-") {score=2.66;}
		if (temp->grade=="C+" or temp->grade=="c+") {score=2.33;}
		if (temp->grade=="C" or temp->grade=="c") {score=2.0;}
		if (temp->grade=="C-" or temp->grade=="c-") {score=1.66;}
		if (temp->grade=="D+" or temp->grade=="d+") {score=1.33;}
		if (temp->grade=="D" or temp->grade=="d") {score=1.0;}
		if (temp->grade=="D-" or temp->grade=="d-") {score=0.66;}
		if (temp->grade=="F" or temp->grade=="f") {score=0.33;}
		overall+=(score*temp->hours);
		total_hours+=temp->hours;
		temp=temp->link;
	}
	gpa=(overall/total_hours);
}

student& student::operator = (const student& rhs)
{
	if (this!=&rhs)
	{
		head=rhs.head;
		name=rhs.name;
		pid=rhs.pid;
		gpa=rhs.gpa;
		total_hours=rhs.total_hours;
	}
	return *this;
}

void student::output_student()
{
	ofstream outs;
	outs.open("data.txt");
	outs << name << endl;
	outs << pid << " " << gpa << " " << total_hours;
	while (head!=NULL)
	{
		outs << " " << head->course << " " << head->grade << " " << head->hours;
		head=head->link;
	}
	outs.close();
}