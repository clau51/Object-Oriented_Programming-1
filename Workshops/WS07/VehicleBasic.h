//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 11, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
   class VehicleBasic
   {
      char m_licensePlate[9 + 1];
      char m_address[64 + 1];
      int m_year;

   public:
      //Three argument constructor: Sets object (assume all data valid)
      VehicleBasic(const char* licensePlate, int year, const char* address = "Factory");
      
      //Empty destructor
      virtual ~VehicleBasic() = default;

      //Moves vehicle to new address and prints to screen
      void NewAddress(const char* address);

      //Display year, plate, address of the vehicle
      virtual std::ostream& write(std::ostream& os = std::cout) const;
      
      //Read year, plate, address of the vehicle
      virtual std::istream& read(std::istream& in = std::cin);
   };

   //Helper operator overload function: display year, plate, address of the vehicle
   std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& vehicle);

   //Helper operator overload function: read year, plate, address of the vehicle
   std::istream& operator>>(std::istream& istr, VehicleBasic& vehicle);


}

#endif
