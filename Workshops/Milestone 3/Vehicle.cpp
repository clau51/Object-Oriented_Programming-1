//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 17, 2022
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

   //Vehicle::Vehicle()
   //{
   //   setEmpty();
   //}

   //Constructor: receives licensePlate and makeModel parameters set to default
   Vehicle::Vehicle(const char* licensePlate, const char* makeModel) : ReadWritable()
   {
      if (licensePlate && makeModel && licensePlate[0] && makeModel[0])
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
            m_parkingSpot = vehicle.m_parkingSpot;
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
      if (makeModel && makeModel[0] && sdds::strlen(makeModel) >= 2)
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

   //Set license plate
   Vehicle& Vehicle::setLicensePlate(const char* licensePlate)
   {
      if (licensePlate && licensePlate[0] && sdds::strlen(licensePlate) >= MIN_CHAR_LICENSE && sdds::strlen(licensePlate) <= MAX_CHAR_LICENSE)
      {
         upperstrcpy(m_licensePlate, licensePlate);
      }
      else
      {
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
      if (parkingSpot >= 0)
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
         if (licensePlate && licensePlate[0])
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
      bool success;
      if (isCsv())
      {
         success = readParkingSpot(istr, ',');
         if (success) readLicensePlate(istr, ',');
         if (success) readMakeModel(istr, ',');
      }
      else
      {
         cout << "Enter Licence Plate Number: ";
         do
         {
            success = readLicensePlate(istr, '\n');
            if (!success)
            {
               cout << "Invalid Licence Plate, try again: ";
            }
         } while (!success);

         cout << "Enter Make and Model: ";
         do
         {
            success = readMakeModel(istr, '\n');
            if (!success)
            {
               cout << "Invalid Make and model, try again: ";
            }
         } while (!success);
      }

      return istr;
   }

   //Read parking spot
   bool Vehicle::readParkingSpot(istream& istr, char delimiter) //receive a parkingSpot variable?
   {
      char delimit;
      bool success = true;
      int parkingSpot;
      istr >> parkingSpot;
      if (istr)
      {
         delimit = istr.get();
         if (delimit != delimiter)
         {
            success = false;
            cin.clear();
            cin.ignore(1000, delimiter);
            if (isCsv())
            {
               setEmpty();
            }
         }
         else
         {
            if (isCsv())
            {
               setParkingSpot(parkingSpot);
            }
            else
            {
               success = false;
               if (parkingSpot >= 0)
               {
                  setParkingSpot(parkingSpot);
                  success = true;
               }
            }
         }
      }
      else
      {
         istr.clear();
         istr.ignore(1000, delimiter);
         success = false;
      }

      return success;
   }

   //Read license plate
   bool Vehicle::readLicensePlate(std::istream& istr, char delimiter)
   {
      bool success = true;
      char tempLicense[MAX_CHAR_LICENSE + 1];
      istr.getline(tempLicense, MAX_CHAR_LICENSE + 1, delimiter);
      if (!istr)
      {
         istr.clear();
         istr.ignore(1000, delimiter);
         if (isCsv())
         {
            setEmpty();
         }
         success = false;
      }
      else
      {
         if (isCsv())
         {
            setLicensePlate(tempLicense);
         }
         else
         {
            success = false;
            if (sdds::strlen(tempLicense) >= MIN_CHAR_LICENSE && sdds::strlen(tempLicense) <= MAX_CHAR_LICENSE)
            {
               setLicensePlate(tempLicense);
               success = true;
            }
         }
      }

      return success;
   }

   //Read make and model
   bool Vehicle::readMakeModel(std::istream& istr, char delimiter)
   {
      bool success = true;
      char tempMakeModel[MAX_CHAR_MAKEMODEL + 1];
      istr.getline(tempMakeModel, MAX_CHAR_MAKEMODEL + 1, delimiter);
      if (!istr)
      {
         istr.clear();
         istr.ignore(1000, delimiter);
         if (isCsv())
         {
            setEmpty();
         }
         success = false;
      }
      else
      {
         if (isCsv())
         {
            setMakeModel(tempMakeModel);
         }
         else
         {
            success = false;
            if (sdds::strlen(tempMakeModel) >= MIN_CHAR_MAKEMODEL)
            {
               setMakeModel(tempMakeModel);
               success = true;
            }
         }
      }

      return success;
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

            ostr << "Licence Plate: " << m_licensePlate << endl;

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