#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
#include <iostream>

namespace sdds {
   class Seat {
   private:
	   char* m_name;
	   int m_row;
	   char m_letter;

	   bool validate(int row, int letter)const;
	   Seat& alAndCp(const char* str);
   public:
	   Seat& reset();
	   bool isEmpty()const;
	   bool assigned()const;
	   Seat();
	   Seat(const char* passengerName);
	   Seat(const char* passengerName, int row, char letter);
	   ~Seat();
	   Seat& set(int row, char letter);
	   int row()const;
	   char letter()const;
	   const char* passenger() const;
	   std::ostream& display(std::ostream& coutRed = std::cout)const;
	   std::istream& read(std::istream& cinRef = std::cin);
   };
}
#endif // !SDDS_SEAT_H_


