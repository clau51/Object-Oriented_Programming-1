#include "ReadWritable.h"

namespace sdds
{
   ReadWritable::ReadWritable()
   {
      m_commaMode = false;
   }

   bool ReadWritable::isCsv() const
   {
      return m_commaMode;
   }

   void ReadWritable::setCsv(bool value)
   {
      m_commaMode = value;
   }

   std::istream& operator>>(std::istream& istr, ReadWritable& read)
   {
      return read.read(istr);
   }

   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& write)
   {
      return write.write(ostr);
   }

}