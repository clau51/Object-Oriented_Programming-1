//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: December 1, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_

#include "Collection.h"

namespace sdds 
{
	template <typename T>
	bool search(const T* array, int size, const char* key, Collection<T>& collection)
	{
		bool ok = false;
		for (int i = 0; i < size; i++) {
			if (array[i] == key) {
				collection.add(array[i]);
				ok = true;
			}
		}

		return ok;
	}
}

#endif