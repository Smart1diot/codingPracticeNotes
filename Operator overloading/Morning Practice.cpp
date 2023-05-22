#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents)
		: m_cents{ cents } {}

	int getCents() const { return m_cents; }

	// Cents operator+(const Cents& c1, const Cents& c2) - need to explicitly provide prototype for operator+ so uses of opperator+ in other files know this overload exists when not using friend functions
};

Cents operator+(const Cents& c1, const Cents& c2)
{
	return Cents{ c1.getCents() + c2.getCents()};
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };

	Cents centsSum{ cents1 + cents2 };

	std::cout << "I have " << centsSum.getCents() << " cents." << '\n';

	return 0;
}

//*NOTE* try to use normal functions more than friend functions