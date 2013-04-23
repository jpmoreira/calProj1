/*
 * Vehicle.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: mppl
 */

#include "Vehicle.h"

Vehicle::Vehicle(int seats):nrSeats(seats),occupiedSeats(0) {

}

Vehicle::Vehicle(Vehicle& v):nrSeats(v.nrSeats),occupiedSeats(0) {
}

int Vehicle::addPassengers(int nrPassengers) {
	if(nrSeats-occupiedSeats>=nrPassengers){
		occupiedSeats+=nrPassengers;
		return 0;
	}
	else{
		int ret=nrPassengers-(nrSeats-occupiedSeats);//return nr of passengers than dont fit
		occupiedSeats=nrSeats;
		return ret;
	}
}


bool Vehicle::isFull() {
	return nrSeats==occupiedSeats;
}

Vehicle::Vehicle(Vehicle* v):nrSeats(v->nrSeats),occupiedSeats(v->occupiedSeats) {
}

int Vehicle::getCapacity() {
	return nrSeats;
}

int Vehicle::getOccupiedSeats() {
	return occupiedSeats;
}
