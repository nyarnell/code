#ifndef SIM_H
#define SIM_H

#include "crew.h"
#include "lawn.h"
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Sim{

	public:
		Sim();
		Sim(int n, int t, int d);

		void set_num_cust(int n){ num_cust = n; }
		void set_num_teams(int t){ num_teams = t; }
		void set_num_days(int d) { num_days = d; }
		void set_labor_costs(double l) { labor_costs = l; }
		void set_vehicle_costs(double v) { vehicle_costs = v; }
		void set_lawnmower_costs(double m) {lawnmower_costs = m; }
		void set_num_mows(int p) { num_mows = p; }
		
		void pay_labor_costs(double labor) {labor_costs+=labor;}
		void pay_vehicle_costs(double gas) {vehicle_costs+=gas;}
		void pay_lawnmower_costs(double work) {lawnmower_costs+=work;}

		int get_num_cust(){ return num_cust; }
		int get_num_teams(){ return num_teams; }
		int get_num_days(){ return num_days; }	
		double get_labor_costs() { return labor_costs; }
		double get_vehicle_costs() {return vehicle_costs; }
		double get_lawnmower_costs() {return lawnmower_costs; }
		int get_num_mows() {return num_mows; }

		bool read_lawns(string lawn_file);
		void new_customer();
		void run(string logfile); //needs to be implemented
		void output_lawns();
		void grow_grass(double growth); //needs to be implemented
		double total_costs() { return labor_costs+vehicle_costs+lawnmower_costs; }
		
		priority_queue<Lawn> lawns;
		vector<Crew> crews;
		
	private:
		vector<bool> used;

		unsigned int num_cust;
		int num_teams;
		int num_days;
		double labor_costs;
		double vehicle_costs;
		double lawnmower_costs;
		int num_mows;
};


#endif
