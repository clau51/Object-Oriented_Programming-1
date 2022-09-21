//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 21, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Assessment.h"

using namespace std;

namespace sdds
{
	bool read(int& value, FILE* fptr)
	{
		bool success = fscanf(fptr, "%d", &value) == 1;
		return success;
	}
	bool read(double& value, FILE* fptr)
	{
		bool success = fscanf(fptr, "%lf", &value) == 1;
		return success;
	}
	bool read(char* cstr, FILE* fptr)
	{
		bool success = fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
		return success;
	}

	bool read(Assessment& asme, FILE* fptr)
	{
		double tempDouble;
		char tempcString[60 + 1];
		bool ok = false;

		if (read(tempDouble, fptr) && read(tempcString, fptr))
		{
			asme.m_mark = new double;
			asme.m_title = new char[strlen(tempcString) + 1];
			*asme.m_mark = tempDouble;
			strcpy(asme.m_title, tempcString);
			ok = true;	
		}
		else
		{
			ok = false;
		}
		return ok;
	}
	void freeMem(Assessment*& aptr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;
		}
		delete[] aptr;
		aptr = nullptr;
	}

	int read(Assessment*& aptr, FILE* fptr)
	{
		int i;
		int records;
		
		read(records, fptr);

		aptr = new Assessment[records];

		for (i = 0; i < records && read(aptr[i], fptr); i++)
		{
			;
		}
		
		if (i != records)
		{
			freeMem(aptr, i);
			i = 0;
		}	
		return i;	
	}
}

