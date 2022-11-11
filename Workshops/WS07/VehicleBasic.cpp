/*
Name:
Email:
Student ID:
Data:
Section:
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;

namespace sdds
{

   VehicleBasic::VehicleBasic(const char* licensePlate, int year, const char* address)
   {
      strcpy(m_licensePlate, licensePlate);
      strcpy(m_address, address);
      m_year = year;
   }


   void VehicleBasic::NewAddress(const char* address)
   {
      if (strcmp(m_address, address))
      {
         cout << "|";
         cout.width(8);
         cout.setf(ios::right);
         cout << m_licensePlate;
         cout.unsetf(ios::right);
         cout << "| ";
         cout << "|";
         cout.width(20);
         cout.setf(ios::right);
         cout << m_address;
         cout.unsetf(ios::right);
         cout << " ---> ";
         cout.width(20);
         cout.setf(ios::left);
         cout << address;
         cout.unsetf(ios::left);
         cout << "|" << endl;

         strcpy(m_address, address);
      }
   }

   VehicleBasic& VehicleBasic::set(const char* address)
   {
      if (address && address[0])
      {
         strcpy(m_address, address);
      }
      else
      {
         m_address[0] = '\0';
      }

      return *this;
   }

   ostream& VehicleBasic::write(ostream& os)const
   {
      os << "| " << m_year << " | " << m_licensePlate << " | " << m_address;

      return os;
   }

   istream& VehicleBasic::read(istream& in)
   {
      char newline;
      bool ok;

      do
      {
         ok = true;
         cout << "Built year: ";
         in >> m_year;
         newline = in.get();
         if (in && newline == '\n')
         {
            cout << "License plate: ";
            in >> m_licensePlate;
            cout << "Current location: ";
            in >> m_address;
         }
         else
         {
            cout << "Invalid year..." << endl;
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n');
         }
      } while (!ok);

      return in;
   }

   std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& vehicle)
   {
      return vehicle.write(ostr);
   }

   std::istream& operator>>(std::istream& istr, VehicleBasic& vehicle)
   {
      return vehicle.read(istr);
   }

}

//VehicleBasic& vehicle = aDumper //Base& rBase = derived Derived& derived = base
//vehicle.read(istr) //vehicle.read calls Dumper::read() because read is virtual

//Parent can reference a child
//Child can't reference a parent

//int& a = b
//a = 10;
//b will also become 10

//Base& rBase = derived;
//rBase = getNum();
//derived will also become getNum
