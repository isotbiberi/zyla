//============================================================================
// Name        : Zyla.cpp
// Author      : ismail baslar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include"zyla/CameraOperations.h"
#include"zyla/FitsOperations.h"


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World
	std::map<std::string,std::pair<std::string,std::string>> header;
Andor_Camera * cam = new Andor_Camera(0);
cam->initializeController();
cam->setExpTime(1);
cam->setNumberOfFrames(10);
cam->afterInitialization();
cam->prepareAcq();
cam->startAcq();
for(int k=0;k<=cam->getNumberOfFrames()-1;k++)
{
createFits(cam->getFitsBuffer(k),header);
}

cam->stopAcq();








	return 0;
}
