//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 29, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Parking.h"
#include "Utils.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

namespace sdds
{
   //Two argument constructor
   Parking::Parking(const char* filename, int noOfSpots)
   {
      if (filename && filename[0] && noOfSpots >= MIN_PARKING && noOfSpots <= MAX_PARKING)
      {
         m_noOfSpots = noOfSpots;
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
         else
         {
            cout << "Error in data file" << endl;
            setEmpty();
         }
      }
      else
      {
         cout << "Error!" << endl;
         setEmpty();
      }
   }

   //Display in NOT comma mode
   ostream& Parking::displayNotCommaMode(int parkingSpot, const char* title, ostream& ostr)const
   {
      ostr << title << endl;
      m_parkingSpots[parkingSpot]->setCsv(false);
      ostr << *m_parkingSpots[parkingSpot] << endl;

      return ostr;
   }

   //Run the parking program
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
      for (int i = 0; i < m_noOfSpots; i++)
      {
         delete m_parkingSpots[i];
      }
   }

   //Check if Parking object is empty
   bool Parking::isEmpty()const
   {
      return m_filename == nullptr;
   }

   //Print status of parking and its available spots
   void Parking::parkingStatus()const
   {
      cout << "****** Valet Parking ******" << endl;
      cout << "*****  Available spots: ";
      cout << setw(4) << left << m_noOfSpots - m_parked << ' ';
      printChar('*', 5, cout) << endl;
   }

   //Park vehicle and display a parking ticket
   void Parking::parkVehicle()
   {
      if (m_parked < m_noOfSpots)
      {
         int selection = m_vehicleMenu.run();

         if (selection == 1)
         {
            parkAndDisplayVehicleType<Car>(cin);
         }
         else if (selection == 2)
         {
            parkAndDisplayVehicleType<Motorcycle>(cin);
         }
         else
         {
            cout << "Parking cancelled" << endl;
         }
      }
      else
      {
         cout << "Parking is full" << endl;
      }

      promptEnter(cin);
   }

   //Return the vehicle; remove it from the parking spots
   void Parking::returnVehicle()
   {
      char userInput[8 + 1];
      bool isFound = false;
      cout << "Return Vehicle" << endl;
      cout << "Enter License Plate Number: ";
      getString(userInput, 1, 8, "Invalid Licence Plate, try again: ");
      cout << endl;

      for (int i = 0; i < m_noOfSpots && !isFound; i++)
      {
         if (m_parkingSpots[i])
         {
            if (*m_parkingSpots[i] == userInput)
            {
               displayNotCommaMode(i, "Returning:", cout);
               deallocateParking(i);
               m_parked--;
               isFound = true;
            }
         }
      }
      if (!isFound)
      {
         cout << "License plate ";
         displayUpper(userInput) << " Not found" << endl << endl;
      }
      promptEnter(cin);
   }

   //Display string in uppercase
   ostream& displayUpper(const char* userInput, ostream& ostr)
   {
      for (int i = 0; i < strlen(userInput); i++)
      {
         ostr << toupper(userInput[i]);
      }

      return ostr;
   }

   //Prompt to click enter to continue
   std::istream& promptEnter(std::istream& istr)
   {
      cout << "Press <ENTER> to continue...."; //make function for this
      istr.ignore(1000, '\n');

      return istr;
   }

   //List all parked vehicles
   void Parking::listVehicle()const
   {
      cout << "*** List of parked vehicles ***" << endl;
      for (int i = 0; i < m_noOfSpots; i++)
      {
         if (m_parkingSpots[i])
         {
            m_parkingSpots[i]->setCsv(false);
            cout << *m_parkingSpots[i];
            printChar('-', 31) << endl;
         }
      }
      promptEnter(cin);
   }

   //Find a vehicle based on user input
   void Parking::findVehicle()const
   {
      char userInput[8 + 1];
      bool isFound = false;
      cout << "Vehicle Search" << endl;
      cout << "Enter Licence Plate Number: ";
      getString(userInput, 1, 8, "Invalid Licence Plate, try again: ");
      cout << endl;

      for (int i = 0; i < m_noOfSpots && !isFound; i++)
      {
         if (m_parkingSpots[i])
         {
            if (*m_parkingSpots[i] == userInput)
            {
               displayNotCommaMode(i, "Vehicle found:", cout);
               isFound = true;
            }
         }
      }
      if (!isFound)
      {
         cout << "License plate ";
         displayUpper(userInput) << " Not found" << endl << endl;
      }
      promptEnter(cin);
   }

   //Close parking by removing all vehicles from the parking spots
   bool Parking::closeParking()
   {
      char selection;
      bool ok;

      if (!m_parked)
      {
         cout << "Closing Parking" << endl;
         ok = true;
      }
      else
      {
         cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
         cout << "Are you sure? (Y)es/(N)o: ";
         selection = getChar("YyNn", "Invalid response, only (Y)es or (N)o are acceptable, retry: ");
         ok = selection == 'Y' || selection == 'y';
         if (ok)
         {
            cout << "Closing Parking" << endl;
            for (int i = 0; i < m_noOfSpots; i++)
            {
               if (m_parkingSpots[i])
               {
                  cout << endl << "Towing request" << endl;
                  printChar('*', 21) << endl;
                  m_parkingSpots[i]->setCsv(false);
                  cout << *m_parkingSpots[i];
                  deallocateParking(i);
               }
            }
         }
      }

      return ok;
   }

   //Exit parking and save to file based on user input
   bool Parking::exitParking()const
   {
      char selection;
      bool ok;

      printPrompt("This will terminate the program!");
      selection = getChar("YyNn", "Invalid response, only (Y)es or (N)o are acceptable, retry: ");
      ok = selection == 'Y' || selection == 'y';
      if (ok)
      {
         cout << "Exiting program!" << endl;
      }

      return ok;
   }

   //Save to the file
   void Parking::saveFile()const
   {
      if (*this)
      {
         ofstream myfile(m_filename);
         if (myfile) //if file is open
         {
            for (int i = 0; i < m_noOfSpots; i++)
            {
               if (m_parkingSpots[i])
               {
                  m_parkingSpots[i]->setCsv(true);
                  myfile << *m_parkingSpots[i];
               }
            }
         }
      }
   }

   //Set parking to safe empty state
   Parking& Parking::setEmpty()
   {
      m_filename = nullptr;
      m_noOfSpots = 0;
      for (int i = 0; i < MAX_PARKING; i++)
      {
         m_parkingSpots[i] = nullptr;
      }
      m_parked = 0;

      return *this;
   }

   //Check if object is valid
   Parking::operator bool()const
   {
      return !isEmpty();
   }

   //Make parking spot available and set to null for next use
   Parking& Parking::deallocateParking(int parkingSpot)
   {
      delete m_parkingSpots[parkingSpot];
      m_parkingSpots[parkingSpot] = nullptr;

      return *this;
   }

   //Print prompt to user (message and Are you sure?)
   std::ostream& printPrompt(const char* message, std::ostream& ostr)
   {
      ostr << message << endl;
      ostr << "Are you sure? (Y)es/(N)o: ";

      return ostr;
   }

   //Load data from file
   bool Parking::loadFile()
   {
      bool ok = true;
      if (*this)
      {
         ifstream myfile(m_filename);
         if (myfile) //if file is open
         {
            char ch;
            for (int i = 0; i < m_noOfSpots && myfile.peek() != EOF; i++)
            {
               ch = readChar(',', "CM", myfile);
               if (myfile)
               {
                  if (ch == 'C')
                  {
                     if (!loadVehicleType<Car>(myfile))
                     {
                        ok = false;
                     }
                  }
                  else if (ch == 'M')
                  {
                     if (!loadVehicleType<Motorcycle>(myfile))
                     {
                        ok = false;
                     }
                  }
               }
               else
               {
                  myfile.clear();
                  myfile.ignore(1000, '\n');
                  ok = false;
               }
            }
         }
      }
      return ok;
   }
}
