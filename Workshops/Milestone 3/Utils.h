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
   //void strcpy(char* des, const char* src, int len);
   int strcmp(const char* s1, const char* s2);

   ////Get integer value from user
   //int getInt(std::istream& istr = std::cin);

   ////Get positive integer value from user
   //int getIntPositive(std::istream& istr = std::cin);

   ////Get integer from user in specific range
   //int getIntRange(int min, int max, std::istream& istr = std::cin);

   ////Get user input for a yes or no question
   //char getYesNo(const char* validChars);

   ////Display a character 'x' number of times
   //std::ostream& printChar(char character, int num, std::ostream& ostr = std::cout);

   //char* lowerstrcpy(char des[], const char source[]);

   //char tolower(char ch);

   char toupper(char ch);

   char* upperstrcpy(char des[], const char source[]);

   int readIntValidate(std::istream& istr, char delimiter, const char* msg);

   int readInt(std::istream& istr, char delimiter);

   int readIntNonNegative(std::istream& istr, char delimiter);

   int readIntRange(std::istream& istr, char delimiter, int min, int max);

   bool readStringValidation(const char* string, int minChars, int maxChars, const char* prompt, std::istream& istr = std::cin);
}
#endif // !
