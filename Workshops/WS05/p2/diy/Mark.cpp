#include "Mark.h"
#include <iostream>

namespace sdds
{
	Mark& Mark::setInvalid()
	{
		m_mark = -1;
		return *this;
	}

	Mark::Mark(int mark)
	{
		if (validate(mark))
		{
			m_mark = mark;
		}
		else
		{
			setInvalid();
		}
	}

	bool Mark::validate(int mark)const
	{
		return mark >= 0 && mark <= 100;
	}

	Mark::operator int()const
	{
		return validate(m_mark) ? m_mark : 0;
	}

	Mark::operator double()const
	{
		double gpa = 0.0;

		if (m_mark >= 50 && m_mark < 60)
		{
			gpa = 1.0;
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			gpa = 2.0;
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			gpa = 3.0;
		}
		else if (m_mark >= 80 && m_mark <= 100)
		{
			gpa = 4.0;
		}

		return gpa;
	}

	Mark::operator char()const
	{
		char gpa = 'X';

		if (m_mark >= 0 && m_mark < 50)
		{
			gpa = 'F';
		}
		else if (m_mark >= 50 && m_mark < 60)
		{
			gpa = 'D';
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			gpa = 'C';
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			gpa = 'B';
		}
		else if (m_mark >= 80 && m_mark <= 100)
		{
			gpa = 'A';
		}

		return gpa;
	}

	Mark::operator bool()const
	{
		return validate(m_mark);
	}

	bool Mark::operator==(const Mark& mark)const
	{
		return *this && mark ? m_mark == mark.m_mark : false;
	}

	bool Mark::operator!=(const Mark& mark)const
	{
		return *this && mark ? m_mark != mark.m_mark : false;
	}
	bool Mark::operator<(const Mark& mark)const
	{
		return *this && mark ? m_mark < mark.m_mark : false;

	}
	bool Mark::operator>(const Mark& mark)const
	{
		return *this && mark ? m_mark > mark.m_mark : false;

	}
	bool Mark::operator<=(const Mark& mark)const
	{
		return *this && mark ? m_mark <= mark.m_mark : false;

	}
	bool Mark::operator>=(const Mark& mark)const
	{
		return *this && mark ? m_mark >= mark.m_mark : false;
	}

	Mark& Mark::operator++()
	{
		int temp = m_mark;
		if (*this)
		{
			if (validate(++temp))
			{
				m_mark++;
			}
			else
			{
				setInvalid();
			}
		}

		return *this;
	}

	Mark Mark::operator++(int)
	{
		int temp = m_mark; //100
		Mark old = *this; //100
		if (*this) //if 100 is valid
		{
			if (validate(++temp)) // 101 is not valid
			{
				m_mark++;
			}
			else // set invalid;
			{
				setInvalid();
			}
		}

		return old;
	}

	Mark& Mark::operator--()
	{
		int temp = m_mark;
		if (*this)
		{
			if (validate(--temp))
			{
				m_mark--;
			}
			else
			{
				setInvalid();
			}
		}


		return *this;
	}

	Mark Mark::operator--(int)
	{
		int temp = m_mark;
		Mark old = *this;
		if (*this)
		{
			if (validate(--temp))
			{
				m_mark--;
			}
			else
			{
				setInvalid();
			}
		}

		return old;
	}

	bool Mark::operator~()
	{
		return *this && (m_mark >= 50) ? true : false;
	}

	Mark& Mark::operator=(int num)
	{
		m_mark = num;
		if (!(*this))
		{
			setInvalid();
		}

		return *this;
	}

	Mark& Mark::operator+=(int num) //what if it was initially valid, but adds past 100?
	{
		if (*this)
		{
			m_mark += num;
			if (!(*this))
			{
				setInvalid();
			}
		}

		return *this;
	}


	Mark& Mark::operator-=(int num) //can fix an invalid number or not?
	{

		if (*this)
		{
			m_mark -= num;
			if (!(*this))
			{
				setInvalid();
			}
		}

		return *this;
	}

	int Mark::getMark()const
	{
		return m_mark;
	}

	int& operator+=(int& num, const Mark& mark)
	{
		if (mark)
		{
			num += mark.getMark();
		}
		return num;
	}

	int& operator-=(int& num, const Mark& mark)
	{
		if (mark)
		{
			num -= mark.getMark();
		}
		return num;
	}

	Mark Mark::operator+(const Mark& mark)const
	{
		Mark temp = *this;
		temp.m_mark += mark.m_mark;

		if (!temp)
		{
			temp.setInvalid();
		}

		return temp;
	}

	Mark Mark::operator+(int num)const
	{
		Mark temp = *this;
		temp.m_mark += num;

		if (!temp)
		{
			temp.setInvalid();
		}

		return temp;
	}

	//unclear on instructions whether or not there are restrictions (ie. max number)
	int operator+(int& num, const Mark& mark) 
	{
		return num + mark.getMark();
	}

	Mark& Mark::operator<<(Mark& mark)
	{
		m_mark += mark.m_mark;
		mark.m_mark = 0;

		if (!mark)
		{
			mark.setInvalid();
		}

		return *this;
	}

	Mark& Mark::operator>>(Mark& mark)
	{

		mark.m_mark += m_mark;
		m_mark = 0;

		if (!mark)
		{
			mark.setInvalid();
		}

		return *this;
	}
}

