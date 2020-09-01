#include <iostream>
#include "ConfirmationSender.h"
#include "Reservation.h"
namespace sdds{
	//zero argument constructor
	ConfirmationSender::ConfirmationSender() : c_reservation{nullptr}, m_resCt(0){}

	//copy constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& conf){ *this = conf;}

	//copy assignment operator
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& conf){
		if(this != &conf){
			m_resCt = conf.m_resCt;
			delete [] c_reservation;

			c_reservation = new const Reservation*[conf.m_resCt];
			for(size_t i = 0; i < conf.m_resCt; i++){
				c_reservation[i] = conf.c_reservation[i];
			}
		}
		return *this;
	}

	//add reservation
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
		bool isIn = false;
		for(size_t i = 0; i < m_resCt; i++){
			if(c_reservation[i] == &res)
				isIn = true;
		}
		if(isIn == false){

			ConfirmationSender temp = *this;

			delete [] c_reservation;
			m_resCt++;
			c_reservation = new const Reservation*[m_resCt];

			for(size_t i = 0; i < temp.m_resCt; i++){
				c_reservation[i] = temp.c_reservation[i]; 
			}

			c_reservation[m_resCt - 1] = &res;
		}
		return *this;
	}
	//remove reservation
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){

		size_t tempSize = m_resCt;
		for(size_t i = 0; i < tempSize; i++){
			if(c_reservation[i] == &res){
				c_reservation[i] = nullptr;
				m_resCt--;
				for(size_t x = i + 1; x < tempSize; ++x){
					c_reservation[x - 1 ] = c_reservation[x];
				}

				c_reservation[m_resCt] = nullptr;
			}
		}
		
		return *this;
	}

	//move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& conf){
		*this = std::move(conf);
	}

	//move assignment operator
	ConfirmationSender&& ConfirmationSender::operator=(ConfirmationSender&& conf){
		if(this != &conf){
			c_reservation = conf.c_reservation;
			m_resCt = conf.m_resCt;
			conf.c_reservation = nullptr;
			conf.m_resCt = 0;
		}
		return std::move(*this); 
	}

	
	//destructor	
	ConfirmationSender::~ConfirmationSender(){ delete [] c_reservation;}
	
	//display
	void ConfirmationSender::display(std::ostream& os){
		os << "--------------------------" << std::endl
			<< "Confirmations to Send" << std::endl
			<< "--------------------------" << std::endl;
		if(!m_resCt){
			os << "The object is empty!" << std::endl;
		}else{
			for(size_t i = 0; i < m_resCt; i++){
				(*c_reservation[i]).display(os);
			}
		}
		os << "--------------------------" << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, ConfirmationSender& conf){
		conf.display(os);
		return os;
	}

}