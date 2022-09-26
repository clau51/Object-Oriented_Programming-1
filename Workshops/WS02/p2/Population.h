//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 24, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds 
{
	struct Population
	{
		char postalCode[3 + 1];
		int population;
	};

	//Load the data from file into dynamic memory
	bool load(const char* file);
	
	//Sort data by population in ascending order
	void display();

	//Sort data by population in ascending order
	void sort();
	
	//Copies the postal code from source to destination
	void copy(char* tempPostal, int j);
	
	//Copies the population from source to destination
	void copy(int& tempPopulation, int j);

	//Print divider
	void printSeperator(char seperator, int nSeperator);

	//Calculate the total population
	int calculateSum();

	//Deallocate memory
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_