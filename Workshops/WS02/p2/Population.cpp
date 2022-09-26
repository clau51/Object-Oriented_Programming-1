//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 24, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

	Population* aptr = nullptr;
	int nRecords = 0;
	
	//Load the data from file into dynamic memory
	bool load(const char* file)
	{
		bool success = true;

		if (openFile(file))
		{
			int i;
			int counter = 0;
			nRecords = noOfRecords();
			
			aptr = new Population[nRecords];

			for (i = 0; i < nRecords && read(aptr[i]); i++)
			{ 
				counter++;
			}
			
			if (counter != nRecords)
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
				success = false;
			}
		}
		else
		{
			cout << "Could not open data file: " << file << endl;
			success	= false;
		}
		closeFile();
		
		return success;
	}

	//Sort data by population in ascending order
	void sort()
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
					copy(tempPostal, j);
					copy(tempPopulation, j);
				}
			}
		}
	}

	//Copies the postal code from source to destination
	void copy(char* tempPostal, int j)
	{
		strcpy(tempPostal, aptr[j].postalCode);
		strcpy(aptr[j].postalCode, aptr[j + 1].postalCode);
		strcpy(aptr[j + 1].postalCode, tempPostal);
	}

	//Copies the population from source to destination
	void copy(int& tempPopulation, int j)
	{
		tempPopulation = aptr[j].population;
		aptr[j].population = aptr[j + 1].population;
		aptr[j + 1].population = tempPopulation;
	}

	//Print divider
	void printSeperator(char seperator, int nSeperator)
	{
		for (int i = 0; i < nSeperator; i++)
		{
			cout << seperator;
		}
	}

	//Calculate the total population
	int calculateSum()
	{
		int totalPopulation = 0;

		for (int i = 0; i < nRecords; i++)
		{
			totalPopulation += aptr[i].population;
		}

		return totalPopulation;
	}

	//Display data
	void display()
	{
		sort();
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

	//Deallocate memory
	void deallocateMemory()
	{
		delete[] aptr;
		aptr = nullptr;
	}
}