#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"

namespace sdds
{
   class LblShape : public Shape
   {
      char* m_label{};

   protected:
      const char* label()const;

   public:
      LblShape();
      LblShape(const char* cString);
      LblShape(const LblShape& LblShape) = delete;
      LblShape& operator=(const LblShape& LblShape) = delete;
      ~LblShape() override;
      void getSpecs(std::istream& istr) override;
   };
}

#endif











//LblShape();
//LblShape(const char* label);
//LblShape(const LblShape& src);
//LblShape& operator=(const LblShape& src);
//virtual ~LblShape();
//void getSpecs(std::istream& is);
//virtual void draw(std::ostream& os)const = 0;
//virtual void getSpecs(std::istream& is) = 0;