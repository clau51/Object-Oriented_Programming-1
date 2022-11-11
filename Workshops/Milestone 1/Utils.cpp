/***********************************************************************
// Utils Module
// File  utils.cpp
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
#include <iostream>
#include "Utils.h"

using namespace std;
namespace sdds
{
   int strlen(const char* str)
   {
      int len = 0;
      while (str[len])
      {
         len++;
      }
      return len;
   }
   void strcpy(char* des, const char* src, int len)
   {
      int i;
      for (i = 0; src[i] && (len < 0 || i < len); i++)
      {
         des[i] = src[i];
      }
      des[i] = 0; // turning the char array des in to a cString by null terminating it.
   }
   int strcmp(const char* s1, const char* s2)
   {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }

   int getInt(int min, int max)
   {
      bool ok;
      int userInput = 0;

      do
      {
         ok = true;
         char newline;
         cin >> userInput;
         newline = cin.get();

         if (cin && newline == '\n')
         {
            if (userInput < min || userInput > max)
            {
               cout << "Invalid selection, try again: ";
               ok = false;
            }
         }
         else
         {
            cout << "Invalid Integer, try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }

      } while (!ok);

      return userInput;
   }
}