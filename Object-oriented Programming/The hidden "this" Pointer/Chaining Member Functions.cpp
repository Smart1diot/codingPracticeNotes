// using hidden "this" pointer to chain multiple class functions using the class itself
#include <iostream>

class Calc
{
private:
	int m_value{};

public:
	Calc& add(int value) { m_value += value; return *this; } //*this pointer returning the very class object itself 
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	int getValue() { return m_value; }
};

int main()
{
	Calc calc{};
	calc.add(5).sub(3).mult(4);

	std::cout << calc.getValue() << '\n';

	return 0;
}
