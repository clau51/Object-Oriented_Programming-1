#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {


   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   } 

   Numbers::Numbers(const char* filename) {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      //m_numCount = numberCount();
      //if (m_numCount == 0 || !load()) {
      //   deallocate();
      //   setEmpty();
      //   m_isOriginal = false; 
      //}
   }

   //Numbers N = "hello.txt";
//N = "bello.txt";

   Numbers::Numbers(const Numbers& num)
   {
       if (this != &num) {
           setEmpty();
           if (this != &num) {
               m_numbers = new double[num.m_numCount];
               for (int i = 0; i < num.m_numCount; i++) {
                   m_numbers[i] = num.m_numbers[i];
               }
               m_filename = new char[strlen(num.m_filename) + 1];
               strcpy(m_filename, num.m_filename);
               m_isOriginal = num.m_isOriginal;
               m_numCount = num.m_numCount;
           }
       }
   }



   Numbers::~Numbers() {
      //save();
      deallocate();
   }

   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

  

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if(!isEmpty()) {
         maxVal = m_numbers[0];
         for(int i = 1; i < m_numCount; i++)
            if(maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
  
   Numbers& Numbers::operator=(const char* cstring) {
       delete[] m_filename;
       m_filename = nullptr;
       if (cstring) {
           m_filename = new char[strlen(cstring) + 1];
           strcpy(m_filename, cstring);
       }
       return *this;
   }

}
