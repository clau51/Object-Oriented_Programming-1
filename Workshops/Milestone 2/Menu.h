//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 8, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
#include "Utils.h"

namespace sdds
{
   const int MAX_NO_OF_ITEMS = 10;
   const int MAX_CHARS = 50;
   class Menu;

   class MenuItem
   {
      char m_cString[MAX_CHARS + 1];

      //MenuItem One Argument Constructor - sets MenuItem object (receives string)
      MenuItem(const char* cstr = nullptr);

      //Empty Destructor
      virtual ~MenuItem() = default;

      //Set MenuItem to safe empty state
      MenuItem& setEmpty();

      //Display MenuItem object if not empty
      std::ostream& display(std::ostream& ostr = std::cout)const;

      //Check if MenuItem object is not an empty string
      operator bool()const;

      //Prevent MenuItem object from getting assigned to another MenuItem object
      MenuItem& operator=(const MenuItem& menuItem) = delete;

      //Prevent MenuItem object from being copied to another MenuItem object
      MenuItem(const MenuItem& menuItem) = delete;

      //Assign MenuItem object to a string
      MenuItem& operator=(const char* str);

      //Allow Menu to have access to MenuItem
      friend class Menu;
   };

   class Menu
   {
      char m_title[MAX_CHARS + 1];
      MenuItem m_menuItems[MAX_NO_OF_ITEMS];
      int m_noOfItems;
      int m_indent;

   public:
      //Two Argument Constructor - sets Menu object (receives title and identation)
      Menu(const char* str = nullptr, int indent = 0);

      //Empty destructor
      virtual ~Menu() = default;

      //Set Menu object to a safe empty state
      Menu& setEmpty();

      //Prevent Menu object from being assigned to another Menu object
      Menu& operator=(const Menu& menu) = delete;

      //Prevent Menu object from being copied from another Menu object
      Menu(const Menu& menu) = delete;

      //Check if Menu object has a title
      operator bool() const;

      //Check if Menu object is empty
      bool isEmpty() const;

      //Display Menu object if title is valid
      std::ostream& display(std::ostream& ostr = std::cout) const;

      //Set Menu object to a string (title)
      Menu& operator=(const char* str);

      //Add a string into the next available index in an array of MenuItems in Menu object
      void add(const char* str);

      //Insert a string into the Menu as a MenuItem
      Menu& operator<<(const char* str);

      //Gets user input and return the inputted number
      int run()const;

      //Clear the Menu object
      void clear();

      //Int cast operator: return value of run() function
      operator int() const;

      //Print indentation
      std::ostream& indent(std::ostream& ostr = std::cout)const;


   };

}

#endif
