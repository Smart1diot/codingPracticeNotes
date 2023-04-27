//*BEST PRACTICE* use member initializer list to initalize your class member variables 
#include <iostream>

class Something
{
private:
	int m_value1{};
	double m_value2{};
	char m_value3{};

public:
	// Directly initialize our member variables *
	Something(int value1, double value2, char value3='c') : m_value1{value1}, m_value2{value2}, m_value3{value3}
	

	{
		//No need for assignment here
	}

	void print()
	{
		std::cout << "Something(" <<
			m_value1 << ", " << m_value2 << ", " <<
			m_value3 << ")" << '\n';
	}
};

class SomethingWithConst
{
private:
	const int m_value1{};
	const double m_value2{};
	const char m_value3{};

public:
	SomethingWithConst(int value1, double value2, char value3 = 'f') : m_value1{ value1 }, m_value2{ value2 }, m_value3{ value3 }

	{
		//No need for assignment here

	}

	void print()
	{
		std::cout << "Something(" <<
			m_value1 << ", " << m_value2 << ", " <<
			m_value3 << ")" << '\n';
	}
};

class SomethingWithArrays
{
private:
	const int m_array[5];

public:
	SomethingWithArrays(): m_array{ 1, 2, 3, 4, 5 } //c++11 I can list but otherwise should use for loop if before c++11

	{
	}

	void print()
	{
		int arrayMembers{ 5 };
		for (int i{ 0 }; i < arrayMembers; ++i)
		{
			std::cout << m_array[i] << " ";
		}
		std::cout << '\n';
	}
};

class A
{
public:
	A(int x = 0) { std::cout << "A " << x << '\n'; }
};

class B
{
private:
	A m_a{};
public:
	B(int y) : m_a{ y - 1 } // call A(int) constructor to intialize member m_a

	{
		std::cout << "B " << y << '\n';
	}
};

int main()
{
	Something something{1, 2.2 };
	something.print();

	//Const member variables must be initialized
	SomethingWithConst SomethingWithConstVariables{ 4, 5.5 }; 
	SomethingWithConstVariables.print();

	SomethingWithArrays SomethingWConstArrays{};
	SomethingWConstArrays.print();

	B b{ 5 };
}
