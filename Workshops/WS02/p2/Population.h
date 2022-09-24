#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include <cstdio>
//#include "File.h"


namespace sdds 
{
	struct Population
	{
		char postalCode[3 + 1];
		int population;
	};

	bool load(const char* const file);
	void display();
	void deallocateMemory();
	void bubbleSort();
	void printSeperator(char seperator, int nSeperator);
	int calculateSum();
}
#endif // SDDS_POPULATION_H_