#include <iostream> //for cout
#include <fstream> // file i/o
#include <cstdlib> // for exit
#include <iomanip> // for setw
#include <string>  // for getline
using namespace std;

void show_results (ifstream& file_in, ofstream& file_out);

// need documentation for this function

int main()
{
  ifstream fin;
  ofstream fout;

  fin.open("scores.dat");

  if (fin.fail())
  {
    cout<<"Input file fail to open \n";
    exit(1);
  }

  fout.open("scores.out");

  if (fout.fail())
  { 
    cout<<"Input file fail to open \n";
    exit(1);
  }
 
  show_results (fin,fout);  // function call

   fin.close();
   fout.close();

  return 0;
}


 void show_results (ifstream& file_in, ofstream& file_out)
{

  file_out.setf(ios::fixed);
  file_out.setf(ios::showpoint);
  file_out.precision(2);

  string name;  // full name read from the data file
  
  double score1,score2,score3,score4;  // 4 scores

  getline(file_in,name); // read the full name

  while (file_in>> score1>> score2 >> score3>> score4)
  {
 
    file_out.setf(ios::left);

    file_out <<setw(20)<< name;

    file_out.unsetf(ios::left); // cout.setf(ios::right) will not work
                         
    file_out << setw(8)<<score1<<setw(10)<<score2
             <<setw(10)<<score3<<setw(10)<<score4<<endl;

    file_in.ignore(100,'\n');// to remove the '\n' from the input stream
                        // to read the next name
    
    getline(file_in,name);   // read the next name
 }

}
