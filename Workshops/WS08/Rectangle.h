//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 18, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"


namespace sdds
{
   class Rectangle : public LblShape
   {
      int m_width{};
      int m_height{};

      //Set whole object empty
      Rectangle& setEmpty();

   public:

      //Default constructor
      Rectangle();

      //Three argument constructor: receives label, width, height
      Rectangle(const char* label, int width, int height);

      //Override: Read comma-separated Rectangle from istream
      void getSpecs(std::istream& istr) override;

      //Override: draws the rectangle
      void draw(std::ostream& ostr = std::cout)const override;
   };

}

#endif

