#pragma once
class Date
{
private:
	int m_month{};
	int m_day{};
	int m_year{};

public:
	Date(); // Should define default in header

	Date(int month, int day, int year);

	void printInfo();
};
