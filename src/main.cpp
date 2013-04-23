
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Mountain/Mountain.h"
using std::string;


int main(int argc, char **argv) {

Mountain myMountain=Mountain("/home/mppl/Desktop/file.save");

myMountain.computeDistanceMatrix();
cout<<endl;
myMountain.printDistanceMatrix();
cout<< "best point is "<< myMountain.findNearestAverageNonOccupiedPoint().getName()<<endl;

}

