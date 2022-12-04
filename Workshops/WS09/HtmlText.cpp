#include "HtmlText.h"

using namespace std;
namespace sdds
{
   HtmlText::HtmlText(const char* title)
   {
      if (title)
      {
         m_title = ut.alcpy(title);
      }
   }

   HtmlText::HtmlText(const HtmlText& htmlText) : Text(htmlText)
   {
      m_title = ut.alcpy(htmlText.m_title);
   }

   HtmlText& HtmlText::operator=(const HtmlText& htmlText)
   {
      if (this != &htmlText)
      {
         if (htmlText)
         {
            Text::operator=(htmlText);
            delete[] m_title;
            m_title = nullptr;
            m_title = ut.alcpy(htmlText.m_title);
         }
      }

      return *this;
   }

   HtmlText::~HtmlText()
   {
      delete[] m_title;
   }

   ostream& HtmlText::write(ostream& ostr)const
   {
      //bool multipleSpaces = false;

      ostr << "<html><head><title>";

      if (m_title)
      {
         ostr << m_title;
      }
      else
      {
         ostr << "No Title";
      }
      ostr << "</title></head>\n<body>\n";


      if (m_title)
      {
         ostr << "<h1>" << m_title << "</h1>\n";
      }

      //Text::write(ostr);

      //bool ok = true;

      
      for (int i = 0; i < getLen(); i++)
      {         
         if ((*this)[i] == '<')
         {
            ostr << "&lt;";
         }
         else if ((*this)[i] == '>')
         {
            ostr << "&gt;";
         }
         else if ((*this)[i] == '\n')
         {
            ostr << "<br />\n";
         }
         else if (((*this)[i] == ' ' && (*this)[i - 1] == ' ') /*|| ((*this)[i] == ' ' && (*this)[i + 1] == ' ')*/)
         {
            ostr << "&nbsp;";
         }
         else if ((*this)[i])
         {
            ostr << (*this)[i];
         }
      }
      ostr << "</body>\n</html>";

      return ostr;
   }


}