#include <iostream>

class Base
{
private:
	int m_id{};

public:
	Base(int id = 0)
		: m_id{ id }
	{
	}

	int GetId() const { return m_id; }
};

class Derived : public Base
{
private:
	double m_cost{};

public:
	Derived(double cost = 0.0, int id=0)
		:	Base{id}, // Call Base(int) constructor with value id
			m_cost{ cost }
	{
	}

	double getCost() const { return m_cost; }
};

int main()
{
	Base base{ 6 }; // use Base(int) constructor

	Derived derived{ 1.3, 5}; // use Derived(double, int) constructor

	std::cout << "ID: " << derived.GetId() << '\n';
	std::cout << "Cost: " << derived.getCost() << '\n';

	return 0;
}
//
