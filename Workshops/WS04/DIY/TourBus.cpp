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
	
	TourBus& TourBus::reset()
	{
		delete[] tourPassenger;
		tourPassenger = nullptr;
		totalPassengers = 0;
		boarded = 0;

		return *this; // is "t" this object?
	}
		
	TourBus::TourBus()
	{
		tourPassenger = nullptr;
		reset();
	}

	TourBus::TourBus(int num)
	{
		tourPassenger = nullptr;
		reset();
		if (validTour(num))
		{
			tourPassenger = new TourTicket[num];
			totalPassengers = num;
		}
	}
	
	bool TourBus::validTour(int num)
	{
		return (num == PRIVATE_TOUR || num == MINI_TOUR || num == FULL_TOUR);
	}
	
	TourBus::~TourBus()
	{
		delete[] tourPassenger;
	}

	bool TourBus::validTour()const
	{
		return tourPassenger != nullptr;
	}
	
	void TourBus::startTheTour()const
	{
		if (boarded == totalPassengers)
		{
			cout << "|Row | Passenger Name                           | Num |" << endl;
			cout << "+----+------------------------------------------+-----+" << endl;

			TourBus tr;
			tr = *this;
			
			//format(cout << "Row", 40) << endl; 

			for (int i = 0; i < totalPassengers; i++)
			{
				cout << "|";
				cout.width(4);
				cout.setf(ios::right);
				cout << i + 1;
				cout.unsetf(ios::right);
				tourPassenger[i].display(cout) << endl;
			}
			cout << "+----+------------------------------------------+-----+" << endl;

		}
		else
		{
			cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
		}
	}

	//ostream& TourBus::format(ostream& coutRef, int width)
	//{
	//	cout << "|";
	//	cout.width(width);
	//	cout << "|";

	//	return cout;
	//}

	TourBus& TourBus::board()
	{
		char name[MAX_NAME_LEN + 1];
		bool ok = true;

		if (validTour())
		{
			cout << "Boarding " << totalPassengers << " Passengers:" << endl;
			for (int i = 0; i < totalPassengers; i++)
			{
				do
				{
					cout << i + 1 << "/" << totalPassengers << "- Passenger Name: ";
					cin.getline(name, MAX_NAME_LEN, '\n');
					if (!cin.fail())
					{
						tourPassenger[i].issue(name); 
						boarded++;
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