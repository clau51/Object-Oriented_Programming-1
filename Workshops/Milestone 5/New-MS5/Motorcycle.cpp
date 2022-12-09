//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 22, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Motorcycle.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
   //Two argument constructor: receives license plate and make and model
   Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel)
   {
   }

   //Copy constructor
   Motorcycle::Motorcycle(const Motorcycle& motorcycle) /*: Motorcycle(motorcycle)*/
   {
      //m_hasSideCar = motorcycle.m_hasSideCar;
      operator=(motorcycle);
   }

   //Copy assignment operator
   Motorcycle& Motorcycle::operator=(const Motorcycle& motorcycle)
   {
      if (this != &motorcycle)
      {
         if (motorcycle)
         {
            Vehicle::operator=(motorcycle);
            m_hasSideCar = motorcycle.m_hasSideCar;
         }
      }
      return *this;
   }

   //Writes the type of vehicle (ie. if C, represents Car)
   std::ostream& Motorcycle::writeType(std::ostream& ostr) const
   {
      if (isCsv())
      {
         ostr << "M,";
      }
      else
      {
         ostr << "Vehicle type: Motorcycle" << endl;
      }

      return ostr;
   }

   //Overrided read function
   std::istream& Motorcycle::read(std::istream& istr)
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
               m_hasSideCar = userInput;
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
         cout << "Motorcycle information entry" << endl;
         Vehicle::read(istr);
         cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
         userInput = getChar("YyNn", "Invalid response, only (Y)es or (N)o are acceptable, retry: ");
         if (userInput == 'Y' || userInput == 'y')
         {
            m_hasSideCar = true;
         }
         else
         {
            m_hasSideCar = false;
         }
      }
      return istr;
   }

   //Overrided write function
   std::ostream& Motorcycle::write(std::ostream& ostr) const
   {
      if (*this)
      {
         Vehicle::write(ostr);
         if (isCsv())
         {
            ostr << m_hasSideCar << endl;
         }
         else
         {
            if (m_hasSideCar)
            {
               ostr << "With Sidecar" << endl;
            }
         }
      }
      else
      {
         ostr << "Invalid Motorcycle Object" << endl;
      }

      return ostr;
   }
}