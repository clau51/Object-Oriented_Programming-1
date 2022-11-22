//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 18, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Line.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   //Set the whole object to a safe empty state
   Line& Line::setEmpty()
   {
      deallocate();
      m_length = 0;

      return *this;
   }

   //Two argument constructor: receives a string and int
   Line::Line(const char* cString, int length) : LblShape(cString)
   {
      if (length > 0)
      {
         m_length = length;
      }
   }

   //Override: reads comma-separated Line from istream
   void Line::getSpecs(std::istream& istr)
   {
      bool success;

      LblShape::getSpecs(istr);

      if (label())
      {
         success = readInt('\n', m_length, istr);
         if (!(success && m_length > 0))
         {
            setEmpty();
         }
      }
   }

   //Override: draws the line
   void Line::draw(std::ostream& ostr) const
   {
      if (*this)
      {
         ostr << label();
         for (int i = 0; i < m_length - strlen(label()); i++)
         {
            ostr << "=";
         }
      }
      //else //tester...
      //{
      //   ostr << "***ERROR: INVALID LINE!***" << endl;
      //}
   }
}