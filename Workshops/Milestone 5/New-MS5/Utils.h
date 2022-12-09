/***********************************************************************
// Utils Module
// File  utils.h
// Version 0.0
// Date
// Author
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>

namespace sdds
{
	int strlen(const char* str);
	void strcpy(char* des, const char* src, int len);
	int strcmp(const char* s1, const char* s2);

	//Get integer value from user; repeat until valid
	int getInt(std::istream& istr = std::cin);

	//Get integer from user in specific range; repeat until valid
	int getIntRange(int min, int max, std::istream& istr = std::cin);

	//Display a character 'x' number of times
	std::ostream& printChar(char character, int num, std::ostream& ostr = std::cout);

	//Get character from user and print error message; repeat until valid
	char getChar(const char* validChars, const char* errMsg, std::istream& istr = std::cin);

	//Get string from user and print error message; repeat until valid
	void getString(char* string, int minChars, int maxChars, const char* prompt, std::istream& istr = std::cin); //used in ms4
	
	//Get character in uppercase
	char toupper(char ch);

	//Copy uppercase string
	char* upperstrcpy(char des[], const char source[]);

	//Read an int from file
	int readInt(char delimiter, std::istream& istr = std::cin);

	//Read a char from file
	char readChar(char delimiter, const char* validChars, std::istream& istr = std::cin);

}
#endif // !
