#include <cassert>
#include <iostream>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	//Default constructor
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator } 
	{
		assert(denominator != 0);
	}
	//It is a requirement that the parameters be const reference the class
	Fraction(const Fraction& fraction) //I can make the public construct private if i chose
		: m_numerator{ fraction.m_numerator }, m_denominator{ fraction.m_denominator }
	{
		//no need to check for a denominator of 0 here since fraction must already be a valid Fraction
		std::cout << "Copy constructor called\n";
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
	int x(5);					// Direct initalize an integer
	Fraction fiveThirds(5, 3);	// Direct initalize a Fraction, calls Fraction(int,int) constuctor

	//in c++11 we can do a uniform initialization
	int y{ 5 };					// Uniform initialization of an integer
	Fraction fiveThirds2{ 5,3 };	// Uniform initialization of a Fraction, calls Fraction(int, int) constuctor

	//copy initialization
	int z = 6;					// Copy initialize an integer
	Fraction six = Fraction(6);	// Copy initialize a Fraction, will call Fraction(6,1)
	Fraction seven = 7;			// Copy initialize a Fraction, the compiler will try to find a way
	//to convert 7 to a Fraction, which will invoke the Fraction(7,1) constructor

	std::cout << fiveThirds << ' ' << fiveThirds2 << ' ' << six << ' ' << seven << '\n';

	//Copying a class using custom copy construct if there is no custom construct
	//c++ will have a public one to use by default
	Fraction fcopyFiveThirds2{ fiveThirds2 };
	std::cout << fcopyFiveThirds2 << '\n';

	Fraction fcopyFiveThirds3{ Fraction {5,3} }; // this method avoids the copy construct entirely if the compiler choses
	std::cout << fcopyFiveThirds3 << '\n';

	return 0;
}