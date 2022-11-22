//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 18, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_

#include <iostream>

namespace sdds
{
   //Shape is an interface
   class Shape
   {
   public:
      //Pure virtual function
      virtual void draw(std::ostream& ostr = std::cout)const = 0;

      //Pure virtual function
      virtual void getSpecs(std::istream& istr = std::cin) = 0;

      //Destructor
      virtual ~Shape() = default;
   };

   //Insertion operator
   std::ostream& operator<<(std::ostream& ostr, const Shape& shape);

   //Extraction operator
   std::istream& operator>>(std::istream& istr, Shape& shape);
}

#endif