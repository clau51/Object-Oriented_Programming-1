#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Parking.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
   //One argument constructor: if valid, populate parking and vehicle menus
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

   //Run the Parking Application; display messages according to user input
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

   //Destructor
   Parking::~Parking()
   {
      saveFile();
      delete[] m_filename;
      m_filename = nullptr;
   }

   //Check if Parking object is empty
   bool Parking::isEmpty()const
   {
      return m_filename == nullptr;
   }

   //Display parking status
   void Parking::parkingStatus()const
   {
      cout << "****** Valet Parking ******" << endl;
   }

   //Display vehicle depending on user input
   void Parking::parkVehicle()const
   {
      int selection = m_vehicleMenu.run();

      if (selection == 1)
      {
         printMessage("Parking", 1, m_vehicleMenu.getMenuItem(selection - 1)) << endl;
      }
      else if (selection == 2)
      {
         printMessage("Parking", 1, m_vehicleMenu.getMenuItem(selection - 1)) << endl;
      }
      else
      {
         printMessage("Cancelled parking") << endl;
      }
   }

   //Display vehicle returned
   void Parking::returnVehicle()const
   {
      printMessage("Returning Vehicle") << endl;
   }

   //Display list of parked vehicles
   void Parking::listVehicle()const
   {
      printMessage("Listing Parked Vehicles") << endl;
   }

   //Display message "Finding a Vehicle"
   void Parking::findVehicle()const
   {
      printMessage("Finding a Vehicle") << endl;
   }

   //Close parking depending on user input
   bool Parking::closeParking()const
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

   //Exit parking application
   bool Parking::exitParking()const
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

   //Display message where file is loading from
   bool Parking::loadFile()const
   {
      if (*this)
      {
         printMessage("loading data from", 1, m_filename) << endl;
      }

      return *this;
   }

   //Display message where file is saving to
   void Parking::saveFile()const
   {
      if (*this)
      {
         printMessage("Saving data into", 1, m_filename) << endl;
      }
   }

   //Set object to empty state
   Parking& Parking::setEmpty()
   {
      m_filename = nullptr;

      return *this;
   }

   //Check if object is valid
   Parking::operator bool()const
   {
      return !isEmpty();
   }

   //Display prompt
   std::ostream& printPrompt(const char* message, std::ostream& ostr)
   {
      ostr << message << endl;
      ostr << "Are you sure? (Y)es/(N)o: ";

      return ostr;
   }

   //Display a formatted message
   ostream& printMessage(const char* message, int space, const char* cstring, ostream& ostr)
   {
      printChar('-', 33, ostr) << endl;
      ostr << message;
      printChar(' ', space) << cstring << endl;
      printChar('-', 33) << endl;

      return ostr;
   }


}