/*
Name:
Email:
Student ID:
Data:
Section:
*/
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

namespace sdds
{
   Dumper::Dumper(const char* licensePlate, int year, 
           double maxCapacity, const char* address) : 
           VehicleBasic(licensePlate, year)
   {
      m_maxKg = maxCapacity;
      m_currentKg = 0.0;
      VehicleBasic::NewAddress(address);
   }

   bool Dumper::loaddCargo(double cargo)
   {
      //double tempCurrent = m_currentKg;
      //double tempTotal = m_currentKg + cargo;

      //if (tempTotal < m_maxKg)
      //{
      //   m_currentKg += cargo;
      //}

      //return tempCurrent == m_currentKg ? false : true;

      bool loadable = (m_currentKg + cargo) < m_maxKg;

      if (loadable)
      {
         m_currentKg += cargo;
      }

      return loadable;
   }

   bool Dumper::unloadCargo()
   {
      //bool changed = false;

      //if (m_currentKg != 0.0)
      //{
      //   changed = true;
      //   m_currentKg = 0.0;
      //}

      //return changed;

      bool unloadable = m_currentKg != 0.0;

      if (unloadable)
      {
         m_currentKg = 0.0;
      }

      return unloadable;
   }

   std::ostream& Dumper::write(std::ostream& os)const
   {
      VehicleBasic::write(os) << " | " << m_currentKg << "/" << m_maxKg;

      return os;
   }

   std::istream& Dumper::read(std::istream& in)
   {
      VehicleBasic::read(in);
      bool ok;
      char newline;

      do
      {
         ok = false;
         cout << "Capacity: ";
         in >> m_maxKg;
         newline = in.get();
         if (in && newline == '\n')
         {
            do
            {
               ok = true;
               cout << "Cargo: ";
               in >> m_currentKg;
               newline = in.get();
               if (!(in && newline == '\n'))
               {
                  cout << "Invalid cargo..." << endl;
                  ok = false;
                  cin.clear();
                  cin.ignore(1000, '\n');
               }
            } while (!ok);
         }
         else
         {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid capacity..." << endl;
         }
      } while (!ok);
      return in;
   }

   //std::ostream& operator<<(std::ostream& ostr, Dumper& dumper)
   //{
   //   return dumper.write(ostr);
   //}

   //std::istream& operator>>(std::istream& istr, Dumper& dumper)
   //{
   //   return dumper.read(istr);
   //}


}

