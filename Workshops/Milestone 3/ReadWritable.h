//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 17, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_READWRITABLE_H_
#define SDDS_READWRITABLE_H_

#include <iostream>

namespace sdds
{
   class ReadWritable
   {
      bool m_commaMode;


   public:
      //Constructor: sets default m_commaMode to false
      ReadWritable();

      //Destructor
      virtual ~ReadWritable() = default;

      //Check if object is in comma mode
      bool isCsv()const;

      //Set comma mode
      void setCsv(bool value);

      //Pure virtual function: read
      virtual std::istream& read(std::istream& istr = std::cin) = 0;

      //Pure virtual function: write
      virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
   };

   //Helper extraction operator
   std::istream& operator>>(std::istream& istr, ReadWritable& read); //Base& base = derived[0];

   //Helper inseration operator
   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& write);

}

#endif