#ifndef ConfirmationSender_h
#define ConfirmationSender_h
#include "Reservation.h"
namespace sdds{
	class ConfirmationSender{
		const Reservation** c_reservation {nullptr};
		size_t m_resCt {0};
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& conf);
		ConfirmationSender& operator=(const ConfirmationSender& conf);
		ConfirmationSender(ConfirmationSender&& conf);
		ConfirmationSender&& operator=(ConfirmationSender&& conf);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		void display(std::ostream& os);
	};

	std::ostream& operator<<(std::ostream& os, ConfirmationSender& conf);

}

#endif