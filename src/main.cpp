
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Mountain/Mountain.h"
using std::string;


int main(int argc, char **argv) {

Mountain myMountain=Mountain("/home/mppl/Desktop/file.save");

//myMountain.computeDistances();
cout<<endl;
myMountain.placeVehicles(3,4);
myMountain.printPathMatrix();
cout<<endl;
myMountain.printDistanceMatrix();

}

