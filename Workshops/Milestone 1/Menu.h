#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds
{
   const int MAX_NO_OF_ITEMS = 10;
   const int MAX_CHARS = 50;
   class MenuItem
   {
      char m_cString[MAX_CHARS + 1];
      MenuItem();
      MenuItem(const char* cstr);
      std::ostream& display(std::ostream& ostr)const;
      operator bool();
      MenuItem& operator=(const MenuItem& menuItem) = delete;
      friend class Menu;
   };

   class Menu
   {
      MenuItem menuItem[MAX_NO_OF_ITEMS];
      int m_noOfItems;
      int m_indent;
      char m_title[MAX_CHARS + 1];

      Menu(const char* str, int indent = 0);
      Menu& operator=(const Menu& menu) = delete;

   };
}

#endif
