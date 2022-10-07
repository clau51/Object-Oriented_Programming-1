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
		int m_numOfTags;

	public:
		//Check if list is empty
		bool isEmpty();

		//Set TagList to empty state
		void set();

		//Dynamically allocate memory for array of NameTags
		void set(int num);

		//Adds a NameTag to the TagList
		void add(const NameTag& nt);

		//Print all tags with the same size that is the frame size of the longest name in the list
		void print();
		
		//Deallocates memory for array of NameTags and sets TagList to safe empty state
		void cleanup();

		//Get index of the TagList that has the longest name
		int largest()const;
	};

	//Print top or bottom of border frame
	std::ostream& printBorder(int length, char border);

}

#endif