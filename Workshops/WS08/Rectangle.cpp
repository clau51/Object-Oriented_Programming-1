//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 18, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include "Rectangle.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   //Set whole object empty
   Rectangle& Rectangle::setEmpty()
   {
      deallocate();
      m_width = 0;
      m_height = 0;

      return *this;
   }
   
   //Default constructor
   Rectangle::Rectangle() : LblShape()
   {
      m_width = 0;
      m_height = 0;
   }

   //Three argument constructor: receives label, width, height
   Rectangle::Rectangle(const char* cstr, int width, int height) : LblShape(cstr)
   {
      if (width >= (strlen(label()) + 2) && height >= 3)
      {
         m_width = width;
         m_height = height;
      }
   }

   //Override: Read comma-separated Rectangle from istream
   void Rectangle::getSpecs(std::istream& istr)
   {
      bool success;

      LblShape::getSpecs(istr);

      if (label())
      {
         success = readInt(',', m_width, istr);
         if (success && (m_width - 2 >= strlen(label())))
         {
            success = readInt('\n', m_height, istr);
            if (!(success && m_height >= 3))
            {
               setEmpty();
            }
         }
         else
         {
            setEmpty();
         }
      }
      else
      {
         setEmpty();
      }
   }

   //Override: draws the rectangle
   void Rectangle::draw(std::ostream& ostr) const
   {
      if (m_height > 0 && m_width > 0 && label())
      {
         ostr << "+";
         printChar('-', m_width - 2, ostr);
         ostr << "+" << endl;

         ostr << "|"
            << setw(m_width - 2) << left << label() << right
            << "|" << endl;

         for (int i = 0; i < m_height - 3; i++)
         {
            ostr << "|" << setw(m_width - 2) << " " << "|" << endl;
         }

         ostr << "+";
         printChar('-', m_width - 2, ostr);
         ostr << "+";
      }
      //else //tester...
      //{
      //   ostr << "***INVALID RECTANGLE****" << endl;
      //}

   }
}