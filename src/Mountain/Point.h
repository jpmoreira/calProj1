/**
 * @brief A class to encapsulate all the information available about a point such as the number of tourists in there or vehicles present there.
 *
 */

#ifndef POINT_H_
#define POINT_H_
#include "Vehicle.h"
#include <string>
#include <vector>

using std::string;
using std::vector;
class Point {

vector<Vehicle*> vehicles;
int lostTourists;
string alias;
static int count;
int id;


public:

	/**
	 *@brief An empty constructor for  this Class. Initializes the number of lostTourists to zero and the vehicle field to NULL.
	 *@param The name of the new Point
	 */
	Point(string &alias);

	/**
	 * @brief A constructor that clones a given Point. The field "lostTourists" is set to zero.
	 * @param pt A reference to a Point object that will be cloned.
	 *
	 *
	 */
	Point(const Point &pt);


	/**
	 * @brief A constructor that initializes a new Point instance with a clone of a given Vehicle.
	 * @brief Sets the lostTourists field to zero.
	 * @param v A pointer to a Vehicle that whose clone will be a assigned to the vehicle field of the new Point.
	 *
	 */
	Point(Vehicle *v);




	/**
	 * @brief A constructor that initializes a new Point instance with the field vehicle set to NULL and sets lostTourists to a given value.
	 * @param nrTourists the value to be assigned to the lostTourists field of the new Point instance.
	 * @param newAlias the name of the new point
	 */
	Point(string &newAlias,int nrTourists);

	/**
	 * @brief Assigns a new vehicle to this Point instance. Returns true if there was no vehicle there already, false otherwise.
	 * @param v the Vehicle whose clone will be this Point instance's vehicle.
	 * @return Returns True if there was no vehicle there before, false otherwise.
	 *
	 */
	bool setVehicle(Vehicle &v);

	/**
	 * @brief A destructor that frees any dinamically allocated memory for this Point instance
	 *
	 *
	 */
	virtual ~Point();


	/**
	 *
	 * @brief returns A copy of the internal Point array containing a bunch of Vehicle *
	 * @return A vector containing the Vehicles in this point
	 */

	vector<Vehicle *> getVehicles() const;


	/**
	 * @brief A getter for the name of this point
	 * @return A string containing the name of this point
	 */
	string getName() const;

	/**
	 * @brief Overload of the == operator, made to campare two points.
	 * @param pt The point this one is to be compared to
	 * @return A bool stating if both points are equal
	 *
	 */
	bool operator==(Point const& pt) const;
	/*
	 * @brief Returns the id of this point
	 * @return A number containing the ID of this point
	 *
	 */
	int getID();

	/**
	 * @brief Returns the number of tourists contained in this point
	 * @return The number of tourists in this point
	 */
	int getNrTourists();

	/**
	 * @brief A function that adds a given number of tourist to a given point
	 * @param nr the number of tourists to be added
	 *
	 */
	void addTourist(int nr);

	/**
	 * @brief A function that moves all tourist possible from a point to another with a given vehicle
	 * @param pt the point the tourists are to be moved to
	 * @param v a vehicle to be used in the process
	 * @return the number of tourists left in the point
	 *
	 */
	int shipTouristsTo(Point &pt,Vehicle *v);

	/**
	 * @brief A function that moves all tourist possible from one point to another making use of vehicle present in another one
	 * @param dest The point the tourists are to be moved to
	 * @param vehiclePoint A point where the vehicle to be used is present
	 * @return The number of tourist left in the point
	 */
	int shipTouristsTo(Point &dest,Point &vehiclePoint);

	/**
	 * @brief A function that removes the vehicle in a given position in the vehicles array of this point
	 * @param i The index of the element inside the vehicles array
	 *
	 */
	void removeVehicle(int i);

	/**
	 * @brief An operator overload for the assignment operator
	 * @param pt A pointer to be copied to this instance
	 * @return the newly created point
	 *
	 */

	Point operator=(const Point &pt);

	/**
	 * @brief An operator overload destined to verify if a point is smalled than the other
	 * @param pt A point that is to be compared to this instance
	 * @return A bool stating if this instance is smaller than pt
	 *
	 *
	 */
	bool operator<(const Point &pt) const;

	/**
	 * @brief A function to add a given vehicle to the vehicles array
	 * @param v A vehicle that is to be copied to the vehicles array
	 *
	 */
	void addVehicle(Vehicle& v);


	/**
	 *
	 * @brief A function that returns the vehicle in a given position of the vehicles array. NULL is returned if there is no element at that position.
	 * @param i The index of the vehicle to be returned
	 * @return A pointer to a vehicle in the i'th positon of the vehicles array
	 */
	Vehicle *getVehicle(int i);
};

/**
 * @brief A function used to compare two vehicles given a pointer to them. A pointer is smaller than other if they have a smaller elapsedTime
 * @param v1 A pointer to a vehicle to be compared
 * @param v1 A pointer to a vehicle to be compared
 * @return A bool stating if the vehicle pointer by v1 is smaller than the one pointed by v2.
 */

bool vehiclePointerComparator(const Vehicle * v1,const Vehicle *v2);


#endif /* POINT_H_ */
