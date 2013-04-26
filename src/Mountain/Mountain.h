/*
 * Mountain.h
 *
 *  Created on: Apr 7, 2013
 *      Author: mppl
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
	Mountain();
	Mountain(string sourceFile);
	bool saveToFile(string path);
	bool removePoint(string name);
	bool addRoad(string pt1Name,string pt2Name,int weight);
	bool removeRoad(string pt1Name,string pt2Name);
	void printPointsList();
	bool addPoint(string ptName);
	bool addVehicleToPoint(string ptName,int nr_seats);
	void computeDistances();
	void printDistanceMatrix();
	void printPathMatrix();
	void setExit(string& n);
	void setExit(char*);
	bool AddTouristToPoint(string name, int nrToAdd);
	~Mountain();
	static fstream & getFile();
	void placeVehicles(int nrVehicles,int capacity);
	Vertex<Point> * getVertex(string pointName);
	int moveTouristsFromPoint(Vertex<Point> *origin,Vertex<Point> *destination,vector<Point> *path);//TODO make private as soon as it is tested
	int makeAnimatedMoveFromPoint(Vertex<Point> *origin,Vertex<Point> *destination);//TODO move to private as soon as it's tested maybe??

	void paintPath(vector<Point> &path);
	void unpaintPath(vector<Point> &path);

	void evaquate();
private:


	Point findNearestAverageNonOccupiedPoint();
	void parseInstruction(string &inst);
	void parseRemovePointInstruction(string &s);
	void parseAddRoadInstruction(string &s);
	void parseRemoveRoadInstruction(string &s);
	void parseAddPointInstruction(string &s);
	void parseAddVehicleInstruction(string &s);
	void parseParametersInstruction(string &s);
	void parseAddTouristInstruction(string &s);
	void doOneMovement();

	string makeLabel(Point &pt);
	int generateEdgeID(int sourceID,int destID);



	void fillMatrixForRow(int index);
	int moveTouristsToExit(Vertex<Point> *origin);
	int distanceFrom(int index1,int index2);
	void pathFrom(int index1,int index2,vector<Point > *path);
	Vertex<Point> *getNearestVehicle(Vertex<Point>* pt);
	Vertex<Point> *getNearestVehicle(int ptIndex);
	void addPointToLostArray(Vertex<Point> * pt);
	void addPointToVehicleArray(Vertex<Point> *pt);
	void removePointFromLostArray(Vertex<Point> * pt);
	void removePointFromVehicleArray(Vertex<Point> *pt);



};


bool compareVertexPointers(const Vertex<Point> * v1,const Vertex<Point> * v2);




#endif /* MOUNTAIN_H_ */
