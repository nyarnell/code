//
// Program Name: text_processing.cc
//
// Name: Nathaniel Yarnell
// Email: nathanielbyarnell@gmail.com
//
//Description: This program takes an input file and formats it. It
//changers lowercase letters to uppercase, and replaces numbers with asterisks.
//
//Date: 2/16/11
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
  ifstream fin;
  ofstream fout;

  fin.open("Text.dat");
  if (fin.fail())
  {
    cout<<"Input file opening failed.\n";
    exit(1);
  }

  fout.open("output.dat");
  if (fout.fail())
  {
    cout<<"Output file opening failed.\n";
    exit(1);
  }
  
  char ch;
  do {
    fin.get(ch);
    if (islower(ch))
      {
        ch = toupper(ch);
        fout<<ch;
      }
    else if (isdigit(ch))
      fout<<'*';
    else
      fout<<ch;
  } while (!fin.eof());

  fin.close();
  fout.close();

  return 0;
}

