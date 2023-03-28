#include <iostream>

class DateClass // members are private by default
{
	int m_month{};	// private by default, can only be accessed by other members
	int m_day{};	// private by default, can only be accessed by other members
	int m_year{};	// private by default, can only be accessed by other members

public:
	void setDate(int month, int day, int year) // public, can be accessed by anyone // using values tossed in to set date
	{
		// **NOTE IMPORTANT
		//setDate() can access the private members of the class because it is a member of the class itself
		m_month = month;
		m_day = day;
		m_year = year;
	}

	void print() // public, can be accessed by anyone
	{
		std::cout << m_month << '/' << m_day << '/' << m_year << '\n';
	}

};

int main()
{
	DateClass date;
	date.setDate(3, 28, 2023);	// okay, because setDate() is public // We toss our own values to fuck around with
	date.print();				// okay, because print() is public
	std::cout << '\n';

	return 0;
}