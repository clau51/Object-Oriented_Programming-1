//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 7, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include <cstring>
#include <fstream>
using namespace std;

namespace sdds {
	const int MAX_CHARS = 40;
	const int MAX_NAME_LEN = 70;
	const int MIN_BUSINESS = 1;
	const int MAX_BUSINESS = 4;
	const int MIN_ECONPLUS = 7;
	const int MAX_ECONPLUS = 15;
	const int MIN_ECON = 20;
	const int MAX_ECON = 38;

	//Validate correct row numbers and seating letters
	bool Seat::validate(int row, int letter)const
	{
		return (((row >= MIN_BUSINESS && row <= MAX_BUSINESS) && (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')) ||
			((row >= MIN_ECONPLUS && row <= MAX_ECONPLUS) && (letter >= 'A' && letter <= 'F')) ||
			((row >= MIN_ECON && row <= MAX_ECON) && (letter >= 'A' && letter <= 'F')));
	}

	//Check if string is valid and if it is, copy string to name
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

	//Reset object to safe empty state
	Seat& Seat::reset()
	{
		delete[] m_name;
		m_name = nullptr;
		m_row = 0;
		m_letter = 0;

		return *this;
	}

	//Check if object is in empty state
	bool Seat::isEmpty()const
	{
		return m_name == nullptr;
	}

	//Check if seats are assigned and valid
	bool Seat::assigned()const
	{
		return validate(m_row, m_letter);
	}
	
	//Default constructor - set object to safe empty state
	Seat::Seat()
	{
		m_name = nullptr;
		reset();
	}
	
	//Constructor - deallocate memory and copy string to name
	Seat::Seat(const char* passengerName)
	{
		m_name = nullptr;
		delete[] m_name;
		alAndCp(passengerName);
		m_row = 0;
		m_letter = 0;
	}

	//Constructor - deallocate memory and copy string to name, then set row and letter
	Seat::Seat(const char* passengerName, int row, char letter)
	{
		m_name = nullptr;
		delete[] m_name;
		alAndCp(passengerName);
		set(row, letter);
	}
	
	//Destructor - deallocate memory
	Seat::~Seat()
	{
		delete[] m_name;
	}

	//Set row and letter (validate first)
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

	//Get row
	int Seat::row()const
	{
		return m_row;
	}

	//Get letter
	char Seat::letter()const
	{
		return m_letter;
	}
	
	//Get passenger name
	const char* Seat::passenger()const
	{
		return m_name;
	}

	//Display passenger and seat information in formatted manner
	ostream& Seat::display(ostream& coutRef)const
	{
		char tempString[MAX_CHARS + 1];

		if (isEmpty())
		{
			coutRef << "Invalid Seat!";
		}
		else if (validate(m_row, m_letter))
		{
			coutRef.width(MAX_CHARS);
			coutRef.setf(ios::left);
			coutRef.fill('.');
			if (strlen(m_name) > MAX_CHARS)
			{
				strncpy(tempString, m_name, MAX_CHARS);
				tempString[MAX_CHARS] = '\0';
				coutRef << tempString;
			}
			else
			{
				coutRef << m_name;
			}
			coutRef.fill(' ');
			coutRef.unsetf(ios::left);
			coutRef << " ";
			coutRef << m_row;
			coutRef << m_letter;
		}
		else
		{
			coutRef.width(MAX_CHARS);
			coutRef.setf(ios::left);
			coutRef.fill('.');
			coutRef << m_name;
			coutRef.fill(' ');
			coutRef << " ___";
			coutRef.unsetf(ios::left);
		}
		return coutRef;
	}

	//Read passenger information from file
	istream& Seat::read(istream& cinRef)
	{
		reset();
		char name[MAX_NAME_LEN + 1];
		int row;
		char letter;

		cinRef.getline(name, MAX_NAME_LEN, ',');
		cinRef >> row;
		cinRef >> letter;
		cinRef.ignore(1000, '\n');
		if (!cinRef.fail())
		{
			alAndCp(name);
			if (!isEmpty())
			{
				set(row, letter);
			}
		}		
		
		return cinRef;		
	}

}