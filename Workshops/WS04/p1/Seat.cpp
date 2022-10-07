#define _CRT_SECURE_NO_WARNINGS

#include "Seat.h"
#include <cstring>
#include <fstream>
using namespace std;

namespace sdds {
	const int MAX_CHARS = 40;

	bool Seat::validate(int row, int letter)const
	{
		return (((row >= 1 && row <= 4) && (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')) ||
			((row >= 7 && row <= 15) && (letter >= 'A' && letter <= 'F')) ||
			((row >= 20 && row <= 38) && (letter >= 'A' && letter <= 'F')));
	}

	Seat& Seat::alAndCp(const char* str) //deallocate before calling
	{
		m_name = nullptr;
		if (str && str[0] != '\0')
		{
			m_name = new char[strlen(str) + 1];
			strcpy(m_name, str);
		}

		return *this;
	}

	Seat& Seat::reset()
	{
		delete[] m_name;
		m_name = nullptr;
		m_row = 0;
		m_letter = 0;

		return *this;
	}

	bool Seat::isEmpty()const
	{
		return m_name == nullptr;
	}

	bool Seat::assigned()const
	{
		return validate(m_row, m_letter);
	}
	
	Seat::Seat()
	{
		m_name = nullptr;
		reset();
	}
	
	Seat::Seat(const char* passengerName)
	{
		alAndCp(passengerName);
		m_row = 0;
		m_letter = 0;
	}

	Seat::Seat(const char* passengerName, int row, char letter)
	{
		alAndCp(passengerName);
		set(row, letter);
	}
	
	Seat::~Seat()
	{
		delete[] m_name;
	}

	Seat& Seat::set(int row, char letter)
	{
		if (validate(row, letter)) 
		{
			m_row = row;
			m_letter = letter;
		}
		else
		{
			m_row = 0;
			m_letter = 0;
		}

		return *this;
	}

	int Seat::row()const
	{
		return m_row;
	}

	char Seat::letter()const
	{
		return m_letter;
	}
	
	const char* Seat::passenger()const
	{
		return m_name;
	}

	ostream& Seat::display(ostream& coutRed)const
	{
		char tempString[MAX_CHARS + 1];

		if (isEmpty())
		{
			coutRed << "Invalid Seat!";
		}
		else if (validate(m_row, m_letter))
		{
			coutRed.width(40);
			coutRed.setf(ios::left);
			coutRed.fill('.');
			if (strlen(m_name) > 40)
			{
				strncpy(tempString, m_name, MAX_CHARS);
				tempString[MAX_CHARS] = '\0';
				coutRed << tempString;
			}
			else
			{
				coutRed << m_name;
			}
			coutRed.fill(' ');
			coutRed.unsetf(ios::left);
			coutRed << " ";
			coutRed << m_row;
			coutRed << m_letter;
		}
		else
		{
			coutRed.width(40);
			coutRed.setf(ios::left);
			coutRed.fill('.');
			coutRed << m_name;
			coutRed.fill(' ');
			coutRed << " ___";
			coutRed.unsetf(ios::left);
		}
		return coutRed;
	}

	istream& Seat::read(istream& cinRef)
	{
		reset();
		char name[70 + 1]{};
		int row{};
		char letter{};

		cinRef.getline(name, 70, ',');
		cinRef >> row;
		cinRef >> letter;
		cinRef.ignore(1000, '\n');
		if (cinRef)
		{
			alAndCp(name);
			set(row, letter);
		}		
		
		return cinRef;		
	}

}