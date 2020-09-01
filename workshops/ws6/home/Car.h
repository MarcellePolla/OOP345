#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <string>
#include "Vehicle.h"

namespace sdds{
	class Car : public Vehicle{
	
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;

	public:

		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		void setCondition(std::string condition);
		
	};
}
#endif