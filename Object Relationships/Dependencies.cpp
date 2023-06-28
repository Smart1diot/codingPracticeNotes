#include <iostream>

class Point
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point(double x, double y, double z)
		: m_x{ x }, m_y{ y }, m_z{ z } {}

	friend std::ostream& operator<<(std::ostream& out, const Point& point);

};

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	//since operator<< is a friend of the Point class, we can
	//access Point's members directly.
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
	return out;
}

int main()
{
	Point point1{ 2.0,3.0,4.0 };

	//this program has a dependency on std::cout here
	std::cout << point1;

	return 0;
}
//The object being depended on is typically instantiated as needed
//like opening a file to write data to
