#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include <iostream>
#include "TourTicket.h"

namespace sdds
{
	//bool validTour(const <- cannot change receiving paramter) const <- cannot change member variables
	class TourBus
	{
	private:
		TourTicket* m_tourPassenger; //change to m_
		int m_totalPassengers;
		int m_boarded;
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
		bool validTour(int num)const;
		void startTheTour()const;
		TourBus& board();
		bool allBoarded()const;
		//std::ostream& format(int width, char* string)const;
	};
}

#endif