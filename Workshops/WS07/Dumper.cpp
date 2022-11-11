//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 11, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"
#include "Utils.h"

namespace sdds
{
   //Four argument constructor derived from VehicleBasic
   Dumper::Dumper(const char* licensePlate, int year,
      double maxCapacity, const char* address) :
      VehicleBasic(licensePlate, year)
   {
      if (maxCapacity > 0.0)
      {
         m_maxKg = maxCapacity;
      }
      else
      {
         m_maxKg = 0.0;
      }
      
      m_currentKg = 0.0;
      NewAddress(address);
   }

   //Load cargo
   bool Dumper::loaddCargo(double cargo)
   {
      bool loadable = (m_currentKg + cargo) < m_maxKg;

      if (loadable)
      {
         m_currentKg += cargo;
      }

      return loadable;
   }

   //Unload cargo
   bool Dumper::unloadCargo()
   {
      bool unloadable = m_currentKg != 0.0;

      if (unloadable)
      {
         m_currentKg = 0.0;
      }

      return unloadable;
   }

   //Display built year, license plate, current location, capacity, cargo
   std::ostream& Dumper::write(std::ostream& os)const
   {
      VehicleBasic::write(os) << " | " << m_currentKg << "/" << m_maxKg;

      return os;
   }

   //Read built year, license plate, current location, capacity, cargo
   std::istream& Dumper::read(std::istream& in)
   {
      VehicleBasic::read(in);

      cout << "Capacity: ";
      m_maxKg = getDblNonNeg(in);
      cout << "Cargo: ";
      m_currentKg = getDblNonNeg(in);

      return in;
   }

   //These helpers are not needed as we have made our Base class read() & write() functions virtual
   // 
   //std::ostream& operator<<(std::ostream& ostr, const Dumper& dumper)
   //{
   //   return dumper.write(ostr);
   //}

   //std::istream& operator>>(std::istream& istr, Dumper& dumper)
   //{
   //   return dumper.read(istr);
   //}


}

