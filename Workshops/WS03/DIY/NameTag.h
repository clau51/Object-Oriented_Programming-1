//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: October 3, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_

namespace sdds
{
	const int MAX_NAME_LEN = 50;

	struct NameTag
	{
	private:
		char m_name[MAX_NAME_LEN + 1];
		bool validate(const char* name)const;

	public:
		
		void print()const;
		void set(const char* name);
		int length()const;
	};
}


#endif