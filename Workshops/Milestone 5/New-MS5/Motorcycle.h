//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 22, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOTORCYCLE_H_
#define SDDS_MOTORCYCLE_H_
#include "Vehicle.h"

namespace sdds
{
   class Motorcycle : public Vehicle
   {
      bool m_hasSideCar{};
   public:
      //Default constructor
      Motorcycle() = default;

      //Two argument constructor: receives license plate and make and model
      Motorcycle(const char* licensePlate, const char* makeModel);

      //Copy constructor
      Motorcycle(const Motorcycle& motorcycle);

      //Copy assignment operator
      Motorcycle& operator=(const Motorcycle& motorcycle);

      //Destructor
      virtual ~Motorcycle() = default;

      //Writes the type of vehicle (ie. if C, represents Car)
      std::ostream& writeType(std::ostream& ostr = std::cout)const override;

      //Overrided read function
      std::istream& read(std::istream& istr = std::cin) override;

      //Overrided write function
      std::ostream& write(std::ostream& ostr = std::cout) const override;
   };

}

#endif