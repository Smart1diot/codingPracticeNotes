#include <iostream>
#include <string>
#include <string_view>

class Foo
{
private:
	const int m_value{ 0 };

	void setup() // setup is private so it can only be used by our constructors

	{
		//code to do some common setup tasks e.g. ope a file or database)
		std::cout << "Setting things up..." << '\n';
	}

public:
	Foo()
	{
		setup();
	}

	Foo(int value) : m_value{ value }

	{
		setup();
	}
};

int main()
{
	Foo a;

	Foo b{ 5 };

	return 0;
}
