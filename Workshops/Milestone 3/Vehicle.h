#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include "ReadWritable.h"

namespace sdds
{
   class Vehicle : public ReadWritable
   {
      char m_licensePlate[8 + 1]; //1 to 8 chars ??if enter something more than 8 chars? //Are we going to cut it off at 8 chars, or just set to null?
      char* m_makeModel; //More than 2 chars (cannot be null or empty) ?? empty or more than 2 chars?
      int m_parkingSpot; //Can be 0+ (0 means not parked)
      Vehicle& setEmpty();
      bool isEmpty()const;
   public:
      Vehicle(); //do I need this? 
      Vehicle(const char* licensePlate, const char* makeModel);
      Vehicle& operator=(const Vehicle& vehicle); //Copy assignment
      operator bool()const;
      Vehicle(const Vehicle& vehicle); //Copy constructor
      virtual ~Vehicle(); //Destructor
      const char* getLicensePlate()const;
      const char* getMakeModel()const;
      Vehicle& setMakeModel(const char* makeModel);
      int getParkingSpot()const;
      Vehicle& deallocate();
      Vehicle& setParkingSpot(int parkingSpot);
      bool operator==(const char* licensePlate)const;
      bool operator==(const Vehicle& vehicle)const;

      std::istream& read(std::istream& istr = std::cin) override;
      std::ostream& write(std::ostream& ostr = std::cout) const override;

      virtual std::ostream& writeType(std::ostream& ostr = std::cout)const = 0;
   };
}

#endif