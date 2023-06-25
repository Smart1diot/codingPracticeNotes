//operators, function calls, and function templates
#include <iostream>

class Cents
{
private:
	int m_cents{};
public:
	Cents(int cents)
		: m_cents{ cents }
	{}

	//bool overloaded function to make templates and classes work together
	friend bool operator<(const Cents& c1, const Cents& c2)
	{
		return (c1.m_cents < c2.m_cents);
	}

	friend std::ostream& operator<<(std::ostream& ostr, const Cents& c)
	{
		ostr << c.m_cents;
		return ostr;
	}
};

template <typename T>
const T& max(const T& x, const T& y)
{
	//to make (x<y) work we need an overloaded function in the class
	return (x < y) ? y : x;
}

int main()
{
	Cents nickel{ 5 };
	Cents dime{ 10 };

	Cents bigger = max(nickel, dime);
	std::cout << bigger << " is bigger\n";

	return 0;
}
//