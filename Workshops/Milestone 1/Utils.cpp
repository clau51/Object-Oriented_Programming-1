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
// Carmen Lau      November 8, 2022 Added getInt, getIntPositive, getIntRange, printChar
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

   int getInt(istream& istr)
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

   int getIntPositive(istream& istr)
   {
      int userInput;
      bool ok;

      do
      {
         ok = true;
         userInput = getInt(istr);
         if (userInput < 0)
         {
            cout << "Please enter a positive value: ";
            ok = false;
         }
      } while (!ok);

      return userInput;
   }


   int getIntRange(int min, int max, istream& istr)
   {
      bool ok;
      int userInput = 0;

      do
      {
         ok = true;
         userInput = getInt(istr);

         if (userInput < min || userInput > max)
         {
            cout << "Invalid selection, try again: ";
            //cout << "Please enter a number between " << min << " and " << max << ": ";
            ok = false;
         }

      } while (!ok);

      return userInput;
   }

   //Display a character
   std::ostream& printChar(char character, int num, std::ostream& ostr)
   {
      for (int i = 0; i < num; i++)
      {
         ostr << character;
      }

      return ostr;
   }

}