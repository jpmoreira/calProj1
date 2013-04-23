/*
 * Mountain.cpp
 *
 *  Created on: Apr 7, 2013
 *      Author: mppl
 */

#include "Mountain.h"
using namespace std;
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


fstream Mountain::tempOutputFile(tempFilePath,ios_base::in|ios_base::out|ios_base::trunc);




Mountain::Mountain():mountainGraph(new Graph<Point>()),viewer(new GraphViewer(600,600,true,7772)),drawOnEdit(true),edited(true),exit(NULL){

	viewer->createWindow(600, 600);
	viewer->defineEdgeColor("blue");
	viewer->defineVertexColor("lightGray");
}

Mountain::Mountain(string sourceFile):mountainGraph(new Graph<Point>()),viewer(new GraphViewer(600,600,true,7772)),drawOnEdit(true),edited(true),exit(NULL){
	fstream src(sourceFile.c_str());
	string instruction;
	viewer->createWindow(600, 600);
	viewer->defineEdgeColor("blue");
	viewer->defineVertexColor("lightGray");


	drawOnEdit=false;//don't rearange for every instruction

	while(getline(src,instruction)){
		//cout<<"parsing: "<<instruction<<endl;
		parseInstruction(instruction);
	}
	viewer->rearrange();//rearrange now
	drawOnEdit=true;//rearrange every time a command is given
	src.close();//close file stream


}

bool Mountain::saveToFile(string path) {
	ofstream newFileStream;
	newFileStream.open(path.c_str());
	ifstream temp(tempFilePath);
	newFileStream<<temp.rdbuf();
	newFileStream<<"PR "<<exit<<endl;
	newFileStream.close();
	temp.close();

	return true;
}

bool Mountain::removePoint(string name) {
	Vertex<Point> *temp=mountainGraph->getVertex(Point(name));//we need this to get the id;
	if(temp!=NULL){
		edited=true;
		int id= ((Point)temp->getInfo()).getID();
		mountainGraph->removeVertex(temp->getInfo());

		cout<<"Removing a point with name= "<<name<<". (id= "<<id<<")"<<endl;
		tempOutputFile<<"RP "<<name<<endl;
		viewer->removeNode(id);
		if(drawOnEdit){
			viewer->rearrange();
		}
		return true;
	}
	else{
		cout<<"Impossible to remove Point named "<<name<<"."<<endl;
		return false;
	}
}


bool Mountain::addRoad(string origin, string dest, int weight) {
	if(weight<0){
		cout<<"Can't create new road from: "<<origin<<" to: "<<dest<<" and weight: "<<weight<<". Invalid weight."<<endl;
		return false;
	}
	if(origin==dest){
		cout<<"Can't create new road from: "<<origin<<" to itself."<<endl;
		return false;
	}

	Point source(origin);
	Point destination(dest);
	if(mountainGraph->hasEdge(source,destination)){


		cout<<"Can't create new road from: "<<origin<<" to: "<<dest<<". Already existing road."<<endl;
		return false;
	}

	if(mountainGraph->addEdge(source,destination,weight)){
		mountainGraph->addEdge(destination,source,weight);//add back edge (thei should always be bidirectional)

		edited=true;

		//get points to extract ids
		Point pt1=mountainGraph->getVertex(origin)->getInfo();
		Point pt2=mountainGraph->getVertex(destination)->getInfo();

		int theEdgeID=generateEdgeID(pt1.getID(),pt2.getID());
		viewer->addEdge(theEdgeID,pt1.getID(),pt2.getID(),EdgeType::UNDIRECTED);
		stringstream s;
		s<<weight;
		viewer->setEdgeLabel(theEdgeID,s.str());

		if(drawOnEdit){
			viewer->rearrange();
		}
		cout<<"Adding a road with origin= "<<origin<<" dest= "<<dest<<" and weight= "<<weight<<". (id= "<<theEdgeID<<")"<<endl;
		tempOutputFile<<"AR "<<origin<<" "<<dest<<" "<<weight<<endl;
		return true;

	}
	else{
		cout<<"Can't create new road from: "<<origin<<" to: "<<dest<<" and weight: "<<weight<<". Invalid end points."<<endl;
		return false;
	}
}

bool Mountain::removeRoad(string pt1Name, string pt2Name) {
	if(pt1Name==pt2Name){
		cout<<"Can't delete road from: "<<pt1Name<<" to itself"<<endl;
		return false;
	}
	Point origin(pt1Name);
	Point dest(pt2Name);
	if(mountainGraph->removeEdge(origin,dest)){

		mountainGraph->removeEdge(dest,origin);
		edited=true;
		int sourceID=mountainGraph->getVertex(origin)->getInfo().getID();
		int destID=mountainGraph->getVertex(dest)->getInfo().getID();
		int edgeID=generateEdgeID(sourceID,destID);
		cout<<"Removing a road with origin= "<<pt1Name<<" dest= "<<pt2Name<<".(id= "<<edgeID<<")"<<endl;
		tempOutputFile<<"RR "<<pt1Name<<" "<<pt2Name<<endl;
		viewer->removeEdge(edgeID);
		if(drawOnEdit){
			viewer->rearrange();
		}

		return true;
	}
	else{
		cout<<"Can't delete road from: "<<pt1Name<<" to: "<<pt2Name<<". Inexistent road."<<endl;
		return false;
	}

}
bool Mountain::addPoint(string ptName) {
	Point pt(ptName);
	if(mountainGraph->addVertex(pt)){
		edited=true;
		cout<<"Adding a point with name= "<<ptName;

		cout<<" (id= "<<pt.getID()<<")."<<endl;

		tempOutputFile<<"AP "<<ptName<<endl;//output to file

		//viewer stuff
		viewer->addNode(pt.getID());//insert node
		viewer->setVertexLabel(pt.getID(),makeLabel(pt));//define it's label
		if(drawOnEdit){
			viewer->rearrange();
		}
		return true;
	}


	else{
		cout<<"Impossible to add point named "<<ptName<<". Please try another name"<<endl;
		return false;
	}

}

bool Mountain::addVehicleToPoint(string ptName, int nr_seats) {
	Vehicle theVehicle(nr_seats);
	Point thePt(ptName);
	Vertex<Point> *v=mountainGraph->getVertex(thePt);
	if(v!=NULL){thePt=v->getInfo();}
	if(v!=NULL && thePt.getVehicle()==NULL){//if there is such a point with no vehicle in it
		edited=true;
		thePt.setVehicle(theVehicle);//TODO not working see why
		v->setInfo(thePt);
		vehiclesPointArray.push_back(v);//add to array

		cout<<"Adding a vehicle of capacity "<<nr_seats<<" to point with name= "<<ptName<<endl;

		tempOutputFile<<"AV "<<ptName<<" "<<nr_seats<<endl;
		viewer->setVertexLabel(thePt.getID(),makeLabel(thePt));
		if(drawOnEdit){
			viewer->rearrange();
		}
		return true;
	}
	else{
		cout<<"Impossible to add vehicle to point named "<<ptName<<endl;
		return false;
	}
}




void Mountain::printPointsList() {
}

Mountain::~Mountain() {
	tempOutputFile.close();
	delete mountainGraph;
	delete viewer;
}

void Mountain::parseInstruction(string& inst) {
	string instructionName=inst.substr(0,2);
	string instructionParams=inst.substr(3);

	if(instructionName=="RP")
		parseRemovePointInstruction(instructionParams);
	else if(instructionName=="AR")
		parseAddRoadInstruction(instructionParams);
	else if(instructionName=="RR")
		parseRemoveRoadInstruction(instructionParams);
	else if(instructionName=="AP")
		parseAddPointInstruction(instructionParams);
	else if(instructionName=="AV")
		parseAddVehicleInstruction(instructionParams);
	else if(instructionName=="PR")
		parseParametersInstruction(instructionParams);
	else if(instructionName== "AT")
		parseAddTouristInstruction(instructionParams);
}

void Mountain::parseRemovePointInstruction(string& s) {
	removePoint(s);
}
void Mountain::parseAddTouristInstruction(string& s) {
	int space=s.find(' ',0);
	string name=s.substr(0,space);
	int nr=atoi(s.substr(space+1).c_str());
	AddTouristToPoint(name,nr);
}

void Mountain::parseAddRoadInstruction(string& s) {
	int origin_end=s.find(' ',0);
	int dest_end=s.find(' ',origin_end+1);
	string origin=s.substr(0,origin_end);
	string destination=s.substr(origin_end+1,dest_end-origin_end-1);
	int weight=atoi(s.substr(dest_end+1).c_str());
	addRoad(origin,destination,weight);
}

void Mountain::parseRemoveRoadInstruction(string& s) {
	int origin_end=s.find(' ',0);
	string origin=s.substr(0,origin_end);
	string destination=s.substr(origin_end+1);
	removeRoad(origin,destination);
}

void Mountain::parseAddPointInstruction(string& s) {
	int name_end=s.find(' ',0);
	string name=s.substr(0,name_end);
	addPoint(name);

}


void Mountain::parseAddVehicleInstruction(string& s) {
	int name_end=s.find(' ',0);
	string name=s.substr(0,name_end);
	int seats=atoi(s.substr(name_end+1).c_str());
	addVehicleToPoint(name,seats);


}

fstream& Mountain::getFile() {
	return tempOutputFile;
}

void Mountain::parseParametersInstruction(string& s) {
	setExit(s);
}

string Mountain::makeLabel(Point& pt) {
		stringstream myStr;
		myStr<<pt.getName();
	if(exit!=NULL && exit->getInfo()==pt){//if it's exit
		myStr<<" E("<<pt.getNrTourists()<<")";
	}

	else if(pt.getVehicle()==NULL){//if it has no vehicle
		myStr<<" T("<<pt.getNrTourists()<<")";

	}
	else{
		Vehicle *v=pt.getVehicle();
		myStr<<" V("<<v->getCapacity()<<","<<v->getOccupiedSeats()<<")";

	}
		return myStr.str();
}

int Mountain::generateEdgeID(int sourceID, int destID) {
	int biggest=destID;
	int smallest=sourceID;
	if(sourceID>=destID){//ensure the biggest is in the correct place
		biggest=sourceID;
		smallest=destID;
	}
	//concatenate the two numbers
	int times = 1;
	while (times <= smallest)
		times *= 10;
	return biggest*times + smallest;


}

int Mountain::shortestDistance(Point pt1, Point pt2) {
	computeDistances();//only executed one time or if graph is edited
	int pt1Index=-1;
	int pt2Index=-1;
	vector<Vertex<Point> *> theArray=mountainGraph->getVertexSet();
	for(unsigned int i=0;i<theArray.size();i++){
		if(theArray[i]->getInfo()==pt1){pt1Index=i;}
		if(theArray[i]->getInfo()==pt2){pt2Index=i;}
	}


	if(pt1Index>0 && pt2Index>0){return distanceMatrix[pt1Index][pt2Index];}


	else{return -1;}
}

void Mountain::computeDistances() {
	if(edited){

		//initialize vector
		int size=mountainGraph->getNumVertex();

		distanceMatrix=vector< vector<int> > (size);
		pathMatrix=vector< vector<int> > (size);

		for(int i=0;i<size;i++){
			distanceMatrix[i]=vector<int> (size);
			pathMatrix[i]=vector<int> (size);
		}

		vector<Vertex<Point> *> theArray=mountainGraph->getVertexSet();
		for(int i=0;i<size;i++){

			mountainGraph->dijkstraShortestPath(theArray[i]->getInfo());
			fillMatrixForRow(i);
		}

		edited=false;
	}



}

Point Mountain::findNearestAverageNonOccupiedPoint() {
	computeDistances();
	int index=-1;
	int value=INT_INFINITY;
	for(int i=0;i<distanceMatrix.size();i++){
		Point pt= mountainGraph->getVertexSet()[i]->getInfo();

		if(pt.getVehicle()==NULL){
			int sum=0;
			for(int f=0;f<distanceMatrix.size();f++){
				sum+=distanceMatrix[i][f];
			}
			if(sum<value){
				index=i;
				value=sum;
			}
		}
	}
		if(index==-1){
			string name="no_name";
			return Point(name);}
		return mountainGraph->getVertexSet()[index]->getInfo();
	}

bool Mountain::AddTouristToPoint(string name, int nrToAdd) {
	Point thePt(name);
	Vertex<Point> *v=mountainGraph->getVertex(thePt);
	if(v==NULL){
		cout<<"Impossible to add "<<nrToAdd<<" Tourists to point named "<<name<<endl;
		return false;}
	int index=v->getIndex();
	thePt=v->getInfo();
	thePt.addTourist(nrToAdd);
	v->setInfo(thePt);

	tempOutputFile<<"AT "<<name<<" "<<nrToAdd<<endl;
	cout<<"Adding "<<nrToAdd<<" Tourists to point named "<<name<<endl;
	viewer->setVertexLabel(thePt.getID(),makeLabel(thePt));//define it's label
	if(drawOnEdit){
		viewer->rearrange();
	}
		return true;
}

void Mountain::setExit(string& n) {
	Point testPt(n);
	Vertex<Point> *v=mountainGraph->getVertex(testPt);
	if(v==NULL){
		cout<<"Impossible to setup Exit as Point "<<n<<endl;
		return;
	}
	cout<<"Exit is point named: "<<n<<endl;
	exit=v;
	testPt=v->getInfo();

	viewer->setVertexLabel(testPt.getID(),makeLabel(testPt));//define it's label
	if(drawOnEdit){
		viewer->rearrange();
	}

}

void Mountain::setExit(char* str) {
	string theStr(str);
	setExit(theStr);
}

void Mountain::moveVehicleTo(Vertex<Point>* origin,
		Vertex<Point>* destination) {
}

void Mountain::fillMatrixForRow(int index) {
	vector<Vertex<Point> *> theArray=mountainGraph->getVertexSet();
	for(int i=0;i<distanceMatrix.size();i++){

		distanceMatrix[index][i]=theArray[i]->getDist();
		distanceMatrix[i][index]=distanceMatrix[index][i];

		if(theArray[i]->path!=NULL){
			pathMatrix[i][index]=theArray[i]->path->getIndex();
		}
		else{
			pathMatrix[i][index]=-1;
		}


	}
}

void Mountain::printDistanceMatrix() {
	for(int i=0;i<distanceMatrix.size();i++){
		for(int f=0;f<distanceMatrix.size();f++){
			cout<<" "<<distanceMatrix[i][f]<<" ";
		}
		cout<<endl;
	}
}
void Mountain::printPathMatrix(){
	cout<<endl;
	for(int i=0;i<pathMatrix.size();i++){
			for(int f=0;f<pathMatrix.size();f++){
				cout<<" "<<pathMatrix[i][f]<<" ";
			}
			cout<<endl;
		}
}

void Mountain::placeVehicles(int nrVehicles, int capacity) {

	drawOnEdit=false;
	for(int i=0;i<nrVehicles;i++){
		Point pt=findNearestAverageNonOccupiedPoint();
		bool possibleToAdd=addVehicleToPoint(pt.getName(),capacity);
		if (!possibleToAdd){
			cout<<"Impossible to auto add all Vehicles to graph. "<<i<<" added so far."<<endl;
		}
	}
	drawOnEdit=true;

}
