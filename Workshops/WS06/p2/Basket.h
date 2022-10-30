//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 29, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>

namespace sdds
{
   struct Fruit
   {
   private:
      char m_name[30 + 1]{};
      double m_qty{};
   public:
      //Default constructor: set object of type Fruit to safe empty state
      Fruit();

      //Sets name and quantity of fruit
      Fruit& set(const char* name, double qty);
      
      //Two argument constructor: set object to values in parameters
      Fruit(const char* name, double qty);

      //Copy assignment operator: copy object of type Fruit from right side into left side
      Fruit& operator=(const Fruit& fruit2);

      //Operator bool: return true if object passes validation
      operator bool() const;

      //Get name of fruit
      const char* getName()const;

      //Get weight of fruit
      double getQty()const;
   };

   class Basket
   { 
      Fruit* m_fruits{};
      int m_numFruits{};
      double m_price{};
   public:

      //Default constructor: set object of type Basket to safe empty state
      Basket();

      //Three argument constructor: set object to values in parameters
      Basket(Fruit* fruit, int size, double price);

      //Copy constructor: copy object of type Basket from right side into left side
      Basket(const Basket& basket2);

      //Deallocate memory and set to safe empty state
      Basket& deallocate();

      //Set object of type Basket to safe empty state
      Basket& setEmpty();

      //Copy assignment operator: copy object of type Basket from right side into left side
      Basket& operator=(const Basket& basket2);
      
      //Deallocate memory for object of type Basket
      ~Basket();

      //Set price of basket
      void setPrice(double price);

      //Check if object of type Basket is not empty
      operator bool()const;

      //Add a fruit to basket
      Basket& operator+=(Fruit fruit);
      
      //Display basket
      friend std::ostream& operator<<(std::ostream&, const Basket& basket);
   };

}

#endif
