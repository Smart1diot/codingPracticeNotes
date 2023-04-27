//*Favor non-static membern initialization to give default values for member variables
#include <iostream>

class Rectangle
{
private:
	double m_length{ 1.0 };
	double m_width{ 1.0 };

public:

	Rectangle(double length, double width) :
		m_length{ length },
		m_width{ width }

	{
	}

	Rectangle(double length) :
		m_length{ length }

	{
	}

	void print()
	{
		std::cout << "length: " << m_length << ", width: " << m_width << '\n';
	}
};

int main()
{
	Rectangle x{ 2.0,3.0 };
	x.print();

	Rectangle y{ 4.0 };
	y.print();

	Rectangle z{}; // wont compile without parameters send to it

	return 0;
}
