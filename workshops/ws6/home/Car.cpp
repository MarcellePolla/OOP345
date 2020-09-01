#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include <algorithm>
#include <typeinfo>
#include "Car.h"

namespace sdds{

	Car::Car(std::istream& ss){
		//grab car info from stream
		std::string maker;
		std::string condition;
		double speed;

		getline(ss, maker, ',');
		m_maker = maker.substr(maker.find_first_not_of(' '), (maker.find_last_not_of(' ') - maker.find_first_not_of(' ')) + 1);

		getline(ss, condition, ',');
		condition.erase(std::remove(condition.begin(), condition.end(), ' '), condition.end());
		if(!condition.empty())
			condition = condition.substr(condition.find_first_not_of(' '), (condition.find_last_not_of(' ') - condition.find_first_not_of(' ')) + 1);

		setCondition(condition);


		//ss >> speed;
		if(ss >> speed){
			m_topSpeed = speed;
			std::string comma;
			ss >> comma;
		}else{
			throw "Invalid record!";
		}
		
	}
	
	void Car::setCondition(std::string condition){ 
		if(condition == "n" || condition.empty()) m_condition = "new";
		else if(condition == "b") m_condition = "broken";
		else if(condition == "u") m_condition = "used";
		else throw "Invalid record!";
	}
	
	std::string Car::condition() const{ return m_condition;}
	
	double Car::topSpeed() const{ return m_topSpeed;}

	void Car::display(std::ostream& out) const{
		out << "| " << std::right << std::setw(10) << m_maker
			<< " | " << std::left << std::setw(6) << condition() 
			<< " | " << std::fixed << std::setw(6)  << std::setprecision(2) << topSpeed() << " |";
	}

}