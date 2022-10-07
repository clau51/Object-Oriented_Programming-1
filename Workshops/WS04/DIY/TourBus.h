#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include <iostream>
#include "TourTicket.h"

namespace sdds
{
	class TourBus
	{
	private:
		TourTicket* tourPassenger;
		int totalPassengers;
		int boarded;
		//TourBus t;
		//t = nullptr;
		//
		// cin >> num;
		//t = new TourBus[num]
		//
	public:
		TourBus& reset();
		TourBus();
		TourBus(int num);
		~TourBus();
		bool validTour()const; //is const because it doesn't change the return type or object?
		bool validTour(int num);
		void startTheTour()const;
		TourBus& board();
		//std::ostream& format(std::ostream& coutRef, int width);
	};
}

#endif