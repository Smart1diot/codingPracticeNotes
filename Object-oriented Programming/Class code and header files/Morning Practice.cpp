#include <iostream>

class Calc
{
private:
	int m_value = 0;

public:
	Calc(int value=0); //Construct function

	Calc& add(int value); // add value function and return Calc obj
	Calc& sub(int value);
	Calc& mult(int value);

	int getValue() { return m_value; }
};

Calc::Calc(int value)
	: m_value{ value }
{}

Calc& Calc::add(int value) { m_value += value; return *this; } // Defining Calc add function outside of class
Calc& Calc::sub(int value) { m_value -= value; return *this; }
Calc& Calc::mult(int value) { m_value *= value; return *this; }

int main()
{
	Calc calc{ 0 };
	calc.add(5).sub(1).mult(2);

	std::cout << calc.getValue() << '\n';

	return 0;
}