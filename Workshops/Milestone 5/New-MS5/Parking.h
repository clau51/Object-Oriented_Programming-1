//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 29, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_
#include <iostream>
#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

namespace sdds
{
   const int MAX_PARKING = 100;
   const int MIN_PARKING = 10;

   class Parking
   {
      char* m_filename{};
      Menu m_mainMenu{ "Parking Menu, select an action:", 0 };
      Menu m_vehicleMenu{ "Select type of the vehicle:", 1 };
      int m_noOfSpots{};
      Vehicle* m_parkingSpots[MAX_PARKING]{}; //act like parking spots (array of pointers)
      int m_parked{};

      //Check if Parking object is empty
      bool isEmpty()const;

      //Print status of parking and its available spots
      void parkingStatus()const;

      //Park vehicle and display a parking ticket
      void parkVehicle(); 

      //Return the vehicle; remove it from the parking spots
      void returnVehicle(); 

      //List all parked vehicles
      void listVehicle()const;

      //Find a vehicle based on user input
      void findVehicle()const;

      //Close parking by removing all vehicles from the parking spots
      bool closeParking();

      //Exit parking and save to file based on user input
      bool exitParking()const;

      //Load data from file
      bool loadFile();

      //Save to the file
      void saveFile()const;
      
      //Deleted copy constructor
      Parking(const Parking& parking) = delete;

      //Deleted copy assignment
      Parking& operator=(const Parking& parking) = delete;

      //Set parking to safe empty state
      Parking& setEmpty();

      //Check if parking is not empty
      operator bool()const;

      //Make parking spot available and set to null for next use
      Parking& deallocateParking(int parkingSpot);

   public:
      //Destructor
      virtual ~Parking();

      //Run the parking
      int run();

      //Two argument constructor
      Parking(const char* filename, int noOfSpots);

      //Template to load data from a file depending on the type of vehicle
      template<typename T>
      bool loadVehicleType(std::istream& istr = std::cin)
      {
         bool ok = false;
         T* vehicleType = new T;
         vehicleType->setCsv(true);
         istr >> *vehicleType;
         if (*vehicleType) //calls operator bool...(if object is valid)..
         {
            m_parkingSpots[vehicleType->getParkingSpot() - 1] = vehicleType;
            m_parked++;
            ok = true;
         }
         else
         {
            delete vehicleType;
            vehicleType = nullptr;
         }
         return ok;
      }

      //Template to park a vehicle and display the ticket depending on the type of vehicle
      template<typename T>
      bool parkAndDisplayVehicleType(std::istream& istr = std::cin)
      {
         bool isParked = false;
         T* vehicleType = new T;
         istr >> *vehicleType;

         for (int i = 0; i < m_noOfSpots && !isParked; i++)
         {
            if (!m_parkingSpots[i]) //if parking spot is null
            {
               vehicleType->setParkingSpot(i + 1);
               m_parkingSpots[i] = vehicleType;
               m_parked++;
               std::cout << std::endl;
               displayNotCommaMode(i, "Parking Ticket", std::cout);
               isParked = true;
            }
         }

         return isParked;
      }

      //Display in NOT comma mode
      std::ostream& displayNotCommaMode(int parkingSpot, const char* title, std::ostream& ostr = std::cout)const;
   };

   //Print prompt to user (message and Are you sure?)
   std::ostream& printPrompt(const char* message, std::ostream& ostr = std::cout);

   //Display string in uppercase
   std::ostream& displayUpper(const char* userInput, std::ostream& ostr = std::cout);

   //Prompt to click enter to continue
   std::istream& promptEnter(std::istream& istr = std::cin);
}

#endif