#include <iostream>
#include <cassert>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction() // default constructor gets called if no user-provided initialization values are provided
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	//Constructor with two parameters, one parameter having a default value
	Fraction(int numerator, int denominator = 1)
	{
		assert(denominator != 0); //checks to make sure we dont devide by zero 
		m_numerator = numerator;
		m_denominator = denominator;
	}

	int getNumerator() { return m_numerator; }
	int getDenominator() { return m_denominator; }
	double getValue() { return static_cast<double>(m_numerator) / m_denominator; } 
};

int main()
{
	//perfer value-initialization over default-initialization for class objects ( Fraction frac "{}"; )
	//favor brace initialization to initaize class objects
	Fraction frac{}; // calls fraction() default constructor just by existing (big balls energy)
	std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';

	return 0;
}
