//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 18, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "LblShape.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
   //Allocate and copy m_label
   LblShape& LblShape::alAndCp(const char* str)
   {
      if (str && str[0])
      {
         m_label = new char[strlen(str) + 1];
         sdds::strcpy(m_label, str);
      }

      return *this;
   }

   //Returns m_label
   const char* LblShape::label() const
   {
      return m_label;
   }

   //Deallocate memory for m_label
   LblShape& LblShape::deallocate()
   {
      delete[] m_label;
      m_label = nullptr;

      return *this;
   }

   //One argument constructor (receives a string)
   LblShape::LblShape(const char* cString)
   {
      alAndCp(cString);
   }

   //Destructor Deallocates m_label
   LblShape::~LblShape()
   {
      delete[] m_label;
   }

   //Reads a comma delimited string
   void LblShape::getSpecs(std::istream& istr)
   {
      deallocate();
      m_label = getDynCstr(',', istr);
      if (!m_label || !m_label[0])
      {
         m_label = nullptr;
      }
      ////Deallocate before doing anything
      //deallocate();

      //if (istr)
      //{
      //   alAndCp(label);
      //}
      //else
      //{
      //   istr.clear();
      //   istr.ignore(1000, ',');
      //}

      //delete[] label;
   }

   //Check if object is valid;
   LblShape::operator bool() const
   {
      return m_label != nullptr;
   }

   //Helper: read an int
   bool readInt(char delimiter, int& member, istream& istr)
   {
      bool success = true;
      char delimit;

      istr >> member;
      if (istr)
      {
         delimit = istr.get();
         if (delimit != delimiter)
         {
            istr.ignore(1000, delimiter);
            success = false;
         }
      }
      else
      {
         istr.clear();
         istr.ignore(1000, delimiter);
         success = false;
      }

      return success;
   }

   //Print a character a number of times
   ostream& printChar(char character, int num, ostream& ostr)
   {
      for (int i = 0; i < num; i++)
      {
         ostr << character;
      }

      return ostr;
   }

}







