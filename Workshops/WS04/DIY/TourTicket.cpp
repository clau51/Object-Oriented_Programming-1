/***********************************************************************
// OOP244 Workshop 4 p2: TourTicket Module
//
// File	TourTicket.cpp
// Version 1.0
// Date	2022/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "TourTicket.h"
using namespace std;
namespace sdds {
   int next_ticketNumber = 100;

   //Receive string and copy string to m_name, set null terminator
   void TourTicket::copyName(const char* str) {
      int i=0;
      for(i=0;i < 40 && str[i]; m_name[i] = str[i], i++);
      m_name[i] = 0;
   }

   //Constructor - set default values
   TourTicket::TourTicket() {
      m_name[0] = char(0); //Sets the first character of the string to the null character
      m_ticketNumber = -1;
   }

   //Receive string, copy string to m_name, increment ticket number
   TourTicket& TourTicket::issue(const char* passengerName) {
      if(passengerName && passengerName[0]) {
         copyName(passengerName);
         m_ticketNumber = next_ticketNumber++;
      }
      return *this;
   }

   //Display name and ticket number
   std::ostream& TourTicket::display(std::ostream& coutRef) const {
      if(valid()) {
         coutRef << "| ";
         coutRef.width(40);
         coutRef.setf(ios::left);
         coutRef << m_name << " | " << m_ticketNumber << " |";
         coutRef.unsetf(ios::left);
      }
      else {
         coutRef << "Invalid TourTicket information" << endl;
      }
      return coutRef;
   }

   //Check if m_name is empty
   bool TourTicket::valid() const {
      return bool(m_name[0]);
   }
}