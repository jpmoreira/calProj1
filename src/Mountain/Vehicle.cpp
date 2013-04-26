/*
 * Vehicle.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: mppl
 */

#include "Vehicle.h"

Vehicle::Vehicle(int seats):nrSeats(seats),elapsedTime(0) {

}

Vehicle::Vehicle(Vehicle& v):nrSeats(v.nrSeats),elapsedTime(v.elapsedTime) {
}





Vehicle::Vehicle(Vehicle* v):nrSeats(v->nrSeats),elapsedTime(v->elapsedTime) {
}

int Vehicle::getCapacity() {
	return nrSeats;
}

int Vehicle::getElapsedTime() const{
	return elapsedTime;
}

int Vehicle::incrementElapsedTime(int increment) {
	elapsedTime+=increment;
	return elapsedTime;
}
