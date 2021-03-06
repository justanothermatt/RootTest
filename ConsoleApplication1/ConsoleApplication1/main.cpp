//main.cpp : Defines the entry point for the console application.
//This program take in a text file with drivers and trips. It analyzes driver names
//and trips taken, then outputing a file with sorted drivers, their miles driven, and their average MPH
//Matt W. Walker 10/15/2018

#include "stdafx.h"
#include "Driver.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

//Struct used as a comparator. This Struct tests the miles driven by each object
//in a vecotr. This is called upon later once all objects are filled into a vector
struct comparator {
	bool operator ()(Driver& startVector, Driver& endVector) const {
		if (startVector.getMiles() < endVector.getMiles()) return true;
		if (startVector.getMiles() > endVector.getMiles()) return false;
		return false;
	}
};

//Main Function has two arguments to accept command line inputs
int main(int argc, char *argv[])
{
	//Variable Declaration
	string		   inputFile;		//Name of the input file
	string		   outputFile;		//Name of the output file
	ifstream	   cin(argv[1]);	//Opening the input file based on command line argument value and declaring "cin" as the input command
	const char	   *path = argv[2];	//Reading in the path name for the output file from cmd line
	ofstream	   cout(path);		//Declaring the path for any "cout" statement to be the output file
	vector<Driver> drivers;			//Vector of any created objects


	if (!cin.is_open()) { cout << "Could not open file\n"; }	//Ensure the file can open
		
	else {
		while (!cin.eof()) {	//While there are still characters in the file
			string command;	//Command is either Driver or Trip
			cin >> command;

			if (command == "Driver") {
				string driverName;	//Local name of driver
				cin >> driverName;
				Driver Object = Driver(driverName);		//Creating a new object named the string driverName
				drivers.push_back(Driver(driverName));	//Creating a vector of pointers to an object in a vector
			}
			
			else if (command == "Trip") {
				string driverName;	//Local name of driver
				cin >> driverName;

				//This iterator will move through the vector of objects searching for the correct one
				//then, it will use all the ->set() functions. Arrow used instead of dot because of iterator being a pointer
				for (vector<Driver>::iterator i = drivers.begin(); i != drivers.end(); i++) {	
					if (i->getName() == driverName) {
						string	startTime;	
						string	endTime;		
						float	miles;
						
						cin >> startTime;
						startTime.erase(remove(startTime.begin(), startTime.end(), ':'), startTime.end());
						i->setStart(stof(startTime));
						
						cin >> endTime;
						endTime.erase(remove(endTime.begin(), endTime.end(), ':'), endTime.end());
						i->setEnd(stof(endTime));

						cin >> miles;
						i->setMiles(miles);
					}
				}
			}
		}
		//Call of sort function with comparator parameter. rbegin and rend used to put in reverse order
		sort(drivers.rbegin(), drivers.rend(), comparator());

		//For loop iterator displaying outputs using ->get() functions
		for (vector<Driver>::iterator i = drivers.begin(); i != drivers.end(); i++) {
			float MPH = i->averageSpeed(to_string(i->timeDriven(i->getStart(), i->getEnd())), i->getMiles());
			cout << i->getName() << ": " << round(i->getMiles()) << " miles @ " << round(MPH) << " MPH." << endl;
		}
	}
    return 0;
}