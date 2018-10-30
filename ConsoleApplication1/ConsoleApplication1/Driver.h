//Driver.h defines the include header file when using the driver class.
//Definition of class can be found in Driver.cpp file
#pragma once
#include <string>
using namespace std;
class Driver {
private:

	//Set variables
	string driverName;
	float startTime;
	float endTime;

	//Get Variables
	float avgSpeed;
	float totalMiles;

	//Calculation variables
	int totalTime;

	int minFirst;
	int minSecond;
	float totalMin;

	int hourFirst;
	int hourSecond;
	float totalHour;

	float minAsDecimal;
	float timeOnRoad;

public:
	//Constructor
	Driver(string name);

	//Getters
	float  getStart();
	float  getEnd();
	float  getMiles();
	string getName();

	//Setters
	void setDriverName(string n);
	void setStart(float s);
	void setEnd(float e);
	void setMiles(float m);

	//Calculation functions
	int timeDriven(float sTime, float eTime);
	float averageSpeed(string totalTime, float totalMiles);
};