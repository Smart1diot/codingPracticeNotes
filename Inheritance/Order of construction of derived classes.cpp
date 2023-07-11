#include <iostream>

class Chicken
{
public:
	int m_id{};

	Chicken(int id = 0)
		: m_id{ id }
	{
		std::cout << "Base\n";
	}

	int getID() const { return m_id; }
};

class Egg : public Chicken
{
public:
	double m_cost{};

	Egg(double cost = 0.0)
		: m_cost{ cost }
	{
		std::cout << "Derived\n";
	}

	double getCost() const { return m_cost; }
};

int main()
{
	Chicken base;
	
	Egg derived;

	return 0;
}
//
