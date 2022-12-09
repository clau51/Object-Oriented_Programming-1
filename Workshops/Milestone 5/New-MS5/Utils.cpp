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
// Carmen Lau      November 8, 2022 Added getInt, getIntPositive, getIntRange, getDouble, getDblNonNeg, getDoubleRange, getYesNo, printChar
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

   //Get integer value from user
   int getInt(istream& istr)
   {
      int userInput;
      char newline;
      bool ok;

      do
      {
         ok = true;
         istr >> userInput;
         if (istr)
         {
            newline = istr.get();
            if (newline != '\n')
            {
               cout << "Invalid Integer, try again: ";
               istr.clear();
               istr.ignore(1000, '\n');
               ok = false;
            }
         }
         else
         {
            cout << "Invalid Integer, try again: ";
            istr.clear();
            istr.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok);

      return userInput;
   }

   //Get integer from user in specific range
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

   //Display a character 'x' number of times
   std::ostream& printChar(char character, int num, std::ostream& ostr)
   {
      for (int i = 0; i < num; i++)
      {
         ostr << character;
      }

      return ostr;
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

   //Read an int from file
   int readInt(char delimiter, istream& istr) //fixed, ms4
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
            istr.setstate(ios::failbit);
         }
      }
      else //if input is not valid
      {
         input = -1;
         istr.setstate(ios::failbit);
      }

      return input;
   }

   //Get string from user and print error message; repeat until valid
   void getString(char* string, int minChars, int maxChars, const char* prompt, istream& istr) //used in ms4
   {
      bool ok;
      char* tempString = new char[maxChars + 1];
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
            }
            else
            {
               std::strcpy(string, tempString);
            }
         }
         else
         {
            cout << prompt;
            istr.clear();
            istr.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok);

      delete[] tempString;
   }

   //Get character from user and print error message; repeat until valid
   char getChar(const char* validChars, const char* errMsg, istream& istr) //fixed, ms4
   {
      char input;
      char delimiter;
      bool ok;
      do
      {
         ok = true;
         istr >> input;
         delimiter = istr.get();
         if (delimiter != '\n')
         {
            cout << errMsg;
            istr.clear();
            istr.ignore(1000, '\n');
            ok = false;
         }
         else
         {
            bool isFound = false;
            for (int i = 0; i < strlen(validChars) && !isFound; i++)
            {
               if (input == validChars[i])
               {
                  isFound = true;
               }
            }

            if (!isFound)
            {
               cout << errMsg;
               ok = false;
            }
         }
      } while (!ok);
      return input;
   }

   //Read a char from file
   char readChar(char delimiter, const char* validChars, istream& istr) //fixed, ms4
   {
      char input;
      char del;

      istr >> input;
      del = istr.get();
      if (del != delimiter)
      {
         istr.ignore(1000, delimiter);
         istr.setstate(ios::failbit);
      }
      else
      {
         bool isFound = false;
         for (int i = 0; i < strlen(validChars) && !isFound; i++)
         {
            if (input == validChars[i])
            {
               isFound = true;
            }
         }

         if (!isFound)
         {
            istr.setstate(ios::failbit);
         }
      }
      return input;
   }

}