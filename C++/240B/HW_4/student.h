// Name: Nathaniel Yarnell
// Date: 2/17/2012
// Description: This file contains the interface of the class student.

#include <string>

using namespace std;

struct node
{
	string course;
	string grade;
	double hours;
	node* link;
};

class student
{
	public:
		student();
		~student();
		student(const student& copy);
		void set_name_pid(string title, string id);
		void view_info();
		void view_courses();
		void insert_course(node* course);
		void remove_course(string classname);
		student& operator = (const student& rhs);
		void output_student();
	private:
		string name;
		string pid;
		double gpa;
		double total_hours;
		node* head;
		void calc_gpa();
};