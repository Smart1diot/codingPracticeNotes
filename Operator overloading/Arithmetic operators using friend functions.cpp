#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents)
		: m_cents{ cents } {}

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents& c1, const Cents& c2);

	int getCents() const { return m_cents; }
};

Cents operator+(const Cents& c1, const Cents& c2) // function that adds two classes together
{
	return c1.m_cents + c2.m_cents;
}

Cents operator-(const Cents& c1, const Cents& c2)
{
	return c1.getCents() - c2.getCents();
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 2 };
	Cents centsSum{ cents1 + cents2 }; // new class created with data added from two classes
	Cents centsSub{ cents1 - cents2 }; // new class created with data subtracted from two classes

	std::cout << "I have " << centsSum.getCents() << " cents.\n";
	std::cout << "I have " << centsSub.getCents() << " cents.\n";

	return 0;
}
//
