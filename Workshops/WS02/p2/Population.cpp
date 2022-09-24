#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

	Population* aptr = nullptr;
	int nRecords = 0;

	bool read(Population& population, FILE* fptr)
	{
		bool success = fscanf(fptr, "%3[^,],%d\n", population.postalCode, &population.population) == 2;
		return success;
	}

	bool load(const char* const file)
	{
		int records;
		bool ok = false;

		if (openFile(file))
		{
			nRecords = noOfRecords();
			aptr = new Population[nRecords];

			for (int i = 0; i < nRecords && read(aptr[i], fptr); i++)
			{
				;
			}
			ok = true;
		}
		return ok;
	}

	void bubbleSort()
	{
		int i, j;
		int temp;

		for (i = nRecords; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (aptr[j].population > aptr[j + 1].population)
				{
					temp = aptr[j].population;
					aptr[j].population = aptr[j + 1].population;
					aptr[j + 1].population = temp;
				}
			}
		}
	}

	// 0 1 2 3 4 5 6 7 8 9 10
	
	void printSeperator(char seperator, int nSeperator)
	{
		for (int i = 0; i < nSeperator; i++)
		{
			cout << seperator;
		}
	}

	
	void display()
	{
		bubbleSort();
		cout << "Postal Code: population" << endl;
		printSeperator('-', 25);
		cout << endl;
		for (int i = 0; i < nRecords; i++)
		{
			cout << aptr[i].postalCode << " " << aptr[i].population << endl;
		}
		printSeperator('-', 25);
	}

	void deallocateMemory()
	{
		delete[] aptr;
		aptr = nullptr;
	}
}


//Open file
//Check if null
//If successful, assign dynamic memory & read into struct
//After read in dynamically, sort the file.
//print
//deallocate


	//bool read(char* postalCode, FILE* fptr)
	//{
	//	bool success = fscanf(fptr, "%3[^,]", postalCode) == 1;
	//	return success;
	//}

	//bool read(int& population, FILE* fptr)
	//{
	//	bool success = fscanf(fptr, ",%d\n", &population) == 1;
	//	return success;
	//}