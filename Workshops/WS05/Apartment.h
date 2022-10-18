//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 15, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      //Constructor - check if valid and set values
      Apartment(int number, double balance);

      //Display apartment information
      std::ostream& display()const;

      //Check if apartment number is valid
      bool isValid(int number)const;

      //Check if apartment balance is valid
      bool isValid(double balance)const;

      //Check if apartment object is valid
      operator bool() const;

      //Cast apartment object to int
      operator int()const;

      //Cast apartment object to double
      operator double()const;

      //Check if apartment balance is zero
      bool operator~()const;

      //Set apartment in invalid state
      Apartment& setInvalid();

      //Set apartment number to an integer value
      Apartment& operator=(int number);

      //Swap apartment number with another apartment
      Apartment& operator=(Apartment& apt);

      //Add a balance to the current apartment balance
      Apartment& operator+=(double balance);

      //Subtract a balance from the current apartment balance
      Apartment& operator-=(double balance);

      //Add balance from the right apartment to the left apartment
      Apartment& operator>>(Apartment& apt);

      //Add balance from the left apartment to the right apartment
      Apartment& operator<<(Apartment& apt);  
   };

   //Add two apartment balances together
   double operator+(const Apartment& apt, const Apartment& apt2);

   //Add apartment balance to a double value
   double& operator+=(double& doubleNum, const Apartment& apt);
}

#endif // SDDS_APARTMENT_H_