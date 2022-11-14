#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_

#include <iostream>

namespace sdds
{
   class Shape
   {
      //Public or private?
   public:
      virtual void draw(std::ostream& ostr = std::cout)const = 0;
      virtual void getSpecs(std::istream& istr = std::cin) = 0;
      virtual ~Shape() = default; //Why does this have to be public?
      //friend std::ostream& operator<<(std::ostream& ostr, const Shape& shape); //need this if draw private
      //friend std::istream& operator>>(std::istream& istr, Shape& shape); //need this if getSpecs private
   };

   std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
   std::istream& operator>>(std::istream& istr, Shape& shape);

}

#endif