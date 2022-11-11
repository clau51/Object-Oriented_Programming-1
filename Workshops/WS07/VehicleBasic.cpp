//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 11, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
   const int MIN_VEHICLE_YEAR = 1886;
   const int MAX_VEHICLE_YEAR = 2023;
   
   //Three argument constructor: Sets object (assume all data valid)
   VehicleBasic::VehicleBasic(const char* licensePlate, int year, const char* address)
   {
      sdds::strcpy(m_licensePlate, licensePlate, 9);
      sdds::strcpy(m_address, address, 64);
      m_year = year;
   }

   //Moves vehicle to new address and prints to screen
   void VehicleBasic::NewAddress(const char* address)
   {
      if (strcmp(m_address, address))
      {
         cout << "|" << setw(8) << m_licensePlate 
            << "| |" << setw(20) << m_address 
            << " ---> " << setw(20) << left << address << right 
            << "|" << endl;


         sdds::strcpy(m_address, address, 64);
      }
   }

   //Display year, plate, address of the vehicle
   ostream& VehicleBasic::write(ostream& os)const
   {
      os << "| " << m_year << " | " << m_licensePlate << " | " << m_address;

      return os;
   }

   //Read year, plate, address of the vehicle
   istream& VehicleBasic::read(istream& in)
   {
      cout << "Built year: ";
      m_year = getIntRange(MIN_VEHICLE_YEAR, MAX_VEHICLE_YEAR, in);
      cout << "License plate: ";
      in.getline(m_licensePlate, 10, '\n');
      if (!in)
      {
         in.clear();
         in.ignore(1000, '\n');
      }
      cout << "Current location: ";
      in.getline(m_address, 65, '\n');
      if (!in)
      {
         in.clear();
         in.ignore(1000, '\n');
      }

      return in;
   }

   //Helper operator overload function: display year, plate, address of the vehicle
   std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& vehicle)
   {
      return vehicle.write(ostr);
   }

   //Helper operator overload function: read year, plate, address of the vehicle
   std::istream& operator>>(std::istream& istr, VehicleBasic& vehicle)
   {
      return vehicle.read(istr);
   }
}

//VehicleBasic& vehicle = aDumper //ie. Base& rBase = derived Derived& derived = base
//vehicle.read(istr) //vehicle.read calls Dumper::read() because read() is virtual

//Parent can have reference a child
//Child can't have reference a parent
