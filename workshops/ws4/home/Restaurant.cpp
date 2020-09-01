#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"

namespace sdds{

	// 2 argument constructor
	Restaurant::Restaurant(Reservation** reservations, size_t cnt){
		if(cnt > 0){
			m_reservation = new Reservation[cnt];
			for(size_t i = 0; i < cnt; i++){
				if(reservations[i] != nullptr){
					m_reservation[m_resCt++] = *reservations[i];
				}
			}
		}	
	}
	//copy constructor
	Restaurant::Restaurant(const Restaurant& rest){
		*this = rest;
	}

	Restaurant& Restaurant::operator=(const Restaurant& rest){
		if(this != &rest){
			if(rest.size() > 0){
				this->m_resCt = rest.m_resCt;
				delete [] this->m_reservation;
				m_reservation = new Reservation[rest.m_resCt];
 
				for(size_t i = 0; i < rest.size(); i++){
					this->m_reservation[i] = rest.m_reservation[i];
				}
			}
		}
		return *this;
	}
	//move constructor
	Restaurant::Restaurant(Restaurant&& rest){
		*this = std::move(rest);
	}

	//move assignment operator
	Restaurant&& Restaurant::operator=(Restaurant&& rest){
		if(this != &rest){
			m_resCt = rest.m_resCt;
			delete [] m_reservation;
			m_reservation = rest.m_reservation;
			rest.m_resCt = 0u;
			rest.m_reservation = nullptr;
		}

		return std::move(*this);
	}

	//destructor
	Restaurant::~Restaurant(){
		delete [] m_reservation;
	}

	//returns reservartions qnt
	size_t Restaurant::size() const {return m_resCt;}

	//display function
	void Restaurant::display(std::ostream& os){
		os << "--------------------------" << std::endl
			<< "Fancy Restaurant" << std::endl
			<< "--------------------------" << std::endl;
		if(!m_resCt){
			os << "The object is empty!" << std::endl;
		}else{
			for(size_t i = 0; i < size(); i++){
				os << m_reservation[i];
			}
		}
		os << "--------------------------" << std::endl;
	}

	//insertion operator overload
	std::ostream& operator<<(std::ostream& os, Restaurant& rest){
		rest.display(os);
		return os;
	}
}