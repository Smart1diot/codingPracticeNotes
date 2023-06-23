//Implicit conversion example
//explicit keyword example
//delete keyword example

#include <cassert>
#include <iostream>
#include <string>

class Fraction// Implicit conversion example
{
	int m_numerator;
	int m_denominator;

public:
	//Default constructor
	Fraction(int numerator = 0, int denominator = 1)//2.implicit conversion
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
		assert(denominator != 0);
	}

	Fraction(const Fraction& copy)
		: m_numerator{ copy.m_numerator }, m_denominator{ copy.m_denominator }
	{
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);//3.implicit conversion

	int getNumerator() { return m_numerator; }
	void setNumerator(int numerator) { m_numerator = numerator; }
};

class MyString//Explicit keyword example
{
private:
	std::string m_string;

public:
	//delete keyword to prevent constructor use
	MyString(char) = delete; // any use of this constructor is an error

	//explicit keyword makes this constructor ineligible for implicit conversions
	explicit MyString(int x) // allocate string of size x
	{
		m_string.resize(x);
	}

	MyString(const char* string) // allocate string to hold string value
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	out << s.m_string;
	return out;
}

void printString(const MyString& s)
{
	std::cout << s;
}

void printFraction(const Fraction& f) //1.implicit conversion
{
	std::cout << f;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f1) //3.implicit conversion
{
	out << f1.m_numerator << '/' << f1.m_denominator;

	return out;
}

int main()
{
	//implicit conversion - prints 6/1
	printFraction(6); 
	//converts int 6 into fraction& using copy constructor then converts 
	//to fraction and prints 6/1 using ostream& friend function

	//-------------------------------------------------------------

	//MyString mine = 'x'; //compile error since MyString(int) is now explicit
	//std::cout << mine << '\n';
	//printString('x'); //compile error since MyString(int) is now explicit

	MyString str{ 'x' }; //Allowed: initialization parameters may still
	//be implicitly converted to match

	//*Best Practice* consider making our constructors and user-defined conversion
	//member functions explicit to prevent implicit conversion errors
	
	//-------------------------------------------------------------

	//delete keyword used from class
	MyString str2{ 'y' }; //compie error, since MyString(char) is deleted

	return 0;
}
