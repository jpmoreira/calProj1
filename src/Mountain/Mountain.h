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


	int shortestDistance(Point pt1, Point pt2);//TODO

	void fillMatrixForRow(int index);




};

#endif /* MOUNTAIN_H_ */
