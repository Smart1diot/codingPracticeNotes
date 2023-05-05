#include <iostream>

class Something
{
private:
	static int s_value;

public:
	//static member function
	static int getValue() { return s_value; }
};

int Something::s_value{ 1 }; // initialize

int main()
{
	std::cout << Something::getValue() << '\n';

	return 0;
}
//*NOTE* static variales dont have *this pointer since they arent attached to objects

//static member functions can directly access other static members, but not
// non-static members - this is because non-static members must belong to a 
// class object 