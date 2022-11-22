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
// Name            Date             Reason
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

   int strcmp(const char* s1, const char* s2)
   {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }

   char toupper(char ch)
   {
      if (ch >= 'a' && ch <= 'z')
      {
         ch -= ('a' - 'A');
      }
      return ch;
   }

   char* upperstrcpy(char des[], const char source[])
   {
      int i = 0, j = 0;
      for (; source[i] != 0; i++)
      {
         des[j++] = toupper(source[i]);
      }
      des[j] = char(0);
      return des;
   }

   int readInt(istream& istr, char delimiter)
   {
      char delimit;
      int input;
      istr >> input;
      if (istr)
      {
         delimit = istr.get();
         if (delimit != delimiter)
         {
            input = -1;
            cin.clear();
            cin.ignore(1000, delimiter);
         }
      }
      else
      {
         istr.clear();
         istr.ignore(1000, delimiter);
         input = -1;
      }

      return input;
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
         if (cin.get() == '\n')
         {
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
         }
         else
         {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok);
      return userInput;
   }

}