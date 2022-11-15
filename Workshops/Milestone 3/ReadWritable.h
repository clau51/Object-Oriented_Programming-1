#ifndef SDDS_READWRITABLE_H_
#define SDDS_READWRITABLE_H_

#include <iostream>

namespace sdds
{
   class ReadWritable
   {
      bool m_commaMode;


   public:
      ReadWritable();
      virtual ~ReadWritable() = default;
      bool isCsv()const;
      void setCsv(bool value);
      virtual std::istream& read(std::istream& istr = std::cin) = 0;
      virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
   };

   std::istream& operator>>(std::istream& istr, ReadWritable& read); //Base& base = derived[0];
   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& write);

}

#endif