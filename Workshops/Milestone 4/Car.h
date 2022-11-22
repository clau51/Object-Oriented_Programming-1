#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

#include "Vehicle.h"

namespace sdds
{
   class Car : public Vehicle
   {
      bool m_carWash{};

   public:
      Car() = default;
      Car(const char* licensePlate, const char* makeModel);
      Car(const Car& car);
      Car& operator=(const Car& car);
      ~Car() = default;
      std::ostream& writeType(std::ostream& ostr = std::cout)const override;
      std::istream& read(std::istream& istr = std::cin) override;
      std::ostream& write(std::ostream& ostr = std::cout) const override;
      //operator bool()const
      //{
      //   return m_carWash;
      //}

   };
}

#endif