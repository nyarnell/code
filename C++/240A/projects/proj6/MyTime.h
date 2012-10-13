//**********************************************************************
// function: MyTime
// purpose: Default constructor stores 0 for both values
// parameters: none
// calls: none
//**********************************************************************
// function: MyTime(int h, int m);
// purpose: Constructor takes two values and assigns them
// parameters: int h, int m
// calls: simplify
//*
// function: AddMin
// purpose: Function takes one int argument, and adds that value
// to the minutes variable of a MyTime object
// parameters: int m
// calls: none
//*
// function: AddHr
// purpose: Function takes one int argument, and adds that value
// to the hours variable of a MyTime object
// parameters: int h
// calls: none
//*
// function: Reset
// purpose: Function resets the values of the calling object to the
// two arguments
// parameters: int h, int m
// calls: simplify
//*
// function: +
// purpose: overloads + so it can add two objects of type MyTime
// parameters: const MyTime& t1, const MyTime& t2
// calls: simplify
//*
// function: -
// purpose: overloads - so it can subtract two objects of type MyTime
// parameters: const MyTime& t1, const MyTime& t2
// calls: none
//*
// function: *
// purpose: overloads * so it can multiplty an object of type MyTime
// and a number, either object*num, or num*object.
// parameters: (const MyTime& t1, int num) or (int num, const MyTime& t1)
// calls: simplify
//*
// function: >>
// purpose: overloads >> so it can be used with objects of type MyTime
// parameters: istream& fin, MyTime& t
// calls: iomanip, for setfill and setw
//*
// function: <<
// purpose: overloads << so it can be used with objects of type MyTime
// parameters: ostream& fout, const MyTime& t
// calls: none
//*
// function: get_hours
// purpose: accessor function gets the value of hours
// parameters: none
// calls: none
//*
// function: get_minutes
// purpose: accessor function gets the value of minutes
// parameters: none
// calls: none
//*
// function: simplify
// purpose: this function ensures that the minutes variable of objects of
// type MyTime will always remain within the range of 0-59. If the value of minutes
// is greater than 59, hours++ and minutes=0;
// parameters: none
// calls: none
//*
// function: ==
// purpose: this function overloads == so it can be used with objects
// of type MyTime
// parameters: const MyTime& t1, const MyTime& t2
// calls: none
//*
// function: >
// purpose: this function overloads > so it can be used with objects of
// type MyTime
// parameters: const MyTime& t1, const MyTime& t2
// calls: none
//*
// function: <
// purpose: this function overloads < so it can be used with objects of
// type MyTime
// parameters: const MyTime& t1, const MyTime& t2
// calls: none

#include <iostream>
#include <iomanip>
using namespace std;
    
class MyTime
{   
  public:
    MyTime();
    MyTime(int h, int m);   
   
    void AddMin(int m);
    void AddHr(int h);
      
    void Reset(int h, int m);    
   
    friend MyTime operator + (const MyTime& t1, const MyTime& t2);

    friend MyTime operator + (const MyTime& t1, int num);

    friend MyTime operator + (int num, const MyTime& t1);
 
    friend MyTime operator - (const MyTime& t1, const MyTime& t2);

    friend MyTime operator - (const MyTime& t1, int num);

    friend MyTime operator - (int num, const MyTime& t1);
 
    friend MyTime operator * (const MyTime& t1, int num);
    
    friend MyTime operator * (int num, const MyTime& t1);

    friend istream& operator >>(istream& fin, MyTime& t);
    
    friend ostream& operator <<(ostream& fout, const MyTime& t);
            
    int get_hours() const;
    int get_minutes() const;
   
  private:
      void simplify();
      int hours;
      int minutes;   // 0 <= minutes <= 59
 };
   
 bool operator == (const MyTime& t1, const MyTime& t2);
   

 bool operator < (const MyTime& t1, const MyTime& t2);

 
 bool operator > (const MyTime& t1, const MyTime& t2);
