// 3/26/2023 Classes and class members pt 1
#include <iostream>

struct DateStruct
{
	int year{};
	int month{};
	int day{};
};

class DateClass // Class similar as struct with only difference is the "public:"
{
public:
	int m_year{};
	int m_month{};
	int m_day{};

	void print() // defines a member function named print() within the class
	{
		std::cout << m_year << '/' << m_month << '/' << m_day; // We are only able to access members within the class
	}
};

void print(const DateStruct& date)
{
	std::cout << date.year << '/' << date.month << '/' << date.day;
}

int main()
{
	DateStruct today{ 2020,10,14 }; // use information initialization
	DateClass realToday{ 2023,3,26 }; // declare a variable of class DateClass

	today.day = 16; //use member selection operator to select a member of the struct

	print(today); //print function using struct

	std::cout << '\n';

	realToday.print(); //print function accessed through class struct 

	

	return 0;
}