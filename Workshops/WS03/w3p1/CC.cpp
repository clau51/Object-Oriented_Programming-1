//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 30, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "CC.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	const int MAX_NAME_LEN = 70;

	//Validate credit card information
	bool CC::validate(const char* name,
		unsigned long long cardNo,
		short cvv,
		short expMon,
		short expYear)const
	{
		unsigned long long minCard = 4000000000000000;
		unsigned long long maxCard = 4099999999999999;
		short minMonth = 1;
		short maxMonth = 12;
		short minYear = 22;
		short maxYear = 32;
		short minCvv = 100;
		short maxCvv = 999;

		return (name != nullptr && sdds::strlen(name) > 2) &&
			(cardNo >= minCard && cardNo <= maxCard) &&
			(cvv >= minCvv && cvv <= maxCvv) &&
			(expMon >= minMonth && expMon <= maxMonth) &&
			(expYear >= minYear && expYear <= maxYear);
	}

	//Print 16-digit number in a set of 4-digit numbers seperated by spaces
	void CC::prnNumber()const
	{
		cout.width(4);
		cout.fill('0');
		cout << m_creditNo / 1000000000000 << " ";
		cout.width(4);
		cout << m_creditNo % 1000000000000 / 100000000 << " ";
		cout.width(4);
		cout << m_creditNo % 100000000 / 10000 << " ";
		cout.width(4);
		cout << m_creditNo % 10000;
		cout.fill(' ');
	}

	//Sets object to safe empty state
	void CC::set()
	{
		m_name = nullptr;
		m_cvv = 0;
		m_expMonth = 0;
		m_expYear = 0;
		m_creditNo = 0;
	}

	//Deallocate cardholder's name and sets object to safe empty state
	void CC::cleanUp()
	{
		delete[] m_name;
		set();
	}

	//Returns true if object is in safe empty state
	bool CC::isEmpty() const
	{
		return m_name == nullptr;
	}

	//Sets object to values if data is valid
	void CC::set(const char* cc_name,
		unsigned long long cc_no,
		short m_cvv,
		short m_expMon,
		short m_expYear)
	{
		cleanUp();
		if (validate(cc_name, cc_no, m_cvv, m_expMon, m_expYear))
		{
			m_name = new char[sdds::strlen(cc_name) + 1];
			sdds::strcpy(m_name, cc_name);
			m_creditNo = cc_no;
			CC::m_cvv = m_cvv;
			m_expMonth = m_expMon;
			CC::m_expYear = m_expYear;
		}
	}

	//Read values from console if data is valid and return true if values are stored in object successfully
	bool CC::read()
	{
		char tempName[MAX_NAME_LEN + 1];
		short tempCvv;
		short tempMonth;
		short tempYear;
		unsigned long long tempCredit;

		cleanUp();
		cout << "Card holder name: ";
		cin.getline(tempName, MAX_NAME_LEN + 1);
		if (!cin.fail()) cout << "Credit card number: ";
		cin >> tempCredit;
		if (!cin.fail()) cout << "Card Verification Value (CVV): ";
		cin >> tempCvv;
		if (!cin.fail()) cout << "Expiry month and year (MM/YY): ";
		cin >> tempMonth;
		cin.ignore(1);
		cin >> tempYear;
		if (!cin.fail()) set(tempName, tempCredit, tempCvv, tempMonth, tempYear);
		else cin.clear();
		cin.ignore(2000, '\n');

		return isEmpty() == false;
	}

	//Display formatted credit card information
	void CC::display(int row) const
	{
		if (isEmpty()) cout << "Invalid Credit Card Record" << endl;
		else
		{
			if (row > 0)
			{
				//Print row number
				cout << "| ";
				cout.width(3);
				cout.setf(ios::right);
				cout << row;
				cout.unsetf(ios::right);
				cout << " | ";

				//If name is longer than 30 characters, print only the first 30 characters
				if ((sdds::strlen(m_name)) > 30)
				{
					char tempName[30 + 1];
					sdds::strcpy(tempName, m_name, 30);
					cout << tempName;
				}
				//Else print the whole name
				else
				{
					cout.width(30);
					cout.setf(ios::left);
					cout << m_name;
				}
				cout.unsetf(ios::left);
				
				//Print credit card number
				cout << " | ";
				prnNumber();
				cout << " | ";

				//Print CVV code
				cout << m_cvv;
				cout << " | ";
				
				//Print expiry month
				cout.width(2);
				cout.setf(ios::right);
				cout << m_expMonth;
				cout.unsetf(ios::right);

				//Print expiry year
				cout << "/" << m_expYear << " |" << endl;
			}
			else if (row <= 0)
			{
				cout << "Name: " << m_name << endl;
				cout << "Creditcard No: ";
				prnNumber();
				cout << endl;
				cout << "Card Verification Value: " << m_cvv << endl;
				cout << "Expiry Date: " << m_expMonth << "/" << m_expYear << endl;
			}
		}
	}
}

//int main
// CC cc{};
// cc.set();