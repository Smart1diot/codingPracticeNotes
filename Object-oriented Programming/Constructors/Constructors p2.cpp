#include <iostream>
#include <cassert>

class Date
{
private: 
	int m_year{ 1900 };
	int m_month{ 1 };
	int m_day{ 1 };

public: 
	//Tell the compiler to create a default consntructor, even if
	//there are other user-provided constructors.
	Date() = default;// "= default" can also be used to default to nothing for non static member initialization

	Date(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
};

int main()
{
	Date date{}; // date is initialized to Jan 1st, 1900
	Date today{ 2023,4,2 }; // today is initialized to April 2nd, 2023

	return 0;
}
