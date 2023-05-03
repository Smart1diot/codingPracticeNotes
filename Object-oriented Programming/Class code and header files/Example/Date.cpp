#include <iostream>
#include "Date.h"

//Date Constructor
Date::Date(int year, int month, int day)
{
	setDate(year, month, day);
}

void Date::setDate(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

int main()
{
	Date date{ 2023,05,02 };
	std::cout << date.getMonth() << '/' << date.getDay() << '/' << date.getYear() << '\n';

	return 0;
}