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
	int nrToEvaquate;
	int nrEvaquated;
	bool drawOnEdit;
	bool edited;

	vector<vector<int> > distanceMatrix;


	static fstream tempOutputFile;
	double meanTime;

public:
	Mountain();
	Mountain(string sourceFile);
	bool saveToFile(string path);
	bool addEmptyPoint(string name);

	bool removePoint(string name);
	bool addRoad(string pt1Name,string pt2Name,int weight);
	bool removeRoad(string pt1Name,string pt2Name);
	void printPointsList();
	bool addTouristPoint(string ptName,int nr);
	bool addVehicleToPoint(string ptName,int nr_seats);
	void computeDistanceMatrix();
	void printDistanceMatrix();
	~Mountain();
	static fstream & getFile();
	Point findNearestAverageNonOccupiedPoint();//TODO do this to calculate place where to place the vehicle
private:


	void parseInstruction(string &inst);
	void parseRemovePointInstruction(string &s);
	void parseAddRoadInstruction(string &s);
	void parseRemoveRoadInstruction(string &s);
	void parseAddTouristInstruction(string &s);
	void parseAddVehicleInstruction(string &s);
	void parseParametersInstruction(string &s);

	string makeLabel(Point &pt);
	int generateEdgeID(int sourceID,int destID);


	int shortestDistance(Point pt1, Point pt2);//TODO

	void fillMatrixForRow(int index);

};

#endif /* MOUNTAIN_H_ */
