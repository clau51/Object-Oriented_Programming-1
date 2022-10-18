//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 9, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "TourBus.h"
#include "TourTicket.h"

using namespace std;

namespace sdds
{
	const int PRIVATE_TOUR = 4;
	const int MINI_TOUR = 16;
	const int FULL_TOUR = 22;
	const int MAX_NAME_LEN = 40;
	
	//Reset TourBus object to a safe empty state
	TourBus& TourBus::reset()
	{
		delete[] m_tourPassenger;
		m_tourPassenger = nullptr;
		m_totalPassengers = 0;
		m_boarded = 0;

		return *this;
	}
	
	//Constructor - set to a safe empty state
	TourBus::TourBus()
	{
		m_tourPassenger = nullptr;
		reset();
	}

	//Constructor - set to a safe empty state and assign dynamic memory
	TourBus::TourBus(int num)
	{
		m_tourPassenger = nullptr;
		reset();
		if (validTour(num))
		{
			m_tourPassenger = new TourTicket[num];
			m_totalPassengers = num;
		}
	}

	//Check if dynamic memory is allocated
	bool TourBus::validTour()const
	{
		return m_tourPassenger != nullptr;
	}
	
	//Check if tour size is valid
	bool TourBus::validTour(int num)const
	{
		return (num == PRIVATE_TOUR || num == MINI_TOUR || num == FULL_TOUR);
	}
	
	//Destructor - deallocate dynamic memory
	TourBus::~TourBus()
	{
		delete[] m_tourPassenger;
	}
	
	//Check if the correct number of passengers have boarded
	bool TourBus::allBoarded()const
	{
		return m_boarded == m_totalPassengers;
	}

	//Start the tour
	void TourBus::startTheTour()const
	{
		if (allBoarded())
		{
			cout << "Starting the tour...." << endl;
			cout << "Passenger List:" << endl;
			cout << "|Row | Passenger Name                           | Num |" << endl;
			cout << "+----+------------------------------------------+-----+" << endl;

			for (int i = 0; i < m_totalPassengers; i++)
			{
				cout << "|  ";
				cout.width(2);
				cout.setf(ios::left);
				cout << i + 1;
				cout.unsetf(ios::left);
				m_tourPassenger[i].display(cout) << endl;
			}
			cout << "+----+------------------------------------------+-----+" << endl;
		}
		else
		{
			cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
		}
	}

	//Board passengers
	TourBus& TourBus::board()
	{
		char name[MAX_NAME_LEN + 1];
		bool ok = true;

		if (validTour())
		{
			cout << "Boarding " << m_totalPassengers << " Passengers:" << endl;
			for (int i = 0; i < m_totalPassengers; i++)
			{
				do
				{
					cout << i + 1 << "/" << m_totalPassengers << "- Passenger Name: ";
					cin.getline(name, MAX_NAME_LEN, '\n');
					if (!cin.fail())
					{
						m_tourPassenger[i].issue(name); 
						m_boarded++;
						ok = true;
					}
					else
					{
						cout << "Please enter a valid name..." << endl;
						cin.clear();
						cin.ignore(1000, '\n');
						ok = false;
					}
				} while (!ok);
			}
		}

		return *this;
	}
}