/*
 * Coordinate.h
 *
 *  Created on: Apr 2, 2013
 *      Author: mppl
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

/**
 * @class Coordinate
 * @brief A class that represents the location of a point in the earth surface
 *
 */


class Coordinate {
	double altitude,latitude,longitude;

public:

	/**
	 * @brief Latitude getter
	 * @param degrees A boolean to indicate if the value returned should be in degrees or radians
	 * @return returns the latitude of this point in degrees in case degrees was false. In radians otherwise
	 *
	 */
	double getLatitude(bool degrees);

	/**
	 * @brief Longitude getter
	 * @param degrees A boolean to indicate if the value returned should be in degrees or radians
	 * @return returns the longitude of this point in degrees in case degrees was false. In radians otherwise
	 *
	 */

	double getLongitude(bool degrees);

	/**
	 * @brief A method to calculate the shortest distance between two points
	 * @param destination The point to which the distance is to be returned
	 * @return Returns the shortest distance in meters to the desired point
	 *
	 */

	double distanceTo(Coordinate destination);

	/**
	 * @brief Empty Constructor. Initializes all parameters to zero
	 *
	 */

	Coordinate();

	/**
	 *
	 * @brief Constructor to initialize altitude, latitude and longitude
	 * @param h the value to which altitude is to be initialized
	 * @param lat the value to which latitude is to be initialized
	 * @param longit the value to which longitude is to be initialized
	 */

	Coordinate(double h,double lat, double longit);
	virtual ~Coordinate();
};

#endif /* COORDINATE_H_ */
