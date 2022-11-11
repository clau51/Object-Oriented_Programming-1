/*
Name:
Email:
Student ID:
Data:
Section:
*/
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
      VehicleBasic(const char* licensePlate, int year, const char* address = "Factory");
      virtual ~VehicleBasic() = default;
      void NewAddress(const char* address);
      VehicleBasic& set(const char* address);
      virtual std::ostream& write(std::ostream& os = std::cout) const;
      virtual std::istream& read(std::istream& in = std::cin);
   };

   std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& vehicle);
   std::istream& operator>>(std::istream& istr, VehicleBasic& vehicle);


}

#endif
