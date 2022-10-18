#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds
{
	class Mark
	{
	private:
		int m_mark;
		bool validate(int mark)const;
	public:
		Mark(int mark = 0);
		Mark& setInvalid();

		operator int()const;
		operator double()const;
		operator char()const;
		operator bool()const;

		bool operator==(const Mark& mark)const;
		bool operator!=(const Mark& mark)const;
		bool operator<(const Mark& mark)const;
		bool operator>(const Mark& mark)const;
		bool operator<=(const Mark& mark)const;
		bool operator>=(const Mark& mark)const;

		Mark& operator++();
		Mark operator++(int);
		Mark& operator--();
		Mark operator--(int);
		bool operator~();

		Mark& operator=(int num);
		Mark& operator+=(int num);
		Mark& operator-=(int num);

		int getMark()const;

		Mark operator+(const Mark& mark)const;
		Mark operator+(int num)const;
		Mark& operator<<(Mark& mark);
		Mark& operator>>(Mark& mark);
	};

	int& operator+=(int& num, const Mark& mark);
	int& operator-=(int& num, const Mark& mark);
	int operator+(int& num, const Mark& mark);
}

#endif