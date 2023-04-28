#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
	std::string m_color{"black"};
	double m_radius{10.0};

public:
	Ball() = default; // best for default members

	Ball(std::string_view color) : m_color{ color } {}

	Ball(double radius) : m_radius{ radius } {}

	Ball(std::string_view color, double radius) :
		m_color{color},
		m_radius{radius}

	{
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();
	 
	Ball bluetwenty{ "blue", 20.0 };
	bluetwenty.print();

	return 0;
}