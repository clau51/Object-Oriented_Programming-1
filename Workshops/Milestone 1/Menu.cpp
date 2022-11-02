#include <iostream>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{

   class Menu;

   MenuItem::MenuItem()
   {
      ;
   }

   MenuItem::MenuItem(const char* cstr)
   {
      if (cstr)
      {
         sdds::strcpy(m_cString, cstr, 50);
      }
      else
      {
         m_cString[0] = '\0';
      }
   }

   ostream& MenuItem::display(ostream& ostr) const
   {
      if (m_cString)
      {
         ostr << m_cString << endl;
      }

      return ostr;
   }

   MenuItem::operator bool()
   {
      return m_cString[0] != '\0';
   }

   Menu::Menu(const char* str, int indent)
   {
      if (str[0] && strlen(str) >=1 && strlen(str) <= MAX_CHARS)
      {
         strcpy(m_title, str, 50);
         m_indent = indent;
         m_noOfItems = 0;
      }
   }


}

int main()
{
   return 0;
}