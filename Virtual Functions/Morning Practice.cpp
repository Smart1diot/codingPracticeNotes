#include <iostream>
#include <string_view>
#include <string>

class Base
{
protected:
	int m_value{};

public:
	Base(int value)
		: m_value{value}
	{}

	std::string_view getName() const { return "Base"; }
	int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{value}
	{}

	std::string_view getName() const { return "Derived"; }
	int getValueDoubled() const { return m_value * 2; }
};

int main()
{
	Derived derived{ 5 };

	//These are both legal
	Base& rBase{ derived }; 
	Base* pBase{ &derived };

	std::cout << "derived is a " << derived.getName()
		<< " and has value " << derived.getValue() << '\n';

	std::cout << "rBase is a " << rBase.getName()
		<< " and has value " << rBase.getValue() << '\n';

	std::cout << "pBase is a " << pBase->getName()
		<< " an has value " << pBase->getValue() << '\n';

	return 0;
}//