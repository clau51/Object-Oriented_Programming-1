#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
       double* m_numbers{}; //holds the adress of the dynamic array of doubles holding the number collection
       char* m_filename{}; //holds the name of the file associated with the class (if it is the original object and not a copy)
      bool m_isOriginal; //true if this object is the original (and not a copy)
      int m_numCount; //holds the number of values in the m_number dynamic array
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& num);
      Numbers& operator=(Numbers& obj);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();
      Numbers& operator=(const char* cstring);
      bool load();
      int numberCount()const;
      Numbers& sort(bool ascending);
      Numbers operator-()const;
      Numbers operator+()const;
      std::ostream& display(std::ostream& ostr = std::cout)const;
      Numbers& operator+=(double num);
      void save();
   };
      std::ostream& operator<<(std::ostream& os, const Numbers& N);
      std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

