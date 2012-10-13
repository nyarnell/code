#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "sim.h"

using namespace std;

int main ( int argc, char *argv[] )
{
	//initialize random val
	srand(time(NULL));

	//case for incorrect number of arguments - error and syntax message
	//if there are not 4 arguments (./a.out counts as one) then 
	//it will spit out an error message
	if(argc!=4){
		cerr << "Incorrect number of arguments." 
		<< "\nUsage: " << argv[0] << " [c] [t] [d]" << endl
		<< "\tc - customers\n\tt - teams\n\td - days" << endl;
		return(-1);	
	}

	//Make new Sim and
	//convert arguments to ints - arguments come in as char
	//argv[1] is how we extract the arguments passed
	Sim s(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

	//Read the lawns into PQ from file passed to read_lawns
	if(!s.read_lawns("lawns.txt")){
		cerr << "Error loading customers" << endl;
		return -1;
	}

	//Run the sim with output going to file passed to run
	s.run("logfile.txt");

	s.output_lawns();
	
	//fin.close();

	return 0;
}

