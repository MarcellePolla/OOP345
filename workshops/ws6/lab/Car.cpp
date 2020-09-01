#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Car.h"

namespace sdds{

	Car::Car(std::istream& ss){
		//grab car info from stream
		ss >> m_maker >> m_condition >> m_topSpeed;

	}
	
	std::string Car::condition() const{
		//returns condition string 
		std::string condition;
		if(m_condition == "n") condition = "new";
		else if(m_condition == "b") condition = "broken";
		else if(m_condition == "u") condition = "used";
		return condition;
	}
	
	double Car::topSpeed() const{ return m_topSpeed;}

	void Car::display(std::ostream& out) const{
		out << "| " << std::right << std::setw(10) << m_maker
			<< " | " << std::left << std::setw(6) << condition() 
			<< " | " << std::fixed << std::setw(6)  << std::setprecision(2) << topSpeed() << " |" << std::endl;
	}

}