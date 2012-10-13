#include <iostream>
using namespace std;
//*********************************************************
// Function: set
// Purpose:  set the width and the height according to the
//           incoming arguments
// Params:   w - the value for the width
//           h - the value for the height
// Calls:    none
// Uses:     check
//*********************************************************
//void Rectangle::set(int w, int h);
//*********************************************************************
// Function: input_measurements 
// Purpose:  reads and stores the values from the keyboard.
// Calls:    none
// Uses:     check
//*********************************************************************
//void Rectangle::input_measurements( );
//*********************************************************************
// Function: output_measurements
// Purpose:  output the height and width the screen.
// Calls:    none
// Uses:     ostream
//*********************************************************************
//void Rectangle::output_measurements( );
//*********************************************************************
// Function: calc_area
// Purpose:  calculate the area of the rectangle.
// Calls:    none
// Uses:     none
//*********************************************************************
//void Rectangle::calc_area( );
//*********************************************************************
// Function: calc_peri
// Purpose:  calculate the perimeter of the rectangle.
// Calls:    none
// Uses:     none
//*********************************************************************
//void Rectangle::calc_peri( );
//*********************************************************************
// Function: get_height
// Purpose:  returns the height of the rectangle.
// Calls:    none
// Uses:     none
//*********************************************************************
//int Rectangle::get_height( );
//*********************************************************************
// Function: get_width
// Purpose:  returns the width of the rectangle.          
// Calls:    none  
// Uses:     none   
//*********************************************************************
//int Rectangle::get_width( );

class Rectangle
{
  public:
     //mutator
      void set (int w, int h);
      void input_measurements();

      void calc_area();
      void calc_peri();
      void output_measurements();      

      // accessors
      int get_height();
      int get_width();

    private:
     void check(); // can be used with in the definition of the
                   // member fumctions of the rectangle class
     int height,
         width;
  };

void menu(char& ch);
//display the choices to th user

int main()
 {
   Rectangle r1;  // object of the Rectangle type
   char ans;     // loop control variable
   int ht,      // height of the rectangle
       wd;      // width of the rectangle

   cout <<" Enter the height and the width of the rectangle -->  ";
   cin >> ht >> wd;

   r1.set(ht,wd);  // set height and the width using the set member func.


   do{
     menu(ans);
     switch (ans){
     case 'a': case 'A':
               r1.calc_area();
               break;
     case 'i': case 'I':
               r1.input_measurements();
               break;
     case 'p': case 'P':
               r1.calc_peri();
               break;
     case 'o': case 'O':
               r1.output_measurements();
               break;
     case 'Q': case 'q':
               cout<<"   Thank you for using the program \n\n";
               break;
     default:
           cout<<" Not a valid option\n";
  }
  
 }while (ans != 'q' && ans != 'Q');
  
   return 0;
}   

void menu(char& ch)
{
   cout<<"\n  a -- Area   \n";
   cout<<"  p -- Perimeter \n";
   cout<<"  0 -- Output measurements  \n";
   cout<<"  I -- Input measurements \n";
   cout<<"  q -- Quit  \n\n";
   cout<<" Enter the choice  -->   ";
   cin>>ch;
}
          
void Rectangle :: set(int w, int h)
{
   width = w;
   height = h;
   check();
}


void Rectangle:: input_measurements()
{
   cout<<" enter the height and the width ";
   cin>>height>>width;
   check();
}

void Rectangle::check()
{
   while (height < 0 || width < 0){
     cout<<"Invalid.   Enter positive values -->   ";
     cin >> height >> width;
 }
}

void Rectangle :: calc_area()
{
   int ar;
   ar =  height * width;
   cout <<" Area is "<< ar  << endl;
}

void Rectangle:: calc_peri()
{
   int p;
   
   p = 2* (height + width);

   cout <<" Perimeter is "<< p  << endl;
}

int Rectangle::get_width()
{
  return (width);
}

int Rectangle::get_height()
{
   return (height);
}

void Rectangle ::output_measurements()
{
  cout <<" Height is = "<< height <<endl;
  cout <<" Width is =  "<< width  <<endl;
}
