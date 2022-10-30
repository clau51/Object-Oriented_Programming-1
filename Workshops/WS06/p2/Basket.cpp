//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 29, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Basket.h"

using namespace std;
namespace sdds
{
   //Default constructor: set object of type Fruit to safe empty state
   Fruit::Fruit()
   {
      m_name[0] = '\0'; 
      m_qty = 0;
   }

   //Sets name and quantity of fruit

   Fruit& Fruit::set(const char* name, double qty)
   {
      strcpy(m_name, name);
      m_qty = qty;

      return *this;
   }

   //Two argument constructor: set object to values in parameters
   Fruit::Fruit(const char* name, double qty) //Fruit("apple", 2.4);
   {
      if (name && name[0] && qty > 0)
      {
         if (strlen(name) >= 0 && strlen(name) <= 30)
         {
            set(name, qty);
         }
      }
   }


   //Copy assignment operator: copy object of type Fruit from right side into left side
   Fruit& Fruit::operator=(const Fruit& fruit2)
   {
      if (fruit2) //No need to check if this != & fruit2 because there is no dynamic memory in struct Fruit
      {
         set(fruit2.m_name, fruit2.m_qty);
      }

      return *this;
   }

   //Operator bool: return true if object passes validation
   Fruit::operator bool() const
   {
      return (m_qty > 0) && (m_name[0] != '\0');
   }

   //Get name of fruit
   const char* Fruit::getName() const
   {
      return m_name;
   }

   //Get weight of fruit
   double Fruit::getQty() const
   {
      return m_qty;
   }

   //Default constructor: set object of type Basket to safe empty state
   Basket::Basket()
   {
      setEmpty(); 
   }

   //Three argument constructor: set object to values in parameters
   Basket::Basket(Fruit* fruit, int size, double price) //ok
   {
      setEmpty();
      if (fruit && size > 0 && price > 0)
      {
         m_fruits = new Fruit[size];
         for (int i = 0; i < size; i++)
         {
            m_fruits[i] = fruit[i];
         }
         m_numFruits = size;
         m_price = price;
      }
   }

   //Copy constructor: copy object of type Basket from right side into left side
   Basket::Basket(const Basket& basket2)
   {
      setEmpty();
      *this = basket2;
   }


   //Deallocate memory and set to safe empty state
   Basket& Basket::deallocate()
   {
      delete[] m_fruits;
      m_fruits = nullptr;

      return *this;
   }

   //Set object of type Basket to safe empty state
   Basket& Basket::setEmpty()
   {
      m_fruits = nullptr;
      m_numFruits = 0;
      m_price = 0;

      return *this;
   }

   //Copy assignment operator: copy object of type Basket from right side into left side
   Basket& sdds::Basket::operator=(const Basket& basket2)
   {
      if (this != &basket2)
      {
         deallocate();

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

   //Deallocate memory for object of type Basket
   Basket::~Basket()
   {
      delete[] m_fruits;
   }

   //Set price of basket
   void Basket::setPrice(double price)
   {
      if (price > 0)
      {
         m_price = price;
      }
   }

   //Check if object of type Basket is not empty
   Basket::operator bool() const
   {
      return m_fruits != nullptr;
   }

   //Add a fruit to basket
   Basket& Basket::operator+=(Fruit fruit)
   {
      if (fruit)
      {
         Fruit* temp = new Fruit[m_numFruits + 1];
         for (int i = 0; i < m_numFruits; i++)
         {
            temp[i] = m_fruits[i];
         }
         temp[m_numFruits] = fruit;
         m_numFruits++;

         deallocate();

         m_fruits = temp;
      }

      return *this;
   }

   //Display basket
   ostream& operator<<(ostream& ostr, const Basket& basket)
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


