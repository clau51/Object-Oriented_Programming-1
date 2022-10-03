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
	void TagList::set()
	{
		m_nameTags = nullptr;
		m_numOfTags = 0;
	}
	void TagList::set(int num)
	{
		cleanup();
		m_nameTags = new NameTag[num];
	}
	void TagList::add(const NameTag& nameTag)
	{
		if ((m_nameTags != nullptr) && (nameTag.length() <= 50))
		{
			m_nameTags[m_numOfTags] = nameTag;
			m_numOfTags++;
		}

	}
	void TagList::print()
	{
		int largestIndex = largest();
		for (int i = 0; i < m_numOfTags; i++)
		{
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
	
	void TagList::cleanup()
	{
		delete[] m_nameTags;
		set();
	}

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

	ostream& printBorder(int length, char border)
	{
		for (int i = 0; i < length; i++)
		{
			cout << border;
		}
		return cout;
	}
}