//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 3, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_
#include <iostream>
#include "NameTag.h"

namespace sdds
{
	struct TagList
	{
	private:
		NameTag* m_nameTags;
		int m_numOfTags{};

	public:
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();
		int largest()const;
	};

	std::ostream& printBorder(int length, char border);

}

#endif