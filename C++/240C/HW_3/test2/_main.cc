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
	
	for (int day=0; day<s.get_num_days(); day++){
		if (rand function <=.15){ s.new_customer(); }
		if (rand function <=.25){ //rain
			s.pay_labor_costs(s.get_num_teams()*20);
			s.grow_grass(.27);
			// output to logfile that it rained
		}
		else if (lawns.top().get_height()<3.0){ //no lawns to mow today
			s.pay_labor_costs(s.get_num_crews()*20);
			s.grow_grass(.15);
		}
		else{
			for (vector<Crew>::iterator it = crews.begin(); it!=crews.end(); ++it){
				it.set_busy(false);
				it.set_en_route(false);
				it.set_mowing(false);
			}
			for (int hours=0; hours<10; hours++){ //hours loop begins
				s.pay_labor(s.get_num_crews()*17); //pay workers their hourly wage
				for (int minutes=0; minutes<60; minutes++){ //minutes loop
					for (vector<Crew>iterator it4 = crews.begin(); it4!=crews.end(); ++it4){
						if (it4.get_en_route()){
							if (minutes == it4.get_busy_minutes()){ //ready to mow
								//dog exception
								s.pay_lawnmower_costs(it4.get_best_lawn().get_area()*.005);
								it4.set_en_route(false);
								it4.set_mowing(true);
								it4.set_x_coord(it4.get_best_lawn().get_x_coord());
								it4.set_y_coord(it4.get_best_lawn().get_y_coord());
								//set busy time based on bestlawn area
							}
						}
					for (vector<Crew>iterator it5 = crews.begin(); it5!=crews.end(); ++it5){
						if (it5.get_mowing()){
							if (minutes == it5.get_busy_minutes()){ //done mowing
								s.set_num_mows(s.get_num_mows()+1);
								it5.set_mowing(false);
								it5.set_busy(false);
								it5.get_best_lawn().set_height(2.0);
								lawns.push(it5.get_best_lawn());
							}
						}
					}
					}
					vector<Crew>::iterator it = crews.begin();
					while (!it.get_busy()) {++it;} //the current crew is busy
					if !(it==crews.end()){ //do nothing until the next minute
						list<Lawn> candidates;
						Lawn best_lawn;
						double best_lawn_time = 9999; //arbitrarily high number. Initializing to 0 would cause problems
						bool go_home = true;
						double best_time_to_home;
						double best_time_to_lawn;
						double best_time_to_mow;
						for (int i = 0; i<s.get_num_teams(); i++){ //dolan says to try no more than the 
							Lawn temp = new Lawn;					//the number of teams working that day
							temp = lawns.top();
							lawns.pop();
							candidates.push_back(temp);
						}
						for (list<Lawn>::iterator it2 = candidates.begin(); it2!=candidates.end(); ++it2){
							double time_to_lawn = sqrt(pow((it.get_x_coord()-it2.get_x_coord()), 2.0)+pow((it.get_y_coord()-it2.get_y_coord()), 2.0))/.5;
							if (time_to_lawn%.5 > 0) { time_to_lawn++; } //if there is a remainder, it takes one more minute
							double time_to_mow = ceil(it2.get_area()/(600/it2.get_length())); 	// 600/length is their mowing speed in
							double time_to_home = it2.get_home_distance()/.5;							// feet per minute
							if (time_to_home%.5 > 0) { time_to_home++; }
							double travel_time = time_to_lawn+time_to_mow+time_to_home;
							if (hours<9  || travel_time+minutes<60){
								if (time_to_lawn+time_to_mow < best_lawn_time){ //then the lowest combination of travel and work is the best
									best_lawn = it2;
									best_time_to_home = time_to_home;
									best_time_to_lawn = time_to_lawn;
									best_time_to_mow = time_to_mow;
									go_home = false;
								}
							}
						}
						if (go_home){
							it.set_busy(true); // this crew cannot drive to a lawn, mow it, and drive home before the end of the day. 
							it.set_x_coord(5.0); // so we set them to busy and their coordinates back to the home base, and
							it.set_y_coord(7.5); // pretend like they drove there. They remain busy until the next day.
							s.pay_vehicle_costs(sqrt(pow((it.get_x_coord()-5.0), 2.0)+pow((it.get_y_coord()-7.5), 2.0))*.55)
							for (list<Lawn>::iterator it3 = candidates.begin(); it3!=candidates.end(); ++it3){	
								lawns.push(it3);
							}
						}
						else {
							//output to logfile that a crew has been assigned best_lawn
							it.set_best_lawn(best_lawn);
							for (list<Lawn>::iterator it3 = candidates.begin(); it3!=candidates.end(); ++it3){	
								if (!it3==best_lawn) lawns.push(it3);
							}
							s.pay_vehicle_costs(best_time_to_lawn*.55);
							if (best_time_to_lawn+minutes >= 60){
								it.set_busy_minutes(((best_time_to_lawn+minutes)%60)+1);
							}
							else it.set_busy_minutes(best_time_to_lawn+minutes+1);
							it.set_busy(true);
							it.set_en_route(true);
						}
				}
			}
			s.grow_grass(.15); //end of the day
		}
	}
	//ins.close();
	//outs.close();
}