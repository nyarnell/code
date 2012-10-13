
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
		//new customer check
		int cust1=rand()%100+1;
		if (cust1 <=15){
			new_customer();
			ofs << "New customer!" << endl;
		}
		//rain check
		int rain1=rand()%100+1;
		if (rain1 <=25){
			pay_labor_costs(get_num_teams()*20);
			grow_grass(.27);
			ofs << "It has rained and all of the workers went home." << endl;
		}
		//height check
		else if (lawns.top().get_height()<3.0){
			pay_labor_costs(get_num_teams()*20);
			grow_grass(.15);
			ofs << "The grass isn't long enough to cut at any houses, workers went home." << endl;
		}
		else{
			ofs << "Mowing on day " << day+1 << "." << endl;
			//set busy bools to false
			for (vector<Crew>::iterator it = crews.begin(); it!=crews.end(); ++it){ it->set_busy(false); }
			//hours loop begins
			for (int hours=0; hours<10; hours++){
				pay_labor_costs(get_num_teams()*17);
				//minutes loop begins
				for (int minutes=0; minutes<60; minutes++){
					for (vector<Crew>::iterator it4 = crews.begin(); it4!=crews.end(); ++it4){
						if (it4->get_en_route()){
							//check if the crew has arrived
							if (hours*60+minutes == it4->get_busy_minutes()){
								int dog1 = rand()%100+1; //dog exception
								bool doghere=false;
								try{
								if ( dog1<=2 ){
									doghere=true;
									throw doghere;
									}//dog exception
								}
								catch(bool &doghere){	
									doghere=true;
									ofs << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it4->get_crew_number();
									ofs << " has arrived at " << it4->get_best_lawn() << endl;	
									ofs << "There's a dog at this house, the crew had to leave" << endl;
									it4->get_best_lawn().set_dog(1);
									it4->set_en_route(false);
									it4->set_mowing(false);
									it4->set_busy(false);
									Lawn temp = it4->get_best_lawn();
									list<Lawn> candidates;
									double best_lawn_time = 9999; //arbitrarily high number. Initializing to 0 would cause problems
									bool go_home = true;
									//move the number of crews worth of lawns from the priority queue, or if that number is larger than
									//the size of the priority queue, move everything in the PQ into candidates
									if ( num_teams > (int)lawns.size() ){
										for (int i = 0; i<(int)lawns.size(); i++){
											if (lawns.top().get_height()>=3.0){
												Lawn temp = lawns.top();
												lawns.pop();
												candidates.push_back(temp);
											}
										}
									}
									else{
										for (int i = 0; i<num_teams; i++){
											if (lawns.top().get_height()>=3.0){
												Lawn temp = lawns.top();
												lawns.pop();
												candidates.push_back(temp);
											}
										}
									}
									if ((int)candidates.size()>0){
										for (list<Lawn>::iterator it2 = candidates.begin(); it2!=candidates.end(); ++it2){
											//generate travel times, in minutes, for how long it will take the crew to get to the lawn
											//(time_to_lawn), how long it will take to mow the lawn (time_to_mow), and how long it will
											//take to travel home afterwards (time_to_home).
											double time_to_lawn = ceil(sqrt(pow((it4->get_x_coord()-it2->get_x_coord()), 2.0)+pow((it4->get_y_coord()-it2->get_y_coord()), 2.0))/.5);
											double time_to_mow = ceil(it2->get_area()/(600/(it2->get_height()-2.0)));
											double time_to_home = ceil(it2->get_home_distance()/.5);
											double travel_time = time_to_lawn+time_to_mow+time_to_home;
											//Check to see if a crew can go there, mow, and get back before the end of the day
											if (((9-hours)*60+(60-minutes)) > travel_time){
												if (time_to_lawn+time_to_mow < best_lawn_time){
													it4->set_best_lawn(*it2);
													it4->set_best_time_to_home(time_to_home);
													it4->set_best_time_to_lawn(time_to_lawn);
													it4->set_best_time_to_mow(time_to_mow);
													best_lawn_time = time_to_lawn+time_to_mow;
													go_home = false;
												}
											}
										}
										if (go_home){
											//This loop occurs if none of the lawns can be travelled to before the end of the day.
											//So we send them home, calculating their travel costs.
											ofs << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it4->get_crew_number();
											ofs << " sent home for the day." << endl;
											it4->set_busy(true);
											it4->set_x_coord(5.0);
											it4->set_y_coord(7.5);
											pay_vehicle_costs(ceil(sqrt(pow((it4->get_x_coord()-5.0), 2.0)+pow((it4->get_y_coord()-7.5), 2.0))*.55));
											for (list<Lawn>::iterator it3 = candidates.begin(); it3!=candidates.end(); ++it3){	
												lawns.push(*it3);
											}
										}
										else {
											for (list<Lawn>::iterator it3 = candidates.begin(); it3!=candidates.end(); ++it3){
												//push everything except for best_lawn back into the priority queue
												if ((*it3)!=it4->get_best_lawn()) lawns.push(*it3);
											}
											pay_vehicle_costs(it4->get_best_time_to_lawn()*.55);
											it4->set_busy_minutes(hours*60+minutes+it4->get_best_time_to_lawn());
											it4->set_busy(true);
											it4->set_en_route(true);
											it4->set_x_coord(it4->get_best_lawn().get_x_coord());
											it4->set_y_coord(it4->get_best_lawn().get_y_coord());
										}
									} 
									else{
										//This loop occurs if candidates is empty, which can be because the priority queue is empty, or if
										//none of the lawns in lawns has a grass height >= 3.0
										ofs << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it4->get_crew_number();
										ofs << " sent home for the day." << endl;
										it4->set_busy(true);
										it4->set_x_coord(5.0);
										it4->set_y_coord(7.5);
										pay_vehicle_costs(ceil(sqrt(pow((it4->get_x_coord()-5.0), 2.0)+pow((it4->get_y_coord()-7.5), 2.0))*.55));
									}
									lawns.push(temp);
								}
								if(!doghere){
									ofs << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it4->get_crew_number();
									ofs << " has arrived at " << it4->get_best_lawn() << endl;
									pay_lawnmower_costs(it4->get_best_lawn().get_area()*.005);
									it4->set_en_route(false);
									it4->set_mowing(true);
									it4->set_busy_minutes(hours*60+minutes+it4->get_best_time_to_mow());
								}
							}
						}
					}
					for (vector<Crew>::iterator it5 = crews.begin(); it5!=crews.end(); ++it5){
						if (it5->get_mowing()){
							//check if the crew is done mowing
							if (hours*60+minutes == it5->get_busy_minutes()){
								ofs << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it5->get_crew_number();
								ofs << " has finished mowing at " << it5->get_best_lawn() << endl;
								set_num_mows(get_num_mows()+1);
								it5->set_mowing(false);
								it5->set_busy(false);
								it5->get_best_lawn().set_height(2.0);
								lawns.push(it5->get_best_lawn());
							}
						}
					}
					for (vector<Crew>::iterator it = crews.begin(); it!=crews.end();){
						//iterate until you find a non-busy crew
						if (it->get_busy()) {++it;}
						else{
							list<Lawn> candidates;
							double best_lawn_time = 9999; //arbitrarily high number. Initializing to 0 would cause problems
							bool go_home = true;
							//move the number of crews worth of lawns from the priority queue, or if that number is larger than
							//the size of the priority queue, move everything in the PQ into candidates
							if ( num_teams > (int)lawns.size() ){
								for (int i = 0; i<(int)lawns.size(); i++){
									Lawn temp2 = lawns.top();
									if (lawns.top().get_height()>=3.0 && !temp2.get_dog()){
										Lawn temp = lawns.top();
										lawns.pop();
										candidates.push_back(temp);
									}
								}
							}
							else{
								for (int i = 0; i<num_teams; i++){
									Lawn temp3 = lawns.top();
									
									if (lawns.top().get_height()>=3.0 && !temp3.get_dog()){
										Lawn temp = lawns.top();
										lawns.pop();
										candidates.push_back(temp);
									}
								}
							}
							if ((int)candidates.size()>0){
								for (list<Lawn>::iterator it2 = candidates.begin(); it2!=candidates.end(); ++it2){
									//generate travel times, in minutes, for how long it will take the crew to get to the lawn
									//(time_to_lawn), how long it will take to mow the lawn (time_to_mow), and how long it will
									//take to travel home afterwards (time_to_home).
									double time_to_lawn = ceil(sqrt(pow((it->get_x_coord()-it2->get_x_coord()), 2.0)+pow((it->get_y_coord()-it2->get_y_coord()), 2.0))/.5);
									double time_to_mow = ceil(it2->get_area()/(600/(it2->get_height()-2.0)));
									double time_to_home = ceil(it2->get_home_distance()/.5);
									double travel_time = time_to_lawn+time_to_mow+time_to_home;
									//Check to see if a crew can go there, mow, and get back before the end of the day
									if (((9-hours)*60+(60-minutes)) > travel_time){
										if (time_to_lawn+time_to_mow < best_lawn_time){
											it->set_best_lawn(*it2);
											it->set_best_time_to_home(time_to_home);
											it->set_best_time_to_lawn(time_to_lawn);
											it->set_best_time_to_mow(time_to_mow);
											best_lawn_time = time_to_lawn+time_to_mow;
											go_home = false;
										}
									}
								}
								if (go_home){
									//This loop occurs if none of the lawns can be travelled to before the end of the day.
									//So we send them home, calculating their travel costs.
									ofs << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it->get_crew_number();
									ofs << " sent home for the day." << endl;
									it->set_busy(true);
									it->set_x_coord(5.0);
									it->set_y_coord(7.5);
									pay_vehicle_costs(ceil(sqrt(pow((it->get_x_coord()-5.0), 2.0)+pow((it->get_y_coord()-7.5), 2.0))*.55));
									for (list<Lawn>::iterator it3 = candidates.begin(); it3!=candidates.end(); ++it3){	
										lawns.push(*it3);
									}
								}
								else {
									for (list<Lawn>::iterator it3 = candidates.begin(); it3!=candidates.end(); ++it3){
										//push everything except for best_lawn back into the priority queue
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
								//This loop occurs if candidates is empty, which can be because the priority queue is empty, or if
								//none of the lawns in lawns has a grass height >= 3.0
								ofs << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " - Crew #" << it->get_crew_number();
								ofs << " sent home for the day." << endl;
								it->set_busy(true);
								it->set_x_coord(5.0);
								it->set_y_coord(7.5);
								pay_vehicle_costs(ceil(sqrt(pow((it->get_x_coord()-5.0), 2.0)+pow((it->get_y_coord()-7.5), 2.0))*.55));
								++it;
							}
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
	ofs << "Lawnmower costs: $" << lawnmower_costs << endl << endl;
	ofs.close();
}


void Sim::output_lawns(){
	ofstream ofs;
	//open logfile in append mode
	ofs.open("logfile.txt", fstream::in | fstream::out | fstream::app);
	ofs << "The " << lawns.size() << " lawns from tallest grass to shortest:" << endl;
	priority_queue<Lawn> tmp;
	while (!lawns.empty())
	{
		Lawn l = lawns.top();
		ofs << l << endl;
		tmp.push(l);
		lawns.pop();
	}
	lawns = tmp;
	ofs.close();
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
	//uses basically the same code as Sim()
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