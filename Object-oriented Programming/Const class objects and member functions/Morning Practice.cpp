#include <iostream>

class Something
{
public:
	int m_value{};

	Something() : m_value{} {}

	void resetValue() { m_value = 0; }
	void setValue(int value) { m_value = value; }

	int getValue() const; // const get value function
};

int Something::getValue() const { return m_value; } //defined const getValue function 

int main()
{
	const Something something{}; //calls default constuctor on const class
	
	std::cout << something.getValue() << '\n'; // cant use getValue() till defined function is also const

	return 0;
}

//*NOTES*
//Make any member function that does not modify the state of the class
//object const, so that it can be called by const objects.