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