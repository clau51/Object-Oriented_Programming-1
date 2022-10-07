//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 3, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "TagList.h"
#include "NameTag.h"

using namespace std;
namespace sdds
{
	//Check if list is empty
	bool TagList::isEmpty()
	{
		return m_nameTags == nullptr;
	}

	//Set TagList to empty state
	void TagList::set()
	{
		m_nameTags = nullptr;
		m_numOfTags = 0;
	}

	//Dynamically allocate memory for array of NameTags
	void TagList::set(int num)
	{
		cleanup();
		if (isEmpty())
		{
			m_nameTags = new NameTag[num];
		}
	}

	//Adds a NameTag to the TagList
	void TagList::add(const NameTag& nameTag)
	{
		m_nameTags[m_numOfTags] = nameTag;
		m_numOfTags++;
	}

	//Print all tags with the same size that is the frame size of the longest name in the list
	void TagList::print()
	{
		//Get the index with the largest name
		int largestIndex = largest();
		for (int i = 0; i < m_numOfTags; i++)
		{
			//Get the largest name for the frame size
			int largestLength = m_nameTags[largestIndex].length();
			printBorder(largestLength + 4, '*') << endl;
			
			cout << ("* ");
			cout.width(largestLength);
			cout.setf(ios::left);
			m_nameTags[i].print();
			cout.unsetf(ios::left);
			cout << " *" << endl;
			
			printBorder(largestLength + 4, '*') << endl;
		}
	}
	
	//Deallocates memory for array of NameTags and sets TagList to safe empty state
	void TagList::cleanup()
	{
		delete[] m_nameTags;
		set();
	}

	//Get index of the TagList that has the longest name
	int TagList::largest()const
	{
		int largestIndex = 0;
		for (int i = 0; i < m_numOfTags; i++)
		{
			if (m_nameTags[largestIndex].length() < m_nameTags[i].length())
			{
				largestIndex = i;
			}
		}
		return largestIndex;
	}

	//Print top or bottom of border frame
	ostream& printBorder(int length, char border)
	{
		for (int i = 0; i < length; i++)
		{
			cout << border;
		}
		return cout;
	}
}