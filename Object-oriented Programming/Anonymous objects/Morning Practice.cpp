#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents)
		: m_cents{ cents } {}

	int getCents() const
	{
		return m_cents;
	}
};

Cents add(const Cents& c1, const Cents& c2)
{
	//return anonymous Cents value
	return {c1.getCents() + c2.getCents()};
}

int main()
{
	std::cout << "I have " << add(Cents{ 5 }, Cents{ 3 }).getCents() <<
		" cents\n"; // prints anonymous Cents value

	return 0;
}

// *NOTE* anonymous objects exist temporarily 