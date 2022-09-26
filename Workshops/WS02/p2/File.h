/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.h
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Carmen Lau	   Sept 24, 2022   Add function prototype
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "Population.h"

namespace sdds {
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
	bool openFile(const char filename[]);

   // Closes the open file
   void closeFile();

   // Finds the records kept in the file to be used for the dynamic memory allocation 
   // of the records in the file
   int noOfRecords();

   //Reads the records from file and loads them
   bool read(Population& population);
}
#endif // !SDDS_FILE_H_