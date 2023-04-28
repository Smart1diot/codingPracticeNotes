//Delegating constructor i.e. constructor chaining
#include <iostream>

class Foo
{
private:

public:
	Foo()
	{
		//code to do A
	}

	Foo(int value) : Foo{}	// use Foo() default constructor to do A
							// make sure you're calling the constructor
							// from the member initializer list, not body
	{
		//*Body*
		//code to do B
		std::cout << "swag";
	}
};

int main()
{
	Foo f{ 2 }; 
	

	return 0;
}