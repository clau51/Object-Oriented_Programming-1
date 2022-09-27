#include <iostream>
#include "CC.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	bool CC::validate(const char* name,
		unsigned long long cardNo,
		short cvv,
		short expMon,
		short expYear)const
	{
		long long minCard = 4000000000000000;
		long long maxCard = 4099999999999999;
		short minMonth = 1;
		short maxMonth = 12;
		short minCvv = 100;
		short maxCvv = 999;
		int ok = 0;

		/*if (name == nullptr || strlen(name) <= 2) ok++;
		if (cardNo < minCard || cardNo > maxCard) ok++;
		if (cvv < minCvv || cvv > maxCvv) ok++;
		if (expMon < minMonth || expMon > maxMonth) ok++;
		if (expYear < 22 || expYear > 32) ok++;
		return ok == 0;*/
		return (name != nullptr && strlen(name) > 2) &&
			(cardNo >= minCard && cardNo <= maxCard) &&
			(cvv >= minCvv && cvv <= maxCvv) &&
			(expMon >= minMonth && expMon <= maxMonth);
	}

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

	void CC::set()
	{
		m_name = nullptr;
		m_cvv = 0;
		m_expMonth = 0;
		m_expYear = 0;
		m_creditNo = 0;
	}

	void CC::cleanUp()
	{
		delete[] m_name;
		set();
	}

	bool CC::isEmpty() const
	{
		return m_name == nullptr;
	}

	void CC::set(const char* cc_name,
		unsigned long long cc_no,
		short m_cvv,
		short m_expMon,
		short m_expYear)
	{
		cleanUp();
		if (validate(cc_name, cc_no, m_cvv, m_expMon, m_expYear))
		{
			m_name = new char[strlen(cc_name) + 1];
			strcpy(m_name, cc_name);
			m_creditNo = cc_no;
			CC::m_cvv = m_cvv;
			m_expMonth = m_expMon;
			CC::m_expYear = m_expYear;
		}
	}

	bool CC::read()
	{
		char tempName[71 + 1];
		short tempCvv;
		short tempMonth;
		short tempYear;
		unsigned long long tempCredit;

		cleanUp();
		cout << "Card holder name: ";
		cin.getline(tempName, 71 + 1); //read up to 71 characters (discards new line)
		if (!cin.fail()) cout << "Credit card number: ";
		cin >> tempCredit;
		if (!cin.fail()) cout << "Card Verification Value (CVV): ";
		cin >> tempCvv;
		if (!cin.fail()) cout << "Expiry month and year (MM/YY): ";
		cin >> tempMonth;
		cin.ignore(1);
		cin >> tempYear;
		if (!cin.fail())
		{
			set(tempName, tempCredit, tempCvv, tempMonth, tempYear);
		}
		else
		{
			cin.clear();
		}
		cin.ignore(2000, '\n');

		return isEmpty() == false;
	}

	void CC::display(int row) const
	{
		if (isEmpty()) cout << "Invalid Credit Card Record" << endl;
		else
		{
			if (row > 0)
			{
				cout << "| ";
				cout.width(3);
				cout.setf(ios::right);
				cout << row;
				cout.unsetf(ios::right);
				cout << " | ";

				if ((strlen(m_name)) > 30)
				{
					char tempName[30 + 1]{};
					strcpy(tempName, m_name, 30);
					cout << tempName;
				}
				else
				{
					cout.width(30);
					cout.setf(ios::left);
					cout << m_name;
				}
				cout.unsetf(ios::left);
				cout << " | ";
				prnNumber();
				cout << " | ";
				cout << m_cvv;
				cout << " | ";
				cout.width(2);
				cout.setf(ios::right);
				cout << m_expMonth;
				cout.unsetf(ios::right);
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