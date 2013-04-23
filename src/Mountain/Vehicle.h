/*
 * Vehicle.h
 *
 *  Created on: Apr 5, 2013
 *      Author: mppl
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

/**
 * @class Vehicle
 * @brief A class that simulates a vehicle and manages all related operations such as adding passangers.
 */

class Vehicle {

	int nrSeats;
	int occupiedSeats;


public:

	/**
	 * @brief A method that generates a Vehicle with a given number of available seats and zero passangers
	 * @param seats The numbers of seats the newly created vehicle will have
	 *
	 */
	Vehicle(int seats);

	/**
	 *
	 * @brief A method that generates a Vehicle based on a given one. Occupied seats are initialized with value 0
	 * @param v A reference to a vehicle whose information is to be cloned.
	 */
	Vehicle(Vehicle &v);

	/**
	 *
	 * @brief A method that generates a Vehicle based on a given one. Occupied seats are initialized with value 0
	 * @param v A pointer to a vehicle whose information is to be cloned.
	 *
	 */

	Vehicle(Vehicle *v);

	/**
	 * @brief A method that attempts to add a certain number of passengers to the Vehicle.
	 * @return The number of passengers for whom there was no seats left.
	 * @param nrPassengers The number of passengers to add.
	 *
	 */

	int addPassengers(int nrPassengers);

	/**
	 *
	 * @brief A method that informs the caller if the Vehicle is full.
	 * @return Returns true if there are no empty seats left, false otherwise.
	 *
	 */
	bool isFull();

	/**
	 *
	 * @brief A method that returns the number of seats this instance has.
	 * @return The number of seats this Vehicle has.
	 *
	 */

	int getCapacity();
	int getOccupiedSeats();
};

#endif /* VEHICLE_H_ */
