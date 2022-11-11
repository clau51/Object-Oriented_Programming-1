#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Parking.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
   Parking::Parking(const char* filename)
   {
      if (filename && filename[0])
      {
         m_filename = new char[strlen(filename) + 1];
         std::strcpy(m_filename, filename);
         
         if (loadFile())
         {
            m_mainMenu << "Park Vehicle" 
               << "Return Vehicles" 
               << "List Parked Vehicles"
               << "Find Vehicle" 
               << "Close Parking (End of day)" 
               << "Exit Program";

            m_vehicleMenu << "Car" 
               << "Motorcycle" 
               << "Cancel";
         }
         else
         {
            cout << "Error in data file" << endl;
         }
      }
      else
      {
         setEmpty();
      }
   }
   int Parking::run()
   {
      if (*this)
      {
         bool ok;
         do
         {
            ok = false;
            int selection;
            parkingStatus();
            selection = m_mainMenu.run();
            if (selection == 1) parkVehicle();
            else if (selection == 2) returnVehicle();
            else if (selection == 3) listVehicle();
            else if (selection == 4) findVehicle();
            else if (selection == 5 && closeParking()) ok = true;
            else if (selection == 6 && exitParking()) ok = true;
         } while (!ok);

      }
      return isEmpty();
   }
   Parking::~Parking()
   {
      delete[] m_filename;
      m_filename = nullptr;
   }
   bool Parking::isEmpty()
   {
      return m_filename == nullptr;
   }
   void Parking::parkingStatus()
   {
      cout << "****** Valet Parking ******" << endl;
   }
   void Parking::parkVehicle()
   {
      //m_vehicleMenu.display();
      int selection = m_vehicleMenu.run();
      
      if (selection == 1)
      {
         printDivider('-', 33) << endl;
         cout << "Parking Car" << endl;
         printDivider('-', 33) << endl;
      } 
      else if (selection == 2)
      {
         printDivider('-', 33) << endl;
         cout << "Parking Motorcycle" << endl;
         printDivider('-', 33) << endl;
      }
      else
      {
         printDivider('-', 33) << endl;
         cout << "Cancelled parking" << endl;
         printDivider('-', 33) << endl;
      }
   }
   
   void Parking::returnVehicle()
   {
      printMessage("Returning Vehicle");
   }
   
   void Parking::listVehicle()
   {
      printMessage("Listing Parked Vehicles");
   }
   
   void Parking::findVehicle()
   {
      printMessage("Finding Vehicle");
   }
   
   bool Parking::closeParking()
   {
      char selection;
      bool ok;
      //create function to display prompt**
      cout << "This will close the parking, All the vehicles will be removed!" << endl;
      cout << "Are you sure? (Y)es/(N)o:";
      selection = getCharSelection("YyNn");
      ok = selection == 'Y' || selection == 'y';

      return ok;
   }

   bool Parking::exitParking()
   {
      char selection;
      bool ok;
      //create function to display prompt**
      cout << "This will terminate the application and save the data!";
      cout << "Are you sure? (Y)es/(N)o:";
      selection = getCharSelection("YyNn");
      ok = selection == 'Y' || selection == 'y';

      return ok;
   }

   bool Parking::loadFile()
   {
      bool ok = true;
      if (*this)
      {
         cout << "loading data from " << m_filename << endl;
      }
      else
      {
         ok = false;
      }

      return ok;
   }
   void Parking::saveFile()
   {
      if (*this)
      {
         cout << "Saving data into " << m_filename << endl;
      }
   }
   Parking& Parking::setEmpty()
   {
      m_filename = nullptr;
      m_mainMenu = nullptr;
      m_vehicleMenu = nullptr;
      
      return *this;
   }

   Parking::operator bool()
   {
      return !isEmpty();
   }

   //std::ostream& printVehicle(std::ostream& ostr = std::cout)
   //{
   //   printDivider('-', 33, ostr);
   //   ostr << "Parking " << m_vehicleMenu.
   //}
}