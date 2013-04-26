/**
 *
 @brief A class to encapsulate all the information available about the environment to be modeled. Encapsulates all information necessary for the evaquation algorithms to operate
 *
 */

#ifndef MOUNTAIN_H_
#define MOUNTAIN_H_

#include "Point.h"
#include "../Graph.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "../GraphViewer/graphviewer.h"

#define tempFilePath ".sceneData"
class Mountain {

private:
	Graph<Point> *mountainGraph;
	GraphViewer *viewer;
	Vertex<Point> *exit;

	vector< Vertex<Point> *> vehiclesPointArray;
	bool drawOnEdit;
	bool edited;

	vector<vector<int> > distanceMatrix;
	vector<vector<int> > pathMatrix;


	static fstream tempOutputFile;

public:
	vector< Vertex<Point> *> lostTouristsArray;//TODO make private as soon as it's not needed;

	/**
	 * @brief A simple constructor that initializes the basic parameters to the default values
	 *
	 *
	 */
	Mountain();

	/**
	 * @brief A constructor that initiliazes all the basic parameters to the default values. It also loads the instructions inside a given file if they're well formed.
	 * @param sourceFile The absolut path of a file to be opened and read
	 *
	 *
	 */
	Mountain(string sourceFile);

	/**
	 * @brief A function that saves the instructions necessary for the creation of the present graph in a file
	 * @param path The absolute path of the file to be written and possibly created.
	 * @return A bool stating if the operation was sucessfull
	 *
	 */
	bool saveToFile(string path);

	/**
	 * @brief A function that removes a given point from the graph
	 * @param name The name of the point to be removed
	 * @bool A bool stating if the point was sucessfully removed
	 *
	 */
	bool removePoint(string name);

	/**
	 * @brief A function that adds a path between two given points
	 * @param pt1Name The name of one point
	 * @param pt2Name The name of the other pointS
	 * @param weight The weight of the given path
	 * @return A bool stating if the operation was sucessfull or not
	 *
	 */
	bool addRoad(string pt1Name,string pt2Name,int weight);


	/**
	 * @breif A function to remove a path between two given points
	 * @param pt1Name The name of the point in one of the ends of the path to be removed
	 * @param pt2Name The name of the point in one of the ends of the path to be removed
	 * @return A bool stating if the operation was sucessfull or not
	 *
	 */
	bool removeRoad(string pt1Name,string pt2Name);

	/**
	 * @brief A function that prints the list of points in the graph
	 *
	 */
	void printPointsList();

	/**
	 * @brief A funtion to add a point to this graph
	 * @param ptName The Name of the point to be created
	 * @return A bool stating if the operation was sucessfull or not
	 */
	bool addPoint(string ptName);

	/**
	 * @brief A function to add a Vehicle to a given point
	 * @param ptName The name of the point the vehicle is to be added to
	 * @param nr_seats The number of seats of the vehicle to be added
	 * @return A bool stating if the operation was sucessfull or not
	 *
	 */

	bool addVehicleToPoint(string ptName,int nr_seats);

	/**
	 * @brief A function that computes the distances between all points in the graph. Only does some computation if some change has been made to the graph since the last computation.
	 *
	 *
	 */
	void computeDistances();
	/**
	 * @brief A function that prints the contents of the distances matrix
	 *
	 *
	 */
	void printDistanceMatrix();

	/**
	 * @brief A function that prints the contents of the path matrix
	 *
	 *
	 */
	void printPathMatrix();


	/**
	 * @brief A function that sets the exit as a given point already contained in the graph
	 * @param n A string containing the name of the point to be set as the evaquation point
	 */
	void setExit(string& n);

	/**
	 *
	 * @brief A function that sets the exit as a given point already contained in the graph
	 * @param str A C string containing the name of the point to be set as the evaquation point
	 *
	 */
	void setExit(char* str);

	/**
	 * @brief A function used to add a given number of tourists to a given point
	 * @param name The name of the point the tourist is to be added to
	 * @param nrToAdd The number of tourists to be added to a given point
	 * @return A bool stating if the operation was sucessfull or not
	 *
	 */
	bool AddTouristToPoint(string name, int nrToAdd);

	/**
	 *
	 * @brief A simple destructor that daellocates the allocated memory for this object
	 *
	 */
	~Mountain();

	/**
	 *
	 * @brief A function that returns the name of the temporary file where all the operations are written
	 * @return An fstream representing the temporary file
	 */
	static fstream & getFile();

	/**
	 * @brief A function that automatically places a given number of vehicles with a given number of seats in the best postion possible inside the graph
	 * @param nrVehicles The number of vehicles to be placed inside the graph
	 * @param capacity The number of available places in each of the vehicles
	 *
	 */

	void placeVehicles(int nrVehicles,int capacity);

	/**
	 *
	 * @brief A function that returns the graph vertex that as a given name
	 * @param pointName The name of the vertex to be returned
	 * @return A pointer to a vertex that has the given name
	 *
	 */

	Vertex<Point> * getVertex(string pointName);

	/**
	 * @brief A function that moves tourists from one point to another
	 * @param origin The source point
	 * @param destination The destination Point
	 * @param path a pointer to a created vector to hold the path made by the vehicle to get the tourists
	 *
	 */
	int moveTouristsFromPoint(Vertex<Point> *origin,Vertex<Point> *destination,vector<Point> *path);//TODO make private as soon as it is tested


	/**
	 * @brief A function that moves tourists from one point to another with some simple animations it the graph representation
	 * @param origin The source point
	 * @param destination The destination Point
	 * @param path a pointer to a created vector to hold the path made by the vehicle to get the tourists
	 *
	 */
	int makeAnimatedMoveFromPoint(Vertex<Point> *origin,Vertex<Point> *destination);//TODO move to private as soon as it's tested maybe??

	/**
	 * @brief A function that sets the color to red the edges contained in a given path
	 * @param path The path to be painted
	 *
	 */
	void paintPath(vector<Point> &path);
	/**
	 * @brief A function that sets the color back to blue of the edges contained in a given path
	 * @param path The path to be painted
	 *
	 */
	void unpaintPath(vector<Point> &path);

	/**
	 *
	 * @brief A function that evaquates all the tourists present in the map in the fastest way possible
	 *
	 */

	void evaquate();
private:


	/**
	 * @brief A function that returns the best Point to place a Vehicle that doesn't already have one
	 * @return The best point available to place a vehicle
	 *
	 */
	Point findNearestAverageNonOccupiedPoint();
	/**
	 * @brief A function that parses and executes a given instruction present on a given string
	 * @param inst The string containing the instruction
	 *
	 *
	 */
	void parseInstruction(string &inst);

	/**
	 * @brief A function that parses the parameters of a well formed remove point instruction and executes it
	 * @param s A string containing the instruction parameters
	 */
	void parseRemovePointInstruction(string &s);
	/**
	 * @brief A function that parses the parameters of a well formed add road instruction and executes it
	 * @param s A string containing the instruction parameters
	 */
	void parseAddRoadInstruction(string &s);

	/**
	 * @brief A function that parses the parameters of a well formed remove road instruction and executes it
	 * @param s A string containing the instruction parameters
	 */
	void parseRemoveRoadInstruction(string &s);
	/**
	 * @brief A function that parses the parameters of a well formed add point instruction and executes it
	 * @param s A string containing the instruction parameters
	 */
	void parseAddPointInstruction(string &s);
	/**
	 * @brief A function that parses the parameters of a well formed add vehicle instruction and executes it
	 * @param s A string containing the instruction parameters
	 */
	void parseAddVehicleInstruction(string &s);

	/**
	 * @brief A function that parses the parameters of a well formed parameters instruction and executes it
	 * @param s A string containing the instruction parameters
	 */
	void parseParametersInstruction(string &s);
	/**
	 * @brief A function that parses the parameters of a well formed add tourist instruction and executes it
	 * @param s A string containing the instruction parameters
	 */
	void parseAddTouristInstruction(string &s);


	/**
	 * @brief A function that makes a label for a given point
	 * @param pt The point to whom a lable is to be made
	 * @return A string containing the text of the lable
	 *
	 */
	string makeLabel(Point &pt);

	/**
	 * @brief A function that generates an unique edge ID based on the ID for his end points
	 * @param sourceID the ID of one of the end points
	 * @param destID the ID of one of the end points
	 * @return the ID for the Edge
	 *
	 */
	int generateEdgeID(int sourceID,int destID);



	/**
	 * @brief A function that fill and entire row of the distance matrix based on the contents of the vertexes
	 * @param index The position of the point to whom the distance was calculated to
	 *
	 *
	 *
	 */
	void fillDistanceMatrixForRow(int index);

	/**
	 * @brief A function that calculates the distance from one point to another. If the graph was not changed since last computation a saved value is retrieved.
	 * @param index1 The position of the starting or ending point
	 * @param index2 The position of the starting or ending point
	 * @return The distance from one point to the other
	 *
	 */
	int distanceFrom(int index1,int index2);
	/**
	 *
	 * @brief A function that fills an array with the path from one point to another
	 * @param index1 The position of the starting or ending point
	 * @param index2 The position of the starting or ending point
	 * @param path A vector to be filled with the path of the way from one point to another
	 *
	 */
	void pathFrom(int index1,int index2,vector<Point > *path);
	/**
	 * @brief A function that returns the point containing the nearest vehicle.
	 * @param pt The point to which the nearest point with a vehicle is to be returned
	 * @return A pointer to a vertex whose point contains the nearest vehicle
	 *
	 */
	Vertex<Point> *getNearestVehicle(Vertex<Point>* pt);
	/**
	 * @brief A function that returns the point containing the nearest vehicle.
	 * @param ptIndex The position of the point to which the nearest point with a vehicle is to be returned
	 * @return A pointer to a vertex whose point contains the nearest vehicle
	 *
	 */
	Vertex<Point> *getNearestVehicle(int ptIndex);
	/**
	 * @brief A function that adds a given point to the list of points containing lost tourist
	 * @param pt A pointer to a vertex to be added
	 *
	 *
	 */
	void addPointToLostArray(Vertex<Point> * pt);
	/**
	 * @brief A function that adds a given point to the list of points containing vehicles
	 * @param pt A pointer to a vertex to be added
	 *
	 *
	 */
	void addPointToVehicleArray(Vertex<Point> *pt);
	/**
	 * @brief A function that removes a given point from the list of points containing lost tourist
	 * @param pt A pointer to a vertex to be removed
	 *
	 *
	 */
	void removePointFromLostArray(Vertex<Point> * pt);

	/**
	 * @brief A function that removes a given point from the list of points containing vehicles
	 * @param pt A pointer to a vertex to be removed
	 *
	 *
	 */
	void removePointFromVehicleArray(Vertex<Point> *pt);



};


/**
 * @brief A function To compare to vertex pointers in order for them to be sorted inside the arrays
 *
 */

bool compareVertexPointers(const Vertex<Point> * v1,const Vertex<Point> * v2);




#endif /* MOUNTAIN_H_ */
