#include <cassert>
#include <iostream>

class Fraction
{
	int m_numerator;
	int m_denominator;

public:
	//Default constructor
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
		assert(denominator != 0);
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;

	return out;
}

int main()
{
	Fraction six = Fraction(6); // copy initialization 
	Fraction seven(Fraction(7));// same copy initialization
	std::cout << six;
	
	return 0;
}
//*Best Practice* 
// try to avoid using copy initialization 
//and use uniform initialization instead 
