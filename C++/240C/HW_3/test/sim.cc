
#include "sim.h"
#include "crew.h"
#include <fstream>
#include <cstdlib>
#include <list>
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <math.h>

using namespace std;

Sim::Sim(){
	num_cust = 0;
	num_teams = 0;
	num_days = 0;
	labor_costs = 0;
	vehicle_costs = 0;
	lawnmower_costs = 0;
	num_mows = 0;
}

Sim::Sim(int n, int t, int d){
	num_cust = n;
	num_teams = t;
	num_days = d;
	labor_costs = 0;
	vehicle_costs = 0;
	lawnmower_costs = 0;
	num_mows = 0;
	for (int i=0; i<num_teams; i++)
	{
		Crew* temp;
		temp = new Crew;
		temp->set_crew_number(i+1);
		crews.push_back(*temp);
	}
}

bool Sim::read_lawns(string lawn_file){
	//Create ifstream
	ifstream fin;
	fin.open((char*)lawn_file.c_str());
	if(fin.fail()){
		return false;
	}

	//First put Lawns into a vector so later
	//we can randomly select some
	vector<Lawn> tmp;
	//vector<bool> used; //now a private member function of Sim

	//Process file
	Lawn l;
	fin >> l;

	while(fin.good()){
		tmp.push_back(l);	
		fin >> l;
	}

	//Close ifstream
	fin.close();

	//ERROR CHECK - make sure num_customers < num_lawns
	if(tmp.size() < num_cust){
		cerr << "Error: too many customers" << endl;
		return false;
	}

	//Make sure we dont reuse lawns
	used.resize(tmp.size());
	for(size_t i = 0; i < used.size(); ++i){
		used[i] = false;
	}

	//now restrict the list to randomly chosen customers
	for(unsigned int i = 0; i < num_cust; ++i){
		size_t index = rand()%tmp.size();
		while(used[index] == true) index = rand()%tmp.size();

		lawns.push(tmp[index]);
		used[index] = true;
	}

	return true;
}	

void Sim::run(string logfile){
	ofstream ofs;
	ofs.open("logfile.txt");
	for (int day=0; day<get_num_days(); day++){
		ofs << endl << "Day " << day+1 << ": We have " << get_num_cust() << " Customers." << endl;
		unsigned int cust1=rand()%100+1; //customer
		if (cust1 <=15){ new_customer(); }
		int rain1=rand()%100+1; //raining
		if (rain1 <=25){ //rain
			pay_labor_costs(get_num_teams()*20);
			grow_grass(.27);
			ofs << "It has rained and all of the workers went home." << endl;// output to logfile that it rained
		}
		else if (lawns.top().get_height()<3.0){ //no lawns to mow today
			pay_labor_costs(get_num_teams()*20);
			grow_grass(.15);
			ofs << "The grass isn't long enough to cut at any houses, workers went home." << endl;
		}
		else{
			cout << endl << "Mowing on day " << day+1 << "." << endl;
			ofs << "Mowing on day " << day+1 << "." << endl;
			for (vector<Crew>::iterator it = crews.begin(); it!=crews.end(); ++it){
				it->set_busy(false);
				it->set_en_route(false);
				it->set_mowing(false);
				it->set_x_coord(5.0);
				it->set_y_coord(7.5);
			}
			for (int hours=0; hours<10; hours++){ //hours loop begins
				//cout << "Hour " << hours << endl;
				pay_labor_costs(get_num_teams()*17); //pay workers their hourly wage
				for (int minutes=0; minutes<60; minutes++){ //minutes loop
					//cout << "Minute " << minutes << endl;
					for (vector<Crew>::iterator it4 = crews.begin(); it4!=crews.end(); ++it4){
						if (it4->get_en_route()){
							//cout << "get_en_route loop" << endl;
							if (hours*60+minutes == it4->get_busy_minutes()){ //ready to mow
								//int dog1 = rand()%100+1; //dog exception
								//if ( dog1<=2 ){ ofs << "Theres a dog at this house, the crew had to leave" << endl; }//dog exception
								//else{
									cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it4->get_crew_number();
									cout << " has arrived at " << it4->get_best_lawn() << endl;
									ofs << "Crew Mowed Lawn" << endl;
									pay_lawnmower_costs(it4->get_best_lawn().get_area()*.005);
									it4->set_en_route(false);
									it4->set_mowing(true);
									it4->set_busy_minutes(hours*60+minutes+it4->get_best_time_to_mow());
								//}
							}
						}
					}
					for (vector<Crew>::iterator it5 = crews.begin(); it5!=crews.end(); ++it5){
						if (it5->get_mowing()){
							//cout << "get_mowing loop" << endl;
							if (hours*60+minutes == it5->get_busy_minutes()){ //done mowing
								cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it5->get_crew_number();
								cout << " has finished mowing at " << it5->get_best_lawn() << endl;
								set_num_mows(get_num_mows()+1);
								it5->set_mowing(false);
								it5->set_busy(false);
								it5->get_best_lawn().set_height(2.0);
								//cout << "Height after mowing: " << it5->get_best_lawn().get_height() << endl;
								lawns.push(it5->get_best_lawn());
							}
						}
					}
					for (vector<Crew>::iterator it = crews.begin(); it!=crews.end();){
						if (it->get_busy()) {++it;}
						else{
							list<Lawn> candidates;
							double best_lawn_time = 9999; //arbitrarily high number. Initializing to 0 would cause problems
							bool go_home = true;
							//cout << endl << "Number of customers in lawns: " << (int)lawns.size() << endl;
							//cout << "List of candidates for crew #" << it->get_crew_number() << ":" << endl;
							int x = (int)lawns.size();
							if ( num_teams > (int)lawns.size() ){
								for (int i = 0; i<x; i++){
									if (lawns.top().get_height()>=3.0){
										//cout << "Height of the top lawn: " << lawns.top().get_height() << endl;
										Lawn temp = lawns.top();
										lawns.pop();
										candidates.push_back(temp);
										//cout << temp << endl;
									}
								}
							}
							else{
								for (int i = 0; i<num_teams; i++){
									if (lawns.top().get_height()>=3.0){
										//cout << "Height of the top lawn: " << lawns.top().get_height() << endl;
										Lawn temp = lawns.top();
										lawns.pop();
										candidates.push_back(temp);
										//cout << temp << endl;
									}
								}
							}
							//cout << "Number of customers in candidates: " << candidates.size() << endl;
							//cout << endl;
							if ((int)candidates.size()>0){
								for (list<Lawn>::iterator it2 = candidates.begin(); it2!=candidates.end(); ++it2){
									//cout << "Calculating travel times for: " << *it2 << endl;
									double time_to_lawn = ceil(sqrt(pow((it->get_x_coord()-it2->get_x_coord()), 2.0)+pow((it->get_y_coord()-it2->get_y_coord()), 2.0))/.5);
									//cout << "Time to lawn: " << time_to_lawn << endl;
									double time_to_mow = ceil(it2->get_area()/(600/(it2->get_height()-2.0))); 	// 600/length is their mowing speed in
									//cout << "Time to mow: " << time_to_mow << endl;
									double time_to_home = ceil(it2->get_home_distance()/.5);
									//cout << "Time to home: " << time_to_home << endl;
									//cout << "Lawn time: " << time_to_lawn+time_to_mow << endl;
									double travel_time = time_to_lawn+time_to_mow+time_to_home;
									if (((9-hours)*60+(60-minutes)) > travel_time){
										if (time_to_lawn+time_to_mow < best_lawn_time){ //then the lowest combination of travel and work is the best
											it->set_best_lawn(*it2);
											it->set_best_time_to_home(time_to_home);
											it->set_best_time_to_lawn(time_to_lawn);
											it->set_best_time_to_mow(time_to_mow);
											best_lawn_time = time_to_lawn+time_to_mow;
											go_home = false;
										}
									}
								}
								cout << "Crew #" << it->get_crew_number() << endl;
								cout << "Best lawn: " << it->get_best_lawn() << endl;
								cout << "Best lawn time: " << best_lawn_time << endl << endl;
								if (go_home){
									ofs << "Crew sent home for the day" << endl;
									it->set_busy(true); // this crew cannot drive to a lawn, mow it, and drive home before the end of the day. 
									it->set_x_coord(5.0); // so we set them to busy and their coordinates back to the home base, and
									it->set_y_coord(7.5); // pretend like they drove there. They remain busy until the next day.
									pay_vehicle_costs(ceil(sqrt(pow((it->get_x_coord()-5.0), 2.0)+pow((it->get_y_coord()-7.5), 2.0))*.55));
									for (list<Lawn>::iterator it3 = candidates.begin(); it3!=candidates.end(); ++it3){	
										lawns.push(*it3);
									}
								}
								else {
									for (list<Lawn>::iterator it3 = candidates.begin(); it3!=candidates.end(); ++it3){	
										if ((*it3)!=it->get_best_lawn()) lawns.push(*it3);
									}
									pay_vehicle_costs(it->get_best_time_to_lawn()*.55);
									it->set_busy_minutes(hours*60+minutes+it->get_best_time_to_lawn());
									it->set_busy(true);
									it->set_en_route(true);
									it->set_x_coord(it->get_best_lawn().get_x_coord());
									it->set_y_coord(it->get_best_lawn().get_y_coord());
								}
							} 
							else{
								ofs << "Crew sent home for the day" << endl;
								it->set_busy(true); // this crew cannot drive to a lawn, mow it, and drive home before the end of the day. 
								it->set_x_coord(5.0); // so we set them to busy and their coordinates back to the home base, and
								it->set_y_coord(7.5); // pretend like they drove there. They remain busy until the next day.
								pay_vehicle_costs(ceil(sqrt(pow((it->get_x_coord()-5.0), 2.0)+pow((it->get_y_coord()-7.5), 2.0))*.55));
								++it;
							}; // do nothing if there are no candidates
						} //busy check loop
					}
				} //minutes loop
			} //hours loop
			grow_grass(.15); //end of the day
		} //rain / new customer check loop
	} //days loop
	ofs << endl << "Total costs: $" << labor_costs+vehicle_costs+lawnmower_costs << endl;
	ofs << "Labor costs: $" << labor_costs << endl;
	ofs << "Vehicle costs: $" << vehicle_costs << endl;
	ofs << "Lawnmower costs: $" << lawnmower_costs << endl;
	ofs.close();
}


void Sim::output_lawns(){ //I think this needs to output to the log file, not cout
	cout << "The " << lawns.size() << " lawns from tallest grass to shortest:" << endl;
	priority_queue<Lawn> tmp;
	while (!lawns.empty())
	{
		Lawn l = lawns.top();
		cout << l << endl;
		tmp.push(l);
		lawns.pop();
	}
	lawns = tmp;
}

void Sim::grow_grass(double growth){
	list<Lawn> grown;
	while (!lawns.empty()){
		Lawn temp = lawns.top();
		
		lawns.pop();
		temp.set_length(temp.get_length()+growth);
		grown.push_back(temp);
	}
	for (list<Lawn>::iterator it = grown.begin(); it!=grown.end(); ++it){
		lawns.push(*it);
	}	
}

void Sim::new_customer(){
	vector<Lawn> tmp;
	ifstream fin;
	fin.open("lawns.txt");
	Lawn l;
	fin >> l;
	while(fin.good()){
		tmp.push_back(l);	
		fin >> l;
	}
	fin.close();
	size_t index = rand()%tmp.size();
	while(used[index] == true) index = rand()%tmp.size();
	lawns.push(tmp[index]);
	used[index] = true;
	num_cust++;
}
