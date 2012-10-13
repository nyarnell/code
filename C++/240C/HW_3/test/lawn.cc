#include"lawn.h"
#include <cmath>

Lawn::Lawn(){
	street_num = 0;
	street = "";
	x_coord = 0.0;
	y_coord = 0.0;
	length = 0;
	width = 0;
	income = 0.0;
	height = 3.0;
	home_distance = 0.0;
}

ostream& operator << (ostream& outs, const Lawn& lawn){
	outs<<lawn.street_num<<" ";
	outs<<lawn.street<<" ";
	outs<<lawn.x_coord<<" ";
	outs<<lawn.y_coord<<" ";
	outs<<lawn.length<<" ";
	outs<<lawn.width<<" ";
	outs<<lawn.income;
	
	return(outs);
}

istream& operator >> (istream& ins, Lawn& lawn){
		
	ins >> lawn.street_num;
	/*
	if(ins.peek() == '\n')
		ins.ignore();
	*/
	ins >> lawn.street;
	ins >> lawn.x_coord;
	ins >> lawn.y_coord;
	ins >> lawn.length;
	ins >> lawn.width;
	ins >> lawn.income;
	lawn.home_distance = sqrt(pow((lawn.x_coord-5.0), 2.0)+pow((lawn.y_coord-7.5), 2.0));
	return(ins);
}

bool Lawn::operator < (const Lawn &other) const {
	if(height == other.get_height()){
		return (income < other.get_income());
	}else{
		return (height < other.get_height());
	}
}

bool Lawn::operator == (const Lawn &other) const {
	if (street_num==other.get_street_num() &&
		street==other.get_street() &&
		x_coord==other.get_x_coord() &&
		y_coord==other.get_y_coord() &&
		length==other.get_length() &&
		width==other.get_width() &&
		income==other.get_income() &&
		height==other.get_height()
	)
		return true;
		else return false;
}
bool Lawn::operator != (const Lawn &other) const {
	if (street_num!=other.get_street_num() ||
		street!=other.get_street() ||
		x_coord!=other.get_x_coord() ||
		y_coord!=other.get_y_coord() ||
		length!=other.get_length() ||
		width!=other.get_width() ||
		income!=other.get_income() ||
		height!=other.get_height()
	)
		return true;
		else return false;
}

Lawn Lawn::operator = (const Lawn &rhs){
	if (this != &rhs){
		street_num = rhs.street_num;
		street = rhs.street;
		x_coord = rhs.x_coord;
		y_coord = rhs.y_coord;
		length = rhs.length;
		width = rhs.width;
		income = rhs.income;
		height = rhs.height;
		home_distance = rhs.home_distance;
	}
	return *this;
}
