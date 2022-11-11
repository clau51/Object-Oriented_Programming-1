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

namespace sdds
{
   int strlen(const char* str);
   void strcpy(char* des, const char* src, int len);
   int strcmp(const char* s1, const char* s2);
   int getInt();
   int getIntRange(int min, int max);
   char getYesNo(const char* validChars);

}
#endif // !
