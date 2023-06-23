#include <cassert>
#include <iostream>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	//Default constructor
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
		assert(denominator != 0);
	}

	//Copy Constructor
	Fraction(const Fraction& copy)
		: m_numerator{ copy.m_numerator }, m_denominator{ copy.m_denominator }
	{
		std::cout << "Copy constructor called\n";
	}

	//Overloaded assignment
	Fraction& operator=(const Fraction& fraction);

	friend std::ostream& operator<<(std::ostream& out, Fraction& f1);
};

//A simplistic implementation of operator=
Fraction& Fraction::operator=(const Fraction& fraction)
{
	//do the copy
	m_numerator = fraction.m_numerator;
	m_denominator = fraction.m_denominator;

	//return the existing object so we can chain this operator
	return *this;
}

std::ostream& operator<<(std::ostream& out, Fraction& f1) //function that prints class members
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main()
{
	Fraction fiveThirds{ 5,3 };	//normal Fraction object
	Fraction f;					//blank object with default parameters if any ave been set
	f = fiveThirds;				//calls overloaded assignment to copy fiveThirds object to f object
	std::cout << f;				//prints fraction 5/3

	std::cout << '\n';			//next line skip

	Fraction fiveThirds2{ 7,2 };	//object 2
	Fraction fiveThirds3{ 9,5 };	//object 3

	fiveThirds = fiveThirds2 = fiveThirds3;	//chained assignment makes all the objects turn 9/5 the last chained object

	std::cout << fiveThirds << ' ' << fiveThirds2 << ' ' << fiveThirds3 << '\n';
	//prints 9/5 9/5 9/5

	return 0;
}
