//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 9, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include <iostream>
#include "TourTicket.h"

namespace sdds
{
	class TourBus
	{
	private:
		TourTicket* m_tourPassenger;
		int m_totalPassengers;
		int m_boarded;

	public:
		//Reset TourBus object to a safe empty state
		TourBus& reset();

		//Constructor - set to a safe empty state
		TourBus();
		
		//Constructor - set to a safe empty state and assign dynamic memory
		TourBus(int num);

		//Destructor - deallocate dynamic memory
		~TourBus();

		//Check if dynamic memory is allocated
		bool validTour()const;

		//Check if tour size is valid
		bool validTour(int num)const;

		//Start the tour
		void startTheTour()const;

		//Board passengers
		TourBus& board();

		//Check if the correct number of passengers have boarded
		bool allBoarded()const;
	};
}

#endif