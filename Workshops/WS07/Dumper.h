//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 11, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

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
      //Four argument constructor derived from VehicleBasic
      Dumper(const char* licensePlate, int year, double maxCapacity, const char* address);
      
      //Empty destructor
      virtual ~Dumper() = default;

      //Load cargo
      bool loaddCargo(double cargo);

      //Unload cargo
      bool unloadCargo();

      //Display built year, license plate, current location, capacity, cargo
      std::ostream& write(std::ostream& os = std::cout) const override;
      
      //Read built year, license plate, current location, capacity, cargo
      std::istream& read(std::istream& in = std::cin) override;
   };

   //These helpers are not needed as we have made our Base class read() & write() functions virtual
   //std::ostream& operator<<(std::ostream& ostr, const Dumper& dumper);
   //std::istream& operator>>(std::istream& istr, Dumper& dumper);


}
#endif

