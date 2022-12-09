//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 22, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

#include "Vehicle.h"

namespace sdds
{
   class Car : public Vehicle
   {
      bool m_carWash{};

   public:
      //Default constructor
      Car() = default;

      //Two argument constructor: receives license plate and make and model
      Car(const char* licensePlate, const char* makeModel);

      //Copy constructor
      Car(const Car& car);

      //Copy assignment operator
      Car& operator=(const Car& car);

      //Destructor
      virtual ~Car() = default;

      //Writes the type of vehicle (ie. if C, represents Car)
      std::ostream& writeType(std::ostream& ostr = std::cout)const override;

      //Overrided read function
      std::istream& read(std::istream& istr = std::cin) override;

      //Overrided write function
      std::ostream& write(std::ostream& ostr = std::cout) const override;
   };
}

#endif