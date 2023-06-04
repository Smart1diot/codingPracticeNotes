#include <iostream>

void printInt(int value)
{
	std::cout << value;
}

class Cents
{
private:
	int m_cents;
public:
	Cents(int cents = 0)
		: m_cents{ cents } {}

	//overloaded int cast
	operator int() const { return m_cents; } // method to convert class Cents to int type

	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents = cents; }
};

int main()
{
	Cents cents{ 7 };
	printInt(cents); // print 7

	std::cout << '\n';

	return 0;
}
