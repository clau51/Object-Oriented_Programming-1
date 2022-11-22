//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 18, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Shape.h"

using namespace std;
namespace sdds
{
   //Insertion operator
   ostream& operator<<(ostream& ostr, const Shape& shape) //Shape = Line
   {
      shape.draw(ostr);
      return ostr;
   }

   //Extraction operator
   istream& operator>>(istream& istr, Shape& shape)
   {
      shape.getSpecs(istr);
      return istr;
   }
}