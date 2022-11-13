#include "Rectangle.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds
{
   Rectangle::Rectangle() /* : LblShape() */
   {
      m_width = 0;
      m_height = 0;
   }

   Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
   {
      m_width = width;
      m_height = height;

      if (m_height < 3 || m_width < (strlen(label) + 2)) // may need to cchange
      {
         //setEmpty()
         m_width = 0;
         m_height = 0;
      }
   }

   void Rectangle::getSpecs(std::istream& istr)
   {
      bool ok;
      char newline;

      LblShape::getSpecs(istr);

      do
      {
         ok = true;
         istr >> m_width;
         newline = istr.get();
         if (istr && newline == '\n')
         {
            istr >> m_height;
            newline = istr.get();
            if (!(istr && newline == '\n'))
            {
               cin.clear();
               cin.ignore(1000, '\n');
            }
         }
         else
         {
            cin.clear();
            cin.ignore(1000, '\n');
         }
      } while (!ok);
   }

   void Rectangle::draw(std::ostream& ostr) const
   {
      ostr << "+"; //use ostr.fill
      for (int i = 0; i < m_width - 2; i++)
      {
         ostr << "-";
      }
      ostr << "+" << endl;

      ostr << "|"
         << setw(m_width - 2) << left << label() << right
         << "|" << endl;

      for (int i = 0; i < m_height - 3; i++)
      {
         ostr << "|" << setw(m_width - 2) << "|" << endl;
      }

      ostr << "+"; //use ostr.fill
      for (int i = 0; i < m_width - 2; i++)
      {
         ostr << "-";
      }
      ostr << "+" << endl;

   }


}