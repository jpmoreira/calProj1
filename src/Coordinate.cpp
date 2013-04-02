/*
 * Coordinate.cpp
 *
 *  Created on: Apr 2, 2013
 *      Author: mppl
 */

#include "Coordinate.h"
#include <math.h>
#define PI 3.14159

Coordinate::Coordinate() {



}

double Coordinate::distanceTo(Coordinate destination) {
	double my_x = altitude * cos(longitude) * sin(PI/2 - latitude);
	double my_y = altitude * sin(longitude) * sin(PI/2  - latitude);
	double my_z = altitude * cos(PI/2 - latitude);

	double dest_x=destination.altitude *cos(destination.longitude) * sin(PI/2-destination.latitude);
	double dest_y=destination.altitude *sin(destination.longitude) * sin(PI/2 - destination.latitude);
	double dest_z=destination.altitude * cos(PI/2 - destination.latitude);

	return sqrt((my_x-dest_x)*(my_x-dest_x)+(my_y-dest_y)*(my_y-dest_y)+(my_z-dest_z)*(my_z-dest_z));
}

Coordinate::Coordinate(double h, double lat, double longit): altitude(h),latitude(lat),longitude(longit) {

}

double Coordinate::getLatitude(bool degrees) {

	return degrees? 180*latitude/PI:latitude;
}

double Coordinate::getLongitude(bool degrees) {

	return degrees? 180*longitude/PI:longitude;
}

Coordinate::~Coordinate() {
	// TODO Auto-generated destructor stub
}

