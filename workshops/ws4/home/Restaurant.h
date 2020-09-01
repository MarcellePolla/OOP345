#ifndef Restaurant_h
#define Restaurant_h
#include "Reservation.h"

namespace sdds{
	class Restaurant{
		Reservation* m_reservation {nullptr};
		size_t m_resCt {0};
		public:
			Restaurant(Reservation* reservations[], size_t cnt);
			~Restaurant();
			Restaurant(const Restaurant& rest);
			Restaurant& operator=(const Restaurant& rest);
			Restaurant(Restaurant&& rest);
			Restaurant&& operator=(Restaurant&& rest);
			size_t size() const;
			void display(std::ostream& os);
	};

	std::ostream& operator<<(std::ostream& os, Restaurant& rest);
}
#endif 