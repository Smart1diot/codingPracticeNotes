#include <iostream>

class Foo
{
private:
	int m_value{ 4 };

public:
	const int& getValue() { return m_value; } //**NOTE getters should return by const reference/value to prevent altering data value
};

int main()
{
	Foo f;
	std::cout << f.getValue() << '\n';

	return 0;
}

//**NOTE 
//1 - If nobody outside your class needs to access a member, dont provide access functions for that member

//2 - If someonen outside your class needs to access a member, think about whether you can expose a behavior or
// action instead (e.g. rather than a setAlive(bool) setter, implement a kill() function instead

//3 If you cant, consider whether you can provide only a getter
