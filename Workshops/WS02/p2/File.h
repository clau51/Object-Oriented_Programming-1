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
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "Population.h"

namespace sdds {
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
	bool openFile(const char filename[]);

   //bool fReadFile(Population& population);

   // Closes the open file
   void closeFile();
   // Finds the records kept in the file to be used for the dynamic memory allocation 
   // of the records in the file
   int noOfRecords();

   bool read(Population& population);
}
#endif // !SDDS_FILE_H_


//Make struct - postalCode, population
//Open file
//Check if null
//If successful, read into struct array dynamically
//After read in dynamically, sort the file.
//print
//deallocate