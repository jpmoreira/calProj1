/*
 * Point.cpp
 *
 *  Created on: Apr 2, 2013
 *      Author: mppl
 */

#include "Point.h"
#include <cstddef>
#include <iostream>
#include <algorithm>
using namespace std;

int Point::count=0;

Point::Point(string &newAlias):vehicles(vector<Vehicle *>(0)),lostTourists(0),id(count) {
	if(newAlias!=""){
		alias=string(newAlias);
	}
	else{
		alias="point "+count;
	}
	count++;
}

Point::Point(const Point& pt):lostTourists(pt.lostTourists),alias(pt.alias),id(pt.id) {
	vector<Vehicle *> vCopy=pt.getVehicles();
	if(vCopy.size()>0){
		for(int i=0;i<vCopy.size();i++){
			Vehicle *v=new Vehicle(vCopy[i]);
			vehicles.push_back(v);
		}
		make_heap(vehicles.begin(),vehicles.end(),&vehiclePointerComparator);
	}
	else{
		vehicles=vector<Vehicle *>(0);
	}
}



Point::Point(string &newAlias,int nrTourists):lostTourists(nrTourists),vehicles(vector<Vehicle *>(0)),id(count) {
	if(newAlias!=""){
		alias=string(newAlias);
	}
	else{
		alias="point "+count;
	}
	count++;
}
void Point::addVehicle(Vehicle& v) {//returns if there was a vehicle there previously
	vehicles.push_back(new Vehicle(v));
	make_heap(vehicles.begin(),vehicles.end(),&vehiclePointerComparator);
}

Point::~Point() {
	for(int i=0;i<vehicles.size();i++){
		delete vehicles[i];
		vehicles[i]=NULL;
	}
}


int Point::shipTouristsTo(Point &pt,Vehicle *v) {
	if(v==NULL){return -1;}
	int cap=v->getCapacity();
	cout<<"Moving ";
	if(cap>=lostTourists){
		cout<<lostTourists;
		pt.lostTourists+=lostTourists;
		lostTourists=0;

	}
	else{
		cout<<cap;
		pt.lostTourists+=cap;
		lostTourists-=cap;
	}
	cout<<" tourists from point "<<alias<<" to point "<<pt.alias<<endl;
	return lostTourists;

}
int Point::shipTouristsTo(Point& dest, Point& vehiclePoint) {
	Vehicle *v=vehiclePoint.getVehicle(0);
	return shipTouristsTo(dest,v);

}

Vehicle* Point::getVehicle(int i) {
	if(i>=vehicles.size()){return NULL;}
	return vehicles[i];
}
vector<Vehicle*> Point::getVehicles() const{
	return vehicles;
}

Point::Point(Vehicle* v):vehicles(vector<Vehicle *>(0)),lostTourists(0),id(count++) {
	vehicles.push_back(new Vehicle(v));
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

void Point::addTourist(int nr) {
	lostTourists+=nr;
}

void Point::removeVehicle(int i) {
	if(i>=vehicles.size()){return;}
	//cout<<"will remove at point "<<alias<<". prior size= "<<vehicles.size()<<endl;
	delete vehicles[i];
	vehicles[i]=NULL;
	vehicles.erase(vehicles.begin()+i);
	make_heap(vehicles.begin(),vehicles.end(),&vehiclePointerComparator);

}



Point Point::operator =(const Point& pt){
	lostTourists=pt.lostTourists;
	alias=pt.alias;
	id=pt.id;


	for(int i=0;i<vehicles.size();i++){//remove all vehicles we have
		delete vehicles[i];
	}
	vehicles=vector<Vehicle *>(0);


	vector<Vehicle *> ptVehicles=pt.getVehicles();
	for(int i=0;i<ptVehicles.size();i++){
		vehicles.push_back(new Vehicle(ptVehicles[i]));
	}
	make_heap(vehicles.begin(),vehicles.end(),&vehiclePointerComparator);

	return *this;
}

bool Point::operator <(const Point& pt) const {
	return lostTourists<pt.lostTourists;
}

bool vehiclePointerComparator(const Vehicle * v1,const Vehicle *v2){
	int time1=v1->getElapsedTime();
	int time2=v2->getElapsedTime();
	return time1>time2;
}
