
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Mountain/Mountain.h"
using std::string;


int main(int argc, char **argv) {

Mountain myMountain=Mountain("/home/mppl/Desktop/file.save");

//myMountain.computeDistances();


myMountain.placeVehicles(2,4);
sleep(10);

myMountain.evaquate();
cout<<"done"<<endl;

}

