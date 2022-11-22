//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 18, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"

namespace sdds
{
   class Line : public LblShape
   {
      int m_length{};
      
      //Set the whole object to a safe empty state
      Line& setEmpty();
   public:

      //Default constructor
      Line() = default;

      //Two argument constructor: receives a string and int
      Line(const char* cString, int length);

      //Override: reads comma-separated Line from istream
      void getSpecs(std::istream& istr) override;

      //Override: draws the line
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