//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 8, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   //MenuItem One Argument Constructor - sets MenuItem object (receives string)
   MenuItem::MenuItem(const char* cstr)
   {
      if (cstr && cstr[0])
      {
         sdds::strcpy(m_cString, cstr, MAX_CHARS);
      }
      else
      {
         setEmpty();
      }
   }

   //Set MenuItem to safe empty state
   MenuItem& MenuItem::setEmpty()
   {
      m_cString[0] = '\0';

      return *this;
   }

   //Display MenuItem object if not empty
   ostream& MenuItem::display(ostream& ostr) const
   {
      if (*this)
      {
         ostr << m_cString << endl;
      }

      return ostr;
   }

   //Check if MenuItem object is not an empty string
   MenuItem::operator bool()const
   {
      return m_cString[0] != '\0';
   }

   //Assign MenuItem object to a string
   MenuItem& MenuItem::operator=(const char* str)
   {
      if (str && str[0])
      {
         sdds::strcpy(m_cString, str, MAX_CHARS);
      }
      else
      {
         m_cString[0] = '\0';
      }

      return *this;
   }

   //*************************************************************************//
   //*
   //* MENU FUNCTIONS
   //*
   //***********************************************************************//
   
   //Two Argument Constructor - sets Menu object (receives title and identation)
   Menu::Menu(const char* str, int indent)
   {
      if (str && str[0])
      {
         sdds::strcpy(m_title, str, MAX_CHARS);
         m_noOfItems = 0;
         if (indent > 0)
         {
            m_indent = indent;
         }
         else
         {
            m_indent = 0;
         }
      }
      else
      {
         setEmpty();
      }
   }

   //Set Menu object to a safe empty state
   Menu& Menu::setEmpty()
   {
      for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
      {
         m_menuItems[i].m_cString[0] = '\0';
      }
      m_title[0] = '\0';
      m_noOfItems = 0;
      m_indent = 0;

      return *this;
   }


   //Check if Menu object has a title
   Menu::operator bool() const
   {
      return !isEmpty();
   }

   //Check if Menu object is empty
   bool Menu::isEmpty()const
   {
      return m_title[0] == '\0';
   }

   //Display Menu object if title is valid
   ostream& Menu::display(ostream& ostr)const
   {
      if (*this) //if title is valid
      {
         indent() << m_title << endl;
         for (int i = 0; i < m_noOfItems; i++)
         {
            indent() << i + 1 << "- " << m_menuItems[i].m_cString << endl;
         }

         if (m_noOfItems) //m_menuItems[0]
         {
            indent() << "> ";
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

   //Set Menu object to a string (title)
   Menu& Menu::operator=(const char* str)
   {
      if (str && str[0])
      {
         sdds::strcpy(m_title, str, MAX_CHARS);
      }
      else //Set to invalid state
      {
         setEmpty();
      }

      return *this;
   }

   //Add a string into the next available index in an array of MenuItems in Menu object
   void Menu::add(const char* str)
   {
      if (*this)
      {
         if (str && str[0])
         {
            if (m_noOfItems < MAX_NO_OF_ITEMS)
            {
               //strcpy(m_menuItems[m_noOfItems].m_cString, str, 50);
               m_menuItems[m_noOfItems] = str;
               m_noOfItems++;
            }
         }
         else
         {
            setEmpty();
         }
      }
   }

   //Insert a string into the Menu as a MenuItem
   Menu& Menu::operator<<(const char* str)
   {
      add(str);

      return *this;
   }

   //Gets user input and return the inputted number
   int Menu::run()const
   {
      int selection = 0;

      display();
      if (*this) //if title valid
      {
         if (m_noOfItems) // or if (m_menuItems[0]) //if list not empty
         {
            selection = getIntRange(1, m_noOfItems);
         }
         else
         {
            selection = 0;
         }
      }

      return selection;
   }

   //Clear the Menu object
   void Menu::clear()
   {
      setEmpty();
   }

   //Int cast operator: return value of run() function
   Menu::operator int() const
   {
      return run();
   }

   //Print indentation
   ostream& Menu::indent(ostream& ostr) const
   {
      for (int i = 0; i < m_indent * 4; i++)
      {
         ostr << ' ';
      }
      return ostr;
   }
}