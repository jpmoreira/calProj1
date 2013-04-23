/*
 * Point.cpp
 *
 *  Created on: Apr 2, 2013
 *      Author: mppl
 */

#include "Point.h"
#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;

int Point::count=0;

Point::Point(string &newAlias):vehicle(NULL),lostTourists(0),id(count) {
	if(newAlias!=""){
		alias=string(newAlias);
	}
	else{
		alias="point "+count;
	}
	count++;
}

Point::Point(const Point& pt):lostTourists(pt.lostTourists),alias(pt.alias),id(pt.id) {
	if(pt.vehicle!=NULL){
		vehicle=new Vehicle(pt.vehicle);
	}
	else{
		vehicle=NULL;
	}
}

Point::Point(Vehicle& v,string &newAlias):vehicle(new Vehicle(v)),lostTourists(0),id(count) {
	if(newAlias!=""){
		alias=string(newAlias);
	}
	else{
		alias="point "+count;
	}
		count++;

}

Point::Point(string &newAlias,int nrTourists):lostTourists(nrTourists),vehicle(NULL),id(count) {
	if(newAlias!=""){
		alias=string(newAlias);
	}
	else{
		alias="point "+count;
	}
	count++;
}
bool Point::setVehicle(Vehicle& v) {//returns if there was a vehicle there previously
	bool ret=true;
	if(vehicle!=NULL){
		ret=false;
	}
	vehicle=new Vehicle(v);
	return ret;
}

Point::~Point() {
	if(vehicle!=NULL){
		delete vehicle;
	}
}


int Point::shipTourists() {

	if(vehicle!=NULL){
		lostTourists=vehicle->addPassengers(lostTourists);
	}
	return lostTourists;
}

Vehicle* Point::getVehicle() {
	return vehicle;
}

Point::Point(Vehicle* v):vehicle(new Vehicle(v)),lostTourists(0),id(count++) {
}

bool Point::moveVehicleFrom(Point &p) {//returns true on sucess
	if(vehicle!=NULL){//if there is a vehicle here already
		return false;
	}
	else if(p.vehicle==NULL){
		return false;
	}

	vehicle=p.vehicle;
	p.vehicle=NULL;
	return true;

}




string Point::getName() const {
	return alias;
}

bool Point::operator==(Point const& pt) const {
	//cout<<"comparing "<<alias<<" and "<<pt.alias<<endl;
	return alias==pt.alias;
}
int Point::getID(){
	return id;
}

int Point::getNrTourists() {
	return lostTourists;
}
