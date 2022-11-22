#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Text.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
   unsigned Text::getFileLength(istream& is)
   {
      unsigned len{};
      if (is)
      {
         // save the current read position
         std::streampos cur = is.tellg();
         //go to the end
         is.seekg(0, ios::end);
         // tell what is the positions (end position = size)
         len = unsigned(is.tellg());
         // now go back to where you were.
         is.seekg(cur);

      }
      return len;
   }

   const char& Text::operator[](int index)const
   {
      return m_content[index];
   }

   Text& Text::deallocate()
   {
      delete[] m_content;
      m_content = nullptr;

      return *this;
   }

   //Text x();
   //x = carmen //already existing item, to assign to another existing item
   Text& Text::operator=(const Text& text)
   {
      if (this != &text)
      {
         if (text)
         {
            delete[] m_content;
            m_content = nullptr;
            m_content = ut.alcpy(text.m_content);
            m_len = text.m_len; //testing
         }

      }

      return *this;
   }

   Text::Text(const Text& text) // Text x(carmen);
   {
      operator= (text);
   }

   Text::~Text()
   {
      delete[] m_content;
   }

   istream& Text::read(istream& istr)
   {
      int tempLen;
      char* tempContent = nullptr;
      char character;
      int counter = 0;

      deallocate();
      tempLen = getFileLength(istr);
      tempContent = new char[tempLen + 1];
      for (int i = 0; i < tempLen; i++)
      {
         character = istr.get();
         if (character != EOF)
         {
            tempContent[i] = character;
            counter++;
         }
      }
      tempContent[counter] = '\0';

      m_len = counter;
      m_content = new char[counter + 1];
      std::strcpy(m_content, tempContent);

      delete[] tempContent;
      return istr;
   }

      //for (int i = 0; i < counter; i++)
      //{
      //   m_content[i] = tempContent[i];
      //}

      //m_content[counter] = '\0';

      //if (m_content[0] != '\0')
      //{
      //   istr.clear(); //not sure if this is what we're supposed to do
      //}

   ostream& Text::write(ostream& ostr)const
   {
      if (*this)
      {
         ostr << m_content;
      }

      return ostr;
   }

   istream& operator>>(istream& istr, Text& text)
   {
      return text.read(istr);
   }

   ostream& operator<<(ostream& ostr, const Text& text)
   {
      return text.write(ostr);
   }

   Text::operator bool()const
   {
      return m_content;
   }
}