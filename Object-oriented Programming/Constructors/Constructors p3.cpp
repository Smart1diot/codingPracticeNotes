//Classes containing class members 
//a class may contain other class objects as member variables. by default, when theh other
//class is constructed, the member vaariables will have their default constructors called, this
//happens before the body of the constructor executes.
#include <iostream>

class A
{
public:
	A() { std::cout << "A" << '\n'; }
};

class B
{
private:
	A m_a; // B contains A as a member variable

public:
	B() { std::cout << "B" << '\n'; }
};

int main()
{
	B b;

	return 0;
}
