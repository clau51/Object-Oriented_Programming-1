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
#define _CRT_SECURE_NO_WARNINGS //NEEEED TO REMOVE*****************
#include <iostream>
#include <cstring> //GETTTTTT RIDDDDDDDDDDDD OF
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

   void readBoolValidation(bool& value, char delimiter, const char* errMsg, istream& istr)
   {
      bool ok;
      int input;
      do
      {
         ok = false;
         input = readInt(istr, delimiter);
         if (input != -1)
         {
            if (input == 1 || input == 0)
            {
               value = input;
               ok = true;
            }
            else
            {
               cout << errMsg;
            }
         }
      } while (!ok);
   }

   int readIntRange(istream& istr, char delimiter, int min, int max)
   {
      int input = readInt(istr, delimiter);
      return input >= min && input <= max ? input : -1;
   }


   void getStringValidation(char* string, int minChars, int maxChars, const char* prompt, istream& istr)
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

   int gettry(std::istream& istr)
   {
      int userInput;
      char newline;
      bool ok;

      do
      {
         ok = true;
         istr >> userInput;
         newline = istr.get();

         if (newline != '\n')
         {
            std::cout << "Invalid Integer, try again: ";
            istr.clear();
            istr.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok);

      return userInput;
   };

}