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

   int getInt()
   {
      int userInput;
      char newline;
      bool ok;

      do
      {
         ok = true;
         cin >> userInput;
         newline = cin.get();

         if (newline != '\n')
         {
            cout << "Invalid Integer, try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok);

      return userInput;
   }


   int getIntRange(int min, int max)
   {
      bool ok;
      int userInput = 0;

      do
      {
         ok = true;
         userInput = getInt();

         if (userInput < min || userInput > max)
         {
            cout << "Invalid selection: ";
            ok = false;
         }

      } while (!ok);

      return userInput;
   }


   char getYesNo(const char* validChars)
   {
      char userInput = 0;
      bool ok;
      int found = 0;
      do
      {
         ok = true;
         cin >> userInput;
         for (int i = 0; i < sdds::strlen(validChars); i++)
         {
            if (userInput == validChars[i])
            {
               found++;
            }
         }

         if (found == 0)
         {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok);

      return userInput;
   }

   std::ostream& printChar(char character, int num, std::ostream& ostr)
   {
      for (int i = 0; i < num; i++)
      {
         ostr << character;
      }

      return ostr;
   }




}