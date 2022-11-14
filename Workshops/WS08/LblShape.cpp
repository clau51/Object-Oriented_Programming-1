#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"

namespace sdds
{
   const char* LblShape::label() const
   {
      return m_label;
   }
   
   //LblShape::LblShape()
   //{
   //   m_label = nullptr; //Don't need to do? m_label is already initialized to null
   //}

   LblShape::LblShape(const char* cString)
   {
      if (cString && cString[0])
      {
         m_label = new char[strlen(cString) + 1];
         strcpy(m_label, cString);
      }
      //else
      //{
      //   m_label = nullptr; //Already initialized to null (in the class)
      //}
   }
   
   LblShape::~LblShape()
   {
      delete[] m_label;
      m_label = nullptr;
   }

   void LblShape::getSpecs(std::istream& istr)
   {
      char label[50 + 1];
      istr.getline(label, 51, ',');

      delete[] m_label;      
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
   }
}







