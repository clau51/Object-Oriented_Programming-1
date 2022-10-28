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

   //One argument constructor: receives a filename and loads double values from the file
   Numbers::Numbers(const char* filename) //Numbers n = "file.txt"
   {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename); //Before assigning the filename, delete dynamic memory allocated for the file
      m_numCount = numberCount(); //Count number of doubles in the file
      if (m_numCount == 0 || !load()) //If not successful (load allocates dynamic memory to m_numbers)
      {
         deallocate();
         setEmpty();
         m_isOriginal = false; //Set object to not original
      }
   }

   //Copy constructor: copy from another object of the same type into current object
   Numbers::Numbers(const Numbers& obj) //Number N = M 
   {
      //Number M;
      //Number N = M;
      //N = M (operator=)
      setEmpty();
      m_isOriginal = false;
      *this = obj;

   }

   Numbers& Numbers::operator=(const Numbers& obj)
   {
      if (this != &obj)
      {
         deallocate();
         setEmpty();

         m_numbers = new double[obj.m_numCount];
         for (int i = 0; i < obj.m_numCount; i++)
         {
            m_numbers[i] = obj.m_numbers[i];
         }
         setFilename(obj.m_filename);
         m_isOriginal = false;
         m_numCount = obj.m_numCount;
      }
      return *this;
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
            fileout.setf(ios::fixed);
            fileout.precision(2);
            fileout << m_numbers[i] << endl;
         }
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
      bool ok = false;
      if (m_filename)
      {
         ifstream filein(m_filename); //Make object called filein
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
               else
               {
                  filein.clear();
                  filein.ignore(1000, '\n');
               }
            }
         }
      }
      return ok;
   }

   int Numbers::numberCount() const
   {
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

   Numbers& Numbers::sort(bool ascending)
   {
      int i, j;
      double temp;

      if (ascending)
      {
         for (i = m_numCount - 1; i > 0; i--)
         {
            for (j = 0; j < i; j++)
            {
               if (m_numbers[j] > m_numbers[j + 1])
               {
                  temp = m_numbers[j];
                  m_numbers[j] = m_numbers[j + 1];
                  m_numbers[j + 1] = temp;
               }
            }
         }
      }
      else if (!ascending)
      {
         for (i = m_numCount - 1; i > 0; i--)
         {
            for (j = 0; j < i; j++)
            {
               if (m_numbers[j] < m_numbers[j + 1])
               {
                  temp = m_numbers[j];
                  m_numbers[j] = m_numbers[j + 1];
                  m_numbers[j + 1] = temp;
               }
            }
         }
      }
      return *this;
   }

   Numbers Numbers::operator-() const
   {
      Numbers temp = *this;
      return Numbers(temp.sort(false));
   }

   Numbers Numbers::operator+() const
   {
      Numbers temp = *this;
      return Numbers(temp.sort(true));
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
         }
         else
         {
            ostr << "*** COPY ***" << endl;
         }

         for (int i = 0; i < m_numCount; i++)
         {

            if (i != m_numCount - 1)
            {
               ostr.setf(ios::fixed);
               ostr.precision(2);
               ostr << m_numbers[i] << ", ";
            }
            else
            {
               ostr << m_numbers[i] << endl;
            }
         }
         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << max() << endl;
         ostr << "Smallest number: " << min() << endl;
         ostr << "Average:         " << average() << endl;
         ostr << "=========================";
         ostr.unsetf(ios::fixed);
         ostr.precision(6);
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
