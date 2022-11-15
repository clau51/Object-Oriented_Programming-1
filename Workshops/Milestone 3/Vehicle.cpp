#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Vehicle.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   Vehicle& Vehicle::setEmpty()
   {
      m_licensePlate[0] = '\0';
      m_makeModel = nullptr;
      m_parkingSpot = 0;

      return *this;
   }

   bool Vehicle::isEmpty()const
   {
      return m_licensePlate[0] == '\0';
   }

   Vehicle::Vehicle() //needed or not?
   {
      setEmpty();
   }

   Vehicle::Vehicle(const char* licensePlate, const char* makeModel)
   {
      if (licensePlate && makeModel && licensePlate[0] && makeModel[2])
      {
         //setEmpty(); //do i need to setEmpty() when creating a new object?
         std::strcpy(m_licensePlate, licensePlate);

         m_makeModel = new char[strlen(makeModel) + 1];
         std::strcpy(m_makeModel, makeModel);
         m_parkingSpot = 0;
      }
      else
      {
         setEmpty();
      }
   }

   Vehicle& Vehicle::operator=(const Vehicle& vehicle)
   {
      if (this != &vehicle)
      {
         if (vehicle)
         {
            //call setEmpty to set nullptr, not necessary?
            deallocate();

            m_makeModel = new char[strlen(vehicle.m_makeModel) + 1];
            std::strcpy(m_makeModel, vehicle.m_makeModel);
            std::strcpy(m_licensePlate, vehicle.m_licensePlate);
            m_parkingSpot = vehicle.m_parkingSpot;
         }
      }
      return *this;
   }

   Vehicle::operator bool() const
   {
      return !isEmpty();
   }

   Vehicle::Vehicle(const Vehicle& vehicle)
   {
      setEmpty(); //need because not value initialized
      *this = vehicle;
   }

   Vehicle::~Vehicle()
   {
      deallocate();
   }

   const char* Vehicle::getLicensePlate()const
   {
      return m_licensePlate;
   }

   const char* Vehicle::getMakeModel()const
   {
      return m_makeModel;
   }

   Vehicle& Vehicle::setMakeModel(const char* makeModel) //possibly use in constructor?
   {
      if (makeModel && makeModel[2]) //instructions say if value null or empty? but cant be less than 2 chars?
      {
         deallocate();
         m_makeModel = new char[strlen(makeModel) + 1];
         std::strcpy(m_makeModel, makeModel);
      }
      else
      {
         deallocate();
         setEmpty();
      }

      return *this;
   }

   Vehicle& Vehicle::deallocate()
   {
      delete[] m_makeModel;
      m_makeModel = nullptr;

      return *this;
   }

   int Vehicle::getParkingSpot() const
   {
      return m_parkingSpot;
   }

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

   bool Vehicle::operator==(const char* licensePlate)const
   {
      bool ok = false;

      if (*this)
      {
         if (licensePlate && licensePlate[0])
         {
            char tempOrig[8 + 1];
            char tempNew[8 + 1];

            lowerstrcpy(tempOrig, m_licensePlate);
            lowerstrcpy(tempNew, licensePlate);

            if (strcmp(tempOrig, tempNew) == 0)
            {
               ok = true;
            }
            else
            {
               ok = false;
            }
         }
      }

      return ok;
   }

   bool Vehicle::operator==(const Vehicle& vehicle)const
   {
      return *this == vehicle.m_licensePlate;
   }

   //Are we assumming valid data?
   istream& Vehicle::read(istream& istr) //is this assuming valid data?
   {
      bool ok;
      char tempLicense[8 + 1];
      char tempMakeModel[60 + 1];

      m_parkingSpot = 0;
      if (isCsv())
      {
         //Vehicle temp; 

         istr >> m_parkingSpot;
         istr.ignore();

         if (istr)
         {
            istr.getline(tempLicense, 9, ',');
            upperstrcpy(m_licensePlate, tempLicense);
         }

         if (istr)
         {
            istr.getline(tempMakeModel, 61, ',');
            deallocate();
            //can make a Vehicle object instead?
            m_makeModel = new char[strlen(tempMakeModel) + 1];
            std::strcpy(m_makeModel, tempMakeModel);
         }
         else
         {
            setEmpty();
         }
      }

      //how to check if istream object failed while reading?
      else
      {
         cout << "Enter License Plate Number: ";
         do
         {
            ok = true;
            istr.getline(tempLicense, 9, '\n');
            //istr >> tempLicense;
            if (!istr || strlen(tempLicense) < 1)
            {
               istr.clear();
               istr.ignore(1000, '\n');
               cout << "Invalid License Plate, try again: ";
               ok = false;
            }
            else
            {
               upperstrcpy(m_licensePlate, tempLicense);
            }
         } while (!ok);

         cout << "Enter Make and Model: ";
         do
         {
            ok = true;
            istr.getline(tempMakeModel, 61, '\n');
            //istr >> tempMakeModel;
            if (!istr) //Wrong output: ab works, but it must have more than 2 chars...
            {
               istr.clear();
               istr.ignore(1000, '\n');
               cout << "Invalid Make and Model, try again: ";
               ok = false;
            }
            else
            {
               if (strlen(tempMakeModel) < 2)
               {
                  cout << "Invalid Make and Model, try again: ";
                  ok = false;
               }
               else
               {
                  deallocate();
                  //can make a Vehicle object instead?
                  m_makeModel = new char[strlen(tempMakeModel) + 1];
                  std::strcpy(m_makeModel, tempMakeModel);
               }
            }
         } while (!ok);
      }

      return istr;
   }

   ostream& Vehicle::write(ostream& ostr)const
   {
      if (*this)
      {
         writeType();
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