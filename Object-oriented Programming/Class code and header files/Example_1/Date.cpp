#include <iostream>
#include "Date.h"

Date::Date() : m_month{ 1 }, m_day{ 1 }, m_year{ 1 } { std::cout << "Setting Up Default Date..." << '\n'; }

Date::Date(int month, int day, int year)
:	m_month{ month },
	m_day{day},
	m_year{year}
{
	std::cout << "Setting Up Date..." << '\n';
}

void Date::printInfo()
{
	std::cout << m_month << '/' << m_day << '/' << m_year << '\n';
}