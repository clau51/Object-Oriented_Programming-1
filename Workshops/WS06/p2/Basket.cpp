#define _CRT_SECURE_NO_WARNINGS
#include "Basket.h"
#include <iostream>

using namespace std;
namespace sdds
{
   bool Fruit::isValid()const
   {
      return (m_name != nullptr) && (m_qty > 0) && (m_name[0] != '\0');
   }

   Fruit::Fruit()
   {
      m_name[0] = '\0';
      m_qty = 0;
   }

   Fruit::Fruit(const char* name, double qty) //Fruit("apple", 2.4);
   {
      //if (name && qty > 0)
      if (isValid())
      {
         strcpy(m_name, name);
         m_qty = qty;
      }
   }

   Fruit& Fruit::operator=(const Fruit& fruit2) //Fruit = Fruit
   {
      if (fruit2.isValid())
      {
         strcpy(m_name, fruit2.m_name);
         m_qty = fruit2.m_qty;
      }

      return *this;
   }

   Basket::Basket()
   {
      setEmpty();
   }

   Basket::Basket(Fruit* obj, int size, double price) //ok
   { //arr of fruits (ie. obj[1], obj[2], ob[3])
      setEmpty();
      if (obj && size > 0 && price > 0)
      {
         m_fruits = new Fruit[size]; //m_fruits[10];
         for (int i = 0; i < size; i++)
         {
            //Fruit = Fruit;
            m_fruits[i] = obj[i];
         }
         m_numFruits = size;
         m_price = price;
      }
   }

   //Basket C;
   //Basket L("apple", 2.3);
   //Basket C = L;
   Basket::Basket(const Basket& basket2)
   {
      setEmpty();
      *this = basket2;
   }

   //Basket X("apple", 2.2);
   //Basket C("orange", 4.4);
   //X = C;
   Basket& sdds::Basket::operator=(const Basket& basket2)
   {
      if (this != &basket2)
      {
         delete[] m_fruits;
         m_fruits = nullptr;

         if (basket2)
         {
            m_fruits = new Fruit[basket2.m_numFruits];
            for (int i = 0; i < basket2.m_numFruits; i++)
            {
               m_fruits[i] = basket2.m_fruits[i];
            }
            m_numFruits = basket2.m_numFruits;
            m_price = basket2.m_price;
         }
      }

      return *this;
   }

   Basket& Basket::setEmpty()
   {
      m_fruits = nullptr;
      m_numFruits = 0;
      m_price = 0;

      return *this;
   }


   Basket::~Basket()
   {
      delete[] m_fruits;
   }

   void Basket::setPrice(double price)
   {
      if (price > 0)
      {
         m_price = price;
      }
   }

   Basket::operator bool() const
   {
      return m_fruits != nullptr;
   }

   //Basket aBasket;
   //aBasket += fruits[2];
   //(aBasket += fruits[0]) += fruits[4];
   //aBasket.setPrice(12.234);
   Basket& Basket::operator+=(Fruit fruit)
   {
      Fruit* temp = new Fruit[m_numFruits + 1];
      for (int i = 0; i < m_numFruits; i++)
      {
         temp[i] = m_fruits[i];
      }
      temp[m_numFruits] = fruit; //Fruit = Fruit

      delete[] m_fruits;
      m_fruits = nullptr;

      m_fruits = temp; //Fruit = Fruit
      m_numFruits++;

      return *this;
   }

   //*****DELETE*****
   ostream& operator<<(ostream& ostr, Fruit& fruit) 
   {
      //*****DELETE*****
      if (fruit.isValid())
      {
         ostr << fruit.getName() << endl;
      }
      else
      {
         ostr << "Invalid" << endl;
      }
         return ostr;
      
   }

   ostream& operator<<(ostream& ostr, Basket& basket)
   {
      if (basket)
      {
         ostr << "Basket Content:" << endl;
         for (int i = 0; i < basket.m_numFruits; i++)
         {
            ostr.setf(ios::right);
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr.width(10);
            ostr << basket.m_fruits[i].getName() << ": " << basket.m_fruits[i].getQty() << "kg" << endl;
         }
         ostr << "Price: " << basket.m_price << endl;
         ostr.unsetf(ios::right);
         ostr.unsetf(ios::fixed);
         ostr.precision(6);
      }
      else
      {
         cout << "The basket is empty!" << endl;
      }
      return ostr;
   }
}


