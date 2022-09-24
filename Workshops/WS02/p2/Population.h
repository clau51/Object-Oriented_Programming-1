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

	//int checkRecords(const char* const file);

	bool load(const char* const file);
	void display();
	void deallocateMemory();
	bool fReadFile(Population& population, FILE* fptr);
	//////bool fReadFile(Population& population);
	bool read(char* postalCode, FILE* fptr);
	bool read(int& population, FILE* fptr);
	void bubbleSort();
	bool read(Population& population, FILE* fptr);
	void printSeperator();
		//int read(Population*& aptr, FILE* fptr);

}
#endif // SDDS_POPULATION_H_