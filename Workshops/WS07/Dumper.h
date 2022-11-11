/*
Name:
Email:
Student ID:
Data:
Section:
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
   class Dumper : public VehicleBasic
   {
      double m_maxKg; //max weight of cargo Dumper can carry...
      double m_currentKg; // current cannot exceed max...

   public:
      Dumper(const char* licensePlate, int year, double maxCapacity, const char* address);
      virtual ~Dumper() = default;
      bool loaddCargo(double cargo);
      bool unloadCargo();
      std::ostream& write(std::ostream& os = std::cout) const override;
      std::istream& read(std::istream& in = std::cin) override;
   };

   //std::ostream& operator<<(std::ostream& ostr, Dumper& dumper);
   //std::istream& operator>>(std::istream& istr, Dumper& dumper);


}
#endif

