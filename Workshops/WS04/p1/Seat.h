//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 7, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
#include <iostream>

namespace sdds {
   class Seat {
   private:
	   char* m_name;
	   int m_row;
	   char m_letter;
	   
	   //Validate correct row numbers and seating letters
	   bool validate(int row, int letter)const;
	
	   //Check if string is valid and if it is, copy string to name
	   Seat& alAndCp(const char* str);
   public:
	   //Reset object to safe empty state
	   Seat& reset();
	
	   //Check if object is in empty state
	   bool isEmpty()const;
	
	   //Check if seats are assigned and valid
	   bool assigned()const;

	   //Default constructor - set object to safe empty state
	   Seat();

	   //Constructor - deallocate memory and copy string to name
	   Seat(const char* passengerName);
	
	   //Constructor - deallocate memory and copy string to name, then set row and letter
	   Seat(const char* passengerName, int row, char letter);

	   //Destructor - deallocate memory
	   ~Seat();

	   //Set row and letter (validate first)
	   Seat& set(int row, char letter);

	   //Get row
	   int row()const;
	
	   //Get letter
	   char letter()const;

	   //Get passenger name
	   const char* passenger() const;

	   //Display passenger and seat information in formatted manner
	   std::ostream& display(std::ostream& coutRef = std::cout)const;

	   //Read passenger information from file
	   std::istream& read(std::istream& cinRef = std::cin);
   };
}
#endif // !SDDS_SEAT_H_


