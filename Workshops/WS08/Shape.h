#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_

#include <iostream>

namespace sdds
{
   class Shape
   {
      virtual void draw(std::ostream& ostr = std::cout)const = 0;
      virtual void getSpecs(std::istream& istr = std::cin) = 0;
   public:
      virtual ~Shape() = default;
      friend std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
      friend std::istream& operator>>(std::istream& istr, Shape& shape);

   };

   std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
   std::istream& operator>>(std::istream& istr, Shape& shape);

}

#endif