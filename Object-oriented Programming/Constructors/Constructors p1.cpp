#include <iostream>
#include <cassert>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction() // default constructor
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	//constructor with two parameters, one parameter having a default value
	Fraction(int numerator, int denominator = 1)
	{
		assert(denominator != 0);
		m_numerator = numerator;
		m_denominator = denominator;
	}

	int getNumerator() { return m_numerator; }
	int getDenominator() { return m_denominator; }
	double getValue() { return static_cast<double>(getNumerator()) / getDenominator(); }
};

int main()
{
	Fraction defaultValues{};
	Fraction fiveThird{ 5,3 }; // list initialization, calls fraction (int, int)
	Fraction threeQuarters(3, 4); // direct initialization, also calls Fraction(int, int)

	std::cout << defaultValues.getNumerator() << '/' << defaultValues.getDenominator() << '\n';
	std::cout << fiveThird.getNumerator() << '/' << fiveThird.getDenominator() << '\n';
	std::cout << threeQuarters.getNumerator() << '/' << threeQuarters.getDenominator() << '\n';


	//perfer value-initialization over default-initialization for class objects ( Fraction frac "{}"; )
	//favor brace initialization to initaize class objects

	return 0;
}
