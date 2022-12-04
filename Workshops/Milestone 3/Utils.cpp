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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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

   int readIntValidate(istream& istr, char delimiter, const char* msg)
   {
      int input;
      bool ok;

      do
      {
         ok = true;
         input = readInt(istr, delimiter);
         if (input == -1)
         {
            cout << msg;
            ok = false;
         }
      } while (!ok);

      return input;
   }

   int readInt(istream& istr, char delimiter)
   {
      char delimit;
      int input;
      istr >> input;
      if (istr) //if input passes istr
      {
         delimit = istr.get();
         if (delimit != delimiter) //if input is not valid (12aa)
         {
            input = -1;
            cin.clear();
            cin.ignore(1000, delimiter);
         }
      }
      else //if input is not valid
      {
         istr.clear();
         istr.ignore(1000, delimiter);
         input = -1;
      }

      return input;
   }

   int readIntNonNegative(istream& istr, char delimiter)
   {
      int input = readInt(istr, delimiter);
      return input >= 0 ? input : -1;
   }

   int readIntRange(istream& istr, char delimiter, int min, int max)
   {
      int input = readInt(istr, delimiter);
      return input >= min && input <= max ? input : -1;
   }


   bool readStringValidation(char* string, int minChars, int maxChars, const char* prompt, istream& istr)
   {
      bool ok;
      char* tempString = nullptr;
      tempString = new char[maxChars + 1];
      do
      {
         ok = true;
         istr.getline(tempString, maxChars, '\n');
         if (istr)
         {
            if (strlen(tempString) < minChars || strlen(tempString) > maxChars)
            {
               ok = false;
               cout << prompt;
               istr.ignore(1000, '\n');
            }
            else
            {
               std::strcpy(string, tempString);
            }
         }
         else
         {
            istr.clear();
            istr.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok);

      return ok;
   }

}