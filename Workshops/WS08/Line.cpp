#include <cstring>
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds
{
   Line::Line() : LblShape()  //Not necessary?...by default it will invoke default constructor of base class
   {
      m_length = 0;
   }

   Line::Line(const char* cString, int length) : LblShape(cString)
   {
      if (length > 0)
      {
         m_length = length;
      }
   }

   void Line::getSpecs(std::istream& istr)
   {
      char newline;
      bool ok;
      LblShape::getSpecs(istr);

      do
      {
         ok = true;
         istr >> m_length;
         if (istr)
         {
            newline = istr.get();
            if (newline != '\n') //istr && newline != '\n' 3aa
            {
               cout << "Invalid integer, try again: ";
               cin.clear();
               cin.ignore(1000, '\n');
               ok = false;
            }
         }
         else
         {
            cout << "Invalid integer, try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok);
   }

   void Line::draw(std::ostream& ostr) const
   {
      if (m_length && label())
      {
         ostr << label();
         for (int i = 0; i < m_length - (signed int)(strlen(label())); i++)
         {
            ostr << "=";
         }
      }
   }




}