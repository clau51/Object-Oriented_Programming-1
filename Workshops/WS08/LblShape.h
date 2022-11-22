//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: November 18, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"

namespace sdds
{
   class LblShape : public Shape
   {
      char* m_label{};

      //Allocate and copy m_label
      LblShape& alAndCp(const char* str);

   protected:
      //Deallocate memory for m_label
      LblShape& deallocate();

      //Returns m_label
      const char* label()const;

   public:
      //Check if object is valid;
      operator bool()const;

      //Default constructor
      LblShape() = default;

      //One argument constructor (receives a string)
      LblShape(const char* cString);

      //Prevent copying to an object of the same class
      LblShape(const LblShape& LblShape) = delete;

      //Prevent assigning to an object of the same class
      LblShape& operator=(const LblShape& LblShape) = delete;

      //Destructor: Deallocates m_label
      ~LblShape() override;

      //Reads a comma delimited string
      void getSpecs(std::istream& istr = std::cin) override;
   };

   //Helper: read an int
   bool readInt(char delimiter, int& member, std::istream& istr = std::cin);

   //Print a character a number of times
   std::ostream& printChar(char character, int num, std::ostream& ostr = std::cout);
}

#endif
