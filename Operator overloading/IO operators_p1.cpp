#include <iostream>

class Point
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z } {}

	friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	//since operator<< is a friend of the Point class, we can access Point's members directly.
	out << "Point(" << point.m_x << ',' << point.m_y << ',' << point.m_z << ')' << '\n';

	return out;
}

int main()
{
	Point p{ 1.1,2.2,3.3 };
	Point p2{ 4.4,5.5,6.6 };

	std::cout << p << p2; // making a function usingg operator<< we can default a print of members just using the class object name
	// doing so allows us to chain multiple class objects to print or whatever is necessary 

	return 0;
}
