#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_
#include <iostream>

namespace sdds
{
   class Text
   {
      char* m_content{};
      int m_len{};
      unsigned getFileLength(std::istream& is);
   protected:
      const char& operator[](int index)const;
      Text& deallocate();
   public:
      int getLen()const
      {
         return m_len;
      }
      Text() = default;
      Text& operator=(const Text& text);
      Text(const Text& Text);
      virtual ~Text();
      virtual std::istream& read(std::istream& istr = std::cin);
      virtual std::ostream& write(std::ostream& ostr = std::cout)const;
      virtual operator bool()const;
   };
   std::istream& operator>>(std::istream& istr, Text& text);
   std::ostream& operator<<(std::ostream& ostr, const Text& text);

}

#endif