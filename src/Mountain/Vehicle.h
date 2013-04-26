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
	int elapsedTime;


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
	 *
	 * @brief A method that returns the number of seats this instance has.
	 * @return The number of seats this Vehicle has.
	 *
	 */

	int getCapacity();

	/**
	 * @brief A function that returns the time used for the vehicle to move so far
	 * @return The time used for the vehicle to move so far
	 */
	int getElapsedTime() const;
	/**
	 *
	 * @brief A function used to increment the time used for the vehicle to move so far
	 * @param increment The amount to be added
	 * @return The value of the elapsedTime parameter after the incrementation is done
	 *
	 */
	int incrementElapsedTime(int increment);
};

#endif /* VEHICLE_H_ */
