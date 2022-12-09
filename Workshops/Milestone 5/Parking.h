#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_
#include <iostream>
#include "Menu.h"
#include "Vehicle.h"

namespace sdds
{
   const int MAX_PARKING = 100;

   class Parking
   {
      char* m_filename;
      Menu m_mainMenu{ "Parking Menu, select an action:", 0 };
      Menu m_vehicleMenu{ "Select type of the vehicle:", 1 };
      int m_noOfSpots;
      Vehicle* m_parkingSpot[MAX_PARKING]; //act like parking spots (array of pointers)
      int m_parked;
      //Parking& setEmpty();


      bool isEmpty()const;
      void parkingStatus()const;
      void parkVehicle()const; //may not be const in future milestones
      void returnVehicle()const; //may not be const in future milestones
      void listVehicle()const;
      void findVehicle()const;
      bool closeParking()const;
      bool exitParking()const;
      bool loadFile()const;
      void saveFile()const; //may not be const in future milestones
      Parking(const Parking& parking) = delete;
      Parking& operator=(const Parking& parking) = delete;
      Parking& setEmpty();
      operator bool()const;

   public:
      virtual ~Parking();
      Parking(const char* filename);
      int run();
      Parking(const char* datafile, int noOfSpots);


   };

   std::ostream& printPrompt(const char* message, std::ostream& ostr = std::cout);
   std::ostream& printMessage(const char* message, int space = 0, const char* cstring = "", std::ostream& ostr = std::cout);
}

#endif

//#ifndef SDDS_PARKING_H_
//#define SDDS_PARKING_H_
//
//#include "Vehicle.h"
//
//namespace sdds
//{
//   const int MAX_PARKING = 100;
//
//   class Parking
//   {
//      int m_noOfSpots;
//      Vehicle* parkingSpot[MAX_PARKING]; //act like parking spots (array of pointers)
//      int m_parked;
//      Parking& setEmpty();
//   public:
//      Parking(const char* datafile, int noOfSpots);
//   };
//}
//
//#endif