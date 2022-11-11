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
               << "Return Vehicle" 
               << "List Parked Vehicles"
               << "Find Vehicle" 
               << "Close Parking (End of day)" 
               << "Exit Program";

            m_vehicleMenu << "Car" 
               << "Motorcycle" 
               << "Cancel";
         }
      }
      else
      {
         cout << "Error in data file" << endl;
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
            else if (selection == 5 && closeParking())
            {
               ok = true;
            }
            else if (selection == 6 && exitParking())
            {
               ok = true;
            }
         } while (!ok);

      }
      return isEmpty();
   }

   Parking::~Parking()
   {
      saveFile();
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
         printDivider('-', 33) << endl << endl;
      } 
      else if (selection == 2)
      {
         printDivider('-', 33) << endl;
         cout << "Parking Motorcycle" << endl;
         printDivider('-', 33) << endl << endl;
      }
      else
      {
         printDivider('-', 33) << endl;
         cout << "Cancelled parking" << endl;
         printDivider('-', 33) << endl << endl;
      }
   }
   
   void Parking::returnVehicle()
   {
      printMessage("Returning Vehicle") << endl;
   }
   
   void Parking::listVehicle()
   {
      printMessage("Listing Parked Vehicles") << endl;
   }
   
   void Parking::findVehicle()
   {
      printMessage("Finding a Vehicle") << endl;
   }
   
   bool Parking::closeParking()
   {
      char selection;
      bool ok;

      printPrompt("This will close the parking; All the vehicles will be removed!");
      selection = getYesNo("YyNn");
      ok = selection == 'Y' || selection == 'y';
      if (ok)
      {
         cout << "Ending application!" << endl;
      }

      return ok;
   }

   bool Parking::exitParking()
   {
      char selection;
      bool ok;

      printPrompt("This will terminate the application and save the data!");
      selection = getYesNo("YyNn");
      ok = selection == 'Y' || selection == 'y';
      if (ok)
      {
         cout << "Exiting application!" << endl;
      }

      return ok;
   }

   bool Parking::loadFile()
   {
      if (*this)
      {
         printMessage("loading data from", m_filename) << endl;
      }

      return bool(*this);
   }

   void Parking::saveFile()
   {
      if (*this)
      {
         printMessage("Saving data into", m_filename) << endl;
      }
   }

   Parking& Parking::setEmpty()
   {
      m_filename = nullptr;
      //m_mainMenu = nullptr;
      //m_vehicleMenu = nullptr;
      
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

   std::ostream& printPrompt(const char* message, std::ostream& ostr)
   {
      ostr << message << endl;
      ostr << "Are you sure? (Y)es/(N)o: ";

      return ostr;
   }

   std::ostream& printMessage(const char* message, ostream& ostr)
   {
      printDivider('-', 33, ostr) << endl;
      ostr << message << endl;
      printDivider('-', 33) << endl;

      return ostr;
   }

   ostream& printMessage(const char* message, const char* file, ostream& ostr)
   {
      printDivider('-', 33, ostr) << endl;
      ostr << message << " " << file << endl;
      printDivider('-', 33) << endl;

      return ostr;
   }

   ostream& printDivider(char character, int num, ostream& ostr)
   {
      for (int i = 0; i < num; i++)
      {
         ostr << character;
      }

      return ostr;
   }
}