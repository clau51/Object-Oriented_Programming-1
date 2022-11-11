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

      bool isEmpty();
      void parkingStatus();
      void parkVehicle();
      void returnVehicle();
      void listVehicle();
      void findVehicle();
      bool closeParking();
      bool exitParking();
      bool loadFile();
      void saveFile();
      Parking(const Parking& parking) = delete;
      Parking& operator=(const Parking& parking) = delete;
      Parking& setEmpty();
      operator bool();

   public:
      Parking(const char* filename);
      virtual ~Parking();
      int run();

   };
   std::ostream& printPrompt(const char* message, std::ostream& ostr = std::cout);
   std::ostream& printMessage(const char* message, std::ostream& ostr = std::cout);
   std::ostream& printMessage(const char* message, const char* file, std::ostream& ostr = std::cout);
   std::ostream& printDivider(char character, int num, std::ostream& ostr = std::cout);

   //std::ostream& printVehicle(std::ostream& ostr = std::cout);
}

#endif