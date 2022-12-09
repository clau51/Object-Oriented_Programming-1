//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 22, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Car.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   //Two argument constructor: receives license plate and make and model
   Car::Car(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel)
   {
   }

   //Copy constructor
   Car::Car(const Car& car) /*: Vehicle(car)*/
   {
      //m_carWash = car.m_carWash;
      operator=(car);
   }

   //Copy assignment operator
   Car& Car::operator=(const Car& car)
   {
      if (this != &car)
      {
         if (car)
         {
            Vehicle::operator=(car);
            m_carWash = car.m_carWash;
         }
      }

      return *this;
   }

   //Destructor
   std::ostream& Car::writeType(std::ostream& ostr) const
   {
      if (isCsv())
      {
         ostr << "C,";
      }
      else
      {
         ostr << "Vehicle type: Car" << endl;
      }

      return ostr;
   }

   //Overrided read function
   std::istream& Car::read(std::istream& istr)
   {
      char userInput;
      if (isCsv())
      {
         Vehicle::read(istr);
         userInput = readInt('\n', istr);
         if (istr)
         {
            if (userInput >= 0 && userInput <= 1)
            {
               m_carWash = userInput;
            }
            else
            {
               deallocate();
               setEmpty();
            }
         }
         else
         {
            istr.clear();
            istr.ignore(1000, '\n');
            deallocate();
            setEmpty();
         }

      }
      else
      {
         cout << endl;
         cout << "Car information entry" << endl;
         Vehicle::read(istr);
         cout << "Carwash while parked? (Y)es/(N)o: ";
         userInput = getChar("YyNn", "Invalid response, only (Y)es or (N)o are acceptable, retry: ", istr);
         if (userInput == 'Y' || userInput == 'y')
         {
            m_carWash = true;
         }
         else
         {
            m_carWash = false;
         }
      }

      return istr;
   }

   //Overrided write function
   std::ostream& Car::write(std::ostream& ostr) const
   {
      if (*this)
      {
         Vehicle::write(ostr);
         if (isCsv())
         {
            ostr << m_carWash << endl;
         }
         else
         {
            if (m_carWash)
            {
               ostr << "With Carwash" << endl;
            }
            else
            {
               ostr << "Without Carwash" << endl;
            }
         }
      }
      else
      {
         ostr << "Invalid Car Object" << endl;
      }

      return ostr;
   }
}