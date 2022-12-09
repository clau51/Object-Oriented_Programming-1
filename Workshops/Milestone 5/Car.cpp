#include <iostream>
#include "Car.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   Car::Car(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel)
   {
   }

   Car::Car(const Car& car) /*: Vehicle(car)*/
   {
      //m_carWash = car.m_carWash;
      operator=(car);
   }

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
   std::istream& Car::read(std::istream& istr)
   {
      char userInput;
      if (isCsv())
      {
         Vehicle::read(istr);
         readBoolValidation(m_carWash, '\n', "Invalid entry, please try again: ", istr);
      }
      else
      {
         cout << endl;
         cout << "Car information entry" << endl;
         Vehicle::read(istr);
         cout << "Carwash while parked? (Y)es/(N)o: ";
         userInput = getYesNo("YyNn");
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