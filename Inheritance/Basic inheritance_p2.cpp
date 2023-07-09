#include <string>
#include <string_view>
#include <iostream>

class Person
{
	//We're making our members public for simplicity
public:
	std::string m_name{};
	int m_age{};

	Person(std::string_view name = "", int age = 0) :
		m_name{ name }, m_age{ age }
	{
	}

	const std::string& getName() const { return m_name; }
	int getAge() const { return m_age; }
};



//BaseballPplayer publicly inheriting Person with keyword public
class BaseballPlayer : public Person 
{
public:
	double m_battingAverage{};
	int m_homeRuns{};

	BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0) :
		m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
	{
	}
};

//Employee publicly inherits from Person
class Employee : public Person
{
public:
	double m_hourlySalary{};
	long m_employeeID{};

	Employee(double hourlySalary, long employeeID = 0)
		: m_hourlySalary{ hourlySalary }, m_employeeID{ employeeID }
	{
	}

	void printNameAndSalary() const
	{
		std::cout << m_name << ": " << m_hourlySalary << '\n';
	}
};

//Supervisor inherits the functions and variables from both
//Employee and Person and add their own m_overseesIDs member variable
class Supervicor : public Employee
{
public:
	//This Supervisor can oversee a max of 5 employees
	long m_overseesIDs[5]{};
};


int main()
{
	//create a new BaseballPlayer object
	BaseballPlayer joe{};
	//Assign it a name (we can do this directly because m_name is public)
	joe.m_name = "Joe";
	//print out the name
	std::cout << joe.getName() << '\n';
	//use the getName() function we've aquired from the Person 
	//base class
	std::cout << '\n';

	Employee frank{ 20.25, 12345 };
	frank.m_name = "Frank"; // we can do this because m_name is public
	frank.printNameAndSalary();
	//


	return 0;
}
