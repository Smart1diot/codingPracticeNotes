#include <iostream>

class Vector3d; // first, we need to tell the compiler that a class
				// named Vector3d exist

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z } {}

	void print() const
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector(const Vector3d& v); // so we can use Vector3d here
	//we cant define this function here, because Vector3d hasnt been defined
	//yet. just forward declared.
};

class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z } {}

	void print() const
	{
		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	friend void Point3d::moveByVector(const Vector3d& v);
	// Point3d::moveByVector() is now a friend of class Vector3d
};

void Point3d::moveByVector(const Vector3d& v) // here we define Point3d::moveByVector()
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

int main()
{
	Point3d p{ 1.0,2.0,3.0 };
	Vector3d v{ 2.0,2.0,-3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}