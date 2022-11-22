#include "Motorcycle.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
   Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel)
   {
   }

   Motorcycle::Motorcycle(const Motorcycle& motorcycle)
   {
      operator=(motorcycle);
   }

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
   std::istream& Motorcycle::read(std::istream& istr)
   {
      int hasSideCar;
      bool ok;
      if (isCsv())
      {
         Vehicle::read(istr);
         do
         {
            ok = false;
            hasSideCar = readInt(istr, '\n');
            if (hasSideCar != -1) //if input successful
            {
               if (hasSideCar == 1 || hasSideCar == 0)
               {
                  m_hasSideCar = hasSideCar;
                  ok = true;
               }
               else
               {
                  cout << "Invalid entry, please try again: ";
               }
            }
         } while (!ok);
      }
      else
      {
         char userInput;
         cout << endl;
         cout << "Motorcycle information entry" << endl;
         Vehicle::read(istr);
         cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
         userInput = getYesNo("YyNn");
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