#include <iostream>
#include <cmath>

class Point2d
{
private:
	double m_x;
	double m_y;

public:
	Point2d(double x = 0.0, double y = 0.0)
		: m_x{ x }, m_y{ y } {};

	double distanceTo(Point2d& p2)
	{
		return std::sqrt((m_x - p2.m_x) * (m_x - p2.m_x) + (m_y - p2.m_y) * (m_y - p2.m_y));
	}

	friend double distanceFrom(Point2d& p1, Point2d& p2);

	void print()
	{
		std::cout << "Point(" << m_x << " , " << m_y << ")\n";
	}
};

double distanceFrom(Point2d& p1, Point2d& p2)
{
	return std::sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
}

int main()
{
	Point2d first{};
	Point2d second{ 3.0,4.0 };

	first.print();
	second.print();

	std::cout << "Distance between two point: " << first.distanceTo(second) << '\n';

	std::cout << "Distance between two point: " << distanceFrom(first, second) << '\n';

	return 0;
}
//
