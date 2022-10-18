//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 15, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   //Constructor - check if valid and set values
   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }

   //Display apartment information
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }

   //Check if apartment number is valid
   bool Apartment::isValid(int number)const
   {
       return number >= 1000 && number <= 9999;
   }

   //Check if apartment balance is valid
   bool Apartment::isValid(double balance)const
   {
       return balance >= 0.0;
   }

   //Check if apartment object is valid
   Apartment::operator bool() const
   {
       return isValid(m_number);
   } 
   
   //Cast apartment object to int
   Apartment::operator int()const
   {
       return m_number;
   }

   //Cast apartment object to double
   Apartment::operator double()const
   {
       return m_balance;
   } 

   //Check if apartment balance is zero
   bool Apartment::operator~()const
   {
       return m_balance < 0.00001;
   } 
   
   //Set apartment in invalid state
   Apartment& Apartment::setInvalid()
   {
       m_number = -1;
       m_balance = 0.0;

       return *this;
   }

   //Set apartment number to an integer value
   Apartment& Apartment::operator=(int number)
   {
       if (*this)
       {
           if (isValid(number))
           {
               m_number = number;
           }

           else
           {
               setInvalid();
           }
       }

       return *this;
   }

   //Swap apartment number with another apartment
   Apartment& Apartment::operator=(Apartment& apt)
   {
        int tempNum = m_number;
        double tempBalance = m_balance;

        m_number = int(apt);
        m_balance = double(apt);

        apt.m_number = tempNum;
        apt.m_balance = tempBalance;
        
        return *this;
   }

   //Add a balance to the current apartment balance
   Apartment& Apartment::operator+=(double balance)
   {
       if (*this && isValid(balance))
       {
           m_balance += balance;
       }
       return *this;
   }

   //Subtract a balance from the current apartment balance
   Apartment& Apartment::operator-=(double balance)
   {
       if (*this && (isValid(balance)) && (m_balance >= balance))
       {
           m_balance -= balance;
       }

       return *this;
   }

   //Add balance from the right apartment to the left apartment
   Apartment& Apartment::operator<<(Apartment& apt)
   {
       if (*this)
       {
           if (m_number != int(apt))
           {
               m_balance += double(apt);
               apt.m_balance = 0.0;
           }
       }
       return *this;

   }

   //Add balance from the left apartment to the right apartment
   Apartment& Apartment::operator>>(Apartment& apt)
   {
       if (*this)
       {

           if (m_number != int(apt))
           {
               apt.m_balance += m_balance;
               m_balance = 0.0;
           }
       }

       return *this;
   }

   //Add two apartment balances together
   double operator+(const Apartment& apt, const Apartment& apt2)
   {
       return apt && apt2 ? double(apt) + double(apt2) : 0.0;
   }

   //Add apartment balance to a double value
   double& operator+=(double& doubleNum, const Apartment& apt)
   {
       if (apt)
       {
           doubleNum += double(apt);
       }   
       return doubleNum;
   }
}