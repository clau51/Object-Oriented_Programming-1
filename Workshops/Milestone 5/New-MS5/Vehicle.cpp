//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 22, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Vehicle.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   const int MIN_CHAR_LICENSE = 1;
   const int MAX_CHAR_LICENSE = 8;
   const int MIN_CHAR_MAKEMODEL = 2;
   const int MAX_CHAR_MAKEMODEL = 60;

   //Set to empty state
   Vehicle& Vehicle::setEmpty()
   {
      m_licensePlate[0] = '\0';
      m_makeModel = nullptr;
      m_parkingSpot = 0;

      return *this;
   }

   //Check if object is empty
   bool Vehicle::isEmpty()const
   {
      return m_licensePlate[0] == '\0';
   }

   //Allocate and copy m_makeModel
   Vehicle& Vehicle::alAndCp(const char* str)
   {
      if (str && str[0])
      {
         m_makeModel = new char[sdds::strlen(str) + 1];
         std::strcpy(m_makeModel, str);
      }

      return *this;
   }

   //Constructor: receives licensePlate and makeModel parameters set to default
   Vehicle::Vehicle(const char* licensePlate, const char* makeModel) : ReadWritable()
   {
      if (validateLicense(licensePlate) && validateMakeModel(makeModel))
      {
         m_parkingSpot = 0;
         setLicensePlate(licensePlate);
         setMakeModel(makeModel);
      }
   }

   //Copy assignment
   Vehicle& Vehicle::operator=(const Vehicle& vehicle)
   {
      if (this != &vehicle)
      {
         if (vehicle)
         {
            setMakeModel(vehicle.m_makeModel);
            setLicensePlate(vehicle.m_licensePlate);
            setParkingSpot(vehicle.m_parkingSpot);
            setCsv(vehicle.isCsv());
         }
      }
      return *this;
   }

   //Check if this object is empty or not
   Vehicle::operator bool() const
   {
      return !isEmpty();
   }

   //Copy constructor
   Vehicle::Vehicle(const Vehicle& vehicle)
   {
      *this = vehicle;
   }

   //Destructor
   Vehicle::~Vehicle()
   {
      delete[] m_makeModel;
   }

   //Get license plate
   const char* Vehicle::getLicensePlate()const
   {
      return m_licensePlate;
   }

   //Get make and model
   const char* Vehicle::getMakeModel()const
   {
      return m_makeModel;
   }

   //Set make and model
   Vehicle& Vehicle::setMakeModel(const char* makeModel)
   {
      if (validateMakeModel(makeModel))
      {
         deallocate();
         alAndCp(makeModel);
      }
      else
      {
         deallocate();
         setEmpty();
      }

      return *this;
   }

   bool Vehicle::validateLicense(const char* licensePlate) const
   {
      return licensePlate && licensePlate[0] && sdds::strlen(licensePlate) >= MIN_CHAR_LICENSE && sdds::strlen(licensePlate) <= MAX_CHAR_LICENSE;
   }

   bool Vehicle::validateMakeModel(const char* makeModel) const
   {
      return makeModel && makeModel[0] && strlen(makeModel) >= MIN_CHAR_MAKEMODEL;
   }

   bool Vehicle::validateParkingSpot(int parkingSpot) const
   {
      return parkingSpot >= 0;
   }

   //Set license plate
   Vehicle& Vehicle::setLicensePlate(const char* licensePlate)
   {
      if (validateLicense(licensePlate))
      {
         upperstrcpy(m_licensePlate, licensePlate);
      }
      else
      {
         deallocate();
         setEmpty();
      }

      return *this;
   }

   //Deallocate memory for m_makeModel
   Vehicle& Vehicle::deallocate()
   {
      delete[] m_makeModel;
      m_makeModel = nullptr;

      return *this;
   }

   //Get parking spot
   int Vehicle::getParkingSpot() const
   {
      return m_parkingSpot;
   }

   //Set parking spot
   Vehicle& Vehicle::setParkingSpot(int parkingSpot)
   {
      if (validateParkingSpot(parkingSpot))
      {
         m_parkingSpot = parkingSpot;
      }
      else
      {
         deallocate();
         setEmpty();
      }
      return *this;
   }

   //Check if left operand is equal to right operand (receiving string)
   bool Vehicle::operator==(const char* licensePlate)const
   {
      bool ok = false;

      if (*this)
      {
         if (validateLicense(licensePlate))
         {
            char tempLicense[MAX_CHAR_LICENSE + 1];

            upperstrcpy(tempLicense, licensePlate);

            if (sdds::strcmp(m_licensePlate, tempLicense) == 0)
            {
               ok = true;
            }
         }
      }

      return ok;
   }

   //Check if left operand is equal to right operand (reciving Vehicle object reference)
   bool Vehicle::operator==(const Vehicle& vehicle)const
   {
      return *this == vehicle.m_licensePlate;
   }

   //Read from istr: get input based on if its in comma seperated value
   std::istream& Vehicle::read(istream& istr)
   {
      int parkingSpot;
      char licensePlate[MAX_CHAR_LICENSE + 1];
      char makeModel[MAX_CHAR_MAKEMODEL + 1];

      m_parkingSpot = 0;
      if (isCsv())
      {
         parkingSpot = readInt(',', istr);
         istr.getline(licensePlate, MAX_CHAR_LICENSE + 1, ',');
         istr.getline(makeModel, MAX_CHAR_MAKEMODEL + 1, ',');

         if (istr)
         {
            if (validateParkingSpot(parkingSpot) && validateMakeModel(makeModel) && validateLicense(licensePlate))
            {
               setParkingSpot(parkingSpot);
               setLicensePlate(licensePlate);
               setMakeModel(makeModel);
            }
            else
            {
               deallocate();
               setEmpty();
            }
         }
         else
         {
            deallocate();
            setEmpty();
            istr.clear();
            istr.ignore(1000, ',');
         }
      }
      else
      {
         cout << "Enter License Plate Number: ";
         getString(licensePlate, MIN_CHAR_LICENSE, MAX_CHAR_LICENSE, "Invalid License Plate, try again: ", istr);
         setLicensePlate(licensePlate);
         cout << "Enter Make and Model: ";
         getString(makeModel, MIN_CHAR_MAKEMODEL, MAX_CHAR_MAKEMODEL, "Invalid Make and model, try again: ", istr);
         setMakeModel(makeModel);

      }
      return istr;
   }

   //Write to ostr: display parking spot, license plate, make and model
   ostream& Vehicle::write(ostream& ostr)const
   {
      if (*this)
      {
         writeType(ostr);
         if (isCsv())
         {
            ostr << m_parkingSpot << "," << m_licensePlate << "," << m_makeModel << ",";
         }
         else
         {
            ostr << "Parking Spot Number: ";
            if (m_parkingSpot) ostr << m_parkingSpot << endl;
            else ostr << "N/A" << endl;

            ostr << "License Plate: " << m_licensePlate << endl;

            ostr << "Make and Model: " << m_makeModel << endl;
         }
      }
      else
      {
         cout << "Invalid Vehicle Object" << endl;
      }

      return ostr;
   }
}