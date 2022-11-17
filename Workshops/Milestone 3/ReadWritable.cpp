//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 17, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "ReadWritable.h"

namespace sdds
{
   //Constructor: sets default m_commaMode to false
   ReadWritable::ReadWritable()
   {
      m_commaMode = false;
   }

   //Check if object is in comma mode
   bool ReadWritable::isCsv() const
   {
      return m_commaMode;
   }

   //Set comma mode
   void ReadWritable::setCsv(bool value)
   {
      m_commaMode = value;
   }

   //Helper extraction operator
   std::istream& operator>>(std::istream& istr, ReadWritable& read)
   {
      return read.read(istr);
   }

   //Helper inseration operator
   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& write)
   {
      return write.write(ostr);
   }

}