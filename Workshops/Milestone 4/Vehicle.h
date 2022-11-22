//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 17, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include "ReadWritable.h"

namespace sdds
{
   class Vehicle : public ReadWritable
   {
      char m_licensePlate[8 + 1]{}; //1 to 8 chars
      char* m_makeModel{}; //More than 2 chars (cannot be null or empty)
      int m_parkingSpot{}; //Can be 0+ (0 means not parked)

      //Allocate and copy m_makeModel
      Vehicle& alAndCp(const char* str);

      //Read parking spot
      bool readParkingSpot(std::istream& istr, char delimiter);

      //Read license plate
      bool readLicensePlate(std::istream& istr, char delimiter);

      //Read make and model
      bool readMakeModel(std::istream& istr, char delimiter);

   protected:
      //Set to empty state
      Vehicle& setEmpty();

      //Check if object is empty
      bool isEmpty()const;

      //Get license plate
      const char* getLicensePlate()const;

      //Get make and model
      const char* getMakeModel()const;

      //Set make and model
      Vehicle& setMakeModel(const char* makeModel);

   public:
      //Vehicle();

      //Constructor: receives licensePlate and makeModel parameters set to default
      Vehicle(const char* licensePlate = nullptr, const char* makeModel = nullptr);

      //Copy assignment
      Vehicle& operator=(const Vehicle& vehicle);

      //Check if this object is empty or not
      operator bool()const;

      //Copy constructor
      Vehicle(const Vehicle& vehicle);

      //Destructor
      virtual ~Vehicle();

      //Deallocate memory for m_makeModel
      Vehicle& deallocate();

      //Get parking spot
      int getParkingSpot()const;

      //Set parking spot
      Vehicle& setParkingSpot(int parkingSpot);

      //Set license plate
      Vehicle& setLicensePlate(const char* licensePlate);

      //Check if left operand is equal to right operand (receiving string)
      bool operator==(const char* licensePlate)const;

      //Check if left operand is equal to right operand (reciving Vehicle object reference)
      bool operator==(const Vehicle& vehicle)const;

      //Read from istr: get input based on if its in comma seperated value
      std::istream& read(std::istream& istr = std::cin) override;

      //Write to ostr: display parking spot, license plate, make and model
      std::ostream& write(std::ostream& ostr = std::cout) const override;

      //Pure virtual function - makes Vehicle an abstract base class
      virtual std::ostream& writeType(std::ostream& ostr = std::cout)const = 0;
   };
}

#endif