#include <iostream>

class Value
{
private:
	int m_value{};

public:
	Value(int value)
		: m_value{ value } {}

	friend bool isEqual(const Value& value1, const Value& value2); // now we are homies
};

bool isEqual(const Value& value1, const Value& value2) // random function thats homies with Value class
{
	return (value1.m_value == value2.m_value);
}

int main()
{
	Value v1{ 5 };
	Value v2{ 6 };
	// now we can access private members within the Value class in any function thats a friend
	std::cout << std::boolalpha << isEqual(v1, v2) << '\n'; 

	return 0;
}
