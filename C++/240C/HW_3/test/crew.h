#ifndef CREW_H
#define CREW_H

#include "lawn.h"
#include <list>

class Crew{
	public:
		Crew();
		
		void set_busy(bool x) { busy = x; }
		void set_en_route(bool y) { en_route = y; }
		void set_mowing(bool z) { mowing = z; }
		void set_busy_minutes(int a) { busy_minutes = a; }
		void set_x_coord(double x) { x_coord = x; }
		void set_y_coord(double y) { y_coord = y; }
		void set_best_lawn(Lawn temp) { best_lawn = temp; }
		void set_crew_number(int num) {number=num;}		
		void set_best_time_to_home(double x) {best_time_to_home = x;}
		void set_best_time_to_lawn(double y) {best_time_to_lawn = y;}
		void set_best_time_to_mow(double z) {best_time_to_mow = z;}

		int get_crew_number(){return number;}
		bool get_busy() { return busy; }
		bool get_en_route() { return en_route; }
		bool get_mowing() { return mowing; }
		int get_busy_minutes() { return busy_minutes; }
		double get_x_coord() { return x_coord; }
		double get_y_coord() { return y_coord; }
		Lawn get_best_lawn() { return best_lawn; }
		double get_best_time_to_home() { return best_time_to_home; }
		double get_best_time_to_lawn() { return best_time_to_lawn; }
		double get_best_time_to_mow() { return best_time_to_mow; }
		
	private:
		bool busy;
		bool en_route;
		bool mowing;
		int busy_minutes;
		double x_coord, y_coord;
		Lawn best_lawn;
		int number;
		double best_time_to_home;
		double best_time_to_lawn;
		double best_time_to_mow;
		
};

#endif
