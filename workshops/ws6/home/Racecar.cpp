#include <iostream>
#include <sstream>
#include "Racecar.h"
#include "Car.h"
namespace sdds{
	Racecar::Racecar(std::istream& in) : Car(in){ in >> m_booster; }
	void Racecar::display(std::ostream& out) const{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const{ return Car::topSpeed() * ( 1 + m_booster);}
}