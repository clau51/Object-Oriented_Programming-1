#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds
{
   const int MAX_NO_OF_ITEMS = 10;
   const int MAX_CHARS = 50;
   class Menu;
   
   class MenuItem
   {
      char m_cString[MAX_CHARS + 1];
      
      MenuItem(const char* cstr = nullptr);
      MenuItem& setEmpty();
      std::ostream& display(std::ostream& ostr = std::cout)const;
      operator bool()const;
      MenuItem& operator=(const MenuItem& menuItem) = delete;
      MenuItem(const MenuItem& menuItem) = delete;
      friend class Menu;
   };
   class Menu
   {
      char m_title[MAX_CHARS + 1];
      MenuItem m_menuItems[MAX_NO_OF_ITEMS];
      int m_noOfItems;
      int m_indent;

   public:
      Menu(const char* str, int indent = 0);
      Menu& setEmpty();
      Menu& operator=(const Menu& menu) = delete;
      Menu(const Menu& menu) = delete;
      operator bool() const;
      bool isEmpty() const;
      std::ostream& display(std::ostream& ostr = std::cout) const;
      Menu& operator=(const char* str);
      void add(const char* str);
      Menu& operator<<(const char* str);
      int run()const;
      void clear();
      operator int() const;
  /*    void display(int indent)
      {
         cout <<  << 
      }*/
      

   };

}

#endif
