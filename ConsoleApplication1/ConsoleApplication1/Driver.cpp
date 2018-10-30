//Driver class is a class dedicated to calculating and assigning attributes
//

#include "stdafx.h"
#include "Driver.h"
#include <algorithm>
#include <string>

using namespace std;

//Overloaded Constructor
Driver::Driver(string name) {
	setDriverName(name);
	totalMiles = 0;
	startTime = 0;
	endTime = 0;
}

//Setters
void Driver::setDriverName(string n) {driverName = n;}
void Driver::setMiles(float m){
	float temp = totalMiles;
	totalMiles = m + temp;
	round(totalMiles);
}
void Driver::setStart(float s){
	float temp = startTime;
	startTime = s + temp;
	round(startTime);
}
void Driver::setEnd(float e){
	float temp = endTime;
	endTime = e + endTime;
	round(endTime);
}

//Getters
string Driver::getName() {return driverName;}
float Driver::getMiles() {return totalMiles;}
float Driver::getStart() {return startTime;}
float Driver::getEnd()   {return endTime;}

//Calculation functions
int Driver::timeDriven(float sTime, float eTime) {
	totalTime = endTime - startTime;
	return totalTime;
}
float Driver::averageSpeed(string tTime, float tMiles) {
	if (stoi(tTime) == NULL || tMiles == NULL) {
		avgSpeed = 0;
	}
	else {
		minFirst = (totalTime % 10);			  //getting the first number of the time (i.e if time is 1234, this is 4)
		minSecond = (totalTime / 10) % 10;		  //getting the second number of the time (from example: 3)
		totalMin = minFirst + (minSecond * 10);   //making the time a float of the right value (from example: 34)

		hourFirst = (totalTime / 100) % 10;
		hourSecond = (totalTime / 1000) % 10;
		totalHour = hourFirst + (hourSecond * 10);

		minAsDecimal = totalMin / 60;
		timeOnRoad = minAsDecimal + totalHour;

		avgSpeed = totalMiles / timeOnRoad;
	}
	return avgSpeed;
}