#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
namespace sdds
{
   class Fruit
   {
      char m_name[30 + 1]{};
      double m_qty{};
   public:
      bool isValid()const;
      Fruit();
      Fruit(const char* name, double qty);
      Fruit& operator=(const Fruit& fruit2);
      const char* getName()const
      {
         return m_name;
      }
      double getQty()const
      {
         return m_qty;
      }
   };
   std::ostream& operator<<(std::ostream& ostr, Fruit& fruit); //*****DELETE*****


   //Fruits[10];
         //Fruit[0].m_name = "Carmen"
         //Fruit[0].m_qty = 2.4
         //Fruit[1].m_name = "Kingsley"
         //Fruit[1].m_qty = 4.4
   class Basket
   { 
      Fruit* m_fruits{};
      int m_numFruits{};
      double m_price{};
   public:
      Basket();
      Basket(Fruit* obj, int size, double price);
      Basket(const Basket& basket2);
      Basket& setEmpty();
      Basket& operator=(const Basket& basket2);
      ~Basket();
      void setPrice(double price);
      operator bool()const;
      Basket& operator+=(Fruit fruit);
      friend std::ostream& operator<<(std::ostream&, Basket& basket);
   };

}

#endif
