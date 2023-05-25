#include <iostream>

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) : m_digit{ digit } {}

	Digit& operator++();
	Digit& operator--();

	friend std::ostream& operator<<(std::ostream& out, const Digit& d);
};

Digit& Digit::operator++() //returns the class itself with 1 increment change
{
	++m_digit;
	return *this;
}

Digit& Digit::operator--() //returns the class itself with 1 decrement change
{
	--m_digit;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Digit& d) // just prints the current digit in selected class
{
	out << d.m_digit << '\n';
	return out;
}

int main()
{
	Digit digit{ 8 }; // we establish an object digit with digit value 8

	std::cout << digit;		//prints 8
	std::cout << ++digit;	//prints 9
	std::cout << ++digit;	//prints 10
	std::cout << --digit;	//prints 9
	std::cout << --digit;	//prints 8

	return 0;
}
//