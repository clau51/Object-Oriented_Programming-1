#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_

#include <iostream>
#include "Text.h"
#include "Utils.h"

namespace sdds
{
   class HtmlText : public Text
   {
      char* m_title{};
   protected:
      
   public:
      HtmlText(const HtmlText& htmlText);
      HtmlText(const char* title = nullptr);
      HtmlText& operator=(const HtmlText& htmlText);
      virtual ~HtmlText();
      std::ostream& write(std::ostream& ostr = std::cout)const override;
      operator bool()const override
      {
         return m_title != nullptr;
      }

      void lol()
      {
         std::cout << (*this)[0] << std::endl;
      }
   };

   //std::ostream& operator<<(std::ostream& ostr, HtmlText& htmlText)
   //{
   //   return htmlText.write(ostr);
   //}

}

#endif