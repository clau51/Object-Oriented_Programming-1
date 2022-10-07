//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 3, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "NameTag.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	//Validate if string is less than max chars and if it is not empty
	bool NameTag::validate(const char* name)const
	{
		return (strlen(name) <= MAX_NAME_LEN) &&
			name[0] != '\0';
	}

	//Print name tag
	void NameTag::print()const
	{
		cout << m_name;
	}

	//Set name tag
	void NameTag::set(const char* name)
	{
		if (validate(name))
		{
			sdds::strcpy(m_name, name);
		}
		else
		{
			cout << "Invalid name!";
		}
	}

	//Get length of name
	int NameTag::length()const
	{
		return sdds::strlen(m_name);
	}
}