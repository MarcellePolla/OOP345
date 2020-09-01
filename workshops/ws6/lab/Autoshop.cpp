#include <iostream>
#include "Autoshop.h"
#include "Vehicle.h"

namespace sdds{

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle){
		//add vehicles to vector
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const{
		
		out << "--------------------------------\n"
			<< "| Cars in the autoshop!        |\n"
			<< "--------------------------------\n";
			//iterate vector to display vehicles in inheritance hierarchy
			for(auto i = m_vehicles.begin(); i != m_vehicles.end(); i++){
				(*i)->display(out);
			}
		out	<< "--------------------------------" << std::endl;
	}

}