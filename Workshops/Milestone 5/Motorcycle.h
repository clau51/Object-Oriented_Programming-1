#ifndef SDDS_MOTORCYCLE_H_
#define SDDS_MOTORCYCLE_H_
#include "Vehicle.h"

namespace sdds
{
   class Motorcycle : public Vehicle
   {
      bool m_hasSideCar{};
   public:
      Motorcycle() = default;
      Motorcycle(const char* licensePlate, const char* makeModel);
      Motorcycle(const Motorcycle& motorcycle);
      Motorcycle& operator=(const Motorcycle& motorcycle);
      ~Motorcycle() = default;
      std::ostream& writeType(std::ostream& ostr = std::cout)const override;
      std::istream& read(std::istream& istr = std::cin) override;
      std::ostream& write(std::ostream& ostr = std::cout) const override;
   };

}

#endif