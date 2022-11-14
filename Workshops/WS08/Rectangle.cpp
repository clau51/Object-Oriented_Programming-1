//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Rectangle.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   Rectangle::Rectangle() : LblShape() //no needed?
   {
      m_width = 0;
      m_height = 0;
   }

   Rectangle::Rectangle(const char* cstr, int width, int height) : LblShape(cstr)
   {     
      if (label())
      {
         if (width >= ((signed int)strlen(label()) + 2) && height >= 3)
         {
            m_width = width;
            m_height = height;
         }
      }
      //else //already safely initialized in class
      //{
      //   m_width = 0;
      //   m_height = 0;
      //}
   }

   void Rectangle::getSpecs(std::istream& istr)
   {
      //bool ok;
      //char comma;

      LblShape::getSpecs(istr);

      istr >> m_width;
      istr.ignore();
      istr >> m_height;
      istr.ignore();

      //do
      //{
      //   ok = true;
      //   istr >> m_width;
      //   if (istr)
      //   {
      //      comma = istr.get();
      //      if (comma != ',')
      //      {
      //         ok = false;
      //         cout << "Invalid width integer, try again: ";
      //         cin.clear();
      //         cin.ignore(1000, '\n');
      //      }
      //      else
      //      {
      //         m_height = getInt(istr);
      //      }
      //   }
      //   else
      //   {
      //      cout << "entered here, try again: ";
      //      cin.clear();
      //      cin.ignore(1000, '\n');
      //      ok = false;
      //   }

      //} while (!ok);

         /*m_width = getInt(istr);
         m_height = getInt(istr);*/
         //do
         //{
         //   ok = true;
         //   istr >> m_width;
         //   newline = istr.get();
         //   if (istr && newline == '\n')
         //   {
         //      istr >> m_height;
         //      newline = istr.get();
         //      if (istr && newline == '\n')
         //      {
         //         cin.clear();
         //         cin.ignore(1000, '\n');
         //      }
         //   }
         //   else
         //   {
         //      cin.clear();
         //      cin.ignore(1000, '\n');
         //   }
         //} while (!ok);
   }

   void Rectangle::draw(std::ostream& ostr) const
   {
      if (m_height > 0 && m_width > 0) //Is the rectangle considered to be in an empty state if the m_label (base class) is nullptr?
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

   }
}