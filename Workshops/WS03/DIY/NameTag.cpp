#include <iostream>
#include "NameTag.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	bool NameTag::validate(const char* name)const
	{
		return (strlen(name) <= MAX_NAME_LEN) &&
			(name != nullptr);
	}

	void NameTag::print()const
	{
		cout << m_name;
	}

	void NameTag::set(const char* name)
	{
		if (validate(name))
		{
			sdds::strcpy(m_name, name);
		}
	}

	int NameTag::length()const
	{
		return sdds::strlen(m_name);
	}
}