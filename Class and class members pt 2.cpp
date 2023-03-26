// 3/26/2023 Class and class members pt 2 *NOTE Use struct for data only, and class for data + functions bundled
#include <iostream>
#include <string>

class Employee // example 1
{
public: 
	std::string m_name{};
	int m_id{};
	double m_wage{};

	// Print employee information to the screen
	void print()
	{
		std::cout << "Name: " << m_name <<
			"	ID: " << m_id <<
			"	Wage: $" << m_wage << '\n';
	}

	void x() { y(); }; // In member functions you can call a function withing a function that is futher down the code
	void y() {};
};



class SpecificDetailedEmployee // example 2
{
	using IDType = int; // nested type alias

	std::string name{};
	IDType id{};
	double wage{};
};

int main()
{
	// Declare two employees
	Employee alex{ "Alex", 1, 25.00 };
	Employee joe{ "Joe", 2, 22.25 };

	// Print out the employee information
	alex.print();
	joe.print();

	return 0;
}
