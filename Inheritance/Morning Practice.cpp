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
	//


	return 0;
}