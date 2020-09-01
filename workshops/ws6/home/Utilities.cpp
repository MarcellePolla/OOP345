#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds{

	Vehicle* createInstance(std::istream& is){
		Vehicle* vehicle = nullptr; 
		std::string line;
		std::string tag;
		std::string delimiter;

		//grab stream and place it in string
		getline(is, line, '\n');

		//string to stream
		std::stringstream ss(line);

		getline(ss, tag, ',');
		tag.erase(std::remove(tag.begin(), tag.end(), ' '), tag.end());

		if(tag == "c" || tag == "C"){
			vehicle = new Car(ss);
		}else if(tag == "r" || tag == "R"){
			vehicle = new Racecar(ss);
		}else if(!tag.empty()){
			//if(tag != "c" && tag != "C" && tag != "r" && tag != "R")
			throw  "Unrecognized record type: [" + tag+ "]" ; 
		}
		
		return vehicle;
	}

}