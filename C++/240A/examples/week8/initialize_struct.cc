#include <iostream>
#include <string>
using namespace std;

// hierarchical structures

struct Day
{
  int month;
  int day;
  int year;
};

struct info
{
  string name;
  Day bday;
  double gpa;
};


int main()
{
  // initialize as you declare it

  info person1 = {"Joe Perfect",{1,1,1995},3.89};


  cout<<person1.name<<"  "<<person1.bday.month<<"  "
      <<person1.bday.day<<"  "<<person1.bday.year<<"  "
      <<person1.gpa<<endl <<endl;


  // Enter from the key board
 
  cout<<"Enter the name  ";
  getline(cin, person1.name);  // to get the full name
  cout<<"Enter the birthday  ";
  cin>>person1.bday.month>>person1.bday.day>>person1.bday.year;
  cout<<"Enter the gpa ";
  cin>>person1.gpa;

  cout<<person1.name<<"  "<<person1.bday.month<<"  "
      <<person1.bday.day<<"  "<<person1.bday.year<<"  "
      <<person1.gpa<<endl << endl;
  

  // using assignment statements

  person1.name = "Joe Smith";
  person1.bday.month = 12;
  person1.bday.day = 10;
  person1.bday.year = 1975;
  person1.gpa = 3.45;

  cout<<person1.name<<"  "<<person1.bday.month<<"  "
      <<person1.bday.day<<"  "<<person1.bday.year<<"  "
      <<person1.gpa<<endl <<endl;
 

 return 0;
}

  

