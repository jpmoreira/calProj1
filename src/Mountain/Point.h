/**
 * @brief A class to encapsulate all the information available about a point such as the number of tourists in there or vehicles present there.
 *
 */

#ifndef POINT_H_
#define POINT_H_
#include "Vehicle.h"
#include <string>
using std::string;
class Point {

Vehicle *vehicle;
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
	 * @param v A reference to a Vehicle that whose clone will be a assigned to the vehicle field of the new Point
	 * @param newAlias A name to give the new Point
	 */
	Point(Vehicle &v,string &newAlias);

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
	 * @brief A method that attempts to move the tourists in this Point to the vehicle. Returns the number of tourist that could not be transfered.
	 * @return The number of tourists that could not be transfered.
	 */
	int shipTourists();
	/**
	 * @brief Returns a pointer to the Vehicle present in this Point. Returns NULL if there was no Vehicle.
	 * @return A pointer to the Vehicle present at this Point. Returns NULL if there was no Vehicle.
	 *
	 *
	 */
	Vehicle * getVehicle();

	bool moveVehicleFrom(Point &p);

	string getName() const;
	bool operator==(Point const& pt) const;
	int getID();
	int getNrTourists();
	void addTourist(int nr);
};

#endif /* POINT_H_ */
