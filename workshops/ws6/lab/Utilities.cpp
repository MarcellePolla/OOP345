#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"

namespace sdds{

	Vehicle* createInstance(std::istream& is){
		Vehicle* vehicle = nullptr; 
		std::string line;
		char tag;

		//grab stream and place it in string
		getline(is, line, '\n');

		//replace commas with spaces
		replace(line.begin(), line.end(), ',', ' ');

		//string to stream
		std::stringstream ss(line);

		//grab vehicle type
		ss >> tag;

		if(tag == 'c' || tag == 'C'){
			vehicle = new Car(ss);
		}
		
		return vehicle;
	}

}