#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

	Population* aptr = nullptr;
	int nRecords = 0;

	bool load(const char* const file)
	{
		bool ok = true;
		bool success = false;

		if (openFile(file))
		{
			nRecords = noOfRecords();
			aptr = new Population[nRecords];

			for (int i = 0; i < nRecords && ok; i++)
			{ 
				success = true;
				if (!read(aptr[i]))
				{
					success = false;
					ok = false;
					cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
				}
			}
		}
		else
		{
			cout << "Could not open data file: " << file << endl;
		}
		return success;
	}

	void bubbleSort()
	{
		int i, j;
		int tempPopulation;
		char tempPostal[3 + 1];

		for (i = nRecords - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (aptr[j].population > aptr[j + 1].population)
				{
					strcpy(tempPostal, aptr[j].postalCode);
					strcpy(aptr[j].postalCode, aptr[j + 1].postalCode);
					strcpy(aptr[j + 1].postalCode, tempPostal);

					tempPopulation = aptr[j].population;
					aptr[j].population = aptr[j + 1].population;
					aptr[j + 1].population = tempPopulation;
				}
			}
		}
	}
	
	void printSeperator(char seperator, int nSeperator)
	{
		for (int i = 0; i < nSeperator; i++)
		{
			cout << seperator;
		}
	}

	int calculateSum()
	{
		int totalPopulation = 0;

		for (int i = 0; i < nRecords; i++)
		{
			totalPopulation += aptr[i].population;
		}

		return totalPopulation;
	}

	
	void display()
	{
		bubbleSort();
		cout << "Postal Code: population" << endl;
		printSeperator('-', 25);
		cout << endl;
		for (int i = 0; i < nRecords; i++)
		{
			cout << (i + 1) << "- " << aptr[i].postalCode << ":  " << aptr[i].population << endl;
		}
		printSeperator('-', 25);
		cout << endl;
		cout << "Population of Canada: " << calculateSum() << endl;
	}

	void deallocateMemory()
	{
		delete[] aptr;
		aptr = nullptr;
	}
}