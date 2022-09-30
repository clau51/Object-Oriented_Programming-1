//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 30, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CC_H_
#define SDDS_CC_H_
namespace sdds
{
	struct CC
	{
	private:
		char* m_name;
		short m_cvv;
		short m_expMonth;
		short m_expYear;
		unsigned long long m_creditNo;

		//Validate credit card information
		bool validate(const char* name,
			unsigned long long cardNo,
			short cvv,
			short expMon,
			short expYear)const;

		//Print 16-digit number in a set of 4-digit numbers seperated by spaces
		void prnNumber()const;
		
	public:
		//Sets object to safe empty state
		void set();
		
		//Deallocate cardholder's name and sets object to safe empty state
		void cleanUp();
		
		//Returns true if object is in safe empty state
		bool isEmpty() const;

		//Sets object to values if data is valid
		void set(const char* cc_name,
			unsigned long long cc_no,
			short m_cvv,
			short m_expMon,
			short m_expYear);

		//Read values from console if data is valid and return true if values are stored in object successfully
		bool read();
		
		//Display formatted credit card information
		void display(int row = 0) const;
	};
}
#endif // !SDDS_CC_H_