# Root Insurance Interview Code

This project is a command line driven code written for the Root Insurance interview process. This program will input a text file with either commands "Driver" or "Trip". Driver will be followed by a name for the driver (Ex. Driver Dan). Trip will be followed by the name of the driver taking the trip, start time, end time, and total miles driven (Ex. Trip Dan 12:01 15:04 33.5) The program will take in all Drivers and Trips, and then output to a text file, the drivers speed and total miles driven. This output will be sorted by most miles driven to least. The code written by me were the following files: "main.cpp" "Driver.h" "Driver.cpp"

## Thought Process

This problem statement was slightly challenging due to the open ended nature of the problem. Not being told to code in a certain language or to implement the solution in a certain way really gave me a freedom to program that college courses have not. Because of this, there were many things to take into consideration when designing a solution, which will be outlined below.

The first choice made was to code this program in C++. Between Visual Studio being the IDE I feel most comfortable working in, and my Data Structures course being taught using objective C++, C++ was the obvious choice. 

The next choice was to design my solution based off of and object oriented approach. It only seemed natural that each “Driver” command would just need to create a new object for later modification. Whereas the Trip command would simply list the attributes for each driver. Because of this, I designed a class called Driver which had certain methods for object mutation. These methods included an overloaded constructor creating the object using the name given by the Driver command, Getters and Setters for attributes (startTime, endTime, milesDriven), and some calculation functions for total time driven and average speed. The entire process of designing this class and how it would operate in main were handwritten as to avoid “spaghetti code”. Below is the outline in pseudo-code for how I thought main would operate at the beginning of this project.

main  
- Read in .txt file from command line
- If(Driver){Take in driver name for later trip assignment}
- If(Trip)  
Find name for assignment  
Read in start time (int assignment)  
Read in end time (int assignment)  
Read in miles driven (int assignment)  

- Sort all current drivers by miles driven
- Save a .txt file to the same directory received from the command line

During the design, a major problem that arose was storage of objects. Since they needed to be sorted later in the program, all the objects needed to be stored after their creation. The choice I made was to implement vectors. This choice was made mostly because of my familiarity with vectors. I knew they were not constrained by size and could easily be manipulated using functions from the STL.

As nice as vectors are, a  problem that came along was sorting. Objects stored in vectors seemed difficult to to sort until some research landed me on a page discussing operators. The operator struct early on in the program is one that was designed around milesDriven comparison within objects. It’s a boolean operator that acts as a greater than and less than for the Object.getMiles(). Using this operator as a third parameter for the std::sort() function I was able to sort the vector from largest to smallest by miles driven. The only thing left at that point was to output all the information to a text file.

## Testing Process

For testing on this program, the main example given by Root was the focus of testing. This prompt is shown below:
````
Driver Dan
Driver Alex
Driver Bob
Trip Dan 07:15 07:45 17.3
Trip Dan 06:12 06:32 21.8
Trip Alex 12:01 13:16 42.0
````
The testing was centered around building the program based off of results of the test. This means that once I wrote something, I would test it's functionality using (most of the time) outputting to a text file. The first test was ensuring the overloaded constructor working correctly using the .getName() method. Outside of this, some other tests were: ensuring the colon was removed from the time, making sure the round() function from STL was actually rounding correctly, and ensuring the comparator worked correctly. Theses test all worked smoothly and the program runs well given any correctly formatted input.
### Author

**Matt Walker** - Github: [Justanothermatt](https://github.com/justanothermatt)
