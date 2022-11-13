#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"

namespace sdds
{
   class Line : public LblShape
   {
      int m_length;

   public:
      Line();
      Line(const char* cString, int length);
      virtual ~Line() = default; //non implemented, do i need one?
      void getSpecs(std::istream& istr) override;
      void draw(std::ostream& ostr = std::cout)const override;

   };


}

#endif


























//
//class Line
//{
//   char* m_label;
//   int m_length;
//public:
//   void setEmpty();
//   void setToDefault();
//   void setLabel(const char* label);
//   void setLength(int length);
//   void set(const char* label, int length);
//   void getSpecs();
//   void draw() const;
//   void printLabel() const;
//   void printLength() const;
//   void print() const;
//   Line();
//   Line(const char* label, int length);
//   Line(const Line& L);
//   Line& operator=(const Line& L);
//   ~Line();
//};