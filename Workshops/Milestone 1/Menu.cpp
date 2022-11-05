#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{

   class Menu;

   MenuItem::MenuItem(const char* cstr) //ok
   {
      if (cstr && cstr[0])
      {
         sdds::strcpy(m_cString, cstr, 50);
      }
      else
      {
         setEmpty(); //Not necessary? Already set to safe empty state in class
      }
   }

   MenuItem& MenuItem::setEmpty() //ok
   {
      m_cString[0] = '\0';

      return *this;
   }


   ostream& MenuItem::display(ostream& ostr) const //ok
   {
      if (*this)
      {
         ostr << m_cString << endl;
      }

      return ostr;
   }

   MenuItem::operator bool()const //ok
   {
      return m_cString[0] != '\0';
   }

   Menu::Menu(const char* str, int indent)
   {
      if (str && str[0])
      {
         sdds::strcpy(m_title, str, 50);
         m_indent = indent;
         m_noOfItems = 0;
      }
      else
      {
         setEmpty(); //Not necessary? Already set to safe empty state in class
      }
   }

   Menu& Menu::setEmpty()
   {
      m_title[0] = '\0';
      m_noOfItems = 0;
      m_indent = 0;
      for (int i = 0; i < m_noOfItems; i++)
      {
         m_menuItems[i].m_cString[0] = '\0'; //Not necessary?
      }

      return *this;
   }


   Menu::operator bool() const
   {
      return !isEmpty();
   }

   bool Menu::isEmpty()const
   {
      return m_title[0] == '\0';
   }

   ostream& Menu::display(ostream& ostr)const
   {
      if (*this) //if title is valid
      {
         ostr.width((m_indent * 4) + strlen(m_title));
         ostr << m_title << endl;
         for (int i = 0; i < m_noOfItems; i++)
         {
            ostr.width((m_indent * 4) + 1);
            ostr << i + 1 << "- " << m_menuItems[i].m_cString << endl;
         }

         if (m_noOfItems)
         {
            ostr.width((m_indent * 4) + 2);
            ostr << "> ";
         }
         else
         {
            ostr << "No Items to display!" << endl;

         }
      }
      else
      {
         ostr << "Invalid Menu!" << endl;
      }

      return ostr;
   }

   Menu& Menu::operator=(const char* str)
   {
      if (str[0])
      {
         sdds::strcpy(m_title, str, 50);
      }
      else //Set to invalid state
      {
         setEmpty();
      }

      return *this;
   }

   void Menu::add(const char* str)
   {
      if (str && str[0])
      {
         if (m_noOfItems < MAX_NO_OF_ITEMS)
         {
            //m_menuitems[m_numOfItems] += str // Create operator(Menu+=(const char* str)
            strcpy(m_menuItems[m_noOfItems].m_cString, str, 50);
            m_noOfItems++;
         }
      }
      else
      {
         setEmpty();
      }
   }

   Menu& Menu::operator<<(const char* str)
   {
      add(str);

      return *this;
   }

   int Menu::run()const
   {
      int selection = 0;
      bool ok;

      display();
      if (*this)
      {
         if (m_menuItems[0].m_cString[0])
         {
            do
            {
               ok = true;
               cin >> selection;
               if (!cin.fail())
               {
                  if (selection < 1 || selection > m_noOfItems)
                  {
                     //cin.ignore(1000, '\n'); //Flush buffer if user enters "12313abc"
                     cout << "Invalid selection, try again: ";
                     cin.ignore();
                     ok = false;
                  }
                  else
                  {
                     cin.ignore();
                  }
               }
               else
               {
                  cout << "Invalid Integer, try again: ";
                  cin.clear();
                  cin.ignore(1000, '\n');
                  ok = false;
               }
            } while (!ok);
         }
         else
         {
            selection = 0;

         }
      }

      return selection;
   }

   void Menu::clear()
   {
      m_title[0] = '\0';
      for (int i = 0; i < m_noOfItems; i++)
      {
         //for (int j = 0; j < strlen(m_menuItems[i].m_cString); j++)
         //{
         //   m_menuItems[i].m_cString[j] = '\0';
         //}
         m_menuItems[i].m_cString[0] = '\0';
      }
      m_noOfItems = 0;
      m_indent = 0;
   }
   Menu::operator int() const
   {
      return run();
   }
}