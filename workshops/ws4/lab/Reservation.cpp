#include <iostream>
#include <string>
#include <algorithm> 
#include <iomanip>
#include "Reservation.h"

namespace sdds{
	Reservation::Reservation() {}

	Reservation::Reservation(const std::string& m_res){

		std::string msg = m_res;
		msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end());

		//get reservation id
		std::string::size_type idEnd;
		idEnd = msg.find(":");
		m_reservation_id = msg.substr(0, idEnd); 
		msg.erase(0, idEnd +1);

		//get comma separated items
		size_t pos = 0;
		int i = 0;
		std::string token[4];
		while((pos = msg.find(',')) != std::string::npos){
			token[i++] = msg.substr(0, pos);
    		msg.erase(0, pos +1 );
		}
		m_name = token[0];
		m_email= token[1];
		m_peopleQnt = std::stoi(token[2]);
		m_day = std::stoi(token[3]);
		m_hour = std::stoi(msg); //gets what is left
/*


		//get name
		std::string::size_type nameEnd;
		idEnd++;
		nameEnd = msg.find(",", idEnd);
		m_name = msg.substr(idEnd, nameEnd - idEnd);
	

		//get email
		std::string::size_type emailEnd;
		nameEnd++;
		emailEnd = msg.find(",", nameEnd);
		m_email = msg.substr( nameEnd , emailEnd - nameEnd);

		//get party size
		std::string::size_type partyEnd;
		emailEnd++;
		partyEnd = msg.find(",", emailEnd);
		m_peopleQnt = std::stoi(msg.substr( emailEnd, partyEnd - emailEnd));

		//get day
		std::string::size_type dayEnd;
		partyEnd++;
		dayEnd = msg.find(",", partyEnd);
		m_day = std::stoi(msg.substr( partyEnd, dayEnd - partyEnd));

		//get time
		std::string::size_type timeEnd;
		dayEnd++;
		timeEnd = msg.find('\n', dayEnd);
		m_hour = std::stoi(msg.substr( dayEnd, timeEnd - dayEnd));

*/

	}

	void Reservation::display(std::ostream& os) const{
		os << "Reservation " << m_reservation_id << ": " 
		<< std::right << std::setw(10) << m_name << " "
		<< std::left << std::setw(25) <<  (" <" + m_email + ">"); 

		if(m_hour >= 6 && m_hour <= 9){
			os << "Breakfast on day " << m_day << " @ " << m_hour << ":00 for " << m_peopleQnt << " people.";
		}
		else if(m_hour >= 11 && m_hour <= 15){
			os << "Lunch on day " << m_day << " @ " << m_hour << ":00 for " << m_peopleQnt << " people.";
		}
		else if(m_hour >= 17 && m_hour <= 21){
			os << "Dinner on day " << m_day << " @ " << m_hour << ":00 for " << m_peopleQnt << " people.";
		}
		else{
			os << "Drinks on day " << m_day << " @ " << m_hour << ":00 for " << m_peopleQnt << " people.";
		}

		 os << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, Reservation& res){
		res.display(os);
		return os;
	}
}

