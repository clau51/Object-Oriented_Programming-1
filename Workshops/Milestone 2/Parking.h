#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_
#include <iostream>
#include "Menu.h"

namespace sdds
{
   class Parking
   {
      char* m_filename;
      Menu m_mainMenu{"Parking Menu, select an action:", 0};
      Menu m_vehicleMenu{"Select type of the vehicle:", 1};

      bool isEmpty()const;
      void parkingStatus()const;
      void parkVehicle()const;
      void returnVehicle()const;
      void listVehicle()const;
      void findVehicle()const;
      bool closeParking()const;
      bool exitParking()const;
      bool loadFile()const;
      void saveFile()const;
      Parking(const Parking& parking) = delete;
      Parking& operator=(const Parking& parking) = delete;
      Parking& setEmpty();
      operator bool()const;

   public:
      virtual ~Parking();
      Parking(const char* filename);
      int run();

   };

   std::ostream& printPrompt(const char* message, std::ostream& ostr = std::cout);
   std::ostream& printMessage(const char* message, int space = 0, const char* cstring = "", std::ostream& ostr = std::cout);
}

#endif