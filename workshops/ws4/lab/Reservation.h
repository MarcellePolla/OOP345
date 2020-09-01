#ifndef Reservation_h
#define Reservation_h
#include <iostream>

namespace sdds{
	class Reservation{
		std::string m_reservation_id;
		std::string m_name;
		std::string m_email;
		int m_peopleQnt;
		int m_day;
		int m_hour;
	public:
			Reservation();
			Reservation(const std::string& m_res);
			void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, Reservation& res);

}

#endif /* Reservation_h */
