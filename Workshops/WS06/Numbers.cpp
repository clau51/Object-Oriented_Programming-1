#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds
{


   Numbers::Numbers()
   {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename)
   {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) //If not successful
      {
         deallocate();
         setEmpty();
         m_isOriginal = false; //Set object to not original
      }
   }

   //Numbers N = "add.txt";
//N = "bello.txt";

   //Create a copy constructor that sets the object to a safe empty state.
   //Sets the object NOT to be original.
   //Assigned the current object to the Numbers object that is being copied (calls the Copy Assignment Operator).

   Numbers::Numbers(const Numbers& num)
   {
      m_isOriginal = false;
      if (this != &num)
      {
         setEmpty();
         if (this != &num)
         {
            m_numbers = new double[num.m_numCount];
            for (int i = 0; i < num.m_numCount; i++)
            {
               m_numbers[i] = num.m_numbers[i];
            }
            m_filename = new char[strlen(num.m_filename) + 1];
            strcpy(m_filename, num.m_filename);
            m_isOriginal = num.m_isOriginal;
            m_numCount = num.m_numCount;
         }
      }

   }


   Numbers::~Numbers()
   {
      save();
      deallocate();
   }

   void Numbers::save()
   {
      if (m_isOriginal && m_numbers)
      {
         ofstream fileout(m_filename);
         for (int i = 0; i < m_numCount; i++)
         {
            fileout << m_numbers[i] << endl;
         }
         //fileout.close();
      }
   }

   bool Numbers::isEmpty() const
   {
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty()
   {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate()
   {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename)
   {
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }



   double Numbers::average() const
   {
      double aver = 0.0;
      if (!isEmpty())
      {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const
   {
      double minVal = 0.0;
      if (!isEmpty())
      {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const
   {
      double maxVal = 0.0;
      if (!isEmpty())
      {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   Numbers& Numbers::operator=(const char* cstring)
   {
      delete[] m_filename;
      m_filename = nullptr;
      if (cstring)
      {
         m_filename = new char[strlen(cstring) + 1];
         strcpy(m_filename, cstring);
      }
      return *this;
   }

   bool Numbers::load()
   {
      //save();
      bool ok = false;
      if (m_filename)
      {
         ifstream filein(m_filename);
         if (filein)
         {
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount && filein; i++)
            {
               filein >> m_numbers[i];
               if (filein)
               {
                  ok = true;
               }
            }
         }
      }
      return ok;
   }

   int Numbers::numberCount() const
   {
      //save();
      int count = 0;
      if (m_filename)
      {
         ifstream filein(m_filename);
         if (filein)
         {
            char ch;
            while (filein.get(ch))
            {
               if (ch == '\n')
               {
                  count++;
               }
            }
         }
      }
      return count;
   }

   std::ostream& Numbers::display(std::ostream& ostr)const
   {
      if (m_numbers == nullptr)
      {
         ostr << "Empty list";
      }
      else
      {
         ostr << "=========================" << endl;
         if (m_isOriginal)
         {
            ostr << m_filename << endl;
            for (int i = 0; i < m_numCount; i++)
            {
               if (i != m_numCount - 1)
               {
                  ostr << m_numbers[i] << ", ";
               }
               else
               {
                  ostr << m_numbers[i] << endl;
               }
            }
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number: " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average: " << average() << endl;
            ostr << "=========================";
         }
         else
         {
            ostr << "*** COPY ***" << endl;
         }
      }
      return ostr;
   }

   Numbers& Numbers::operator+=(double num)
   {
      double* temp = new double[m_numCount + 1]; // 0 1 2 3 4 5 (6)
      for (int i = 0; i < m_numCount; i++) // 0 1 2 3 4 (5)
      {
         temp[i] = m_numbers[i];
      }
      m_numCount++; // 0 1 2 3 4 5 (6)
      temp[m_numCount - 1] = num; // 0 1 2 3 4 5 (6)
      delete[] m_numbers;
      m_numbers = temp;

      return *this;
   }


   ostream& operator<<(ostream& os, const Numbers& N)
   {
      N.display(os);
      return os;
   }

   istream& operator>>(istream& istr, Numbers& N)
   {
      double num;
      istr >> num;
      if (istr)
      {
         N += num;
      }
      return istr;
   }

}
