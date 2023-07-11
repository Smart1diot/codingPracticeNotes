#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
	std::string m_name{};
	int m_age{};

public:
	Person(const std::string_view name = "", int age = 0)
		: m_name{ name },
		m_age{ age }
	{}

	const std::string& getName() const { return m_name; }
	int getAge() const { return m_age; }
};

//BaseballPlayer publicly inheritingn Person
class BaseballPlayer : public Person
{
private:
	double m_battingAverage{};
	int m_homeRuns{};

public:
	BaseballPlayer(const std::string_view name = "", int age = 0,
		double battingAverage = 0.0, int homeRuns = 0)
		: Person{ name,age }, // call Person(const std::string_view, int) to initialize these fields
		m_battingAverage{ battingAverage },
		m_homeRuns{ homeRuns }
	{
	}

	double getBattingAverage() const { return m_battingAverage; }
	int getHomeRuns() const { return m_homeRuns; }
};

int main()
{
	//making a baseball player
	BaseballPlayer pedro{ "Pedro Pascal", 48, 0.366, 42 };

	std::cout << pedro.getName() << '\n';
	std::cout << pedro.getAge() << '\n';
	std::cout << pedro.getBattingAverage() << '\n';
	std::cout << pedro.getHomeRuns() << '\n';


	return 0;
}//
